//
// Created by jeff on 2020/12/17.
//

#include "microtest.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <dlfcn.h>
#include <sql.h>
#include <sqlext.h>
#include <algorithm>
#include <sys/time.h>
#include<fstream>
#include <string>
#include <thread>
#include <mutex>
#include <sstream>
#include <unistd.h>
#include <fstream>
void stmt_execute(SQLHENV	h_env, SQLHDBC   h_dbc, SQLHSTMT	h_stmt, unsigned char* const sql, bool exec_direct);
void print_error(SQLHENV	henv,   SQLHDBC    hdbc, SQLHSTMT	hstmt);
std::string read_conn();

TEST(Connection){

    // Allocate an environment
    SQLHENV h_env = NULL;
    SQLRETURN rc =  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &h_env);
    if (rc == SQL_ERROR){ print_error(h_env, NULL, NULL); }
    assert(h_env);

    rc =  SQLSetEnvAttr(h_env, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0) ;
    if (rc != SQL_SUCCESS) { print_error(h_env, NULL, NULL); }

    // Allocate a connection
    SQLHDBC h_dbc = NULL;
    rc =  SQLAllocHandle(SQL_HANDLE_DBC, h_env, &h_dbc);

    if (rc == SQL_ERROR) { print_error(h_env, h_dbc, NULL); }
    assert(h_dbc);


    // Connect to the driver
    {
        std::string conn_str = read_conn();

        rc = SQLDriverConnect(
                h_dbc,
                NULL,
                (SQLCHAR*)conn_str.c_str(),
                SQL_NTS,
                nullptr,
                0,
                NULL,
                SQL_DRIVER_COMPLETE);
    }



    if (SQL_ERROR == rc)
    {
        print_error(h_env, h_dbc, NULL);
    }
    SQLHSTMT h_stmt = NULL;
    rc = SQLAllocHandle(SQL_HANDLE_STMT, h_dbc, &h_stmt);
    if (rc == SQL_ERROR)
    {
        print_error(h_env, h_dbc, h_stmt);
    }
    assert(h_stmt);
    unsigned char sql[256] = "select * from jeff.TEST;\0";

    stmt_execute(h_env, h_dbc, h_stmt, sql, false);

    rc = SQLCloseCursor(h_stmt);
    if (SQL_ERROR == rc)
    {
        print_error(h_env, h_dbc, h_stmt);
    }


    // Free ODBC handles and exit
    if (h_stmt) {
        SQLFreeHandle(SQL_HANDLE_STMT, h_stmt);
        if (SQL_ERROR == rc) { print_error(h_env, h_dbc, h_stmt); }
    }

    if (h_dbc) {
        SQLDisconnect(h_dbc);
        if (SQL_ERROR == rc) { print_error(h_env, h_dbc, h_stmt); }

        SQLFreeHandle(SQL_HANDLE_DBC, h_dbc);
        if (SQL_ERROR == rc) { print_error(h_env, h_dbc, h_stmt); }
    }

    if (h_env) {
//        std::chrono::milliseconds dura(8000);
//        std::this_thread::sleep_for(dura);
        SQLFreeHandle(SQL_HANDLE_ENV, h_env);
        if (SQL_ERROR == rc) { print_error(h_env, h_dbc, h_stmt); }
    }

}
TEST_MAIN();


void stmt_execute(SQLHENV	h_env,
                  SQLHDBC   h_dbc,
                  SQLHSTMT	h_stmt,
                  unsigned char* const sql,
                  bool exec_direct)
{
    SQLRETURN rc = SQL_ERROR;
    if(exec_direct) {
        rc = SQLPrepare(h_stmt, sql, SQL_NTS);
        if (SQL_ERROR == rc) { print_error(h_env, h_dbc, h_stmt); }

        // SQLExecute
        rc = SQLExecute(h_stmt);
        if (SQL_ERROR == rc) { print_error(h_env, h_dbc, h_stmt); }

        SQLLEN len = -1;
        rc = SQLRowCount(h_stmt, &len);
        printf("get value len:%ld\n", len);
        if (SQL_ERROR == rc) { print_error(h_env, h_dbc, h_stmt); }
        else printf("get value len:%ld\n", len);

        SQLSMALLINT col_num = -1;
        rc = SQLNumResultCols(h_stmt, &col_num);
        if (SQL_ERROR == rc) { print_error(h_env, h_dbc, h_stmt); }
        else printf("get column num:%d\n", col_num);

       // DisplayResults(h_stmt, col_num);
    }
    else {
        SQLSMALLINT sNumResults = -1;

        // Execute the query
        rc = SQLExecDirect(h_stmt, sql, SQL_NTS);
        if (rc == SQL_ERROR) { print_error(h_env, h_dbc, h_stmt); }

        switch (rc) {
            case SQL_SUCCESS: {
                // If this is a row-returning query, display
                // results
                rc = SQLNumResultCols(h_stmt, &sNumResults);
                if (rc == SQL_ERROR) { print_error(h_env, h_dbc, h_stmt); }

                if (sNumResults > 0) {
                    printf("SQLNumResultCols:  %d\n", sNumResults);
                  //  DisplayResults(h_stmt, sNumResults);
                } else {
                    SQLLEN cRowCount;
                    rc = SQLRowCount(h_stmt, &cRowCount);
                    if (cRowCount >= 0) {
                        printf("%ld %s affected\n",
                               cRowCount,
                               (cRowCount == 1 ? "row" : "rows"));
                    }
                }
                break;
            }
            case SQL_SUCCESS_WITH_INFO:
            case SQL_ERROR: {
                break;
            }
            default:
                printf("Unexpected return code %hd!\n", rc);
        }
    }
}


void print_error(SQLHENV	henv,
                 SQLHDBC    hdbc,
                 SQLHSTMT	hstmt){
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

std::string read_conn(){
    char *buffer;
    if((buffer = getcwd(NULL, 0)) == NULL)
    {
        perror("getcwd error");
        return "";
    }
    std::string connstr_path(buffer);
    std::string path = connstr_path + "/conn_str.txt";
    printf("connection path: %s\n", path.c_str());
    std::ifstream t(path);
    std::string conn_str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    return conn_str;
}