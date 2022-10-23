
#include "DAEOciWrapper.h"
#include "DAEEnforcerWrapper.h"
#include "DAELog.h"
#include "SqlException.h"
#include "DAEEnforcerMgr.h"
#include <map>
#include <vector>
#include <assert.h>
#include "oci.h"
#include <commfun.h>

//static std::vector<uint64_t> _vec_nxl; // for OCIStmtPrepare

#ifdef _WIN32


#define  OCIHandleAlloc_DAE OCIHandleAlloc
#define  OCIHandleFree_DAE OCIHandleFree
#define  OCIStmtPrepare2_DAE OCIStmtPrepare2
#define  OCIStmtExecute_DAE OCIStmtExecute
#define  OCIServerAttach_DAE OCIServerAttach
#define  OCIAttrSet_DAE OCIAttrSet
#define  OCIStmtPrepare_DAE OCIStmtPrepare
#define  OCISessionBegin_DAE OCISessionBegin
#define  OCIEnvCreate_DAE OCIEnvCreate
#define  OCIInitialize_DAE OCIInitialize
#define  OCIEnvNlsCreate_DAE OCIEnvNlsCreate
#else

#define  OCIHandleAlloc_DAE OCIHandleAlloc_new
#define  OCIHandleFree_DAE OCIHandleFree_new
#define  OCIStmtPrepare_DAE OCIStmtPrepare_new
#define  OCIStmtPrepare2_DAE OCIStmtPrepare2_new
#define  OCIStmtExecute_DAE OCIStmtExecute_new
#define  OCIServerAttach_DAE OCIServerAttach_new
#define  OCIAttrSet_DAE OCIAttrSet_new
#define  OCISessionBegin_DAE OCISessionBegin_new
#define  OCIEnvCreate_DAE OCIEnvCreate_new
#define  OCIInitialize_DAE OCIInitialize_new
#define  OCIEnvNlsCreate_DAE OCIEnvNlsCreate_new

//OCIBindByName_new
//OCIBindByName2_new
//OCIBindByPos_new
//OCIBindByPos2_new
//OCIDefineByPos_new
//OCIStmtFetch_new
//OCIStmtFetch2_new
//OCIAttrGet_new

#endif

/*
sword   OCIEnvInit (OCIEnv **envp, ub4 mode, 
                    size_t xtramem_sz, void  **usrmempp)
{
    Log::WLog(log_debug, "--OCIEnvInit");
    {
        SqlException exc;
        bool bret = InitalizeEnforcer(&exc);
        assert(bret);
    }
        if(DAEOCIMgrApi::Instance().OCIEnvInit){
            return DAEOCIMgrApi::Instance().OCIEnvInit(envp,  mode, 
            xtramem_sz, usrmempp);
        } 

        return -1;

}

*/

sword   OCIInitialize_DAE   (ub4 mode, void  *ctxp, 
                 void  *(*malocfp)(void  *ctxp, size_t size),
                 void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                 void   (*mfreefp)(void  *ctxp, void  *memptr) )
{
    Log::WLog(log_debug, "--OCIInitialize mode=%u", (uint64_t)mode);
        if(DAEOCIMgrApi::OCIInitialize){
            return DAEOCIMgrApi::OCIInitialize( mode, ctxp,
                malocfp,
                ralocfp,
                mfreefp);
        } 

        return -1;

}

const std::string PowerBIProcessName = "Microsoft.Mashup.Container.NetFX45.exe";
const std::string OdbcProcessName = "odbcad32.exe";

std::string get_current_processname()
{
    char szFilePath[MAX_PATH];
    ::GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
    std::string filePath = szFilePath;
    auto found = filePath.rfind("\\");
    auto processName = filePath.substr(found + 1);

    return processName;
}

