#include "com_nextlabs_jdbc_driverproxy_nxlEnforcer.h"
#include "sqlenforcer_export.h"
#include <string>
#include "DAELog.h"
#include "SqlException.h"
#include "enforcermgr.h"
#include "emdb_sdk.h"
#include "DAEJniQueryMetadata.h"
#include "EMDBType.h"
#include "usercontextinfo.h"

JNIEXPORT jboolean JNICALL Java_com_nextlabs_jdbc_driverproxy_nxlEnforcer_sqlEnforcerInit(JNIEnv *env, jobject obj,\
 jstring moduleName, jstring configFile, jobject excobj)
{
    const char* szmoduleName = env->GetStringUTFChars(moduleName,0);
    const char* szconfigFile = env->GetStringUTFChars(configFile,0);

    SqlException exc;
    bool result = SQLEnforcerInit(szmoduleName, szconfigFile,&exc);

    if(exc.IsBreak()){
        //jclass _class = env->GetObjectClass(obj);
        //jfieldID exc_id = env->GetStaticFieldID(_class, "exception", "Lcom/nextlabs/jdbc/driverproxy/nxlSqlException;");
        //jobject exc_obj = env->GetStaticObjectField(_class,exc_id);  
        jclass exc_class = env->GetObjectClass(excobj);  
        jmethodID exc_setinfo = env->GetMethodID(exc_class,"SetInfo","(ILjava/lang/String;)V"); 

        const char* charDetail = exc.cdetail.c_str();
        jstring jstrDetail = env->NewStringUTF(charDetail);
        int iCode = exc.code;
        jint jintCode = iCode;

        env->CallVoidMethod(excobj,exc_setinfo, jintCode, jstrDetail); 
    }

    env->ReleaseStringUTFChars(moduleName,szmoduleName);
    env->ReleaseStringUTFChars(configFile,szconfigFile);
    
    return result ? JNI_TRUE : JNI_FALSE;
}
JNIEXPORT jlong JNICALL Java_com_nextlabs_jdbc_driverproxy_nxlEnforcer_sqlEnforcerNewContext(JNIEnv *env, jobject obj, jstring userID,\
jstring password, jobject excobj)
{
    const char* user = env->GetStringUTFChars(userID,0);
    const char* pwd = env->GetStringUTFChars(password,0);
    SqlException exc;
    jlong result = SQLEnforcerNewContext(user,pwd,&exc);
    if(exc.IsBreak()){
       // jclass _class = env->GetObjectClass(obj);
        //jfieldID exc_id = env->GetStaticFieldID(_class, "exception", "Lcom/nextlabs/jdbc/driverproxy/nxlSqlException;");
        //jobject exc_obj = env->GetStaticObjectField(_class,exc_id);  
        jclass exc_class = env->GetObjectClass(excobj);  
        jmethodID exc_setinfo = env->GetMethodID(exc_class,"SetInfo","(ILjava/lang/String;)V"); 

        const char* charDetail = exc.cdetail.c_str();
        jstring jstrDetail = env->NewStringUTF(charDetail);
        int iCode = exc.code;
        jint jintCode = iCode;

        env->CallVoidMethod(excobj,exc_setinfo, jintCode, jstrDetail); 
    }
    env->ReleaseStringUTFChars(userID,user);
    env->ReleaseStringUTFChars(password,pwd);
    return result;
}
JNIEXPORT void JNICALL Java_com_nextlabs_jdbc_driverproxy_nxlEnforcer_sqlEnforcerFreeContext(JNIEnv *env, jobject, jlong ctx)
{
    //(*env).CallVoidMethod(m_object, m_mid, userID);
    //jboolean blocked = is_blocked ? JNI_FALSE : JNI_TRUE;
    SQLEnforcerFreeContext((USER_CONTEXT)ctx);
}

