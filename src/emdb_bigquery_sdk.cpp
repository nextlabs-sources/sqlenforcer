//
// Created by jeff on 2020/6/2.
//

#include "emdb_bigquery_sdk.h"
#include "SqlException.h"
#include "commfun.h"
#include "enforcermgr.h"
#include "emdb_result_sdk.h"
#include "DAELog.h"

#ifdef  WIN32
#include <windows.h>
static long g_nEnforcerInited = 0;
#else
#include <atomic>
static std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;
#endif

#include "EMDBConfig.h"


bool initalize_enforcer(SqlException* pExc)
{

    bool bRet = true;
#ifdef  WIN32
    bool bInit = InterlockedCompareExchange(&g_nEnforcerInited, 1, 0);
#else
    bool bInit = lock_stream.test_and_set();
#endif
    if (!bInit)
    {
        //load config file
        const std::string strCfgFile = CommonFun::GetConfigFilePath();
        try
        {
            const auto& config = EMDBConfig::GetInstance();
            auto initial_errors = config.get_initial_errors(ConnectionType::kNone);

            for (const auto& error : initial_errors)
            {
                theLog->WriteLog(log_error, error.c_str());
            }
        }
        catch (const std::exception& e)
        {
            pExc->SetInfo(ERR_CONFIG, e.what());
            return false;
        }

        CEnforcerMgr::Instance()->Init_SDK("jdbc", pExc);
    }



    return bRet;
}


EMDB_BQ_Return    NewResult(EMDB_BQ_Handle * output_result ) {

    *output_result = new CEMDB_BQ_Result();
    return EMDB_BQ_SUCCESS;
}

EMDB_BQ_Return    FreeResult(EMDB_BQ_Handle    result) {
    if(result != NULL){
        delete((CEMDB_BQ_Result*)result);
    } else {
        return EMDB_BQ_INVALID_HANDLE;
    }
    return EMDB_BQ_SUCCESS;
}

EMDB_BQ_Return    EnforceSQL(const char *sql, const char * database, const char * schema, const EMDBUserProperty* userattrs, unsigned int userattrs_size, EMDB_BQ_Handle result){
    if(result == NULL){
        return EMDB_BQ_INVALID_HANDLE;
    }
    if(sql == NULL){
        ((CEMDB_BQ_Result*)result)->SetValue(EMDB_IGNORE, sql,"SQL stayement is empty");
        return EMDB_BQ_ERROR;
    }
    if(userattrs_size == 0 || userattrs == NULL){
        ((CEMDB_BQ_Result*)result)->SetValue(EMDB_IGNORE, sql,"user id and user property is empty");
        return EMDB_BQ_ERROR;
    }
    SqlException exc;
    initalize_enforcer(&exc);
    if(exc.IsBreak()){
        ((CEMDB_BQ_Result*)result)->SetValue(EMDB_FAILED, sql,exc.cdetail);
        return EMDB_BQ_ERROR;
    }

    USER_CONTEXT ctx = CEnforcerMgr::Instance()->NewContext_SDK( &exc);
    if(exc.IsBreak()){
        return EMDB_BQ_ERROR;
    }
    if(!ctx){
        return EMDB_BQ_INVALID_HANDLE;
    }
    CEnforcerMgr::Instance()->SetUserContextInfo(ctx,CONTEXT_INFO_SERVER,"Google" );
    CEnforcerMgr::Instance()->SetUserContextInfo(ctx,CONTEXT_INFO_DATABASE,database );
    CEnforcerMgr::Instance()->SetUserContextInfo(ctx,CONTEXT_INFO_SCHEMA,schema );
    CEnforcerMgr::Instance()->SetUserContextInfo(ctx,CONTEXT_INFO_DB_TYPE,"BigQuery" );

    for(size_t i = 0 ; i < userattrs_size; ++i) {
        CEnforcerMgr::Instance()->AddUserAttrValue_SDK(ctx, userattrs[i].key, userattrs[i].value, &exc);
    }

    VecBindSqlParams params;
    std::string strNew = CEnforcerMgr::Instance()->EvaluationSQL(ctx, sql, params, &exc);
    switch (exc.code){
        case ERR_PARSE:
        case ERR_POLICY_PARSER:
        case ERR_MASK_OPR:
        case ERR_FILTER_OPR:
        case ERR_POLICY_NOMATCH:{
            ((CEMDB_BQ_Result*)result)->SetValue(EMDB_IGNORE, strNew, exc.cdetail);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:IGNORE exception:%s",exc.cdetail.c_str());
        } break;
        case ERR_POLICY:
        case ERR_USERINFO:{
            ((CEMDB_BQ_Result*)result)->SetValue(EMDB_FAILED, strNew, exc.cdetail);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:FAILED exception:%s",exc.cdetail.c_str());
        } break;
        case ERR_DENY:{
            ((CEMDB_BQ_Result*)result)->SetValue(EMDB_DENY, "", exc.cdetail);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:DENY exception:%s",exc.cdetail.c_str());
        } break;
        case ERR_DENY_SELECT:{
            ((CEMDB_BQ_Result*)result)->SetValue(EMDB_DENY_SELECT, strNew, exc.cdetail);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:DENY_SELECT exception:%s",exc.cdetail.c_str());
        }break;
        default:
            ((CEMDB_BQ_Result*)result)->SetValue(EMDB_ALLOW, strNew, exc.cdetail);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:ALLOW ");
            break;
    }

    CEnforcerMgr::Instance()->FreeContext(ctx);

    return EMDB_BQ_SUCCESS;
}


 EMDB_BQ_Return    GetResultCode(EMDB_BQ_Handle  result, EMDB_BQ_ResultCode *output_code){
    if(result == NULL){
        return EMDB_BQ_INVALID_HANDLE;
    }
    *output_code = ((CEMDB_BQ_Result*)result)->GetCode();
    return EMDB_BQ_SUCCESS;
}

 EMDB_BQ_Return    GetNewSQL(EMDB_BQ_Handle  result, const char ** sql){
    if(result == NULL){
        return EMDB_BQ_INVALID_HANDLE;
    }
    *sql = ((CEMDB_BQ_Result*)result)->GetSQL();
    return EMDB_BQ_SUCCESS;
}