sword   OCIEnvCreate_DAE (OCIEnv **envp, ub4 mode, void  *ctxp,
                 void  *(*malocfp)(void  *ctxp, size_t size),
                 void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                 void   (*mfreefp)(void  *ctxp, void  *memptr),
                 size_t xtramem_sz, void  **usrmempp)
{
    Log::WLog(log_debug, "--OCIEnvCreate mode=%u", (uint64_t)mode);
    DAEEnforceMgr::Instance()->SetCharSet( (mode&OCI_UTF16)?OCI_UTF16ID:0 );//set charset
    if(DAEOCIMgrApi::Instance().OCIEnvCreate){
        sword ret =  DAEOCIMgrApi::Instance().OCIEnvCreate(envp, mode, ctxp,
        malocfp,
        ralocfp,
        mfreefp,
        xtramem_sz, usrmempp);
        std::string name = get_current_processname();
        Log::WLog(log_debug, "--OCIEnvCreate processname=%s", name.c_str());
        if((uint64_t)mode == 16387 && (name.compare(PowerBIProcessName) == 0 || name.compare(OdbcProcessName) == 0)){
            Log::WLog(log_debug, "-----------OCIEnvCreate  ODBC deny");
            DAEEnforceMgr::Instance()->InsertODBCEnvp((uint64_t)*envp);
        } else {
            SqlException exc;
            bool bret = DAEEnforceMgr::Instance()->InitalizeEnforcer(&exc);
            Log::WLog(log_debug, exc.cdetail.c_str());
        }
        //assert(bret);
        Log::WLog(log_debug, "--OCIEnvCreate envp=%u", (uint64_t)*envp);
        DAEEnforceMgr::Instance()->SetEnvHandle((void*)*envp);
        return ret;
    } 
    return -1;
}



//---------power bi called this
sword   OCIEnvNlsCreate_DAE (OCIEnv **envp, ub4 mode, void  *ctxp,
                 void  *(*malocfp)(void  *ctxp, size_t size),
                 void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                 void   (*mfreefp)(void  *ctxp, void  *memptr),
                 size_t xtramem_sz, void  **usrmempp,
                 ub2 charset, ub2 ncharset)
{
    Log::WLog(log_debug, "--OCIEnvNlsCreate mode=%u, charset=%u, ncharset=%u", (uint64_t)mode,charset,ncharset);
    DAEEnforceMgr::Instance()->SetCharSet((uint64_t)charset);//set charset
    if(DAEOCIMgrApi::OCIEnvNlsCreate){
        sword ret =  DAEOCIMgrApi::OCIEnvNlsCreate( envp,mode, ctxp,
            malocfp,
            ralocfp,
            mfreefp,
            xtramem_sz,usrmempp,
            charset,ncharset);
        std::string name = get_current_processname();
        if((uint64_t)mode == 16777223 && name.compare(PowerBIProcessName) == 0){
            DAEEnforceMgr::Instance()->InsertODBCEnvp((uint64_t)(*envp));
            Log::WLog(log_debug, "-----OCIEnvNlsCreate  ODBC deny");
        } else {
            SqlException exc;
            bool bret = DAEEnforceMgr::Instance()->InitalizeEnforcer(&exc);
            Log::WLog(log_debug, exc.cdetail.c_str());
        }

        //assert(bret);
        DAEEnforceMgr::Instance()->SetEnvHandle((void*)*envp);
        return ret;
    } 

    return -1;

}
/*
sword   OCIFEnvCreate (OCIEnv **envp, ub4 mode, void  *ctxp,
                 void  *(*malocfp)(void  *ctxp, size_t size),
                 void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                 void   (*mfreefp)(void  *ctxp, void  *memptr),
                 size_t xtramem_sz, void  **usrmempp, void  *fupg)
{
    Log::WLog(log_debug, "--OCIFEnvCreate");
        if(DAEOCIMgrApi::Instance().OCIFEnvCreate){
            return DAEOCIMgrApi::Instance().OCIFEnvCreate( envp, mode, ctxp,
            malocfp,
            ralocfp,
            mfreefp,
            xtramem_sz, usrmempp, fupg);
        } 

        return -1;

}

*/

