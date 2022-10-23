#ifndef IODBC_MACROS_H
#define IODBC_MACROS_H

#ifdef WIN32
#include <windows.h>
#endif
#include <sql.h>
#include <set>
#include "commfun.h"
/*
 *  Most of these macro instructions and struct are referenced from implemention of IODBC 
 *  Do not use any return statement between ENTER_XXX and LEAVE_XXX,  ODBC_LOCK() and ODBC_UNLOCK()
 */

#define ODBC_LOCK() odbc_lock()

#define ODBC_UNLOCK() odbc_unlock()

#define ENTER_HDBC(hdbc, hold_lock) \
    SQLRETURN ret_code = SQL_SUCCESS; \
    ODBC_LOCK(); \
    ConnectHandleProxy *pdbc = EnforcerDataMgr::Instance().to_connect_handle_proxy(hdbc); \
    if (!pdbc) { \
        ret_code = SQL_INVALID_HANDLE; \
        goto done; \
    } \
    else if(pdbc->dbc_cip_ == 1) { \
        ret_code = SQL_ERROR; \
        goto done; \
    } \
    pdbc->dbc_cip_ = 1; \
    if (!hold_lock) { \
        ODBC_UNLOCK(); \
    }

#define LEAVE_HDBC(hdbc, hold_lock) \
    if (!hold_lock) { \
        ODBC_LOCK(); \
    } \
    pdbc->dbc_cip_ = 0; \
    done: \
      ; \
    ODBC_UNLOCK(); \
    return ret_code

#define ENTER_STMT(hstmt) \
    SQLRETURN ret_code = SQL_SUCCESS; \
    ODBC_LOCK(); \
    StmtHandleProxy *pstmt = EnforcerDataMgr::Instance().to_stmt_handle_proxy(hstmt); \
    if (!pstmt) { \
        ret_code = SQL_INVALID_HANDLE; \
        goto done; \
    } \
    else if (pstmt->stmt_cip_ == 1) { \
        ret_code = SQL_ERROR; \
        goto done; \
    } \
    pstmt->stmt_cip_ = 1; \
    SqlErr::clear_sql_err(pstmt->errs_);/*EnforcerDataMgr::Instance().clear_error(hstmt); \*/\
    pstmt->errs_ = nullptr;\
    ODBC_UNLOCK();

#define LEAVE_STMT(hstmt) \
    ODBC_LOCK(); \
    pstmt->stmt_cip_ = 0; \
    done: \
      ; \
    ODBC_UNLOCK();  \
    return ret_code


void odbc_lock();
void odbc_unlock();

struct SqlErr;
struct EnvHandleProxy;
struct StmtHandleProxy;
struct ConnectHandleProxy;
struct StmtHandleProxy;
class ODBCQueryMetadata;

struct EnvHandleProxy{
    EnvHandleProxy(SQLHANDLE env_handle);
    ~EnvHandleProxy();
    void add_connect_handle(SQLHANDLE connect_handle);
    std::set<ConnectHandleProxy* > connect_handle_set_;
    SQLHANDLE env_handle_;
    SqlErr *errs_;
};

struct ConnectHandleProxy {
    ConnectHandleProxy(EnvHandleProxy*env_handle, SQLHANDLE connect_handle, USER_CONTEXT enforcer_context);
    ~ConnectHandleProxy();
    void add_stmt_handle(SQLHANDLE stmt_handle);
    EnvHandleProxy * env_handle_proxy__;
    SQLHANDLE connect_handle_;
    USER_CONTEXT enforcer_context_ = 0;
    std::set<StmtHandleProxy* > stmt_handle_set_;
    char dbc_cip_;      /* Call in Progress flag */
    SqlErr *errs_;
    ODBCQueryMetadata* _meta_opr = NULL;
};

struct StmtHandleProxy {
    StmtHandleProxy(ConnectHandleProxy *connect_handle_proxy, SQLHANDLE stmt_handle);
    ~StmtHandleProxy();
    SQLHANDLE stmt_handle_;
    ConnectHandleProxy *connect_handle_proxy_;
    SqlErr *errs_;
    char stmt_cip_;     /* Call in progress on this handle */
};

struct SqlErr {
    static SqlErr* make_sql_err(int idx, SqlErr *head, int err_code, const char *detail);
    static void clear_sql_err(SqlErr *head);
    static SqlErr* pop_one(SqlErr * perr);
    int idx_;
    SqlErr *next_;
    int err_code_;
    char *detail_;
};

#endif