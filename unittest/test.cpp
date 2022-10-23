#include "microtest.h"
/* commonlib */
#include "commfun.h"
#include "config.h"
#include "EnforcerDataMgr.h"
#include "nanodbc.h"
/* policymgr */
#include <unistd.h>
/* sqlenforcer */
#include "sqlenforcer_export.h"
//#include "test_jeff.h"
#include "test_mask.h"
#include "SqlException.h"
#include "parser.h"

#ifdef JEFF

#define SQL_SERVER_CNN_STR NANODBC_TEXT("Driver=ODBC Driver 17 for SQL Server;Server=tcp:bard-dbc-executer.qapf1.qalab01.nextlabs.com,1433;Uid=sa;PWD=123blue!;Database=NXL_USER")
#define ORACLE_CNN_STR NANODBC_TEXT("DRIVER={Oracle 19 ODBC driver};uid=system;PWD=123blue123blue;dbq=EMDB-Oracle.qapf1.qalab01.nextlabs.com:1521/orcl")
#define MYSQL_CNN_STR NANODBC_TEXT("Driver={MySQL ODBC 8.0 Unicode Driver};Server=EMDB-MySQL.qapf1.qalab01.nextlabs.com;Port=3306;Database=sakila;User=root; Password=123blue!;Option=67108864;")

#include "parser.h"
#include "EMMaskOpr.h"
TEST(MASK) {
    std::string src = "select BUS0T_A, BUS0T_C AS CC FROM BUS0T";
    std::string out;
    bool bret = parser::compress_sql(src, out);
    if(bret) {
        printf("ori:%s\n", src.c_str());
        printf("new:%s\n", out.c_str());
    }

}

TEST(SQLENFORCER) {
    SqlException e;
    std::string conf_str = CommonFun::GetConfigFilePath();
    const char *  cfg = conf_str.c_str();
    bool rc = SQLEnforcerInit("odbc", cfg, &e);
    ASSERT_TRUE(rc);
}

//TEST(CConfig) {
//    class CConfig cfg; cfg.ReadConfig(CommonFun::GetConfigFilePath().c_str());
//    cfg.PrintConfigData();
//}

TEST(CommonFun) {
    void *h = CommonFun::LoadShareLibrary("libodbc_nxl.so");
    ASSERT_NOTNULL(h);
    void *f = CommonFun::GetProcAddress(h, "SQLGetDiagRec");
    ASSERT_NOTNULL(f);
    auto folder = CommonFun::GetProgramDataFolder();
    ASSERT_STREQ(folder, "/etc/Nextlabs/DAEforWin");
    auto url = CommonFun::UrlEncode("http://www.jsons.cn/urlencode/");
    ASSERT_STREQ(url, "http%3A%2F%2Fwww.jsons.cn%2Furlencode%2F");
    ASSERT_TRUE(CommonFun::StrCaseCmp("Hello", "hello") == 0);
    ASSERT_FALSE(CommonFun::StrCaseCmp("Hello", "he1llo") == 0);
    char buf[16] = { 0 }; int result = -1;
    bool b = CommonFun::CopyIntToA(12, buf, 16, result);
    ASSERT_TRUE(b && result == 2);
    wchar_t wbuf[16] = { 0 };
    b = CommonFun::CopyIntToW(123, wbuf, 16, result);
    ASSERT_TRUE(b && result == 3);

    std::string dst = "";
    ASSERT_TRUE(CommonFun::ToUTF8(L"hello world", dst) == "hello world" && dst == "hello world");
    std::wstring wdst = L"";
    ASSERT_TRUE(CommonFun::FromUTF8("hello world", wdst) == L"hello world" && wdst == L"hello world");
}

TEST(EnforcerDataMgr) {
    void *env1 = (void*)1;
    void *cnn1 = (void*)501;
    void *stmt1 = (void*)701;

    auto& EDM_INS = EnforcerDataMgr::Instance();
    EDM_INS.alloc_env_handle(env1);
    EDM_INS.alloc_connect_handle(env1, cnn1);
    EDM_INS.bind_stmt_handle(cnn1, stmt1);
    ASSERT_TRUE(EDM_INS.to_connect_handle_proxy(cnn1) != nullptr);
    ASSERT_TRUE(EDM_INS.to_stmt_handle_proxy(stmt1) != nullptr);
    ASSERT_TRUE(EDM_INS.to_connect_handle_proxy((void*)502) == nullptr);

    EDM_INS.push_error(SQL_HANDLE_STMT, stmt1, 10, "test error");
    EDM_INS.push_error(SQL_HANDLE_STMT, stmt1, 20, "another test error");
    EDM_INS.clear_error(SQL_HANDLE_STMT, stmt1);
    ASSERT_TRUE(EDM_INS.to_stmt_handle_proxy(stmt1)->errs_ == nullptr);

    EDM_INS.push_error(SQL_HANDLE_STMT, stmt1, 10, "test error");
    EDM_INS.push_error(SQL_HANDLE_STMT, stmt1, 20, "another test error");
    int i = -1; std::string err; EDM_INS.get_error(SQL_HANDLE_STMT, stmt1, 2, i, err);
    ASSERT_TRUE(i == 20 && err == "another test error");
    while (EDM_INS.get_error_last(SQL_HANDLE_STMT, stmt1, i, err));
    ASSERT_TRUE(EDM_INS.to_stmt_handle_proxy(stmt1)->errs_ == nullptr);

    EDM_INS.freehandle(SQL_HANDLE_STMT, stmt1);
    EDM_INS.freehandle(SQL_HANDLE_DBC, cnn1);
    EDM_INS.freehandle(SQL_HANDLE_ENV, env1);
}

