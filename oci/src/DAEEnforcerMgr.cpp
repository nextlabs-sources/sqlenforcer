#include "SqlException.h"
#include "DAEEnforcerWrapper.h"
#include "commfun.h"
#include "DAELog.h"
#include <atomic>
std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;

#include "EMDBConfig.h"
#include "DAEEnforcerMgr.h"
#include "DAETableMetadata.h"
#include "DAEUserAttrsOpr.h"
#include "DAEResourcedata.h"

std::atomic_int64_t inti_ret = 0;

// Workaround to fix bug 66860
SqlException storedExc;

#include "oci.h"


bool DAEEnforceMgr::InitalizeEnforcer(SqlException* pExc)
{
    bool bInit = lock_stream.test_and_set();
    if (!bInit)
    {
        //std::vector<std::string> vec;
        bool bRet = true;
        do{
            //load config file
//            EMDBConfig::GetInstance();
//            const std::string strCfgFile = CommonFun::GetConfigFilePath();
//            if(NULL == theConfig){
//                theConfig = new CConfig();
//
//                bRet = theConfig->ReadConfig(strCfgFile.c_str(), vec);
//
//                if (!bRet) {
//                    delete theConfig;
//                    theConfig = NULL;
//                    pExc->SetInfo(ERR_CONFIG, detail_err_config);
//                    break;
//                }
//            }
            //load enforcer

            std::string dllpath = CommonFun::GetEnforcerModule();
            bRet = Enforcer::Instance()->LoadEnforcer(dllpath);
            if (bRet) {
                EMDBReturn binit = (EMDBReturn)Enforcer::Instance()->EMDBInit("oci");
                if(binit == EMDB_SUCCESS){
                    bRet = true;
                } else {
                    bRet = false;
                }

                //Log::_logfunc = Enforcer::Instance()->SQLEnforcerWriteLogWithTagA;
            } else {
                Log::WLog(log_error,detail_err_lib_sqlenfoercer.c_str());
                pExc->SetInfo(ERR_LIBRARY, detail_err_lib_sqlenfoercer);
            }
        } while(0);

        if(bRet){
            _binited = true;
            // for (auto errMsg : vec)
            // {
            //     Log::WLog(log_error,errMsg.c_str());
            // }
        } else {
            _binited = false;
            storedExc = *pExc;
        }
    }
    else
    {
        *pExc = storedExc;
    }
    return _binited;
}

bool DAEEnforceMgr::NewEnforcerCtx( void* srvp){
    if(!_binited){
        return false;
    }
//    size_t irf = dbstring.rfind('/');
//    std::string db_name = "";
//    if (irf != std::string::npos) {
//        db_name = dbstring.substr(irf + 1);
//        size_t ilen = db_name.length();
//        if(ilen>2 && db_name[0] == '"' && db_name[ilen-1] == '"' ){
//          db_name = db_name.substr(1, ilen-2);
//        }
//    }
//    //
//    size_t ilf = dbstring.rfind(':');
//    std::string server_name = "";
//    if (ilf != std::string::npos) {
//        server_name = dbstring.substr(0,ilf);
//        size_t ilen = server_name.length();
//        if(ilen>2 && server_name[0] == '"' && server_name[ilen-1] == '"' ){
//            server_name = server_name.substr(1, ilen-2);
//        }
//    }

//    DAEResourcedata res(srvp,_envp);
//    bool bret = res.QueryResourcedata();
//    if(bret){
//        Log::WLog(log_debug,"DAEResourcedata:%s  %s  %s  %s", res._user.c_str(), res._schema.c_str(), res._db.c_str(), res._server.c_str());
//    }

    int ret = -1;
    //USES_CONVERSION;
    void* hd = nullptr;
    if (Enforcer::Instance()->IsLoaded())
    {
       // Log::WLog(log_debug,"EMDBNewUserCtx before");
        ret = Enforcer::Instance()->EMDBNewUserCtx(
                "",
                "",
                "",
                "Oracle",
                &hd);
        Log::WLog(log_debug,"EMDBNewUserCtx end ret=%d",(int)ret);

    }
    //theLog.WriteLog(1, "RUN EMDBNewUserCtx %s", ret == 0 ?"succeed":"failed");

    if (ret == 0) {
        auto it = _map_srv2nxl.find((uint64_t)srvp);
        if(it != _map_srv2nxl.end()){
            void * hd = (void*)(it->second);
            if (hd) {
                int ret = Enforcer::Instance()->EMDBClearUserCtxProperty(hd);
                assert(ret==EMDB_SUCCESS);
                ret = Enforcer::Instance()->EMDBFreeUserCtx(hd);
                assert(ret==EMDB_SUCCESS);
            }
        }
        _map_srv2nxl[(uint64_t)srvp] = (uint64_t)hd;
        Log::WLog(log_debug,"_map_srv2nxl[%d]=%d",(uint64_t)srvp,(uint64_t)hd);
        //theLog.WriteLog(1, L"--------_map_srv2nxl[%d]=%d",srvhp,hd);
    }
    return true;
}


