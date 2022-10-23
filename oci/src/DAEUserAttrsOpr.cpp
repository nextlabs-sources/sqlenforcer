//
// Created by jeff on 2021/6/22.
//

#include "DAEUserAttrsOpr.h"
#include "DAELog.h"
#include <fstream>
#include <map>
#include <commfun.h>
#include <EMDBConfig.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oci.h>
#include "DAEOciWrapper.h"

void get_connect_str(std::string & server, std::string & user, std::string & pwd, std::string & user_info);
void checkerr(OCIError *errhp, sword  status);
int QueryUserAttrsFromDB(const std::string & username, std::map<std::string,std::string> & userattrs);


void DAEUserAttrsOpr::QueryUserAttrs(const std::string & username, std::map<std::string,std::string> & userattrs){
#ifdef HARD_CODE
#ifdef _WIN32
    std::ifstream t("C:\\ProgramData\\Nextlabs\\DAEforWin\\Config\\userattr.txt");
#else
    std::ifstream t("/usr/nextlabs/daeforlinux/config/userattr.txt");
#endif

    std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    int i = 0;
    int size = str.length();
    std::string line;
    while(i < size){
        if(str[i] == '\n' || str[i] == '\r'  ){
            if(line.length()>2){
                size_t  ifind = line.find('=');
                if(ifind != std::string::npos){
                    std::string key = line.substr(0,ifind);
                    std::string val = line.substr(ifind+1);
                    userattrs[key]=val;
                }

            }
            line.clear();
        } else {
            line+=str[i];
        }
        i++;
    }
#else
    //
    QueryUserAttrsFromDB(username,userattrs);
#endif
}

