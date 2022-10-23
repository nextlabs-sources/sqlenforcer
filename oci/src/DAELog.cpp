#include "DAELog.h"
#include <stdio.h>
#include <stdarg.h>
#ifdef _WIN32
#include <windows.h>
#endif
#define MAX_MESSAGE_SIZE_CHARS 1024*10
#include "DAEEnforcerWrapper.h"

namespace sources = boost::log::sources;
namespace sinks = boost::log::sinks;

// Declare attribute keywords
BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", boost::log::trivial::severity_level)
BOOST_LOG_ATTRIBUTE_KEYWORD(timestamp, "TimeStamp", boost::posix_time::ptime)

WriteLog_Fun Log::_logfunc = nullptr;

//bool Log::InitLog(const std::string& module_name, const std::string & log_path){
//    boost::shared_ptr< boost::log::core > core = boost::log::core::get();
//
//    core->set_filter(boost::log::trivial::severity >= boost::log::trivial::trace);
//    boost::log::add_common_attributes(); // Add TimeStamp, ThreadID so that we can use those attributes in Format.
//
//    /* log formatter: [TimeStamp] [ThreadId] [Severity Level] [Scope] Log message */
//    auto fmtTimeStamp = boost::log::expressions::format_date_time(timestamp, "%Y-%m-%d %H:%M:%S.%f");
//    //auto fmtThreadId = boost::log::expressions::attr<boost::log::attributes::current_thread_id::value_type>("ThreadID");
//    auto fmtSeverity = boost::log::expressions::attr<boost::log::trivial::severity_level>(severity.get_name());
//
//    boost::log::formatter logFmt = boost::log::expressions::format("%1%|%2%|%3%")
//                                   % fmtTimeStamp %  fmtSeverity % boost::log::expressions::smessage;
//
//
//    {
//        typedef sinks::synchronous_sink < sinks::text_file_backend > sink_t;
//        std::string strLogPath = log_path + '/'  + module_name + "_%Y-%m-%d_%H-%M-%S.%N.log";
//        //typedef sinks::text_file_backend backend_t;
//        boost::shared_ptr< sinks::text_file_backend > backend =
//                boost::make_shared< sinks::text_file_backend >(
//                        boost::log::keywords::file_name =  strLogPath,
//                        boost::log::keywords::rotation_size = 10 * 1024 * 1024,
//                        boost::log::keywords::min_free_space = 30 * 1024 * 1024,
//                        boost::log::keywords::open_mode = std::ios_base::app);
//        boost::shared_ptr< sink_t > fsSink(new sink_t(backend));
//        fsSink->set_formatter(logFmt);
//        fsSink->locked_backend()->auto_flush(true);
//        core->add_sink(fsSink);
//    }
//
//    return true;
//}

int Log::WLog(int nlevel, const char* szFmt, ...) {
    int nLog = 0;
    const int nMaxMsgSize = 1024;
    char szLog[nMaxMsgSize] = {0};

    //format log content
    va_list args;
    va_start(args, szFmt);
    nLog = vsnprintf(szLog, nMaxMsgSize-1, szFmt, args);
    va_end(args);
    if(_logfunc!=NULL) {
        _logfunc(nlevel, szLog);
    } else {

        if(NULL != Enforcer::Instance()->EMDBWriteLog) {
            Enforcer::Instance()->EMDBWriteLog(nlevel, "OCI", szLog);
        } else {
            #ifdef _WIN32
                ::OutputDebugStringA(szLog);
            #else
                WriteLogInternal(nlevel, szLog);
            #endif
        }
    }
   //
	return nLog;
}

void Log::WriteLogInternal(int nlevel, const char* szLog)
{
    switch(nlevel)
    {
        case boost::log::trivial::trace:
            BOOST_LOG_TRIVIAL(trace)<<szLog;
            break;
        case boost::log::trivial::debug:
            BOOST_LOG_TRIVIAL(debug)<<szLog;
            break;
        case boost::log::trivial::info:
            BOOST_LOG_TRIVIAL(info)<<szLog;
            break;
        case boost::log::trivial::warning:
            BOOST_LOG_TRIVIAL(warning)<<szLog;
            break;
        case boost::log::trivial::error:
            BOOST_LOG_TRIVIAL(error)<<szLog;
            break;
        case boost::log::trivial::fatal:
            BOOST_LOG_TRIVIAL(fatal)<<szLog;
            break;
        default:
            break;
    }
}