/*
TEST(NANODBC) {
    unsigned int count = 0;
#ifdef SQL_SERVER_CNN_STR
    try {
        nanodbc::connection cnn(SQL_SERVER_CNN_STR);
        nanodbc::statement stmt(cnn, NANODBC_TEXT("SELECT 1 TEST;"));
        nanodbc::result result = nanodbc::execute(stmt);
        short columns = result.columns();
        nanodbc::string const null_value = NANODBC_TEXT("NULL");
        std::string c;
        for (short col = 0; col < columns; ++col) {
            nanodbc::string colname = result.column_name(col);
            std::string c;
            ASSERT_STREQ(CommonFun::ToUTF8(colname, c), "TEST");
        }
        while (result.next()) {
            for (short col = 0; col < columns; ++col) {
                auto value = result.get<int>(col);
                ASSERT_EQ(value, 1);
            }
        }
    }
    catch (nanodbc::database_error const& e) {
        mt::printFailed(e.what());
        ++count;
    }
#endif
#ifdef ORACLE_CNN_STR
    try {
        nanodbc::connection cnn(ORACLE_CNN_STR);
        nanodbc::statement stmt(cnn, NANODBC_TEXT("SELECT 1 test FROM DUAL"));
        nanodbc::result result = nanodbc::execute(stmt);
        short columns = result.columns();
        nanodbc::string const null_value = NANODBC_TEXT("NULL");
        std::string c;
        for (short col = 0; col < columns; ++col) {
            nanodbc::string colname = result.column_name(col);
            std::string c;
            ASSERT_STREQ(CommonFun::ToUTF8(colname, c), "TEST");
        }
        while (result.next()) {
            for (short col = 0; col < columns; ++col) {
                auto value = result.get<int>(col);
                ASSERT_EQ(value, 1);
            }
        }
    }
    catch (nanodbc::database_error const& e) {
        mt::printFailed(e.what());
        ++count;
    }
#endif
#ifdef MYSQL_CNN_STR
    try {
        nanodbc::connection cnn(MYSQL_CNN_STR);
        nanodbc::statement stmt(cnn, NANODBC_TEXT("SELECT 1 TEST;"));
        nanodbc::result result = nanodbc::execute(stmt);
        short columns = result.columns();
        nanodbc::string const null_value = NANODBC_TEXT("NULL");
        std::string c;
        for (short col = 0; col < columns; ++col) {
            nanodbc::string colname = result.column_name(col);
            std::string c;
            ASSERT_STREQ(CommonFun::ToUTF8(colname, c), "TEST");
        }
        while (result.next()) {
            for (short col = 0; col < columns; ++col) {
                auto value = result.get<int>(col);
                ASSERT_EQ(value, 1);
            }
        }
    }
    catch (nanodbc::database_error const& e) {
        mt::printFailed(e.what());
        ++count;
    }
#endif
    ASSERT_EQ(count, 0);
}
*/
#endif
int Log(int nLogLevel, const char* szMsg) {
    printf("%s\n", szMsg);
    return 0;
}

TEST(beautify_sql){
   // const std::string src = "SELECT * FROM EMDB_1_2.customer_mask WHERE ((customer_mask.salary =-100.01  or  customer_mask.salary =1.1e2 ) AND (customer_mask.test_a ='test1\'2'  or  customer_mask.test_a ='test1\'1' ) )  ";
    const std::string src = "SELECT * FROM EMDB_1_2.customer_mask WHERE ( (customer_mask.test_a ='test\\\\'12'  or  customer_mask.test_a ='test1''1' ) )  ";
    std::string  out;
    parser::beautify_sql( src, out);
    printf("%s\n",out.c_str());
}
/*
TEST(parsesql){
    std::string src = "SELECT customer_id, c_privilege_level FROM jdbc-enforcer";
    printf("ori:%s\n", src.c_str());
    std::string out;
    bool B = parser::beautify_sql( src,  out);
    //if(B)
    printf("ori:%s\n", out.c_str());
}
*/


/*
#include "policymgr_export.h"
TEST(POLICYMGR) {
    std::string policysyncinterval="60";
//    jpchost=https://92cc.nextlabs.solutions
//    jpcport=443
//    jpcuser=apiclient2
//    jpcpwd=12345Blue!

    std::string cchost="https://92cc.nextlabs.solutions";
    std::string ccport="443";
    std::string ccuser="Administrator";
    std::string ccpwd="123next!";
    std::string policytag="EMDB";

    bool b = PolicyInit(cchost.c_str(),
                        ccport.c_str(),
                        ccuser.c_str(),
                        ccpwd.c_str(),
                        policytag.c_str(),
                        atoi(policysyncinterval.c_str()),
                        &Log);


//    std::string str = CommonFun::GetConfigFilePath();
//    class CConfig cfg; cfg.ReadConfig(str.c_str());
//    auto theConfig = &cfg;
//    b = PolicyInit((*theConfig)[CFG_POLICY_CCHOST].c_str(),
//                        (*theConfig)[CFG_POLICY_CCPORT].c_str(),
//                        (*theConfig)[CFG_POLICY_CCUSER].c_str(),
//                        (*theConfig)[CFG_POLICY_CCPWD].c_str(),
//                        (*theConfig)[CFG_POLICY_TAG].c_str(),
//                        atoi((*theConfig)[CFG_POLICY_SYNCINTERVAL].c_str()),
//                        &Log);


    ASSERT_TRUE(b);
    sleep(3);
}


*/



TEST_MAIN()