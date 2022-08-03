#include <iostream>
#include "CmDataCache.h"
#include <ctime>
#include "../../../redispool/redisclient.h"
// int stoi_s(const std::string &str)
// {
//     int i = 0;
//     try
//     {
//         i = std::stoi(str);
//     }
//     catch (...)
//     {
//     }
//     return i;
// }
void DataCache::PollingQueue()
{

    std::vector<std::string> list;
    RedisOperate instance;
    std::string list_name = "cm_id_cluster";
    ormpp::dbng<ormpp::mysql> mysqlclient;
    settingParser mysql_example;
    sqlconnect conne = mysql_example.GetSettinghParser("conf/config.json");
    std::string port = "3306";
    mysqlclient.connect(conne.host.c_str(), conne.user.c_str(), conne.password.c_str(), conne.db.c_str());
    int sleep_judge = 0;
    while (true)
    {
        if (list.empty())
        {
            list = instance.GetListFromRedis(list_name);
            if (list.empty())
            {
                LOGGER->info("no cache data,PollingQueue  sleep 300s");
                sleep(300);
                LOGGER->info("PollingQueue  wakeup");
                continue;
            }
        }
        for (auto &now_id : list)
        {
            LOGGER->info("PollingQueue  id is {}", now_id);
            IdMuster muster = ParseCmId(now_id);
            if (muster.time != "oc" && muster.time != "web" && muster.time != "now")
            {
                CallBackRules rule;
                CallBackData data;
                std::string cm_data_cache = instance.SearchRules(now_id);
                int calllog_or_cc_number = 1;
                std::tuple<std::string, std::string, std::string, std::string, std::string, std::string> id_cluster;

                if (cm_data_cache != "null")
                {
                    data = CacheCmJsonSwitch(cm_data_cache);
                    PrepareId(data, rule, calllog_or_cc_number, muster.calllog_id, id_cluster, mysqlclient);
                    GetRulesFromRedis(rule);
                    if (OC_sync_judge(muster.calllog_id, mysqlclient) || CheckTimeOut(muster))
                    {
                        GetOCSyncData(data, mysqlclient);
                        if (CallBackJudge(rule, data))
                        {
                            // callback
                            instance.DelKey(now_id);
                            instance.LREMForList(list_name, {now_id});
                            std::string caback_data = MergeCacheJson(data, cm_data_cache);
                            CallBackManage begin_callback;
                            int class_judge = 2;
                            begin_callback.CacheCmData(data, caback_data, class_judge, mysqlclient);
                            LOGGER->info("pull actionqueue");
                        }
                        else
                        {
                            instance.DelKey(now_id);
                            instance.LREMForList(list_name, {now_id});
                            LOGGER->info("donot pass rules judge,donot callback");
                        }
                    }
                    else
                    {
                        LOGGER->info("oc not sync,back to redis,and sleep 300s");
                        sleep(300);
                    }
                }
                else
                {
                    instance.LREMForList(list_name, {now_id});
                    LOGGER->info("null cm_data_cache ,donot callback");
                }
            }
        }
        list.clear();
    }
}

