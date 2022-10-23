#ifndef ENFORCER_DATA_MGR_H
#define ENFORCER_DATA_MRG_H

#ifdef WIN32
#include <windows.h>
#endif
#include <map>
#include <string>
#include <sql.h>
#include "iodbc_macros.h"
#include "EMDBType.h"

struct SqlErr;
struct EnvHandleProxy;
struct StmtHandleProxy;
struct ConnectHandleProxy;
struct SqlException;

struct EnforcerDataMgr {
    friend struct ConnectHandleProxy;
    friend struct StmtHandleProxy;
    friend struct EnvHandleProxy;

    static EnforcerDataMgr& Instance();
    //void alloc_env_handle(SQLHANDLE env_handle);
    bool alloc_env_handle(SQLHANDLE env_handle);
    //bool bind_connect_handle(SQLHANDLE connect_handle_proxy);
    bool freehandle(SQLSMALLINT handtype, SQLHANDLE handle);

    bool bind_connect_handle(SQLHANDLE env_handle, SQLHANDLE connect_handle);

    void alloc_connect_handle(SQLHANDLE env_handle, SQLHANDLE connect_handle);

    void bind_enforcer_context(SQLHANDLE connect_handle, USER_CONTEXT enforcer_context, ODBCQueryMetadata * meta_opr);
    void bind_stmt_handle(SQLHANDLE connect_handle, SQLHANDLE stmt_handle);
    ConnectHandleProxy *to_connect_handle_proxy(SQLHANDLE connect_handle);
    StmtHandleProxy *to_stmt_handle_proxy(SQLHANDLE stmt_handle);
    bool get_enforcer_context_by_connect_handle(SQLHANDLE connect_handle, USER_CONTEXT& out_enforcer_context);
    bool get_enforcer_context_by_stmt_handle(SQLHANDLE stmt_handle, USER_CONTEXT& out_enforcer_context);

    bool disconnect(SQLHANDLE connect_handle);

    bool push_error(SQLSMALLINT handletype, SQLHANDLE handle, int err_code, const char *detail);	/* some script is blocked by enforcer, this will generate errs */
    bool push_error(SQLSMALLINT handletype, SQLHANDLE handle, const SqlException* errInfo);
    bool get_error(SQLSMALLINT handletype, SQLHANDLE handle, int idx, int& out_err_code, std::string& out_detail);
    bool get_error_last(SQLSMALLINT handletype, SQLHANDLE handle, int& out_err_code, std::string& out_detail);//https://docs.microsoft.com/en-us/sql/odbc/microsoft/sqlerror-visual-foxpro-odbc-driver?view=sql-server-2017
    bool clear_error(SQLSMALLINT handletype, SQLHANDLE handle);

private:
    std::map<SQLHANDLE , EnvHandleProxy * >     env_handle_2_env_handle_proxy_;
    std::map<SQLHANDLE , ConnectHandleProxy*>  connect_handle_2_connect_handle_proxy_;
    std::map<SQLHANDLE , StmtHandleProxy*>     stmt_handle_2_stmt_handle_proxy_;
    
};

#endif 

