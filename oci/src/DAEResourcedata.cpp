//
// Created by jeff on 2021/6/24.
//
#include "stdafx.h"
#include "DAEResourcedata.h"
#include <oci.h>
#include <oratypes.h>
#include "DAEOciWrapper.h"
#include "DAELog.h"
#include <commfun.h>
#include "DAEEnforcerMgr.h"

void printOCIError(OCIError *errhp,sword retcode){
    // if(retcode != -1){
    //     Log::WLog(log_debug, "error detail=retcode=%d", retcode);
    // }
    OraText errbuf[512]={0};
    sb4 errcode = 0;
    DAEOCIMgrApi::OCIErrorGet((dvoid *)errhp, (ub4) 1, (OraText *) NULL, &errcode,
                errbuf, (sb4) sizeof(errbuf), OCI_HTYPE_ERROR);
    //Log::WLog(log_debug, "error detail=%s", (char*)errbuf);
    if(DAEEnforceMgr::Instance()->IsU16CharSet()){
        std::u16string err_16((char16_t*)errbuf, 256) ;
        std::string err_8;
        CommonFun::ToUTF8(err_16,err_8);
        Log::WLog(log_warning, " detail=%s", err_8.c_str());
    } else{
        Log::WLog(log_warning, " detail=%s", (char*)errbuf);
    }

}

