#include <string>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <json/json.h>
#include <fstream>

#include "../include/Utility.h"

#ifdef _WIN32
#include <windows.h>
#endif
#include "sql.h"

#ifndef SQL_TINYINT
#define SQL_TINYINT -6
#endif // !SQL_TINYINT
#ifndef SQL_BIGINT
#define SQL_BIGINT -5
#endif // !SQL_BIGINT

#ifdef _WIN32
#define FILE_PATH_SEPERATOR '\\'
#else
#define FILE_PATH_SEPERATOR '/'
#endif

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::runtime_error;
using std::string;

std::string Utility::getcwd(const std::string &program_path)
{
    int iPos = program_path.rfind(FILE_PATH_SEPERATOR);
    const string cwd = program_path.substr(0, iPos);

    return cwd;
}

std::string Utility::getConnStrConfigPath()
{
    cout << "Please input the absolute path of the connection string config file:" << endl;

    string path;
    getline(cin, path);

    return path;
}

std::string Utility::getSqlStatement(const std::string &sql_statement_or_path)
{
    auto i = sql_statement_or_path.find(".sql");

    if (i == string::npos)
    {
        return sql_statement_or_path;
    }
    else
    {
        std::ifstream in(sql_statement_or_path);

        if (in)
        {
            std::string text((std::istreambuf_iterator<char>(in)),
                             std::istreambuf_iterator<char>());
            Utility::removeUTF8BOM(text);
            return text;
        }
        else
        {
            throw runtime_error("Can not read config file: " + sql_statement_or_path);
        }
    }
}

NXL::nanodbc::result Utility::getSQLResults(const std::string &conn_str, const std::string &sql)
{
    const auto& connstr =  NANODBC_TEXT(conn_str);
    const auto& sqlstr = NANODBC_TEXT(sql);
    NXL::nanodbc::connection conn(connstr);
    auto result = NXL::nanodbc::execute(conn, sqlstr);

    return result;
}

void Utility::showSQLResults(NXL::nanodbc::result &results)
{
    const short columns = results.columns();

    if (columns > 0) {
        // show the column names
        for (short i = 0; i < columns; ++i)
        {
            printf("%-25s", results.column_name(i).c_str());
        }
        printf("\n");

        // show the column data for each row
        while (results.next())
        {
            for (short col = 0; col < columns; ++col)
            {
                auto col_type = results.column_datatype(col);

                switch (col_type)
                {
                    case SQL_BIGINT:
                    case SQL_INTEGER:
                    case SQL_SMALLINT:
                    case SQL_TINYINT:
                    {
                        auto value = results.get<int>(col, 0.0);
                        printf("%-25s", std::to_string(value).c_str());
                    }
                        break;
                    case SQL_NUMERIC:
                    case SQL_DECIMAL:
                    case SQL_FLOAT:
                    case SQL_REAL:
                    case SQL_DOUBLE:
                    {
                        auto value = results.get<double>(col, 0.0);
                        printf("%-25s", std::to_string(value).c_str());
                    }
                        break;
                    default:
                    {
                        auto value = results.get<string>(col, "null");
                        printf("%-25s", value.c_str());
                    }
                        break;
                }

            }
            printf("\n");
        }
    }
}

void Utility::showMenu()
{
    printf("%s\n", "MENU:");
    printf("%-25s %s\n", "QUIT/Q", "exit program");
}

int Utility::compare_str(const std::string &left, const std::string &right)
{
#ifndef _WIN32
    return strcasecmp(left.c_str(), right.c_str()) ;
#else
    return stricmp(left.c_str(), right.c_str());
#endif
}

void Utility::removeUTF8BOM(std::string& s) noexcept {
    if ((unsigned char)s[0] == 0xEF
        && (unsigned char)s[1] == 0xBB
        && (unsigned char)s[2] == 0xBF)
    {
        s.erase(0, 3);
    }
}

std::string Utility::readFstream(std::fstream& fstream) {
    std::stringstream ss;
    ss << fstream.rdbuf();

    return ss.str();
}