//bool DAEEnforceMgr::SetUserAttributes(void* hd){
//
//    int ret = -1;
//    std::map<std::string,std::string> _users;
//    DAEUserAttrsOpr::QueryUserAttrs(_users);
//    for(auto & it:_users){
//        ret = Enforcer::Instance()->EMDBSetUserCtxProperty(hd, it.first.c_str(), it.second.c_str());
//        if(ret != 0){
//            Log::WLog(log_error,"set user attr failed!");
//        }
//    }
//    return true;
//}

//bool DAEEnforceMgr::BindMetadataFunction(void* srcp){
//    auto it1 = _map_src2srv.find((uint64_t)srcp);
//    if (it1 == _map_src2srv.end()) {
//        return false;
//    }
//    uint64_t srv = it1->second;
//    auto it2 = _map_srv2nxl.find(srv);
//    if (it2 == _map_srv2nxl.end()) {
//        return false;
//    }
//    void * hd = (void*)(it2->second);
//    if (!hd) {
//        return false;
//    }
//    auto it3 = _map_metadata_func.find((uint64_t)srcp);
//    if(it3 == _map_metadata_func.end()){
//        DAEQueryMetadata * data = new DAEQueryMetadata(srcp, _envp);
//        QueryMetadataFunc func  = std::bind(&DAEQueryMetadata::QueryMetadata,data,std::placeholders::_1,std::placeholders::_2);
//        Enforcer::Instance()->EMDBQueryMetadata_cb(hd,func);
//        _map_metadata_func[(uint64_t)srcp] = data;
//    }
//    return true;
//}

bool DAEEnforceMgr::EvaluationSql(std::string & sql_new, bool & deny, const std::string & sql_old, void* svcp){

    if(!_binited){
        return false;
    }
    if (sql_old.find("all_cons_columns") != std::string::npos) {
        return false;
    }
    

    //
    uint64_t find_svcp = 0;
    if(svcp != nullptr){
        find_svcp = (uint64_t)svcp;
    }  else {
        return false;
    }


    auto it1 = _map_svc2srv.find(find_svcp);
    if (it1 == _map_svc2srv.end()) {
        return false;
    }
    uint64_t srv = it1->second;
    auto it2 = _map_srv2nxl.find(srv);
    if (it2 == _map_srv2nxl.end()) {
        return false;
    }
    void * hd = (void*)(it2->second);
    if (!hd) {
        return false;
    }

    EMDBResultHandle result;
    int ret = Enforcer::Instance()->EMDBNewResult(&result);
    if (ret != 0){
        return false;
    }

    ret = Enforcer::Instance()->EMDBEvalSql(sql_old.c_str(), hd, result);
    if (ret != 0) {
        return false;
    }

    EMDBResultCode code;
    ret = Enforcer::Instance()->EMDBResultGetCode(result, &code);
    if (ret != 0) {
        return false;
    }

    const char* output = NULL;
    ret = Enforcer::Instance()->EMDBResultGetDetail(result, &output);
    if (ret != 0) {
        return false;
    }

    Log::WLog(log_debug, "-----enforcer result code:%d", code);
    if (code == EMDB_USE_NEW_TEXT) {
        sql_new = output;
        //Log::WLog(log_debug, "-----enforcer succeed sql:%s", sql_new.c_str());
    }
    else if(code == EMDB_DENY_EXECUTE){
        deny = true;
    }
    //theLog.WriteLog(1, L"************NewSQL is [%s]", wstrNewSQL.c_str());

    ret = Enforcer::Instance()->EMDBFreeResult(result);
    if (ret != 0) {
        return false;
    }

    return true;
}

