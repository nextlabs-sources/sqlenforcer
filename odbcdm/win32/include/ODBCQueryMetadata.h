#ifndef ODBCQUERYMETADATA_H
#define ODBCQUERYMETADATA_H
#include <string>
#include <vector>
#include "EMDBType.h"
#include "enforcerwrapper.h"
class ODBCQueryMetadata {
public:
    virtual ~ODBCQueryMetadata(){

    }
    ODBCQueryMetadata(void* conn, EMDB_DB_TYPE dbtype):_conn(conn),_dbtype(dbtype){

    }
public:
    bool SetDBType(EMDB_DB_TYPE tp){ _dbtype = tp;}
    bool QueryMetadataFunc(const std::string & table, MetadataVec & vecmeta);
private:
    void * _conn;
    EMDB_DB_TYPE _dbtype;
};


#endif