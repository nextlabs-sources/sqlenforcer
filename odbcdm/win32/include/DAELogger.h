#ifndef DAE_LOGGER_H
#define DAE_LOGGER_H

#include <string>

#include "enforcerwrapper.h"

enum DaeLogLevel
{
    log_trace = 0,
    log_debug,
    log_info,
    log_warning,
    log_error,
    log_fatal
};

class DAELogger
{
public:
    static int WriteLog(DaeLogLevel log_level, const std::string& msg)
    {
        return Enforcer::Instance()
                ->SQLEnforcerWriteLogWithTagA(static_cast<int>(log_level), "ODBC", msg.c_str());
    }

    static int Trace(const std::string& msg)
    {
        return WriteLog(DaeLogLevel::log_trace, msg);
    }

    static int Debug(const std::string& msg)
    {
        return WriteLog(DaeLogLevel::log_debug, msg);
    }

    static int Info(const std::string& msg)
    {
        return WriteLog(DaeLogLevel::log_info, msg);
    }

    static int Warning(const std::string& msg)
    {
        return WriteLog(DaeLogLevel::log_warning, msg);
    }

    static int Error(const std::string& msg)
    {
        return WriteLog(DaeLogLevel::log_error, msg);
    }

    static int Fatal(const std::string& msg)
    {
        return WriteLog(DaeLogLevel::log_fatal, msg);
    }
};

#endif