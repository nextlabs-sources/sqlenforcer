//
// Created by jeff on 2021/6/16.
//
#include "DAETableMetadata.h"
#include <oci.h>
#include <oratypes.h>
#include "DAEOciWrapper.h"
#include "DAEEnforcerMgr.h"
#include <commfun.h>
#include "DAELog.h"
EMDataType get_datatype_by_name(const char* name);
void log_error_metadata(OCIError * errhp){
    OraText errbuf[512]={0};
    sb4 errcode = 0;
    DAEOCIMgrApi::OCIErrorGet((dvoid *)errhp, (ub4) 1, (OraText *) NULL, &errcode,
                errbuf, (sb4) sizeof(errbuf), OCI_HTYPE_ERROR);
    //Log::WLog(log_debug, "error detail=%s", (char*)errbuf);
    if(DAEEnforceMgr::Instance()->IsU16CharSet()){
        std::u16string err_16((char16_t*)errbuf, 256) ;
        std::string err_8;
        CommonFun::ToUTF8(err_16,err_8);
        Log::WLog(log_warning, "get table metadata failed detail=%s", err_8.c_str());
    } else{
        Log::WLog(log_warning, "get table metadata failed detail=%s", (char*)errbuf);
    }
}


EMDataType get_datatype_by_name(const char* name){

    if (0 == CommonFun::StrCaseCmp(name, "DATE"))
    {
        return EMDATA_DATE;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "TIMESTAMP"))
    {
        return EMDATA_TIMESTAMP;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "TIMESTAMP_TZ"))
    {
        return EMDATA_TIMESTAMP_TZ_ORA;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "TIMESTAMP_LTZ"))
    {
        return EMDATA_TIMESTAMP_TZ_ORA;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "REAL"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "DOUBLE"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "FLOAT"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "NUMBER"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "BFLOAT"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "BDOUBLE"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "DECIMAL"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "OCTET"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "INTEGER"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "SMALLINT"))
    {
        return EMDATA_NUMBER;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "VARCHAR2"))
    {
        return EMDATA_STRING;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "VARCHAR"))
    {
        return EMDATA_STRING;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "CHAR"))
    {
        return EMDATA_STRING;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "NCHAR"))
    {
        return EMDATA_STRING;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "NVARCHAR2"))
    {
        return EMDATA_STRING;
    }
    else if (0 == CommonFun::StrCaseCmp(name, "RAW"))
    {
        return EMDATA_STRING;
    }
    //@2020-11-11
    // else if (0 == CommonFun::StrCaseCmp(name, "CLOB"))
    // {
    //     return EMDATA_STRING;
    // }
    // else if (0 == CommonFun::StrCaseCmp(name, "BLOB"))
    // {
    //     return EMDATA_STRING;
    // }

   //Log::WLog(log_warning, "GetTypeCodeByName, typename:%s", name);

    return EMDATA_NONSUPPORT;
}

