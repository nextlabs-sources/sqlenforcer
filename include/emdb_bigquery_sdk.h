//
// Created by jeff on 2020/6/2.
//

#ifndef EMDB_EMDB_BIGQUERY_SDK_H
#define EMDB_EMDB_BIGQUERY_SDK_H
#ifndef WIN32
#define EMDB_BQ_API __attribute__((visibility("default")))
#else
#ifdef EMDB_SDK_EXPORT
#define EMDB_BQ_API  __declspec(dllexport)
#else
#define EMDB_BQ_API  __declspec(dllimport)
#endif //EMDB_SDK_EXPORT
#endif //WIN32

#define EMDB_BQ_Handle void*


enum EMDB_BQ_Return{ EMDB_BQ_SUCCESS, EMDB_BQ_ERROR, EMDB_BQ_INVALID_HANDLE };

enum EMDB_BQ_ResultCode{ EMDB_DENY, EMDB_DENY_SELECT, EMDB_ALLOW, EMDB_IGNORE, EMDB_FAILED };

struct EMDBUserProperty{
    const char * key;
    const char * value;
};

extern "C" {
    /* create enforcer result struct
     * param: result handle pointer
     */
    EMDB_BQ_API EMDB_BQ_Return    NewResult(EMDB_BQ_Handle * output_result ) ;
    /* free result
     * param: result handle
     */
    EMDB_BQ_API EMDB_BQ_Return    FreeResult(EMDB_BQ_Handle    result) ;
    /* emdb bigquery sql enforcer
     * param: sql(SQL statement) database(Database Name) schema(Schema name)
     *        userattrs(user properties) userattrs_size( user properties size) result(result handle)
     */
    EMDB_BQ_API EMDB_BQ_Return    EnforceSQL(const char *sql, const char * database, const char * schema, const EMDBUserProperty* userattrs, unsigned int userattrs_size, EMDB_BQ_Handle result);
    /* get result content
     * param: result handle /  out put code : DENY / ALLOW / ERROR
     */
    EMDB_BQ_API EMDB_BQ_Return    GetResultCode(EMDB_BQ_Handle  result, EMDB_BQ_ResultCode *output_code);
    /* get result content
     * param: result handle /  detail: if code is allow then param(detail) will output new sql , but  param(detail) will output error content
     */
    EMDB_BQ_API EMDB_BQ_Return    GetNewSQL(EMDB_BQ_Handle  result, const char ** sql);
    EMDB_BQ_API EMDB_BQ_Return    GetError(EMDB_BQ_Handle  result, const char ** error);
}

extern "C" {

    EMDB_BQ_API EMDB_BQ_Return    EnforceSQL_standalone(
            const char *sql, 
            const char * database, 
            const char * schema, 
            const EMDBUserProperty* userattrs, 
            unsigned int userattrs_size,
            unsigned int * ret_code, 
            char * ret_detail, 
            int detail_max);


    //EMDB_BQ_API EMDB_BQ_Return    EnforceSQL_test();
}


#endif //EMDB_EMDB_BIGQUERY_SDK_H