bool DAEResourcedata::QueryResourcedataA(){

    if (nullptr == _cur_srvp || nullptr == _cur_envp)
    {
        return false;
    }
    OCISvcCtx *srchp = (OCISvcCtx *)_cur_srvp;
    //create sql
    const std::string strSqlFmt = "SELECT (SELECT USERNAME FROM USER_USERS)  username,"
                                   " SYS_CONTEXT('USERENV','CURRENT_SCHEMA')  schemaname,"
                                   " INSTANCE_NAME  dbname,"
                                   " HOST_NAME  servername from v$instance"; //
    Log::WLog(log_debug, "--QueryResourcedata sql =%s",strSqlFmt.c_str()); 

    //create statement

    OCIError *errhp = NULL;
    OCIStmt *pStmt = NULL;
    const static int maxbuf = 256;
    char *cuser = new char[maxbuf]; // use static to reuse the buf. avoid new/delete it
    char *cschema = new char[maxbuf];
    char *cdb = new char[maxbuf];
    char *cserver = new char[maxbuf];
    do
    {

        sword sv = DAEOCIMgrApi::OCIHandleAlloc((dvoid *)_cur_envp, (dvoid **)&errhp, OCI_HTYPE_ERROR, (size_t)0, (dvoid **)0);
        if (sv != OCI_SUCCESS )
        {
            Log::WLog(log_debug, "QueryResourcedata, OCIHandleAlloc  failed rv=%d env=%d", sv, (uint64_t)_cur_envp);
            break;
        }

    //    sv = DAEOCIMgrApi::OCIHandleAlloc((dvoid *)_cur_envp,  (void **)&pStmt, OCI_HTYPE_STMT, 0, (void **)0);
    //    if (sv != OCI_SUCCESS || NULL == pStmt)
    //    {
    //        Log::WLog(log_debug, "QueryResourcedata, OCIHandleAlloc  failed rv=%d", sv);
    //        break;
    //    }

        std::string u8SQL = strSqlFmt;
        sv = DAEOCIMgrApi::OCIStmtPrepare2(srchp, &pStmt, errhp, (const text *)u8SQL.c_str(), (ub4)((u8SQL.length() + 1) * sizeof(char)),nullptr,0, (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);


        if (sv != OCI_SUCCESS)
        {
            //Log::WLog(log_warning, "QueryResourcedata, OCIStmtPrepare failed rv=%d", sv);
            //printOCIError(errhp,sv);
            break;
        }
        //define
        ub2 plen1 = 0;
        ub2 plen2 = 0;
        ub2 plen3 = 0;
        ub2 plen4 = 0;

        {
            OCIDefine *defnp1 = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp1, errhp, 1, (dvoid *)cuser, maxbuf, SQLT_STR,
                                              (dvoid *)0, (ub2 *)&plen1, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
            OCIDefine *defnp2 = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp2, errhp, 2, (dvoid *)cschema, maxbuf, SQLT_STR,
                                              (dvoid *)0, (ub2 *)&plen2, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
            OCIDefine *defnp3 = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp3, errhp, 3, (dvoid *)cdb, maxbuf, SQLT_STR,
                                              (dvoid *)0, (ub2 *)&plen3, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
            OCIDefine *defnp4 = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp4, errhp, 4, (dvoid *)cserver, maxbuf, SQLT_STR,
                                              (dvoid *)0, (ub2 *)&plen4, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
        }

        // execute and fetch
        sv = DAEOCIMgrApi::OCIStmtExecute(srchp, pStmt, errhp, (ub4)1, (ub4)0, (CONST OCISnapshot *)NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
        if (sv != OCI_SUCCESS)
        {
            Log::WLog(log_warning, "query resourcedata OCIStmtExecute failed ,code=%d", int(sv));
            printOCIError(errhp,sv);
            break;
        }

        //get result
        if (sv != OCI_NO_DATA)
        {
            //metadata
            do
            {
                _user = cuser;
                _schema = cschema;
                _db = cdb;
                _server = cserver;
            } while (DAEOCIMgrApi::OCIStmtFetch(pStmt, errhp, 1, 0, 0) == OCI_SUCCESS);
        }

    } while (false);

    if(errhp){
        DAEOCIMgrApi::OCIHandleFree(errhp, OCI_HTYPE_ERROR);
        errhp = NULL;
    }
    delete[] cuser;
    delete[] cschema;
    delete[] cdb;
    delete[] cserver;

    //insert into manager
    if(_user.empty()) {
        return  false;
    }
    return true;
}

bool DAEResourcedata::QueryResourcedataW(){

    if (nullptr == _cur_srvp || nullptr == _cur_envp)
    {
        return false;
    }
    OCISvcCtx *srchp = (OCISvcCtx *)_cur_srvp;
    //create sql
    const std::string strSqlFmt = "SELECT (SELECT USERNAME FROM USER_USERS)  username,"
                                   " SYS_CONTEXT('USERENV','CURRENT_SCHEMA')  schemaname,"
                                   " INSTANCE_NAME  dbname,"
                                   " HOST_NAME  servername from v$instance"; //
    Log::WLog(log_debug, "--QueryResourcedata sql =%s",strSqlFmt.c_str()); 

    //create statement

    OCIError *errhp = NULL;
    OCIStmt *pStmt = NULL;
    const static int maxbuf = 256;
    char16_t *cuser = new char16_t[maxbuf]; // use static to reuse the buf. avoid new/delete it
    char16_t *cschema = new char16_t[maxbuf];
    char16_t *cdb = new char16_t[maxbuf];
    char16_t *cserver = new char16_t[maxbuf];
    do
    {

        sword sv = DAEOCIMgrApi::OCIHandleAlloc((dvoid *)_cur_envp, (dvoid **)&errhp, OCI_HTYPE_ERROR, (size_t)0, (dvoid **)0);
        if (sv != OCI_SUCCESS )
        {
            Log::WLog(log_debug, "QueryResourcedata, OCIHandleAlloc  failed rv=%d", sv);
            break;
        }

//    sv = DAEOCIMgrApi::OCIHandleAlloc((dvoid *)_cur_envp,  (void **)&pStmt, OCI_HTYPE_STMT, 0, (void **)0);
//    if (sv != OCI_SUCCESS || NULL == pStmt)
//    {
//        Log::WLog(log_debug, "QueryResourcedata, OCIHandleAlloc  failed rv=%d", sv);
//        break;
//    }

        std::u16string u16_sql_new;
        CommonFun::FromUTF8(strSqlFmt, u16_sql_new);
        const OraText *stmtTxt = (const OraText *)u16_sql_new.c_str();
        uint32_t stmt_l = u16_sql_new.length() * 2;
        sv = DAEOCIMgrApi::OCIStmtPrepare2(srchp, &pStmt, errhp, stmtTxt, stmt_l,nullptr,0, (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
        //sv = DAEOCIMgrApi::OCIStmtPrepare(pStmt, errhp, stmtTxt, stmt_l, (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);

        if (sv != OCI_SUCCESS)
        {
            // Log::WLog(log_warning, "QueryResourcedata, OCIStmtPrepare failed rv=%d", sv);
            // printOCIError(errhp,sv);
            break;
        }
        //define
        ub2 plen1 = 0;
        ub2 plen2 = 0;
        ub2 plen3 = 0;
        ub2 plen4 = 0;

        {
            OCIDefine *defnp1 = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp1, errhp, 1, (dvoid *)cuser, maxbuf, SQLT_STR,
                                              (dvoid *)0, (ub2 *)&plen1, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
            OCIDefine *defnp2 = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp2, errhp, 2, (dvoid *)cschema, maxbuf, SQLT_STR,
                                              (dvoid *)0, (ub2 *)&plen2, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
            OCIDefine *defnp3 = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp3, errhp, 3, (dvoid *)cdb, maxbuf, SQLT_STR,
                                              (dvoid *)0, (ub2 *)&plen3, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
            OCIDefine *defnp4 = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp4, errhp, 4, (dvoid *)cserver, maxbuf, SQLT_STR,
                                              (dvoid *)0, (ub2 *)&plen4, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
        }

        // execute and fetch
        sv = DAEOCIMgrApi::OCIStmtExecute(srchp, pStmt, errhp, (ub4)1, (ub4)0, (CONST OCISnapshot *)NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
        if (sv != OCI_SUCCESS)
        {
            Log::WLog(log_warning, "query resourcedata OCIStmtExecute failed ,code=%d", int(sv));
            printOCIError(errhp,sv);
            break;
        }

        //get result
        if (sv != OCI_NO_DATA)
        {
            //metadata
            do
            {
                CommonFun::ToUTF8(std::u16string(cuser), _user) ;
                CommonFun::ToUTF8(std::u16string(cschema), _schema) ;
                CommonFun::ToUTF8(std::u16string(cdb), _db) ;
                CommonFun::ToUTF8(std::u16string(cserver), _server) ;

            } while (DAEOCIMgrApi::OCIStmtFetch(pStmt, errhp, 1, 0, 0) == OCI_SUCCESS);
        }

    } while (false);

    if(errhp){
        DAEOCIMgrApi::OCIHandleFree(errhp, OCI_HTYPE_ERROR);
        errhp = NULL;
    }
    delete[] cuser;
    delete[] cschema;
    delete[] cdb;
    delete[] cserver;

    //insert into manager
    if(_user.empty()) {
        return  false;
    }
    return true;
}