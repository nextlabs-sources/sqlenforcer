#include "EnforcerDataMgr.h"
#include "assert.h"
#include <string.h>
#include "iodbc_macros.h"
#include "SqlException.h"
#include "enforcerwrapper.h"
#include "ODBCQueryMetadata.h"


EnvHandleProxy::EnvHandleProxy(SQLHANDLE env_handle): env_handle_(env_handle),errs_(nullptr){

}

EnvHandleProxy::~EnvHandleProxy(){
    for (auto it : connect_handle_set_){
        delete(it);
    }
        
    connect_handle_set_.clear();
    SqlErr::clear_sql_err(errs_);
    errs_ = nullptr;
}

void EnvHandleProxy::add_connect_handle(SQLHANDLE connect_handle){
    ConnectHandleProxy *connect_proxy = new ConnectHandleProxy(this, connect_handle, 0);/* default enforcer_context 0 means not binded  */
    connect_handle_set_.insert(connect_proxy);
    EnforcerDataMgr::Instance().connect_handle_2_connect_handle_proxy_.insert(std::make_pair(connect_handle, connect_proxy));
}


ConnectHandleProxy::ConnectHandleProxy(EnvHandleProxy*env_handle, SQLHANDLE connect_handle, USER_CONTEXT enforcer_context)
                            : env_handle_proxy__( env_handle), connect_handle_(connect_handle), enforcer_context_(enforcer_context), dbc_cip_(0), errs_(nullptr) {
                                
                            }

ConnectHandleProxy::~ConnectHandleProxy() {
    for (auto it : stmt_handle_set_)
        delete(it);
    stmt_handle_set_.clear();
    SqlErr::clear_sql_err(errs_);
    errs_ = nullptr;
    if (enforcer_context_ != 0)
        Enforcer::Instance()->SQLEnforcerFreeContext((const wchar_t*)enforcer_context_);
    if(_meta_opr != NULL){
        delete(_meta_opr);
        _meta_opr = NULL;
    }
}

void ConnectHandleProxy::add_stmt_handle(SQLHANDLE stmt_handle) {
    USER_CONTEXT _;
    bool b = EnforcerDataMgr::Instance().get_enforcer_context_by_stmt_handle(stmt_handle, _);
    assert(!b);   /* internal error */
    StmtHandleProxy *stmt_proxy = new StmtHandleProxy(this, stmt_handle);
    stmt_handle_set_.insert(stmt_proxy);
    EnforcerDataMgr::Instance().stmt_handle_2_stmt_handle_proxy_.insert(std::make_pair(stmt_handle, stmt_proxy));
}

StmtHandleProxy::StmtHandleProxy(ConnectHandleProxy *connect_handle_proxy, SQLHANDLE stmt_handle)
            : stmt_handle_(stmt_handle), connect_handle_proxy_(connect_handle_proxy), errs_(nullptr), stmt_cip_(0) {}

StmtHandleProxy::~StmtHandleProxy() {
    SqlErr::clear_sql_err(errs_);
    errs_ = nullptr;
}

SqlErr* SqlErr::make_sql_err(int idx, SqlErr *head, int err_code, const char *detail) {
    SqlErr *ret = new SqlErr;
    ret->idx_ = idx;
    ret->next_ = head;
    ret->err_code_ = err_code;
    ret->detail_ = detail ? strdup(detail) : nullptr;
    return ret;
}

void SqlErr::clear_sql_err(SqlErr *head) {
    if (!head) return;
    for (SqlErr *it = head; it;) {
        SqlErr *tmp = it->next_;
        if (it->detail_) free(it->detail_);
        delete (it);
        it = tmp;
    }
}

SqlErr* SqlErr::pop_one(SqlErr * perr){
    if (perr == nullptr)
        return perr;
    
    SqlErr * head = perr;
    SqlErr * next = head->next_;
    
    head->next_ = nullptr;
    clear_sql_err(head);
    return next;
}

EnforcerDataMgr& EnforcerDataMgr::Instance() {
    static EnforcerDataMgr ins;
    return ins;
}