bool DAEEnforceMgr::IsDeny(void* stmtp)  {// for insert/update/delete
    if(!_binited){
        return false;
    }
    if(!stmtp)
        return false;
    std::shared_lock<std::shared_mutex> lockw(_mutex_stmt); 
    auto it = _map_stmt2deny.find((uint64_t)stmtp);
    if(it != _map_stmt2deny.end()){
        return it->second;
    }
    return false;
}


void DAEEnforceMgr::BindServerHandle(void* svcp,void* srvp){
    if(!_binited){
        return;
    }
    _map_svc2srv[(uint64_t)svcp]=(uint64_t)srvp;
    //_svclist.push_back( (uint64_t)svcp);
    Log::WLog(log_debug,"_map_svc2srv[%d]=%d ",(uint64_t)svcp,(uint64_t)srvp);
}

void DAEEnforceMgr::UpdateDenyMap(void* stmtp, bool deny){
    if(!_binited){
        return;
    }
    std::unique_lock<std::shared_mutex> lockw(_mutex_stmt); 
    _map_stmt2deny[(uint64_t)stmtp]=deny;
}

void DAEEnforceMgr::ClearHandle(void* hd, int type){
    if(!_binited){
        return;
    }
    if(OCI_HTYPE_SVCCTX == type){
        auto it = _map_svc2srv.find((uint64_t)hd);
        if (it != _map_svc2srv.end()) {
            _map_svc2srv.erase(it);
        }
        auto it2 =  _map_metadata_func.find((uint64_t)hd);
        if (it2 != _map_metadata_func.end()) {
            delete(it2->second);
            _map_metadata_func.erase(it2);
        }
        //_svclist.remove((uint64_t)hd);

    } else if(OCI_HTYPE_SERVER == type) {
        auto it = _map_srv2nxl.find((uint64_t)hd);
        if(it != _map_srv2nxl.end()) {
            void * hd = (void*)(it->second);
            if (hd) {
                int ret = Enforcer::Instance()->EMDBClearUserCtxProperty(hd);
                assert(ret==EMDB_SUCCESS);
                ret = Enforcer::Instance()->EMDBFreeUserCtx(hd);
                assert(ret==EMDB_SUCCESS);
            }
            _map_srv2nxl.erase(it);
        }
        // remove odbc deny srv
        auto itodbc = _deny_srvs.find((uint64_t)hd);
        if(itodbc != _deny_srvs.end()) {
            _deny_srvs.erase(itodbc);
        }

    } else if(OCI_HTYPE_STMT == type){
        std::unique_lock<std::shared_mutex> lockw(_mutex_stmt); 
        auto it = _map_stmt2deny.find((uint64_t)hd);
        if(it != _map_stmt2deny.end()){
            _map_stmt2deny.erase(it);
        }
    }
    //clear DAEOCIENV
    for(auto it = _ocienvpmap.begin(); it != _ocienvpmap.end();++it){
        it->second->Clear(type,(uint64_t)hd);
    }
}

