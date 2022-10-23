/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_nextlabs_jdbc_mssqlproxy_nxlEnforcer */

#ifndef _Included_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer
#define _Included_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_nextlabs_jdbc_mssql_nxlEnforcer
 * Method:    sqlEnforcerInit
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer_sqlEnforcerInit
  (JNIEnv *, jobject, jstring, jstring,jobject);

/*
 * Class:     com_nextlabs_jdbc_mssql_nxlEnforcer
 * Method:    sqlEnforcerNewContext
 * Signature: (Ljava/lang/String;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer_sqlEnforcerNewContext
  (JNIEnv *, jobject, jstring, jstring,jobject);

/*
 * Class:     com_nextlabs_jdbc_mssql_nxlEnforcer
 * Method:    sqlEnforcerFreeContext
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer_sqlEnforcerFreeContext
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_nextlabs_jdbc_mssql_nxlEnforcer
 * Method:    sqlEnforcerEvaluation
 * Signature: (JLcom/nextlabs/jdbc/mssql/nxlEnforcedSqlResult;)Lcom/nextlabs/jdbc/mssql/nxlEnforcedSqlResult;
 */
JNIEXPORT jobject JNICALL Java_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer_sqlEnforcerEvaluationV2
  (JNIEnv *, jobject, jlong, jstring,jobject,jobject);

/*
 * Class:     com_nextlabs_jdbc_mssql_nxlEnforcer
 * Method:    sqlEnforcerUserContext
 * Signature: (JILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer_sqlEnforcerUserContext
  (JNIEnv *, jobject, jlong, jint, jstring);

/*
 * Class:     com_nextlabs_jdbc_mssql_nxlEnforcer
 * Method:    sqlEnforcerWriteLog
 * Signature: (ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer_sqlEnforcerWriteLog
  (JNIEnv *, jobject, jint, jstring);

/*
 * Class:     com_nextlabs_jdbc_mssql_nxlEnforcer
 * Method:    sqlAddDBUserInfo
 * Signature:
 */
JNIEXPORT void JNICALL Java_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer_sqlAddDBUserInfo
        (JNIEnv *, jobject, jlong, jstring, jstring);


JNIEXPORT jstring JNICALL Java_com_nextlabs_jdbc_mssqlproxy_nxlEnforcer_decryptString
        (JNIEnv *, jobject, jstring, jboolean);



#ifdef __cplusplus
}
#endif
#endif
