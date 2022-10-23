#ifndef DAE_OCI_WRAPPER_H
#define DAE_OCI_WRAPPER_H

typedef struct OCIEnv           OCIEnv;

#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <oci.h>
#include <oratypes.h>  

typedef sword  (* OCIEnvCreate_Func)(OCIEnv **envp, ub4 mode, void  *ctxp,
                void  *(*malocfp)(void  *ctxp, size_t size),
                void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                void(*mfreefp)(void  *ctxp, void  *memptr),
                size_t xtramem_sz, void  **usrmempp);

typedef sword   (*OCIInitialize_Func)   (ub4 mode, void  *ctxp, 
                 void  *(*malocfp)(void  *ctxp, size_t size),
                 void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                 void   (*mfreefp)(void  *ctxp, void  *memptr) );                

typedef sword   (*OCIEnvInit_Func) (OCIEnv **envp, ub4 mode, 
                    size_t xtramem_sz, void  **usrmempp);


typedef sword   (*OCIEnvNlsCreate_Func) (OCIEnv **envp, ub4 mode, void  *ctxp,
                 void  *(*malocfp)(void  *ctxp, size_t size),
                 void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                 void   (*mfreefp)(void  *ctxp, void  *memptr),
                 size_t xtramem_sz, void  **usrmempp,
                 ub2 charset, ub2 ncharset);

typedef sword   (*OCIFEnvCreate_Func) (OCIEnv **envp, ub4 mode, void  *ctxp,
                 void  *(*malocfp)(void  *ctxp, size_t size),
                 void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                 void   (*mfreefp)(void  *ctxp, void  *memptr),
                 size_t xtramem_sz, void  **usrmempp, void  *fupg);

typedef sword  (*OCIHandleAlloc_Func)(const void  *parenth, void  **hndlpp, const ub4 type,
	            const size_t xtramem_sz, void  **usrmempp);

typedef  sword   (*OCIHandleFree_Func)(void  *hndlp, const ub4 type);



typedef sword   (*OCIStmtPrepare_Func)(OCIStmt *stmtp, OCIError *errhp, const OraText *stmt,
	            ub4 stmt_len, ub4 language, ub4 mode);

typedef sword (*OCIStmtPrepare2_Func)(OCISvcCtx *svchp, OCIStmt **stmtp, OCIError *errhp,
	            const OraText *stmt, ub4 stmt_len, const OraText *key,
	            ub4 key_len, ub4 language, ub4 mode);

typedef sword   (*OCIStmtExecute_Func)(OCISvcCtx *svchp, OCIStmt *stmtp, OCIError *errhp,
	            ub4 iters, ub4 rowoff, const OCISnapshot *snap_in,
	            OCISnapshot *snap_out, ub4 mode);


typedef sword(*OCIServerAttach_Func)(OCIServer *srvhp, OCIError *errhp,
	            const OraText *dblink, sb4 dblink_len, ub4 mode);

typedef sword   (*OCIAttrSet_Func)(void  *trgthndlp, ub4 trghndltyp, void  *attributep,
	            ub4 size, ub4 attrtype, OCIError *errhp);

typedef sword (*OCIBindByName_Func)(OCIStmt *stmtp, OCIBind **bindp,OCIError *errhp,const OraText *placeholder,
                                    sb4 placeh_len,void *valuep,sb4 value_sz, ub2 dty, void *indp,ub2 *alenp,
                                    ub2 *rcodep,ub4 maxarr_len,ub4 *curelep,ub4  mode);
typedef sword (*OCIBindByName2_Func)(OCIStmt *stmtp,  OCIBind **bindp, OCIError *errhp, const OraText *placeholder,
                                     sb4 placeh_len,  void  *valuep,  sb8 value_sz,  ub2 dty, void  *indp,
                                     ub4 *alenp, ub2 *rcodep, ub4 maxarr_len, ub4 *curelep, ub4 mode);
typedef sword (*OCIBindByPos_Func)(OCIStmt *stmtp, OCIBind **bindp,  OCIError *errhp, ub4 position, void  *valuep, sb4 value_sz,
                                   ub2 dty,  void  *indp, ub2 *alenp, ub2 *rcodep, ub4 maxarr_len, ub4 *curelep, ub4 mode);
typedef sword (*OCIBindByPos2_Func)(OCIStmt *stmtp, OCIBind **bindp,  OCIError *errhp, ub4 position,  void  *valuep,
                                    sb8 value_sz, ub2 dty, void  *indp, ub4 *alenp, ub2 *rcodep, ub4 maxarr_len,
                                    ub4 *curelep, ub4 mode);