sword OCIHandleAlloc_DAE(const void  *parenth, void  **hndlpp, const ub4 type, const size_t xtramem_sz, void  **usrmempp) {
     Log::WLog(log_debug, "--OCIHandleAlloc type=%u parenth=%u",(int)type ,(uint64_t)parenth);
	if (DAEOCIMgrApi::OCIHandleAlloc) {
		//theLog.WriteLog(1, L"ENTER OCIHandleAlloc_ori type=%d", type);
		
		sword ret = DAEOCIMgrApi::OCIHandleAlloc(parenth, hndlpp, type, xtramem_sz, usrmempp);
        if (OCI_HTYPE_STMT == type) {
			DAEEnforceMgr::Instance()->InsertStmt2DaeOciEnv((uint64_t)*hndlpp, (uint64_t)parenth);
		} else if (OCI_HTYPE_SVCCTX == type) {
            DAEEnforceMgr::Instance()->InsertSvcp2DaeOciEnv((uint64_t)*hndlpp, (uint64_t)parenth);
		} else if( OCI_HTYPE_SERVER == type) {
           if(  DAEEnforceMgr::Instance()->IsODBCEnvp((uint64_t)parenth) ){
                DAEEnforceMgr::Instance()->InsertODBCSrvp(uint64_t(*hndlpp));
                Log::WLog(log_debug, "-----InsertODBCSrvp envp=%u srv=%u",(uint64_t)parenth, uint64_t(*hndlpp));
           }
        } 
        //Log::WLog(log_debug, "--OCIHandleAlloc end type=%u  val=%u", (int)type ,uint64_t(*hndlpp));
        return ret;
	}
	Log::WLog(1, "OCIHandleAlloc_ori is NULL");
	return 0;
}

sword   OCIHandleFree_DAE(void  *hndlp, const ub4 type) {
    Log::WLog(log_debug, "--OCIHandleFree");
	if (DAEOCIMgrApi::OCIHandleFree) {
        DAEEnforceMgr::Instance()->ClearHandle(hndlp,type);
		return DAEOCIMgrApi::OCIHandleFree(hndlp, type);
	}
	return 0;
}


sword   OCIStmtPrepare_DAE(OCIStmt *stmtp, OCIError *errhp, const OraText *stmt, 	ub4 stmt_len, ub4 language, ub4 mode) {
    Log::WLog(log_debug, "--OCISmtPrepare mode=%u stmt=%u",mode,(uint64_t)stmtp);
    sword  ret_value = 0;
	if (DAEOCIMgrApi::OCIStmtPrepare) {
		//theLog.WriteLog(1, L"ENTER OCIStmtPrepare2_ori");

        std::string sql_old;
        if(DAEEnforceMgr::Instance()->IsU16CharSet()){
            std::u16string sql_16((char16_t*)stmt, stmt_len/2) ;
            CommonFun::ToUTF8(sql_16,sql_old);
        } else {
            sql_old = std::string((char*)stmt, stmt_len);
        }
        
        //Log::WLog(log_debug, "--OCISmtPrepare sql8 =%s",sql_old.c_str()); 

        //const text *stmt_ori = stmt;
        bool deny = false;
        std::string sql_new = sql_old;
        //Log::WLog(log_debug, "--OCISmtPrepare sql_new length =%d",sql_new.length()); 
        //Log::WLog(log_debug, "sql_old:%s",stmt_ori);
        uint64_t svcp = DAEEnforceMgr::Instance()->GetSvcpFromDaeOciEnv((uint64_t)stmtp);
        Log::WLog(log_debug, "-----GetSvcpFromDaeOciEnv stmt=%u svcp=%u",(uint64_t)stmtp,svcp);
		if(DAEEnforceMgr::Instance()->EvaluationSql(sql_new,deny, sql_old, (void*)svcp)){
            //Log::WLog(log_debug, "dae_sql_new:%s",sql_new.c_str());

            if(DAEEnforceMgr::Instance()->IsU16CharSet()){
                std::u16string u16_sql_new;
                CommonFun::FromUTF8(sql_new, u16_sql_new);
                const OraText *stmtTxt = (const OraText *)u16_sql_new.c_str();
                uint32_t stmt_l = u16_sql_new.length() * 2;
                ret_value = DAEOCIMgrApi::OCIStmtPrepare( stmtp, errhp, stmtTxt, (ub4)(stmt_l),  language, mode);
            } else {
                ret_value = DAEOCIMgrApi::OCIStmtPrepare( stmtp, errhp, (const text*)(sql_new.c_str()), (ub4)(sql_new.length()),  language, mode);
            }
		} else {
            ret_value = DAEOCIMgrApi::OCIStmtPrepare( stmtp, errhp, stmt, stmt_len,  language, mode);
		}
        DAEEnforceMgr::Instance()->UpdateDenyMap(stmtp, deny);
		return ret_value;
	}

    return DAEOCIMgrApi::OCIStmtPrepare(stmtp, errhp, stmt, stmt_len, language, mode);

}