void DAEEnforceMgr::SetEnforcerCtxAttr(void*srcp){
    if(!_binited){
        return;
    }
    auto it = _map_svc2srv.find((uint64_t)srcp);
    if (it == _map_svc2srv.end()) {
        return;
    }
    auto it2 = _map_srv2nxl.find((uint64_t)it->second);
    if (it2 == _map_srv2nxl.end()) {
        return;
    }
    int ret = -1;
    EMDBUserCtxHandle hd = (EMDBUserCtxHandle) it2->second;
    if(nullptr == hd){
        Log::WLog(log_error,"find EMDBUserCtxHandle failed!");
    }

    //bind server/da/schema
    DAEResourcedata res(srcp,_envp);
    bool bret = false;
    if(IsU16CharSet()){
        bret = res.QueryResourcedataW();
    } else {
        bret = res.QueryResourcedataA();
    }
    
    if(bret){
        Log::WLog(log_debug,"DAEResourcedata:%s  %s  %s  %s", res._user.c_str(), res._schema.c_str(), res._db.c_str(), res._server.c_str());
    }
    else {
        return ;
    }
    if(!res._server.empty()){
        Enforcer::Instance()->EMDBSetUserCtxProperty((void*)it2->second, "server", res._server.c_str());
    }
    if(!res._db.empty()){
        Enforcer::Instance()->EMDBSetUserCtxProperty(hd, "database", res._db.c_str());
    }
    if(!res._schema.empty()){
        Enforcer::Instance()->EMDBSetUserCtxProperty(hd, "schema", res._schema.c_str());
    }

    //set attributes
    std::map<std::string,std::string> _users;
    DAEUserAttrsOpr::QueryUserAttrs(res._user, _users);
    for(auto & it:_users){
        ret = Enforcer::Instance()->EMDBSetUserCtxProperty(hd, it.first.c_str(), it.second.c_str());
        if(ret != 0){
            Log::WLog(log_error,"set user attr failed!");
        }
    }

    //bind function
    auto it3 = _map_metadata_func.find((uint64_t)srcp);
    if(it3 == _map_metadata_func.end()){
        DAEQueryMetadata * data = new DAEQueryMetadata(srcp, _envp);
        //QueryMetadataFunc func = nullptr;
        if(DAEEnforceMgr::Instance()->IsU16CharSet()){
            QueryMetadataFunc func  = std::bind(&DAEQueryMetadata::QueryMetadataW,data,std::placeholders::_1,std::placeholders::_2);
            Enforcer::Instance()->EMDBQueryMetadata_cb(hd, func);
        } else {
            QueryMetadataFunc func  = std::bind(&DAEQueryMetadata::QueryMetadataA,data,std::placeholders::_1,std::placeholders::_2);
            Enforcer::Instance()->EMDBQueryMetadata_cb(hd, func);
        }
        _map_metadata_func[(uint64_t)srcp] = data;
    }else {
        if(DAEEnforceMgr::Instance()->IsU16CharSet()){
            QueryMetadataFunc func  = std::bind(&DAEQueryMetadata::QueryMetadataW,it3->second,std::placeholders::_1,std::placeholders::_2);
            Enforcer::Instance()->EMDBQueryMetadata_cb(hd, func);
        } else {
            QueryMetadataFunc func  = std::bind(&DAEQueryMetadata::QueryMetadataA,it3->second,std::placeholders::_1,std::placeholders::_2);
            Enforcer::Instance()->EMDBQueryMetadata_cb(hd, func);
        }
    }

}


void DaeOciEnv::Clear(int type, uint64_t hd){
    switch (type)
    {
    case OCI_HTYPE_STMT :
        /* code */
        {
            std::unique_lock<std::shared_mutex> lockw(_mutex_stmt); 
            auto it = _stmtps.find(hd);
            if(it != _stmtps.end()){
                _stmtps.erase(it);
            }
        }
        break;
    case OCI_HTYPE_SVCCTX:
        {
            for(auto it = _svcps.begin(); it != _svcps.end(); ++it){
                if(*it == hd){
                    it = _svcps.erase(it);
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
}