bool EnforcerDataMgr::alloc_env_handle(SQLHANDLE env_handle){
    
    EnvHandleProxy *env_proxy = nullptr;;/* default enforcer_context 0 means not binded  */
    auto find_it = env_handle_2_env_handle_proxy_.find(env_handle);
    if(find_it == env_handle_2_env_handle_proxy_.end()){
        env_proxy = new EnvHandleProxy(env_handle);
        EnforcerDataMgr::Instance().env_handle_2_env_handle_proxy_.insert(std::make_pair(env_handle, env_proxy));
    }else{
        env_proxy = find_it->second;
        if(nullptr == env_proxy ){
            return false;
        }
        for (auto it : env_proxy->connect_handle_set_)
        if(it)
            delete(it);
        env_proxy->connect_handle_set_.clear();
        if(env_proxy->errs_){
            SqlErr::clear_sql_err(env_proxy->errs_);
            env_proxy->errs_ = nullptr;
        }
    }
    return true;
}


void EnforcerDataMgr::alloc_connect_handle(SQLHANDLE env_handle, SQLHANDLE connect_handle) {
    USER_CONTEXT _;
    bool b = get_enforcer_context_by_connect_handle(connect_handle, _);
    assert(!b); /* internal error */
    bind_connect_handle(env_handle, connect_handle);
}

bool EnforcerDataMgr::freehandle(SQLSMALLINT handtype, SQLHANDLE handle){
    if(SQL_HANDLE_ENV == handtype){
        auto find_it = env_handle_2_env_handle_proxy_.find(handle);
        assert(find_it != env_handle_2_env_handle_proxy_.end());
        EnvHandleProxy *env_proxy = find_it->second;
        assert(env_proxy != nullptr);
        assert(env_proxy->connect_handle_set_.empty());     /* cnns of this env should be empty */
        env_handle_2_env_handle_proxy_.erase(find_it);
        delete(env_proxy);
    }
    else if(SQL_HANDLE_DBC== handtype){
        auto find_it = connect_handle_2_connect_handle_proxy_.find(handle);
        assert(find_it != connect_handle_2_connect_handle_proxy_.end());
        ConnectHandleProxy *cnn_proxy = find_it->second;
        assert(cnn_proxy != nullptr);
        assert(cnn_proxy->stmt_handle_set_.empty());        /* stmts of this cnn should be empty */
        cnn_proxy->env_handle_proxy__->connect_handle_set_.erase(cnn_proxy);
        connect_handle_2_connect_handle_proxy_.erase(find_it);
        delete(cnn_proxy);
    }
    else if(SQL_HANDLE_STMT== handtype){
        auto fd = stmt_handle_2_stmt_handle_proxy_.find(handle);
        assert(fd != stmt_handle_2_stmt_handle_proxy_.end());
        StmtHandleProxy *stmt_proxy = fd->second;
        assert(stmt_proxy != nullptr);
        ConnectHandleProxy *cnn_proxy = stmt_proxy->connect_handle_proxy_;
        cnn_proxy->stmt_handle_set_.erase(stmt_proxy);
        stmt_handle_2_stmt_handle_proxy_.erase(fd);
        delete(stmt_proxy);
    }
    return true;
}

bool EnforcerDataMgr::bind_connect_handle(SQLHANDLE env_handle, SQLHANDLE connect_handle){
    auto find_it = env_handle_2_env_handle_proxy_.find(env_handle);
    if(find_it != env_handle_2_env_handle_proxy_.end()){   /* internal error */
        EnvHandleProxy *env_handle_proxy = find_it->second;
        env_handle_proxy->add_connect_handle(connect_handle);
    }
    return true;
}


void EnforcerDataMgr::bind_enforcer_context(SQLHANDLE connect_handle, USER_CONTEXT enforcer_context, ODBCQueryMetadata * meta_opr) {
    auto find_it = connect_handle_2_connect_handle_proxy_.find(connect_handle);
    if(find_it != connect_handle_2_connect_handle_proxy_.end()){
        find_it->second->enforcer_context_ = enforcer_context;
        find_it->second->_meta_opr = meta_opr;
    }    /* internal error */
}

void EnforcerDataMgr::bind_stmt_handle(SQLHANDLE connect_handle, SQLHANDLE stmt_handle) {
    auto find_it = connect_handle_2_connect_handle_proxy_.find(connect_handle);
    if(find_it != connect_handle_2_connect_handle_proxy_.end()){   /* internal error */
        ConnectHandleProxy *connect_handle_proxy = find_it->second;
        connect_handle_proxy->add_stmt_handle(stmt_handle);
    }
}

ConnectHandleProxy *EnforcerDataMgr::to_connect_handle_proxy(SQLHANDLE connect_handle) {
    auto find_it = connect_handle_2_connect_handle_proxy_.find(connect_handle);
    ConnectHandleProxy *ret = nullptr;
    if (find_it != connect_handle_2_connect_handle_proxy_.end()) {
        ret = find_it->second;
    }
    return ret;
}