sword OCIStmtPrepare2_DAE(OCISvcCtx *svchp, OCIStmt **stmtp, OCIError *errhp, 	const OraText *stmt, ub4 stmt_len, const OraText *key, 	ub4 key_len, ub4 language, ub4 mode) {

    Log::WLog(log_debug, "--OCIStmtPrepare2 mode=%u svchp=%u",mode,(uint64_t)svchp);
    sword  ret_value = 0;
	if (DAEOCIMgrApi::OCIStmtPrepare2) {
		//theLog.WriteLog(1, L"ENTER OCIStmtPrepare2_ori");

        //const text *stmt_ori = stmt;
        bool deny = false;
        std::string sql_old;
        if(DAEEnforceMgr::Instance()->IsU16CharSet()){
            std::u16string sql_16((char16_t*)stmt, stmt_len/2) ;
            CommonFun::ToUTF8(sql_16,sql_old);
        } else {
            sql_old = std::string((char*)stmt, stmt_len);
        }
        std::string sql_new = sql_old;
        //Log::WLog(log_debug, "sql_old:%s",stmt_ori);
		if(DAEEnforceMgr::Instance()->EvaluationSql(sql_new,deny, sql_old, svchp)){
            //Log::WLog(log_debug, "dae_sql_new:%s",sql_new.c_str());

            if(DAEEnforceMgr::Instance()->IsU16CharSet()){
                std::u16string u16_sql_new;
                CommonFun::FromUTF8(sql_new, u16_sql_new);
                const OraText *stmtTxt = (const OraText *)u16_sql_new.c_str();
                uint32_t stmt_l = u16_sql_new.length() * 2;
                ret_value = DAEOCIMgrApi::OCIStmtPrepare2( svchp,stmtp, errhp, stmtTxt, (ub4)(stmt_l),  key, key_len,language, mode);
            } else {
                ret_value = DAEOCIMgrApi::OCIStmtPrepare2( svchp,stmtp, errhp, (const text*)(sql_new.c_str()), (ub4)(sql_new.length()),  key, key_len,language, mode);
            }
            //ret_value = DAEOCIMgrApi::OCIStmtPrepare2(svchp, stmtp, errhp, (const text*)(sql_new.c_str()), (ub4)(sql_new.length()), key, key_len, language, mode);
		} else {
            ret_value = DAEOCIMgrApi::OCIStmtPrepare2(svchp, stmtp, errhp, stmt, stmt_len, key, key_len, language, mode);
		}
        DAEEnforceMgr::Instance()->UpdateDenyMap((void*)(*stmtp), deny);
		return ret_value;
	}
	return 0;
}