EMDB_BQ_Return  GetError(EMDB_BQ_Handle  result, const char ** error){
    if(result == NULL){
        return EMDB_BQ_INVALID_HANDLE;
    }
    *error = ((CEMDB_BQ_Result*)result)->GetError();
    return EMDB_BQ_SUCCESS;
}

bool copy_string(const std::string& src, char *buf, int size, int& result) {
    if (!buf || size <= 0) {
        return false;
    }
    std::string i_str = src;
    bool ret = true;
    int len = i_str.length();
    if (len > size - 1) {
        len = size - 1;
        ret = false;
    }
    strncpy(buf, i_str.c_str(), len);
    buf[len] = '\0';
    result = len;
    return ret;
}

EMDB_BQ_Return    EnforceSQL_standalone(
        const char *sql,
        const char * database,
        const char * schema,
        const EMDBUserProperty* userattrs,
        unsigned int userattrs_size,
        unsigned int * ret_code,
        char * ret_detail,
        int detail_max){

    if(sql == NULL){
        *ret_code = EMDB_IGNORE;
        int len = 0;
        copy_string("SQL stayement is empty",ret_detail,detail_max,len);
        return EMDB_BQ_ERROR;
    }
    if(userattrs_size == 0 || userattrs == NULL){
        *ret_code = EMDB_IGNORE;
        int len = 0;
        copy_string("user id and user property is empty",ret_detail,detail_max,len);
        return EMDB_BQ_ERROR;
    }
    SqlException exc;
    initalize_enforcer(&exc);
    if(exc.IsBreak()){
        *ret_code = EMDB_FAILED;
        int len = 0;
        copy_string(exc.cdetail,ret_detail,detail_max,len);
        return EMDB_BQ_ERROR;
    }

    USER_CONTEXT ctx = CEnforcerMgr::Instance()->NewContext_SDK( &exc);
    if(exc.IsBreak()){
        return EMDB_BQ_ERROR;
    }
    if(!ctx){
        return EMDB_BQ_INVALID_HANDLE;
    }
    CEnforcerMgr::Instance()->SetUserContextInfo(ctx,CONTEXT_INFO_SERVER,"Google" );
    CEnforcerMgr::Instance()->SetUserContextInfo(ctx,CONTEXT_INFO_DATABASE,database );
    CEnforcerMgr::Instance()->SetUserContextInfo(ctx,CONTEXT_INFO_SCHEMA,schema );
    CEnforcerMgr::Instance()->SetUserContextInfo(ctx,CONTEXT_INFO_DB_TYPE,"BigQuery" );

    for(size_t i = 0 ; i < userattrs_size; ++i) {
        CEnforcerMgr::Instance()->AddUserAttrValue_SDK(ctx, userattrs[i].key, userattrs[i].value, &exc);
    }
    VecBindSqlParams params;
    std::string strNew = CEnforcerMgr::Instance()->EvaluationSQL(ctx, sql, params, &exc);
    switch (exc.code){
        case ERR_PARSE:
        case ERR_POLICY_PARSER:
        case ERR_MASK_OPR:
        case ERR_FILTER_OPR:
        case ERR_POLICY_NOMATCH:{
            *ret_code = EMDB_IGNORE;
            int len = 0;
            copy_string(exc.cdetail,ret_detail,detail_max,len);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:IGNORE exception:%s",exc.cdetail.c_str());
        } break;
        case ERR_POLICY:
        case ERR_USERINFO:{
            *ret_code = EMDB_FAILED;
            int len = 0;
            copy_string(exc.cdetail,ret_detail,detail_max,len);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:FAILED exception:%s",exc.cdetail.c_str());
        } break;
        case ERR_DENY:{
            *ret_code = EMDB_DENY;
            int len = 0;
            copy_string(exc.cdetail,ret_detail,detail_max,len);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:DENY exception:%s",exc.cdetail.c_str());
        } break;
        case ERR_DENY_SELECT:{
            *ret_code = EMDB_DENY_SELECT;
            int len = 0;
            copy_string(strNew,ret_detail,detail_max,len);
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:DENY_SELECT exception:%s",exc.cdetail.c_str());
        }break;
        default:{
            *ret_code = EMDB_ALLOW;
            int len = 0;
            copy_string(strNew,ret_detail,detail_max,len);
            //
            theLog->WriteLog(log_info, "EnforceSQL SDK for bigquery:ALLOW ");
            break;
        }
    }

    CEnforcerMgr::Instance()->FreeContext(ctx);

    return EMDB_BQ_SUCCESS;
}