void DataCache::OcWebPollingQueue()
{
    std::vector<std::string> list;
    RedisOperate instance;
    std::string list_name = "cm_id_cluster_ocweb";
    ormpp::dbng<ormpp::mysql> mysqlclient;
    settingParser mysql_example;
    sqlconnect conne = mysql_example.GetSettinghParser("conf/config.json");
    mysqlclient.connect(conne.host.c_str(), conne.user.c_str(), conne.password.c_str(), conne.db.c_str());
    while (true)
    {
        if (list.empty())
        {
            list = instance.GetListFromRedis(list_name);
            if (list.empty())
            {
                LOGGER->info("no cache data,OcWebPollingQueue  sleep 300s");
                sleep(300);
                LOGGER->info("OcWebPollingQueue  wakeup");
                continue;
            }
        }
        for (auto &now_id : list)
        {
            CallBackRules rule;
            CallBackData data;

            IdMuster muster = ParseCmId(now_id);
            std::tuple<std::string, std::string, std::string, std::string, std::string, std::string> id_cluster;
            int calllog_or_cc_number;
            if (muster.time == "cm_whole")
                calllog_or_cc_number = 0; // 0:use cc_number ,1:use calllog_id
            else
                calllog_or_cc_number = 1;
            if (muster.calllog_id != "")
                PrepareId(data, rule, calllog_or_cc_number, muster.calllog_id, id_cluster, mysqlclient); // muster.calllog_id  maybe  cc_number

            bool class_judge = 0; // whatever just not  0
            std::string data_ = "";
            if (muster.time == "web")
            {
                data_ = GetCallRecordFromCm(data,mysqlclient);
                class_judge = 1;
            }
            else if (muster.time == "oc")
                class_judge = 3;
            else if (muster.time == "cm_whole")
            {
                data_ = instance.SearchRules(now_id);
                class_judge = 0;
            }

            // CallBackManage update_action;

            // update_action.CallBackHandle(data,id_cluster,class_judge);
            UpdateMessage update_action;
            if (data.calllog_id != "")
                update_action.HandleSQL(data_,mysqlclient, class_judge, data.calllog_id);

            instance.DelKey(now_id);
            instance.LREMForList(list_name, {now_id});
        }
        list.clear();
    }
}

void DataCache::CallBackActionQueue()
{
    std::vector<std::string> list;
    RedisOperate instance;
    std::string list_name = "cm_id_cluster_now";

    while (true)
    {
        if (list.empty())
        {
            list = instance.GetListFromRedis(list_name);
            if (list.empty())
            {
                LOGGER->info("no cache data,CallBackActionQueue  sleep 300s");
                sleep(300);
                LOGGER->info("CallBackActionQueue  wakeup");
                continue;
            }
        }
        for (auto &now_id : list)
        {
            IdMuster muster = ParseCmId(now_id);

            if (muster.time == "now")
            {
                std::string data_cache = instance.SearchRules(now_id);
                LOGGER->info("begin call back!!!  data is {}", data_cache);
                CallBackAction(data_cache, muster.url);
                instance.DelKey(now_id);
                instance.LREMForList(list_name, {now_id});
            }
            else
            {
                instance.DelKey(now_id);
                instance.LREMForList(list_name, {now_id});
            }
        }
        list.clear();
    }
}

IdMuster DataCache::ParseCmId(const std::string &cm_id)
{
    IdMuster muster;
    int id_num = 0;
    int pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
    // for (int i = 0; i < cm_id.size(); i++)
    // {
    //     if (cm_id[i] == '-')
    //     {
    //         if (pos1 == 0)
    //         {
    //             pos1 = i;
    //             break;
    //         }
    //         else if (pos2 == 0)
    //         {
    //             pos2 = i;
    //             break
    //         }
    //     }
    // }
    if (count(cm_id.begin(), cm_id.end(), '-') == 1)
    {

        pos1 = cm_id.find('-');
        muster.calllog_id = cm_id.substr(0, pos1);
        muster.time = cm_id.substr(pos1 + 1, (cm_id.size() - pos1 - 1));
        // LOGGER->info("calllog_id is {},type is {}", muster.calllog_id, muster.time);
    }
    else if (count(cm_id.begin(), cm_id.end(), '-') == 2)
    {
        pos1 = cm_id.find('-');
        int pos2 = cm_id.find('-', pos1 + 1);
        muster.calllog_id = cm_id.substr(0, pos1);
        muster.url = cm_id.substr(pos1 + 1, pos2 - pos1 - 1);
        muster.time = cm_id.substr(pos2 + 1, (cm_id.size() - pos2 - 1));
    }
    else
    {
        LOGGER->info("parse error ,redis data have problem");
    }
    return muster;
}

bool DataCache::CheckTimeOut(const IdMuster &muster)
{
    auto now = time(NULL);
    std::stringstream sstream;
    sstream << now;
    std::string time_ = sstream.str();
    if (stoi(time_) - stoi(muster.time) >= 600)
    {
        LOGGER->info("Callback_data is timeout,force callback");
        return 1;
    }
    else
        return 0;
}
