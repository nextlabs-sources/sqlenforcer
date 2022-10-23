//
// Created by jeff on 2021/6/24.
//

#ifndef EMDB_DAERESOURCEDATA_H
#define EMDB_DAERESOURCEDATA_H

#include <string>

class DAEEnforceMgr;

class DAEResourcedata {
public:
    DAEResourcedata():_cur_srvp(nullptr),_cur_envp(nullptr){}
    DAEResourcedata( void * cur_srvp,const void* cur_envp):_cur_srvp(cur_srvp),_cur_envp(cur_envp){}
    bool QueryResourcedataA();
    bool QueryResourcedataW();
private:

    void* _cur_srvp ;
    const  void* _cur_envp ;//use to alloc handle
    std::string _server;
    std::string _db;
    std::string _schema;
    std::string _user;

    friend class DAEEnforceMgr;
};


#endif //EMDB_DAERESOURCEDATA_H