int QueryUserAttrsFromDB(const std::string & username, std::map<std::string,std::string> & userattrs) {
    // static text *maxemp = (text *) "SELECT * from guest.customer4";
    if(1 != static_cast<int>(EMDBConfig::GetInstance().get_usermode_mode())){
        return 0;
    }
    static OCIError *errhp;
    static OCIEnv *envhp;

    std::string  server;
    std::string  user;
    std::string  pwd;
    std::string  user_info;
    get_connect_str( server,  user, pwd, user_info);
    if(server.empty() || user.empty() || pwd.empty()){
        Log::WLog(log_error, "[USERMODE.oci_conn_string] is incorrect in config.ini.");
    }
    size_t  ifinddot = user_info.rfind(".");
    if(ifinddot== std::string::npos){
        return 0;
    }
    std::string tb,col;
    tb = user_info.substr(0,ifinddot);
    col = user_info.substr(ifinddot+1);
    //std::string user_name = "GUEST";
    std::string sql = "SELECT * FROM " +tb+ " WHERE "+col+"='"+username+"' ";
    const char * csql = sql.c_str();
    Log::WLog(log_debug, " DAEUserAttrs sql=%s",csql);
    const char *host =  server.c_str();
    const char  *cusername =  user.c_str();
    const char  *password =  pwd.c_str();

    OCIServer *srvhp;
    OCISvcCtx *svchp;
    OCISession *authp = (OCISession *) 0;
    OCIStmt *stmthp;

    sword err = 0;
    err = DAEOCIMgrApi::OCIEnvNlsCreate ((OCIEnv **) &envhp, (ub4) OCI_DEFAULT, (dvoid *) 0,
                           (dvoid *(*)(dvoid *, size_t)) 0,
                           (dvoid *(*)(dvoid *, dvoid *, size_t)) 0,
                           (void (*)(dvoid *, dvoid *)) 0,
                           (size_t) 0, (dvoid **) 0,
                           0, 0);

    if (err != OCI_SUCCESS && err != OCI_SUCCESS_WITH_INFO) {
        //(void) printf("OCIEnvCreate failed with err = %d.\n", err);
        Log::WLog(log_debug, "DAEUserAttrs OCIEnvNlsCreate failed.");
        return  1;
    }

    err =  DAEOCIMgrApi::OCIHandleAlloc((dvoid *) envhp, (dvoid **) &errhp, OCI_HTYPE_ERROR,
                          (size_t) 0, (dvoid **) 0);
    checkerr(errhp, err);

    /* server contexts */
    err =  DAEOCIMgrApi::OCIHandleAlloc((dvoid *) envhp, (dvoid **) &srvhp, OCI_HTYPE_SERVER,
                          (size_t) 0, (dvoid **) 0);
    checkerr(errhp, err);

    err =  DAEOCIMgrApi::OCIHandleAlloc((dvoid *) envhp, (dvoid **) &svchp, OCI_HTYPE_SVCCTX,
                          (size_t) 0, (dvoid **) 0);
    checkerr(errhp, err);

    err =  DAEOCIMgrApi::OCIServerAttach(srvhp, errhp, (const OraText *)host, strlen((char *) host), 0);
    checkerr(errhp, err);

    /* set attribute server context in the service context */
    err =  DAEOCIMgrApi::OCIAttrSet((dvoid *) svchp, OCI_HTYPE_SVCCTX, (dvoid *) srvhp,
                      (ub4) 0, OCI_ATTR_SERVER, (OCIError *) errhp);
    checkerr(errhp, err);

    err =  DAEOCIMgrApi::OCIHandleAlloc((dvoid *) envhp, (dvoid **) &authp,
                          (ub4) OCI_HTYPE_SESSION, (size_t) 0, (dvoid **) 0);
    checkerr(errhp, err);

    err =  DAEOCIMgrApi::OCIAttrSet((dvoid *) authp, (ub4) OCI_HTYPE_SESSION,
                      (dvoid *) cusername, (ub4) strlen((char *) cusername),
                      (ub4) OCI_ATTR_USERNAME, errhp);
    checkerr(errhp, err);

    err =  DAEOCIMgrApi::OCIAttrSet((dvoid *) authp, (ub4) OCI_HTYPE_SESSION,
                      (dvoid *) password, (ub4) strlen((char *) password),
                      (ub4) OCI_ATTR_PASSWORD, errhp);
    checkerr(errhp, err);

    err = DAEOCIMgrApi::OCISessionBegin(svchp, errhp, authp, OCI_CRED_RDBMS,
                          (ub4) OCI_DEFAULT);
    checkerr(errhp, err);
    //

    err =  DAEOCIMgrApi::OCIAttrSet((dvoid *) svchp, (ub4) OCI_HTYPE_SVCCTX,
                      (dvoid *) authp, (ub4) 0,
                      (ub4) OCI_ATTR_SESSION, errhp);
    checkerr(errhp, err);

    err =  DAEOCIMgrApi::OCIHandleAlloc((dvoid *) envhp, (dvoid **) &stmthp,
                          OCI_HTYPE_STMT, (size_t) 0, (dvoid **) 0);
    checkerr(errhp, err);
//    err =  OCIHandleAlloc( (dvoid *) envhp, (dvoid **) &stmthp1,
//                                OCI_HTYPE_STMT, (size_t) 0, (dvoid **) 0);

    /* Retrieve the current maximum employee number. */
    err = DAEOCIMgrApi::OCIStmtPrepare(stmthp, errhp, (const OraText *)csql,
                         (ub4) strlen((char *) csql),
                         (ub4) OCI_NTV_SYNTAX, (ub4) OCI_DEFAULT);
    if (err != OCI_SUCCESS && err != OCI_SUCCESS_WITH_INFO) if (err != OCI_SUCCESS && err != OCI_SUCCESS_WITH_INFO) 
    {
        DAEOCIMgrApi::OCIHandleFree((dvoid *) authp, OCI_HTYPE_SESSION);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) envhp, OCI_HTYPE_ENV);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) stmthp, OCI_HTYPE_STMT);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) srvhp, OCI_HTYPE_SERVER);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) svchp, OCI_HTYPE_SVCCTX);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) errhp, OCI_HTYPE_ERROR);
        Log::WLog(log_warning, "get user attributes from db failed in oci! sql is error.");
        return 0;
    }

    {
        OCIDefine *defnp = (OCIDefine *) 0;
        sword    empno;
        sb2 indp = 0;
        checkerr(errhp, DAEOCIMgrApi::OCIDefineByPos(stmthp, &defnp, errhp, 1, (dvoid *) &empno,
                                       (sword) sizeof(sword), SQLT_INT, (dvoid *) &indp, (ub2 *)0,
                                       (ub2 *)0, OCI_DEFAULT));
    }

    /* execute and fetch */
    err = DAEOCIMgrApi::OCIStmtExecute(svchp, stmthp, errhp, (ub4) 1, (ub4) 0,
                         (CONST OCISnapshot *) NULL, (OCISnapshot *) NULL, OCI_DEFAULT);
    //if (err != OCI_SUCCESS && err != OCI_SUCCESS_WITH_INFO) printf("OCIStmtExecute err = %d.\n", err);

    checkerr(errhp,err);
    if (err != OCI_SUCCESS && err != OCI_SUCCESS_WITH_INFO) {
        DAEOCIMgrApi::OCIHandleFree((dvoid *) authp, OCI_HTYPE_SESSION);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) envhp, OCI_HTYPE_ENV);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) stmthp, OCI_HTYPE_STMT);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) srvhp, OCI_HTYPE_SERVER);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) svchp, OCI_HTYPE_SVCCTX);
        DAEOCIMgrApi::OCIHandleFree((dvoid *) errhp, OCI_HTYPE_ERROR);
        Log::WLog(log_error, "get user attributes from db failed in oci! execute sql error.");
        return 0;
    }

    sword paramcnt = 0;
    checkerr(errhp, DAEOCIMgrApi::OCIAttrGet((CONST dvoid *)stmthp, (ub4)OCI_HTYPE_STMT,
                               (void *)&paramcnt, (ub4 *)0,
                               (ub4) OCI_ATTR_PARAM_COUNT, errhp));

    std::map<std::string,char*> map_val;
    //fprintf(stdout, "Number of columns in query is %d\n",paramcnt);
    sb2 indp = 0;
    for (int i=1; i<=paramcnt; i++)
    {
        void * paramhp;
        checkerr(errhp, DAEOCIMgrApi::OCIParamGet((dvoid *)stmthp, (ub4)OCI_HTYPE_STMT,
                                    (OCIError *)errhp, (dvoid **)&paramhp,
                                    (ub4)i));

        text *col_name;
        ub4 col_name_len;
        checkerr(errhp, DAEOCIMgrApi::OCIAttrGet((dvoid *)paramhp,
                                   (ub4)OCI_DTYPE_PARAM, (dvoid *)&col_name,(ub4 *)&col_name_len,
                                   (ub4) OCI_ATTR_NAME, errhp));
//        checkerr(errhp, OCIAttrGet((dvoid *)paramhp,
//                                   (ub4)OCI_DTYPE_PARAM, (dvoid *)&type,(ub4 *)0,
//                                   (ub4) OCI_ATTR_DATA_TYPE, errhp));
//        checkerr(errhp, OCIAttrGet((dvoid *)paramhp,
//                                   (ub4)OCI_DTYPE_PARAM, (dvoid *)&size,(ub4 *)0,
//                                   (ub4) OCI_ATTR_DATA_SIZE, errhp));

        const static int maxbuf = 256;
        char * val2 = new char[maxbuf];
        ub2 len = 0;
        OCIDefine *defnp3 = NULL;
        err = DAEOCIMgrApi::OCIDefineByPos(stmthp, &defnp3, errhp, i, (dvoid *)val2, maxbuf, SQLT_STR,
                             (dvoid *)&indp, (ub2 *)&len, (ub2 *)0, OCI_DEFAULT);
        

        map_val[std::string((char*)col_name, (size_t)col_name_len)]=val2;
    }

    err = DAEOCIMgrApi::OCIStmtExecute(svchp, stmthp, errhp, (ub4) 1, (ub4) 0,
                         (CONST OCISnapshot *) NULL, (OCISnapshot *) NULL, OCI_DEFAULT);
    checkerr(errhp,err);

    if (NULL != DAEOCIMgrApi::OCIServerDetach ){
        err =  DAEOCIMgrApi::OCIServerDetach(srvhp, errhp, (ub4)OCI_DEFAULT);
        checkerr(errhp, err);
    }

    if (NULL != DAEOCIMgrApi::OCISessionEnd   ){
        err = DAEOCIMgrApi::OCISessionEnd(svchp, errhp, authp, (ub4)0);
        checkerr(errhp, err);
    }

    if(authp)
        DAEOCIMgrApi::OCIHandleFree((dvoid *) authp, OCI_HTYPE_SESSION);
    if(stmthp)
        DAEOCIMgrApi::OCIHandleFree((dvoid *) stmthp, OCI_HTYPE_STMT);
    if(srvhp)
        DAEOCIMgrApi::OCIHandleFree((dvoid *) srvhp, OCI_HTYPE_SERVER);
    if(svchp)
        DAEOCIMgrApi::OCIHandleFree((dvoid *) svchp, OCI_HTYPE_SVCCTX);
    if(errhp)
        DAEOCIMgrApi::OCIHandleFree((dvoid *) errhp, OCI_HTYPE_ERROR);
    if(envhp)
        DAEOCIMgrApi::OCIHandleFree((dvoid *) envhp, OCI_HTYPE_ENV);
    

   
    
    if (err != OCI_SUCCESS && err != OCI_SUCCESS_WITH_INFO) {
        for(auto & it:  map_val){delete(it.second);}
        Log::WLog(log_error, "get user attributes from db failed in oci! execute sql error.");
        return 0;
    }

    for(auto & it:  map_val){
        userattrs.insert(std::make_pair(it.first,std::string(it.second)));
        delete(it.second);
    }
    map_val.clear();

    return 0;
}