StmtHandleProxy *EnforcerDataMgr::to_stmt_handle_proxy(SQLHANDLE stmt_handle) {
    StmtHandleProxy *ret = nullptr;
    auto find_it = stmt_handle_2_stmt_handle_proxy_.find(stmt_handle);
    if (find_it != stmt_handle_2_stmt_handle_proxy_.end())
        ret = find_it->second;
    return ret;
}

bool EnforcerDataMgr::get_enforcer_context_by_connect_handle(SQLHANDLE connect_handle, USER_CONTEXT& out_enforcer_context) {
    auto find_it = connect_handle_2_connect_handle_proxy_.find(connect_handle);
    bool ret = find_it != connect_handle_2_connect_handle_proxy_.end();
    if (ret)
        out_enforcer_context = find_it->second->enforcer_context_;
    return ret;
}

bool EnforcerDataMgr::get_enforcer_context_by_stmt_handle(SQLHANDLE stmt_handle, USER_CONTEXT& out_enforcer_context) {
    auto find_it = stmt_handle_2_stmt_handle_proxy_.find(stmt_handle);
    bool ret = find_it != stmt_handle_2_stmt_handle_proxy_.end();
    if (ret)
        out_enforcer_context = find_it->second->connect_handle_proxy_->enforcer_context_;
    return ret && out_enforcer_context!=0;
}

bool EnforcerDataMgr::disconnect(SQLHANDLE connect_handle) {
    /*
    auto find_it = connect_handle_2_connect_handle_proxy_.find(connect_handle);
    bool ret = find_it != connect_handle_2_connect_handle_proxy_.end();
    if (ret) {
        for (auto it : find_it->second->stmt_handle_set_) {
            stmt_handle_2_stmt_handle_proxy_.erase(it->stmt_handle_);
        }
        //delete(find_it->second);
        connect_handle_2_connect_handle_proxy_.erase(find_it);
    }
    return ret;*/
    return true;
}


//ERROR---------------------------------------------------------------------------
bool EnforcerDataMgr::push_error(SQLSMALLINT handletype, SQLHANDLE handle,  int err_code, const char *detail) {
    SqlErr *head  = nullptr;
   // bool ret = false;
    switch(handletype){
        case SQL_HANDLE_ENV:{
            auto find_it = env_handle_2_env_handle_proxy_.find(handle);
            if(find_it != env_handle_2_env_handle_proxy_.end()){
                head = find_it->second->errs_;
                int new_idx = head ? head->idx_ + 1 : 1;
                find_it->second->errs_ = SqlErr::make_sql_err(new_idx, head, err_code, detail);
            }  
        }
        break;
        case SQL_HANDLE_DBC:{
            auto find_it = connect_handle_2_connect_handle_proxy_.find(handle);
            if(find_it != connect_handle_2_connect_handle_proxy_.end()){
                head = find_it->second->errs_;
                int new_idx = head ? head->idx_ + 1 : 1;
                find_it->second->errs_ = SqlErr::make_sql_err(new_idx, head, err_code, detail);
            }
        }
        break;
        case SQL_HANDLE_STMT:{
            auto find_it = stmt_handle_2_stmt_handle_proxy_.find(handle);
            if(find_it != stmt_handle_2_stmt_handle_proxy_.end()){
                head = find_it->second->errs_;
                int new_idx = head ? head->idx_ + 1 : 1;
                find_it->second->errs_ = SqlErr::make_sql_err(new_idx, head, err_code, detail);
            }
        }
        break;
    }
    
    return true;
}

bool EnforcerDataMgr::push_error(SQLSMALLINT handletype, SQLHANDLE handle, const SqlException* exc){
    if(nullptr == exc){
        return false;
    }
    SqlErr *head  = nullptr;
   // bool ret = false;
    switch(handletype){
        case SQL_HANDLE_ENV:{
            
            auto find_it = env_handle_2_env_handle_proxy_.find(handle);
            if(find_it != env_handle_2_env_handle_proxy_.end()){
                head = find_it->second->errs_;
                int new_idx = head ? head->idx_ + 1 : 1;
                find_it->second->errs_ = SqlErr::make_sql_err(new_idx, head, exc->code, exc->cdetail.c_str());//exc->code
            }
        }
        break;
        case SQL_HANDLE_DBC:{
            auto find_it = connect_handle_2_connect_handle_proxy_.find(handle);
            if(find_it != connect_handle_2_connect_handle_proxy_.end()){
                head = find_it->second->errs_;
                int new_idx = head ? head->idx_ + 1 : 1;
                find_it->second->errs_ = SqlErr::make_sql_err(new_idx, head, exc->code, exc->cdetail.c_str());
            }
        }
        break;
        case SQL_HANDLE_STMT:{
            auto find_it = stmt_handle_2_stmt_handle_proxy_.find(handle);
            if(find_it != stmt_handle_2_stmt_handle_proxy_.end()){
                head = find_it->second->errs_;
                int new_idx = head ? head->idx_ + 1 : 1;
                find_it->second->errs_ = SqlErr::make_sql_err(new_idx, head, exc->code, exc->cdetail.c_str());
            }
        }
        break;
    }
    
    return true;
}

