
#include "cinatra.hpp"
#include "ormpp/dbng.hpp"
#include "ormpp/mysql.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/async.h"
#include <vector>
#include <string>
#include "GetCallRecord.h"
#include "CallBack/CallBack.h"
#define SPDLOG_FILENAME "log/TrimuleLogger.log"
#define SPDLOGGERNAME "TrimuleLogger"
#define LOGGER spdlog::get(SPDLOGGERNAME)
class UpdateMessage
{
public:
    void UpdateMessage::HandleSQL(std::string &s,const bool &class_judge,const std::string &calllog_id)
 
private: 
    void UpdateCalllog(CallInfo callog);
    void UpdateOutCallClue(CallInfo callog,std::string clue_id);
    void UpdateAiCalllogExtension(CallInfo callog,std::string calllog_id);
    void ExecuteCommand(std::string &s,std::string children_db_name);
    // int  NewGetHangupCauseFromCallRecord(CallInfo info);
    // int  GetCallResult(int cause); 
    std::string CalculateTransferManualCost(CallInfo callog);
    std::tuple<int, int,int,int,int> GetIdFromMysql(const bool &class_judge,const std::string &condition);
};