// #include "QueryCAZPolicyOpr.h"
// #include <chrono>
// using namespace std::chrono;
//bool query_pc_test(EMResDictionary & res,const std::string & action){
//
//    size_t cnt_real  = 1;
//
//    //IPolicyRequest * reqs[MAX_TABLE] = {NULL};
//    const IPolicyRequest ** reqs = (const IPolicyRequest**)calloc(cnt_real,sizeof(IPolicyRequest*));
//    std::string user = "user";
//    for (size_t i = 0; i < cnt_real; ++i)
//    {
//        RequestInfo reqinfo;
//        reqinfo._action = action;
//        //user;
//        ResourceAttrValue * value = new ResourceAttrValue("joy",XACML_string);
//        reqinfo._users.insert(std::make_pair("id",value));
//
//        //resource
//        reqinfo._rescs.swap(res);
//
//
//        reqs[i] = create_request(reqinfo, user);
//    }
//
//    if(cnt_real == 1) {
//        IPolicyResult* result = NULL;
//
//        auto st = system_clock::now();
//        QueryStatus  status = single_query_pc(reqs[0], &result);
//        auto ed = system_clock::now();
//        auto duration = duration_cast<microseconds>(ed-st);
//        double  timed = double (duration.count())*microseconds::period::num / microseconds::period::den;
//        theLog->WriteLog(log_error, "query_single_time:%lf",timed);
//
//        free_pc_request(const_cast<IPolicyRequest*>(reqs[0]));
//        free(reqs);
//
////      theLog->WriteLog(log_info, "query_single_pc_time:%ld ms", mtime);
//
//        if (QS_S_OK != status ) {
//            //pExc->SetInfo(ERR_POLICY, "single_query_pc failed.");
//            theLog->WriteLog(log_error, "single_query_pc failed");
//            return false;
//        }
//        int icount = result->ObligationCount();
//        printf("---time---%lf---ob_count=%d---\n",timed,icount);
//
//        free_pc_result(result);
//    }
//    return true;
//}
/*
EMDB_BQ_Return    EnforceSQL_test(){
    SqlException exc;
    initalize_enforcer(&exc);

    std::string action;

    int i = std::rand();
    int rand = i%12;
    EMResDictionary res;
    ResourceAttrValue* v1 = new ResourceAttrValue("jdbc-enforcer",XACML_string);

    ResourceAttrValue *v2=new ResourceAttrValue("Perf",XACML_string);;

    ResourceAttrValue *v3=new ResourceAttrValue("Perf",XACML_string);;

    ResourceAttrValue *v4=new ResourceAttrValue("Google",XACML_string);;


    switch(rand){
        case 0:{
            v3->strValue = "customer";
            v2->strValue ="EMDB_Test";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"SELECT" );
        } break;
        case 1:{
            v3->strValue = "customer";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"SELECT" );
        } break;
        case 2:{
            v3->strValue = "customer_test";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"INSERT" );
        } break;
        case 3:{
            v3->strValue = "customer";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"SELECT" );
        } break;
        case 4:{
            v3->strValue = "customer_test";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"UPDATE" );
        } break;
        case 5:{
            v3->strValue = "customer_update";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"UPDATE" );
        } break;
        case 6:{
            v3->strValue = "customer";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"SELECT" );
        } break;
        case 7:{
            v3->strValue = "customer_test";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"DELETE" );
        } break;
        case 8:{
            v3->strValue = "customer_delete";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"DELETE" );
        } break;
        case 9:{
            v3->strValue = "customer_test";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"INSERT" );
        } break;
        case 10:{
            v3->strValue = "customer";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"SELECT" );
        } break;
        case 11:{
            v3->strValue = "customer_a";
            res.insert(std::make_pair("database",v1));
            res.insert(std::make_pair("schema",v2));
            res.insert(std::make_pair("table",v3));
            res.insert(std::make_pair("server",v4));
            query_pc_test( res ,"SELECT" );
        } break;
    }
    return EMDB_BQ_SUCCESS;
}
 */