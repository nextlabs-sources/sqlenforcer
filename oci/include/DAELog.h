#ifndef OCI_DAE_LOG_H
#define OCI_DAE_LOG_H
#include "stdafx.h"

#include <boost/log/core.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/debug_output_backend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/console.hpp> // boost::log::add_console_log
#include <boost/log/utility/setup/file.hpp> // boost::log::add_file_log
#include <boost/filesystem.hpp>
#include <boost/log/sinks/async_frontend.hpp>


enum emLogLevel
{
    log_trace = boost::log::trivial::trace,
    log_debug = boost::log::trivial::debug,
    log_info = boost::log::trivial::info,
    log_warning = boost::log::trivial::warning,
    log_error = boost::log::trivial::error,
    log_fatal = boost::log::trivial::fatal
};


typedef int (*WriteLog_Fun)(int,const char * );

class Log
{

    public:
    //log callback
    static WriteLog_Fun _logfunc;
    
    //bool InitLog(const std::string& module_name, const std::string & log_path);
    public:
    static int  WLog(int lvl, const char* fmt, ...);
    static void WriteLogInternal(int nlevel, const char* szLog);

};





#endif 
