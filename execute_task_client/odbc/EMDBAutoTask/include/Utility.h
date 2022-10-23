#ifndef EMDB_AUTO_TASK_UTILITY_H
#define EMDB_AUTO_TASK_UTILITY_H

#include "nanodbc_nxl.h"

class Utility {
public:
    static std::string getcwd(const std::string &program_path);
    static std::string getConnStrConfigPath();
    static std::string getSqlStatement(const std::string &sql_statement_or_path);
    static NXL::nanodbc::result getSQLResults(const std::string &conn_str, const std::string &sql);
    static void showSQLResults(NXL::nanodbc::result& results);
    static void showMenu();
    static int compare_str(const std::string& left, const std::string& right);
    static void removeUTF8BOM(std::string& s) noexcept;
    static std::string readFstream(std::fstream& fstream);
};


#endif //EMDB_AUTO_TASK_UTILITY_H