bool EnforcerDataMgr::get_error(SQLSMALLINT handletype, SQLHANDLE handle, int idx, int& out_err_code, std::string& out_detail) {
    SqlErr *head  = nullptr;
    bool ret = false;
    switch(handletype){
        case SQL_HANDLE_ENV:{
            auto find_it = env_handle_2_env_handle_proxy_.find(handle);
            if(find_it != env_handle_2_env_handle_proxy_.end()){
                head = find_it->second->errs_;
            }
        }
        break;
        case SQL_HANDLE_DBC:{
            auto find_it = connect_handle_2_connect_handle_proxy_.find(handle);
            if(find_it != connect_handle_2_connect_handle_proxy_.end()){
                head = find_it->second->errs_;
            }
        }
        break;
        case SQL_HANDLE_STMT:{
            auto find_it = stmt_handle_2_stmt_handle_proxy_.find(handle);
            if(find_it != stmt_handle_2_stmt_handle_proxy_.end()){
                head = find_it->second->errs_;
            }
        }
        break;
    }
    
    if (head) {
        SqlErr *it = nullptr;
        for (it = head; it; it = it->next_) {
            if (it->idx_ == idx) {
                ret = true;
                break;
            }
        }
        if (ret) {
            out_err_code = it->err_code_;
            out_detail = it->detail_;
        }
    }
    return ret;
}

bool EnforcerDataMgr::get_error_last(SQLSMALLINT handletype, SQLHANDLE handle, int& out_err_code, std::string& out_detail){
    
    SqlErr ** ppErr = nullptr;
    bool ret = false;
    switch(handletype){
        case SQL_HANDLE_ENV:{
            auto find_it = env_handle_2_env_handle_proxy_.find(handle);
            if(find_it != env_handle_2_env_handle_proxy_.end()){
                ppErr = &(find_it->second->errs_);
            }
        }
        break;
        case SQL_HANDLE_DBC:{
            auto find_it = connect_handle_2_connect_handle_proxy_.find(handle);
            if(find_it != connect_handle_2_connect_handle_proxy_.end()){
                ppErr = &(find_it->second->errs_);
            }
        }
        break;
        case SQL_HANDLE_STMT:{
            auto find_it = stmt_handle_2_stmt_handle_proxy_.find(handle);
            if(find_it != stmt_handle_2_stmt_handle_proxy_.end()){
                ppErr = &(find_it->second->errs_);
            }
        }
        break;
    }

    SqlErr *head  = nullptr;
    if (ppErr && (head = *ppErr)) {
        out_err_code = head->err_code_;
        out_detail = head->detail_;
        ret = true;
        *ppErr = SqlErr::pop_one(head);
    }
    return ret;
}



bool EnforcerDataMgr::clear_error(SQLSMALLINT handletype, SQLHANDLE handle) {
    switch(handletype){
        case SQL_HANDLE_ENV:{
            
            auto find_it = env_handle_2_env_handle_proxy_.find(handle);
            if(find_it != env_handle_2_env_handle_proxy_.end()){
                SqlErr::clear_sql_err(find_it->second->errs_);
                find_it->second->errs_ = nullptr;
            }
            
        } break;
        case SQL_HANDLE_DBC:{
            auto find_it = connect_handle_2_connect_handle_proxy_.find(handle);
            if(find_it != connect_handle_2_connect_handle_proxy_.end()){
                SqlErr::clear_sql_err(find_it->second->errs_);
                find_it->second->errs_ = nullptr;
            }
        } break;
        case SQL_HANDLE_STMT:{
            auto find_it = stmt_handle_2_stmt_handle_proxy_.find(handle);
            if(find_it != stmt_handle_2_stmt_handle_proxy_.end()){
                SqlErr::clear_sql_err(find_it->second->errs_);
                find_it->second->errs_ = nullptr;
            }
        } break;
    }
    return true;
}