sword   OCIStmtExecute_DAE(OCISvcCtx *svchp, OCIStmt *stmtp, OCIError *errhp, ub4 iters, ub4 rowoff, const OCISnapshot *snap_in,	OCISnapshot *snap_out, ub4 mode) {
	Log::WLog(log_debug, "--OCIStmtExecute svchp = %u stmtp=%u",(uint64_t)svchp,(uint64_t)stmtp );
    if (DAEOCIMgrApi::OCIStmtExecute) {
		//theLog.WriteLog(1, L"ENTER OCIStmtExecute_ori");
		if (DAEEnforceMgr::Instance()->IsDeny(stmtp)) {
            Log::WLog(log_debug, "-----deny execute succeed!");
			return 0; // succeed deny
		}
		else {
			return DAEOCIMgrApi::OCIStmtExecute(svchp, stmtp, errhp, iters, rowoff, snap_in, snap_out, mode);
		}
	}
	return 0;
}


sword   OCIServerAttach_DAE(OCIServer *srvhp, OCIError *errhp,	const OraText *dblink, sb4 dblink_len, ub4 mode) {
	Log::WLog(log_debug, "--OCIServerAttach");
    if (DAEOCIMgrApi::OCIServerAttach) {
//		const text *db = dblink;
//		std::string c_str_db((const char*)db, dblink_len);
       // Log::WLog(log_debug,"DAEOCIMgrApi::OCIServerAttach");
       if(DAEEnforceMgr::Instance()->IsODBCSrvp((uint64_t)srvhp)){
           Log::WLog(log_debug, "-----IsODBCSrvp  %u", (uint64_t)srvhp);
        } else {
            DAEEnforceMgr::Instance()->NewEnforcerCtx(srvhp);
        }
        
		return DAEOCIMgrApi::OCIServerAttach(srvhp, errhp, dblink, dblink_len, mode);
	}
	return 0;
}


sword   OCIAttrSet_DAE(void  *trgthndlp, ub4 trghndltyp, void  *attributep,
	ub4 size, ub4 attrtype, OCIError *errhp) {
    
	if (DAEOCIMgrApi::OCIAttrSet) {
		sword ret =  DAEOCIMgrApi::OCIAttrSet(trgthndlp, trghndltyp, attributep, size, attrtype, errhp);
        if (OCI_HTYPE_SVCCTX == trghndltyp && OCI_ATTR_SERVER == attrtype) {
            Log::WLog(log_debug, "--OCIAttrSet sethandle tyep=%u, attr type=%u", (uint64_t)trghndltyp, (uint64_t)attrtype);
            DAEEnforceMgr::Instance()->BindServerHandle((void*)trgthndlp, (void*)attributep);
        } else if(OCI_HTYPE_SVCCTX == trghndltyp && OCI_ATTR_SESSION == attrtype){
            Log::WLog(log_debug, "--OCIAttrSet sethandle tyep=%u, attr type=%u", (uint64_t)trghndltyp, (uint64_t)attrtype);
            DAEEnforceMgr::Instance()->SetEnforcerCtxAttr((void*)trgthndlp);
        } else if(OCI_HTYPE_ENV == trghndltyp && OCI_ATTR_CHARSET_ID == attrtype){
            Log::WLog(log_debug, "--OCIAttrSet sethandle tyep=%u, attr type=%u", (uint64_t)trghndltyp, (uint64_t)attrtype);
            DAEEnforceMgr::Instance()->SetCharSet((uint64_t)attributep);
        }
        return  ret;
	}
	return 0;
}

sword   OCISessionBegin_DAE (OCISvcCtx *svchp, OCIError *errhp, OCISession *usrhp,
                             ub4 credt, ub4 mode){
    Log::WLog(log_debug, "--OCISessionBegin %u, %u",(uint64_t)credt, (uint64_t)mode);
    //
    if (DAEOCIMgrApi::OCISessionBegin) {
        sword ret = DAEOCIMgrApi::OCISessionBegin (svchp, errhp, usrhp, credt,  mode);
        if(ret == OCI_SUCCESS){
            //
            DAEEnforceMgr::Instance()->SetEnforcerCtxAttr(svchp);
        }
        return ret;
    }
    return 0;
}


