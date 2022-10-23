//
// Created by jeff on 2019/8/21.
//

#ifndef EMDB_TEST_JEFF_H
#define EMDB_TEST_JEFF_H
#include "./third_party/microtest.h"
#include "commfun.h"
#include "config.h"
#include "nanodbc.h"
#include "Interface.h"

#include "userattr.h"
#include "userattr_export.h"
#include "SqlException.h"
#include "sqlenforcer_export.h"
#include <sqlext.h>


int Log_jeff(int nLogLevel, const char* szMsg) {
    printf("%s\n", szMsg);
    return 0;
}



void print_error(SQLHENV	henv,  SQLHDBC hdbc, SQLHSTMT	hstmt){
    SQLINTEGER  ierror = 0;
    SQLCHAR       cmsg[1000] = {0};
    SQLCHAR       cstate[SQL_SQLSTATE_SIZE + 1] = {0};
    SQLSMALLINT cerrmsg = 0;

    while (SQL_SUCCESS == SQLError(henv,
                                   hdbc,
                                   hstmt,
                                   cstate,
                                   &ierror,
                                   cmsg,
                                   (SQLSMALLINT)(sizeof(cmsg) / sizeof(char)),
                                   &cerrmsg))
    {
        printf("[%5.5s] %s (%d)\n", cstate, cmsg, ierror);
    }
}


TEST(odbc_nxl) {
    SQLHENV     h_env = NULL;
    SQLRETURN  rc =  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &h_env);//----------------------------------------------

    if (rc == SQL_ERROR){
        print_error(h_env, NULL, NULL);
    }
    ASSERT_NOTNULL(h_env);

    rc =  SQLSetEnvAttr(h_env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0) ;
    if (rc != SQL_SUCCESS) {
        print_error(h_env, NULL, NULL);
    }

    SQLHDBC     h_dbc = NULL;
    rc =  SQLAllocHandle(SQL_HANDLE_DBC, h_env, &h_dbc);//----------------------------------------------
    if (rc == SQL_ERROR) {


        print_error(h_env, h_dbc, NULL);

        printf("SQLAllocHandle failed");
    }
    ASSERT_NOTNULL(h_dbc);

    unsigned char  c_out_str[1024+1]={0};
    unsigned char con[256] = "DRIVER={HDBODBC};UID=SYSTEM;PWD=123Blue123Blue;SERVERNODE=10.23.60.140:39015;\0";

    rc = SQLDriverConnect(
            h_dbc,
            NULL,
            con,
            SQL_NTS,
            c_out_str,
            1024,
            NULL,
            SQL_DRIVER_COMPLETE);//----------------------------------------------
//    ASSERT_NOTNULL(h_dbc);

    if (SQL_ERROR == rc) {
        print_error(h_env, h_dbc, NULL);
    }
    SQLHSTMT    h_stmt = NULL;
    rc = SQLAllocHandle(SQL_HANDLE_STMT, h_dbc, &h_stmt);//----------------------------------------------
    if (rc == SQL_ERROR) {
        print_error(h_env, h_dbc, h_stmt);
    }
    unsigned  char  sql[256] = "select BANK_T from BANK";
    rc = SQLPrepare(h_stmt, sql, SQL_NTS);//-------------------------------------------------------------
    if (SQL_ERROR == rc) {
        print_error(h_env, h_dbc, h_stmt);
    }
    rc = SQLExecute(h_stmt);//----------------------------------------------------------------------------
    if (SQL_ERROR == rc) {
        print_error(h_env, h_dbc, h_stmt);
    }
