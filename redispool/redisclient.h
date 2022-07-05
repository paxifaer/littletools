#ifndef _REDIS_H_
#define _REDIS_H_

#include <sw/redis++/redis++.h>
#include <iostream>
#include "spdlog/spdlog.h"
#define SPDLOG_FILENAME "log/TrimuleLogger.log"
#define SPDLOGGERNAME "TrimuleLogger"
#include <unordered_set>
#define LOGGER spdlog::get(SPDLOGGERNAME)
using namespace sw::redis;

class RedisOperate
{
public:
  
    static RedisOperate *getInstance();
    void CacheRules(const std::string &key,const std::string &rules);
    std::string SearchRules(const std::string &str);
    void RedisOperate::CacheData(const std::string &key,const std::string &str,int time);
    void RedisOperate::CacheData(const std::string &key,const std::string &str);
    std::unordered_set<std::string> GetSetFromRedis(const std::string & set);
    void REMForSet(const std::string &set_name,const std::unordered_set<std::string> &values);
    void InsertSet(const std::string &set_name,const std::unordered_set<std::string> &values);
private:
    Redis redis;
    void RedisConnect();
    RedisOperate();
    RedisOperate(const RedisOperate &);
    RedisOperate &operator=(const RedisOperate &);
    ~RedisOperate();


};

#endif