typedef sword (*OCIDefineByPos_Func)(OCIStmt *stmtp, OCIDefine **defnp, OCIError *errhp,ub4 position, void *valuep,sb4 value_sz,
                                     ub2 dty,void *indp, ub2 *rlenp, ub2 *rcodep,ub4 mode );

typedef sword (*OCIStmtFetch_Func)(OCIStmt     *stmtp,
                                   OCIError    *errhp,
                                   ub4         nrows,
                                   ub2         orientation,
                                   ub4         mode);
typedef sword (*OCIStmtFetch2_Func)( OCIStmt     *stmtp,
                                     OCIError    *errhp,
                                     ub4         nrows,
                                     ub2         orientation,
                                     ub4         scrollOffset,
                                     ub4         mode);
typedef sword (*OCIAttrGet_Func)(const void    *trgthndlp,
                                 ub4            trghndltyp,
                                 void          *attributep,
                                 ub4            *sizep,
                                 ub4            attrtype,
                                 OCIError       *errhp );

typedef sword   (*OCISessionBegin_Func)  (OCISvcCtx *svchp, OCIError *errhp, OCISession *usrhp,
                          ub4 credt, ub4 mode);

// typedef size_t (*OCIMultiByteStrnDisplayLength_Func)(void  *envhp, const OraText *str1,
//                                      size_t n);

typedef sword (*OCIErrorGet_Func) ( void      *hndlp, 
                  ub4        recordno,
                  OraText       *sqlstate,
                  sb4        *errcodep,
                  OraText       *bufp,
                  ub4        bufsiz,
                  ub4        type );

typedef sword   (*OCIParamGet_Func) (const void  *hndlp, ub4 htype, OCIError *errhp,
                     void  **parmdpp, ub4 pos);


typedef sword (*OCISessionEnd_Func) ( OCISvcCtx       *svchp,
                    OCIError        *errhp,
                    OCISession      *usrhp,
                    ub4             mode);
typedef sword   (*OCIServerDetach_Func)  (OCIServer *srvhp, OCIError *errhp, ub4 mode);


class DAEOCIMgrApi
{
protected:
	DAEOCIMgrApi();
	DAEOCIMgrApi(const DAEOCIMgrApi&) {}

public:
	static DAEOCIMgrApi& Instance()
	{
		static DAEOCIMgrApi odbcApi;
		return odbcApi;
	}

	bool InitApi();

public:

   static OCIEnvCreate_Func OCIEnvCreate ;
   static OCIInitialize_Func OCIInitialize ;
//   static OCIEnvInit_Func OCIEnvInit ;
   static OCIEnvNlsCreate_Func OCIEnvNlsCreate ;
//   static OCIFEnvCreate_Func  OCIFEnvCreate ;

    static OCIHandleAlloc_Func OCIHandleAlloc;
    static OCIHandleFree_Func OCIHandleFree ;
    static OCIStmtPrepare_Func  OCIStmtPrepare ;
    static OCIStmtPrepare2_Func   OCIStmtPrepare2 ;
    static OCIStmtExecute_Func OCIStmtExecute ;
    static OCIServerAttach_Func  OCIServerAttach  ;
    static OCIAttrSet_Func OCIAttrSet;

    static  OCIBindByName_Func OCIBindByName;
    static  OCIBindByName2_Func OCIBindByName2;
    static  OCIBindByPos_Func  OCIBindByPos;
    static  OCIBindByPos2_Func OCIBindByPos2;
    static  OCIDefineByPos_Func OCIDefineByPos;

    static OCIStmtFetch_Func OCIStmtFetch;
    static OCIStmtFetch2_Func OCIStmtFetch2;
    static OCIAttrGet_Func OCIAttrGet;

    static OCISessionBegin_Func OCISessionBegin;

    //static OCIMultiByteStrnDisplayLength_Func OCIMultiByteStrnDisplayLength_oci;

    static OCIErrorGet_Func OCIErrorGet;
    static OCIParamGet_Func OCIParamGet;

    static OCISessionEnd_Func OCISessionEnd;
    static OCIServerDetach_Func OCIServerDetach;

	bool m_bInit = false;

};

#ifdef _WIN32
#else
sword   OCIEnvCreate_new(OCIEnv **envp, ub4 mode, void  *ctxp,
                               void  *(*malocfp)(void  *ctxp, size_t size),
                               void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                               void(*mfreefp)(void  *ctxp, void  *memptr),
                               size_t xtramem_sz, void  **usrmempp);
