#ifndef CALLBACK_H
#define CALLBACK_H

#include <iostream>
#include <string>
#include <json/json.h>
#include "../../dbstruct/dbstruct.h"
#include "../GetCallRecord.h"
#include "ormpp/dbng.hpp"
#include "ormpp/mysql.hpp"


struct CallBackRules{
    int task_id;
    int eid;
    int range;
    int call_record_detail;//0:donot callback,1:callback
    int call_record_detail_occasion;//0 :all  1:auto_task should use rules
    int call_count;
    std::string intention_type_judge;
    std::string call_result_judge;
    CallBackRules() : task_id(0),eid(0),range(0),call_record_detail(0),call_record_detail_occasion(0),
                      call_count(0),intention_type_judge(""),call_result_judge(""){}
};

struct CallBackData{
    //May be cm/oc  data
        std::string record_url;
        std::string answer_time;//sql confirm_timestamp
        std::string hangup_time;//end_time
        int duration_time;
        std::string transfer_number;
        int transfer_duration;
        std::string switch_number;
        int manual_status;
        std::string cc_number;
        int call_result;
        int hangup_type;
    //OC_data
        std::string	uuid;
        std::string	task_id;
        std::string	script_name;
        std::string	callee_phone;
        std::string	caller_phone;
        std::string	calllog_txt;
        std::string	intention_type;
        std::string	label;
        std::string	call_count;
        std::string	match_global_keyword;
        std::string	clue_no;
        std::string	collect_info;
        std::string	buttons;
        std::string	calllog_id;

        CallBackData() : record_url(""),answer_time(""),hangup_time(""),duration_time(0),transfer_number(""),
                         transfer_duration(0),switch_number(""),manual_status(0),cc_number(""),call_result(0),
                        hangup_type(0), uuid(""),task_id(""),script_name(""),callee_phone(""),caller_phone(""),
                        calllog_txt(""),intention_type(""),label(""),call_count(""),match_global_keyword(""),
                        clue_no(""),collect_info(""),buttons(""),calllog_id{}
};

enum IntentionType
{
    IntentionA = 1,
    IntentionB,
    IntentionC,
    IntentionD,
    IntentionE,
    IntentionF,
    IntentionG,
    IntentionH,
    IntentionI,
    IntentionJ //J is not used, just use as sentinel
};

class CallBackManage:public CallRecord{
public:
    void GetOCSyncData(ormpp::dbng<ormpp::mysql> &mysql,CallBackData &data);
};      

#endif