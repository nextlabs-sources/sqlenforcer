#ifndef DAE_ENFORCER_MGR_H
#define  DAE_ENFORCER_MGR_H

#include <stdio.h>
#include <memory>
#include <map>
#include <set>
#include <list>
#include "DAETableMetadata.h"
#include <memory>
#include <shared_mutex>

struct SqlException;
//for prepare  
class DaeOciEnv
{

public:
    DaeOciEnv(uint64_t envp):_envp(envp){}
    ~DaeOciEnv(){}

    void InsertSvcp(uint64_t svcp){ _svcps.push_back(svcp); }
    void InsertStmtp(uint64_t stmtp){ 
        std::unique_lock<std::shared_mutex> lockw(_mutex_stmt); 
        _stmtps.insert(stmtp); 
    }
    uint64_t GetLastSvcpByStmtp(uint64_t stmtp ){
        std::shared_lock<std::shared_mutex> lockr(_mutex_stmt); 
        auto it = _stmtps.find(stmtp);
        if(it != _stmtps.end() && _svcps.size() > 0){
            return _svcps.back();
        } else {
            return 0;
        }
    }

    void Clear(int type, uint64_t hd);

    uint64_t _envp;
    std::list<uint64_t> _svcps;
    std::set<uint64_t> _stmtps;
    std::shared_mutex _mutex_stmt;

};


class DAEEnforceMgr{
public:

    static DAEEnforceMgr* Instance(){
        static DAEEnforceMgr* pEnforcer = new DAEEnforceMgr();
        return pEnforcer;
    }
public:
    bool InitalizeEnforcer(SqlException* pExc);
    bool NewEnforcerCtx( void* srvp);
    bool EvaluationSql(std::string & sql, bool & deny, const std::string & sqlold, void* svcp);
    bool IsDeny(void* stmtp); // for insert/update/delete
    void BindServerHandle(void* svcp, void* srvp);
    void UpdateDenyMap(void* stmtp, bool deny);
    void ClearHandle(void* hd, int type);

    void SetEnvHandle( void* handle){ 
        _envp = handle;
        auto it = _ocienvpmap.find((uint64_t)handle);
        if(it == _ocienvpmap.end()){
            std::shared_ptr<DaeOciEnv> ocienvp = std::make_shared<DaeOciEnv>((uint64_t)handle);
            _ocienvpmap[(uint64_t)handle]=ocienvp;
        }
           
    }
    //bool SetUserAttributes(void* hd);
    //bool BindMetadataFunction(void* srcp);
    void SetEnforcerCtxAttr(void*srcp);
    void* GetEnvp(){return _envp; };

    void SetCharSet(uint64_t set){_characterset=set; }
    bool IsU16CharSet(){return _characterset==1000; }

    void InsertStmt2DaeOciEnv(const uint64_t stmtp,const uint64_t envp) { 
        auto it =  _ocienvpmap.find(envp);
        if(it != _ocienvpmap.end()){
            it->second->InsertStmtp(stmtp);
        }
    }
    void InsertSvcp2DaeOciEnv(const uint64_t svcp,const uint64_t envp) { 
        auto it =  _ocienvpmap.find(envp);
        if(it != _ocienvpmap.end()){
            it->second->InsertSvcp(svcp);
        }
    }
    uint64_t GetSvcpFromDaeOciEnv(const uint64_t stmtp) { 
        uint64_t ret  = 0;
        for(auto it = _ocienvpmap.begin(); it != _ocienvpmap.end();++it){
            ret = it->second->GetLastSvcpByStmtp(stmtp);
            if(ret != 0){
                break;
            }
        }
        return ret;
    }



    void InsertODBCEnvp(const uint64_t envp){ _deny_envs.insert(envp); }
    bool IsODBCEnvp(const uint64_t envp) { return _deny_envs.find(envp) != _deny_envs.end(); }
    void InsertODBCSrvp( const uint64_t srvp){ _deny_srvs.insert(srvp); }
    bool IsODBCSrvp(const uint64_t srvp) { return _deny_srvs.find(srvp) != _deny_srvs.end(); }

    std::map<uint64_t, DAEQueryMetadata*> _map_metadata_func;
private:

    std::map<uint64_t , uint64_t>  _map_srv2nxl;   //srvhp  <->  enforcer_ctx   // for OCIStmtPrepare2
    std::map<uint64_t, uint64_t>  _map_svc2srv; //service context 2 server
    std::map<uint64_t, bool> _map_stmt2deny;
    std::shared_mutex _mutex_stmt;
    //std::map<uint64_t,uint64_t> _map_stmt2svc;
    
     void* _envp = nullptr;// to alloc handle
   // uint64_t _last_svc = 0;
    //std::list<int64_t > _svclist;
    uint64_t _characterset = 0;//default is 0, special is OCI_UTF16ID 

    //this 3 val control odbc Reentry
    bool _binited = false;
    std::set<uint64_t> _deny_envs;
    std::set<uint64_t> _deny_srvs;

    std::map<uint64_t,std::shared_ptr<DaeOciEnv>> _ocienvpmap;
};






#endif