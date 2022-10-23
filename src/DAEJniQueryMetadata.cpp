
#include "DAEJniQueryMetadata.h"
#include <jni.h>
#include "commfun.h"
#include "DAELog.h"


bool DAEJniQueryMetadata::QueryMetadataJni(const std::string & table, MetadataVec & metadata){
    if(_jni_env == NULL || _jni_meta_obi == NULL){
        return false;
    }
    JNIEnv * env = (JNIEnv*)_jni_env; 
    jobject metaobj = (jobject)_jni_meta_obi;

    theLog->WriteLog(log_debug, "QueryMetadataJni begin");
    jclass exc_class = env->GetObjectClass(metaobj);
    jmethodID queryMetaData = env->GetMethodID(exc_class,"queryMetaData","(Ljava/lang/String;)Ljava/lang/String;");

    const char* ctable = table.c_str();
    jstring jstrtable = env->NewStringUTF(ctable);

    jstring val = (jstring)env->CallObjectMethod(metaobj, queryMetaData, jstrtable);//jobject->jstring

    //parser val;
    const char* cval = env->GetStringUTFChars(val,0);
    std::string strval(cval);
    theLog->WriteLog(log_debug, "QueryMetadataJni data=%s",strval.c_str());
    env->ReleaseStringUTFChars(val, cval);
    
    //
    if(strval.length() <= 0){
        return  false;
    }

    std::vector<std::string> vecmetadata;
    CommonFun::SplitString(strval, "{}", vecmetadata);
    if(vecmetadata.size()<= 0){
        return false;
    }

    //parser vecmetadata
    for(size_t i = 0; i < vecmetadata.size();i++ ){
        size_t rf = vecmetadata[i].rfind(".");
        if(vecmetadata[i].length() < 2){
            continue;
        }
        if(rf == std::string::npos){
            return false;
        }
        
        Metadata mt ;
        mt._col = vecmetadata[i].substr(0, rf);
        mt._type = MaskItem::GetDataType(_type, vecmetadata[i].substr(rf+1) );
        metadata.push_back(mt);
    }
    theLog->WriteLog(log_debug, "QueryMetadataJni end");

    return true;
}

