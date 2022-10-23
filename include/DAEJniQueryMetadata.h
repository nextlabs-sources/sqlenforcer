#ifndef DAEQUERYMETADATA_H
#define DAEQUERYMETADATA_H
#include <stdio.h>
#include <string>
#include "EMMaskDef.h"
#include "EMDBType.h"

typedef std::function<bool (const std::string &,MetadataVec & )> QueryMetadataFunc;

class DAEJniQueryMetadata{
    public:
    DAEJniQueryMetadata(EMDB_DB_TYPE type):_type(type){

    }
    virtual ~DAEJniQueryMetadata(){

    }

    bool QueryMetadataJni(const std::string & table, MetadataVec & metadata);
    void SetJniEnvObj(void * env, void * metaobj){
        _jni_env = env;
        _jni_meta_obi = metaobj;
    }
    private:
    void * _jni_env = NULL;
    void * _jni_meta_obi = NULL;
    EMDB_DB_TYPE _type;
};


#endif