//sword   OCIInitialize_new   (ub4 mode, void  *ctxp,
//                                   void  *(*malocfp)(void  *ctxp, size_t size),
//                                   void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
//                                   void   (*mfreefp)(void  *ctxp, void  *memptr) );
// sword   OCIEnvInit_new (OCIEnv **envp, ub4 mode,
//                               size_t xtramem_sz, void  **usrmempp);
sword   OCIEnvNlsCreate_new (OCIEnv **envp, ub4 mode, void  *ctxp,
                                   void  *(*malocfp)(void  *ctxp, size_t size),
                                   void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
                                   void   (*mfreefp)(void  *ctxp, void  *memptr),
                                   size_t xtramem_sz, void  **usrmempp,
                                   ub2 charset, ub2 ncharset);
// sword   OCIFEnvCreate_new (OCIEnv **envp, ub4 mode, void  *ctxp,
//                                  void  *(*malocfp)(void  *ctxp, size_t size),
//                                  void  *(*ralocfp)(void  *ctxp, void  *memptr, size_t newsize),
//                                  void   (*mfreefp)(void  *ctxp, void  *memptr),
//                                  size_t xtramem_sz, void  **usrmempp, void  *fupg);
 sword    OCIHandleAlloc_new(const void  *parenth, void  **hndlpp, const ub4 type,
                                   const size_t xtramem_sz, void  **usrmempp);
 sword    OCIHandleFree_new(void  *hndlp, const ub4 type);
 sword    OCIStmtPrepare_new(OCIStmt *stmtp, OCIError *errhp, const OraText *stmt, ub4 stmt_len, ub4 language, ub4 mode);
 sword    OCIStmtPrepare2_new(OCISvcCtx *svchp, OCIStmt **stmtp, OCIError *errhp,
                                    const OraText *stmt, ub4 stmt_len, const OraText *key,
                                    ub4 key_len, ub4 language, ub4 mode);
 sword    OCIStmtExecute_new(OCISvcCtx *svchp, OCIStmt *stmtp, OCIError *errhp,
                                   ub4 iters, ub4 rowoff, const OCISnapshot *snap_in,
                                   OCISnapshot *snap_out, ub4 mode);
 sword    OCIServerAttach_new(OCIServer *srvhp, OCIError *errhp,
                                    const OraText *dblink, sb4 dblink_len, ub4 mode);
 sword    OCIAttrSet_new(void  *trgthndlp, ub4 trghndltyp, void  *attributep,
                               ub4 size, ub4 attrtype, OCIError *errhp);
sword   OCISessionBegin_new (OCISvcCtx *svchp, OCIError *errhp, OCISession *usrhp,
                                  ub4 credt, ub4 mode);

// sword    OCIBindByName_new(OCIStmt *stmtp, OCIBind **bindp,OCIError *errhp,const OraText *placeholder,
//                                  sb4 placeh_len,void *valuep,sb4 value_sz, ub2 dty, void *indp,ub2 *alenp,
//                                  ub2 *rcodep,ub4 maxarr_len,ub4 *curelep,ub4  mode);
// sword    OCIBindByName2_new(OCIStmt *stmtp,  OCIBind **bindp, OCIError *errhp, const OraText *placeholder,
//                                   sb4 placeh_len,  void  *valuep,  sb8 value_sz,  ub2 dty, void  *indp,
//                                   ub4 *alenp, ub2 *rcodep, ub4 maxarr_len, ub4 *curelep, ub4 mode);
// sword    OCIBindByPos_new(OCIStmt *stmtp, OCIBind **bindp,  OCIError *errhp, ub4 position, void  *valuep, sb4 value_sz,
//                                 ub2 dty,  void  *indp, ub2 *alenp, ub2 *rcodep, ub4 maxarr_len, ub4 *curelep, ub4 mode);
// sword    OCIBindByPos2_new(OCIStmt *stmtp, OCIBind **bindp,  OCIError *errhp, ub4 position,  void  *valuep,
//                                  sb8 value_sz, ub2 dty, void  *indp, ub4 *alenp, ub2 *rcodep, ub4 maxarr_len,
//                                  ub4 *curelep, ub4 mode);
// sword    OCIDefineByPos_new(OCIStmt *stmtp, OCIDefine **defnp, OCIError *errhp,ub4 position, void *valuep,sb4 value_sz,
//                                   ub2 dty,void *indp, ub2 *rlenp, ub2 *rcodep,ub4 mode );
//
// sword    OCIStmtFetch_new(OCIStmt *stmtp, OCIError *errhp, ub4 nrows,ub2 orientation,ub4 mode);
// sword    OCIStmtFetch2_new( OCIStmt *stmtp, OCIError *errhp, ub4  nrows, ub2 orientation, ub4 scrollOffset, ub4 mode);
// sword    OCIAttrGet_new(const void  *trgthndlp, ub4 trghndltyp, void *attributep, ub4 *sizep, ub4 attrtype,
//                               OCIError *errhp );


#endif

#endif