//    rc = SQLExecDirect(h_stmt, sql, SQL_NTS);//-----------------------------------------------------------
//    if (SQL_ERROR == rc) {
//        printf("SQLExecDirect failed");
//    }
    SQLLEN len;
    rc = SQLRowCount(h_stmt, &len);//----------------------------------------------
    printf("get value len:%ld", len);
    if (SQL_ERROR == rc) {
        print_error(h_env, h_dbc, h_stmt);
    }
    SQLSMALLINT col_num;
    rc = SQLNumResultCols(h_stmt, &col_num);//----------------------------------------------
    printf("get column num:%d", col_num);
    if (SQL_ERROR == rc) {
        print_error(h_env, h_dbc, h_stmt);
    }
    rc = SQLCloseCursor(h_stmt);//----------------------------------------------
    if (SQL_ERROR == rc) {
        print_error(h_env, h_dbc, h_stmt);
    }
    rc =SQLFreeStmt(h_stmt, SQL_CLOSE);//----------------------------------------------
    if (SQL_ERROR == rc) {
        print_error(h_env, h_dbc, h_stmt);
    }
}





/*
TEST(userattr){
    UserAttr attr("test1") ;
    UserAttr attr2("test2") ;
    attr2.AddAttr("name1","101");

    attr.UpdateAttr(attr2);
    std::string str = attr.GetUserName();
    bool b1 = str.compare("test1")==0;
    ASSERT_TRUE(b1);

    std::string strValue = attr.GetUserAttr("name1");
    bool b2 = strValue.compare("101")==0;
    ASSERT_TRUE(b2);
    bool b3 = attr.ValidUserAttr("name1", "102", "<");
    ASSERT_TRUE(b3);
    bool b4 = attr.ValidUserAttr("TIMESTAMP@","2019-08-20 02:30:15 ~ 2019-10-29 19:30:15 UTC +8:00", "=");
    ASSERT_TRUE(b4);
    bool b5 = attr.ValidUserAttr("IP@","0.0.0.0 ~ 255.255.255.255 ", "=");
    ASSERT_TRUE(b5);
    bool b6 = attr.ValidUserAttr("TIME@","02:30:15 ~ 19:30:15", "=");
    ASSERT_TRUE(b6);
    bool b7 = attr.ValidUserAttr("APPLICATION@","odbc.exe", "!=");
    ASSERT_TRUE(b7);

}
 */

/*
TEST(userattr_export){

    class CConfig config ;
    config.ReadConfig(CommonFun::GetConfigFilePath().c_str());
    bool bRet = UserAttrInit(Log_jeff,
                             atoi(config[USER_MODE].c_str()),
                             config[USER_MODE_PARAM1].c_str(),
                             config[USER_MODE_PARAM2].c_str(),
                             config[USER_MODE_PARAM3].c_str(),
                             atoi(config[USER_MODE_PARAM4].c_str()));
    ASSERT_TRUE(bRet);
    sleep(1);
    class SqlException exc ;
    IUserAttr* attr = GetUserAttr("sa",&exc );
    ASSERT_NOTNULL(attr);
}
*/

/*
TEST(sqlenforcer){
    SqlException excep;
    bool bret = SQLEnforcerInit("odbc", CommonFun::GetConfigFilePath().c_str(), &excep);
    if (excep.IsBreak()) {
        printf("SQLEnforcerInit failed");

    }
    excep.SetInfo(ERR_NULL, NULL);

    USER_CONTEXT ctx = SQLEnforcerNewContext("sa","123Blue!", &excep);

    SetUserContextInfo(ctx, CONTEXT_INFO_SERVER, "servername");
    SetUserContextInfo(ctx, CONTEXT_INFO_DATABASE, "dbname");
    SetUserContextInfo(ctx, CONTEXT_INFO_SCHEMA, "sa");
    SetUserContextInfo(ctx, CONTEXT_INFO_DB_TYPE, "SqlServer Driver");

     std::string sql =  SQLEnforcerEvaluationSQLA(ctx, "select* from sa.customer", &excep);

    SQLEnforcerFreeContext( ctx);
    int log = SQLEnforcerWriteLogA(3, "log_warning : log content");
}
*/






#endif //EMDB_TEST_JEFF_H