void checkerr(OCIError *errhp, sword  status)
{
    text errbuf[512];
    sb4 errcode = 0;

    switch (status)
    {
        case OCI_SUCCESS:
            break;
        case OCI_SUCCESS_WITH_INFO:
            Log::WLog(log_warning, "DAEUserAttrs OCI_SUCCESS_WITH_INFO");
            //(void) printf("Error - OCI_SUCCESS_WITH_INFO\n");
            break;
        case OCI_NEED_DATA:
            Log::WLog(log_warning, "DAEUserAttrs OCI_NEED_DATA");
            //(void) printf("Error - OCI_NEED_DATA\n");
            break;
        case OCI_NO_DATA:
            Log::WLog(log_warning, "DAEUserAttrs OCI_NEED_DATA");
            break;
        case OCI_ERROR:
            (void) DAEOCIMgrApi::OCIErrorGet((dvoid *)errhp, (ub4) 1, (text *) NULL, &errcode,
                               errbuf, (ub4) sizeof(errbuf), OCI_HTYPE_ERROR);
           // (void) printf("Error - %.*s\n", 512, errbuf);
            Log::WLog(log_warning, "DAEUserAttrs %s", errbuf);
            break;
        case OCI_INVALID_HANDLE:
            Log::WLog(log_warning, "DAEUserAttrs OCI_INVALID_HANDLE");
           // (void) printf("Error - OCI_INVALID_HANDLE\n");
            break;
        case OCI_STILL_EXECUTING:
            Log::WLog(log_warning, "DAEUserAttrs OCI_STILL_EXECUTE");
            //(void) printf("Error - OCI_STILL_EXECUTE\n");
            break;
        case OCI_CONTINUE:
            Log::WLog(log_warning, "DAEUserAttrs OCI_CONTINUE");
           // (void) printf("Error - OCI_CONTINUE\n");
            break;
        default:
            break;
    }
}