bool DAEQueryMetadata::QueryMetadataA(const std::string & tb, MetadataVec & metadata){
    if (tb.length() == 0)
    {
        return false;
    }

    std::vector<std::string> vec;
    CommonFun::SplitString(tb,".",vec);
    
    if(vec.size() != 3){
        return false;
    }

    //find in table
    if (nullptr == _cur_srvp)
    {
        return false;
    }
    OCISvcCtx *svchp = (OCISvcCtx *)_cur_srvp;
    //create sql
    std::string strSqlFmt = "SELECT COLUMN_NAME, DATA_TYPE FROM ALL_TAB_COLUMNS WHERE OWNER = '" + vec[1] + "' AND TABLE_NAME = '" + vec[2] + "' ORDER BY COLUMN_ID";

    //create statement
    const static int maxbuf = 256;
    char *pcolname = new char[maxbuf]; // use static to reuse the buf. avoid new/delete it
    char *pcoltype = new char[maxbuf];
    OCIError *errhp = NULL;
    OCIStmt *pStmt = NULL;
    do
    {
        sword sv = DAEOCIMgrApi::OCIHandleAlloc((dvoid *)_cur_envp, (dvoid **)&errhp, OCI_HTYPE_ERROR, (size_t)0, (dvoid **)0);
        if (sv != OCI_SUCCESS )
        {
            Log::WLog(log_warning, "create_table_metadata, createStatement  failed rv=%d", sv);
            break;
        }

        //       sv = DAEOCIMgrApi::OCIHandleAlloc((dvoid *)_cur_envp,  (void **)&pStmt, OCI_HTYPE_STMT, 0, (void **)0);
        // if (sv != OCI_SUCCESS || NULL == pStmt)
        // {
        //    Log::WLog(log_debug, "create_table_metadata, createStatement  failed rv=%d", sv);
        //     break;
        // }

        std::string u8SQL = strSqlFmt;
        //std::u16string u16SQL = CommonFun::FromUTF8(u8SQL);
        //sv = DAEOCIMgrApi::OCIStmtPrepare(pStmt, errhp, (const text *)u16SQL.c_str(), (ub4)((u16SQL.length() + 1) * sizeof(char16_t)), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
        sv = DAEOCIMgrApi::OCIStmtPrepare2(svchp,&pStmt, errhp, (const text *)u8SQL.c_str(), (ub4)((u8SQL.length() + 1) * sizeof(char)),nullptr,0, (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
        if (sv != OCI_SUCCESS)
        {
            log_error_metadata(errhp);
            break;
        }

        //define
        ub2 nameLen = 0;
        ub2 dataTypeLen = 0;
        {
            OCIDefine *defnp = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp, errhp, 1, (dvoid *)pcolname, maxbuf, SQLT_STR,
                                             (dvoid *)0, (ub2 *)&nameLen, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
        }
        {
            OCIDefine *defnp = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp, errhp, 2, (dvoid *)pcoltype, maxbuf, SQLT_STR,
                                             (dvoid *)0, (ub2 *)&dataTypeLen, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                Log::WLog(log_warning, "create_table_metadata, OCIDefineByPos failed, pos=%d, rv=%d", 2, sv);
                break;
            }
        }

        // execute and fetch
        sv = DAEOCIMgrApi::OCIStmtExecute(svchp, pStmt, errhp, (ub4)1, (ub4)0, (CONST OCISnapshot *)NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
        if (sv != OCI_SUCCESS)
        {
            log_error_metadata(errhp);
            //theLog->WriteLog(log_info, "create_table_metadata, OCIStmtExecute failed,  rv=%d, errcode=%d, msg=%s", sv, errcode, u8Msg.c_str());
            break;
        }

        //get result
        if (sv != OCI_NO_DATA)
        {
            //metadata
            do
            {
                Metadata item;
                item._col = pcolname;
                item._type = get_datatype_by_name(pcoltype);
                metadata.push_back(item);

                // if (EMDATA_NONSUPPORT == item._type)
                // {
                //     break;
                // }

            } while (DAEOCIMgrApi::OCIStmtFetch(pStmt, errhp, 1, 0, 0) == OCI_SUCCESS);
        }

    } while (false);

    //clear
    if(pStmt){
        DAEOCIMgrApi::OCIHandleFree(pStmt, OCI_HTYPE_STMT);
        pStmt = NULL;
    }
    if(errhp){
        DAEOCIMgrApi::OCIHandleFree(errhp, OCI_HTYPE_ERROR);
        errhp = NULL;
    }
    delete[] pcolname;
    delete[] pcoltype;

    //insert into manager
    if(metadata.size() <= 0) {
        return  false;
    }

    return true;
}
bool DAEQueryMetadata::QueryMetadataW(const std::string & tb, MetadataVec & metadata){
    if (tb.length() == 0)
    {
        return false;
    }

    std::vector<std::string> vec;
    CommonFun::SplitString(tb,".",vec);
    
    if(vec.size() != 3){
        return false;
    }

    //find in table
    if (nullptr == _cur_srvp)
    {
        return false;
    }
    OCISvcCtx *svchp = (OCISvcCtx *)_cur_srvp;
    //create sql
    std::string strSqlFmt = "SELECT COLUMN_NAME, DATA_TYPE FROM ALL_TAB_COLUMNS WHERE OWNER = '" + vec[1] + "' AND TABLE_NAME = '" + vec[2] + "' ORDER BY COLUMN_ID";
    
    //printf("metadata sql:%s\n",szSql);
    //create statement
    const static int maxbuf = 256;
    char16_t *pcolname = new char16_t[maxbuf]; // use static to reuse the buf. avoid new/delete it
    char16_t *pcoltype = new char16_t[maxbuf];
    OCIError *errhp = NULL;
    OCIStmt *pStmt = NULL;
    do
    {
        sword sv = DAEOCIMgrApi::OCIHandleAlloc((dvoid *)_cur_envp, (dvoid **)&errhp, OCI_HTYPE_ERROR, (size_t)0, (dvoid **)0);
        if (sv != OCI_SUCCESS )
        {
            Log::WLog(log_warning, "create_table_metadata, createStatement  failed rv=%d", sv);
            break;
        }

        std::string u8SQL = strSqlFmt;
        std::u16string u16_sql_new;
        CommonFun::FromUTF8(u8SQL, u16_sql_new);
        const OraText *stmtTxt = (const OraText *)u16_sql_new.c_str();
        uint32_t stmt_l = u16_sql_new.length() * 2;
        sv = DAEOCIMgrApi::OCIStmtPrepare2(svchp,&pStmt, errhp,stmtTxt, stmt_l,nullptr,0, (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT);
        if (sv != OCI_SUCCESS)
        {
            log_error_metadata(errhp);
            break;
        }

        //define
        ub2 nameLen = 0;
        ub2 dataTypeLen = 0;
        {
            OCIDefine *defnp = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp, errhp, 1, (dvoid *)pcolname, maxbuf, SQLT_STR,
                                             (dvoid *)0, (ub2 *)&nameLen, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                break;
            }
        }
        {
            OCIDefine *defnp = NULL;
            sv = DAEOCIMgrApi::OCIDefineByPos(pStmt, &defnp, errhp, 2, (dvoid *)pcoltype, maxbuf, SQLT_STR,
                                             (dvoid *)0, (ub2 *)&dataTypeLen, (ub2 *)0, OCI_DEFAULT);
            if (sv != OCI_SUCCESS)
            {
                Log::WLog(log_warning, "create_table_metadata, OCIDefineByPos failed, pos=%d, rv=%d", 2, sv);
                break;
            }
        }

        // execute and fetch
        sv = DAEOCIMgrApi::OCIStmtExecute(svchp, pStmt, errhp, (ub4)1, (ub4)0, (CONST OCISnapshot *)NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
        if (sv != OCI_SUCCESS)
        {
            log_error_metadata(errhp);
            //theLog->WriteLog(log_info, "create_table_metadata, OCIStmtExecute failed,  rv=%d, errcode=%d, msg=%s", sv, errcode, u8Msg.c_str());
            break;
        }

        //get result
        if (sv != OCI_NO_DATA)
        {
            //metadata
            do
            {
                Metadata item;
                CommonFun::ToUTF8(std::u16string(pcolname), item._col) ;
                std::string strtype;
                CommonFun::ToUTF8(std::u16string(pcoltype), strtype);
                item._type = get_datatype_by_name(strtype.c_str());
                metadata.push_back(item);

                if (EMDATA_NONSUPPORT == item._type)
                {
                    break;
                }

            } while (DAEOCIMgrApi::OCIStmtFetch(pStmt, errhp, 1, 0, 0) == OCI_SUCCESS);
        }

    } while (false);

    //clear
    if(pStmt){
        DAEOCIMgrApi::OCIHandleFree(pStmt, OCI_HTYPE_STMT);
        pStmt = NULL;
    }
    if(errhp){
        DAEOCIMgrApi::OCIHandleFree(errhp, OCI_HTYPE_ERROR);
        errhp = NULL;
    }
    delete[] pcolname;
    delete[] pcoltype;

    //insert into manager
    if(metadata.size() <= 0) {
        return  false;
    }

    return true; 
}