JNIEXPORT jobject JNICALL Java_com_nextlabs_jdbc_driverproxy_nxlEnforcer_sqlEnforcerEvaluationV2(JNIEnv *env, jobject obj, \
jlong context, jstring sqlText, jobject meta, jobject excobj)
{
    //call back
    UserContextInfo * ctx = CEnforcerMgr::GetUserContextInfo((USER_CONTEXT)context);
    if(NULL == ctx){
        return NULL;
    }
    EMDB_DB_TYPE tp = ctx->GetEMDBType();

    DAEJniQueryMetadata data(tp);
    data.SetJniEnvObj((void*)env, (void*)meta);
    QueryMetadataFunc func  = std::bind(&DAEJniQueryMetadata::QueryMetadataJni,&data,std::placeholders::_1,std::placeholders::_2);
    EMDBQueryMetadata_cb((EMDBUserCtxHandle)context, func);

    const char* sql = env->GetStringUTFChars(sqlText,0);
    bool is_blocked = false;
    SqlException exc;
    std::string enforcedSql = SQLEnforcerEvaluationSQLA((USER_CONTEXT)context,sql,&exc);
    if(exc.IsBreak()){
        jclass exc_class = env->GetObjectClass(excobj);
        jmethodID exc_setinfo = env->GetMethodID(exc_class,"SetInfo","(ILjava/lang/String;)V");

        const char* charDetail = exc.cdetail.c_str();
        jstring jstrDetail = env->NewStringUTF(charDetail);
        int iCode = exc.code;
        jint jintCode = iCode;

        env->CallVoidMethod(excobj,exc_setinfo, jintCode, jstrDetail);
    }
    env->ReleaseStringUTFChars(sqlText,sql);
    const char* charSql = enforcedSql.c_str();
    jstring jstr = env->NewStringUTF(charSql);
    jboolean blocked = is_blocked ? JNI_TRUE : JNI_FALSE;
    jclass cls = env->FindClass("com/nextlabs/jdbc/driverproxy/nxlEnforcedSqlResult");
    jmethodID id = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;Z)V");
    jobject enforcedResultCls = env->NewObject( cls, id, jstr,blocked);

    return enforcedResultCls;
}

JNIEXPORT void JNICALL Java_com_nextlabs_jdbc_driverproxy_nxlEnforcer_sqlEnforcerUserContext(JNIEnv *env, jobject, jlong enforcerContext, jint contextType, jstring contextInfo)
{
    const char* info = env->GetStringUTFChars(contextInfo,0); 
    SetUserContextInfo((USER_CONTEXT)enforcerContext,(USER_CONTEXT_INFO_TYPE)contextType,info);
    env->ReleaseStringUTFChars(contextInfo,info);
}
JNIEXPORT jint JNICALL Java_com_nextlabs_jdbc_driverproxy_nxlEnforcer_sqlEnforcerWriteLog(JNIEnv *env, jobject, jint level, jstring message)
{
    const char* msg = env->GetStringUTFChars(message,0);
    int result = SQLEnforcerWriteLogWithTagA((int)level, "JDBC", msg);
    env->ReleaseStringUTFChars(message,msg);
    return result;
}


JNIEXPORT void JNICALL Java_com_nextlabs_jdbc_driverproxy_nxlEnforcer_sqlAddDBUserInfo
        (JNIEnv * env, jobject obj, jlong enforcerContext, jstring key, jstring val)
{
    SqlException exc;
    const char* strkey = env->GetStringUTFChars(key,0);
    const char* strvalue = env->GetStringUTFChars(val,0);

    CEnforcerMgr::Instance()->AddUserAttrValue_SDK((USER_CONTEXT)enforcerContext, strkey, strvalue, &exc);
    if(strkey){
        env->ReleaseStringUTFChars(key,strkey);
    }
    if(strvalue){
        env->ReleaseStringUTFChars(val,strvalue);
    }
}

JNIEXPORT jstring JNICALL Java_com_nextlabs_jdbc_driverproxy_nxlEnforcer_decryptString
        (JNIEnv * env, jobject obj, jstring src, jboolean isdecrypt){

    const char* csrc = env->GetStringUTFChars(src,0);
    std::string strsrc = csrc;
    env->ReleaseStringUTFChars(src,csrc);

    std::string ret;
    ret = isdecrypt?CommonFun::DecryptString(strsrc):CommonFun::EncryptString(strsrc);

    const char* cret = ret.c_str();
    jstring jstrret = env->NewStringUTF(cret);

    return jstrret;
}