// std::string read_ini_value(const std::string & key, const std::string & str){
//     std::string ifind1str = key + "=" ;
//     std::string strtemp = str;
//     std::string str3;
//     do{
//         size_t ifind2 = strtemp.find(ifind1str);
//         if(ifind2<= 0){
//             //log
//             return "";
//         }
//         char c =  strtemp[ifind2-1];
//         if( c != '\n' && c != '\r'){
//             strtemp = strtemp.substr(ifind2+ifind1str.length());
//             continue;
//         }
//         str3 = strtemp.substr(ifind2+ifind1str.length());
//         break;
//     }while(1);

//     std::string strval ;
//     size_t pos = 0;
//     while(pos < str3.length()){
//         if(str3[pos] == '\0'
//            ||str3[pos] == '\n'
//            ||str3[pos] == '\r'
//            ||str3[pos] == '\t'
//            ||str3[pos] == ' '){
//             break;
//         }
//         strval += str3[pos];
//         pos++;
//     }
//     return strval;
// }

void get_connect_str(std::string & server, std::string & user, std::string & pwd, std::string & user_info){

    //Usermode mode = EMDBConfig::GetInstance().get_usermode_mode();

    std::string conn_str = EMDBConfig::GetInstance().get_usermode_oci_conn_string();
    if(conn_str.empty()){
        return;
    }

    user_info = EMDBConfig::GetInstance().get_usermode_user_info();
    if(user_info.empty()){
        return;
    }

    //
    std::vector<std::string> keyvel;
    CommonFun::SplitString(conn_str, ";", keyvel);
    for(auto & it: keyvel){
        std::vector<std::string> namevel;
        CommonFun::SplitString(it, "=", namevel);
        if(namevel.size() == 2){
            if(namevel[0] == "server"){
                server = namevel[1];
            } else if(namevel[0] == "user") {
                user = namevel[1];
            } else if(namevel[0] == "password") {
                pwd = namevel[1];
            }
        }
    }
    //

    return;
}


