//
// Created by jeff on 2021/6/16.
//

#ifndef EMDB_DAETABLEMETADATAMGR_H
#define EMDB_DAETABLEMETADATAMGR_H

#include "stdafx.h"
#include <string>
#include <vector>
#include "DAEEnforcerWrapper.h"


class DAEQueryMetadata{
public:
    DAEQueryMetadata():_cur_srvp(nullptr),_cur_envp(nullptr){}
    DAEQueryMetadata( void * cur_srvp,const void* cur_envp):_cur_srvp(cur_srvp),_cur_envp(cur_envp){}
    bool QueryMetadataA(const std::string & tb, MetadataVec & metadata);
    bool QueryMetadataW(const std::string & tb, MetadataVec & metadata);
private:

    void* _cur_srvp ;
    const  void* _cur_envp ;//use to alloc handle
    std::string _table;
};


#endif //EMDB_DAETABLEMETADATAMGR_H
