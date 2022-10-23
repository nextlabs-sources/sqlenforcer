#include "usercontextinfo.h"
#include "userattrwrapper.h"
#include "policymgrwrapper.h"
#include "DAELog.h"
#include "table_metadata_cache_manager.h"
//#define DAEFORORACLE_20220111

UserContextInfo::UserContextInfo(const char* szUserName, const char* szPwd):
CEMDBHandle(HANDLE_USERCONTEXTINFO),
m_strUserName(szUserName),
m_strPwd(szPwd),
m_pUserAttr(nullptr)
{
   m_emdbtype  = EMDB_DB_TYPE::EMDB_DB_UNKNOW;
   //EncryptPwd();   
}

UserContextInfo::~UserContextInfo() { /*delete(m_pUserAttr); //m_pUserAttr managed by userattribute module*/
    for (auto it : _map_tb2matadata) {
        delete(it.second);
    }
    _map_tb2matadata.clear();
}

bool UserContextInfo::InitUserAttr(SqlException * pExc)
{
    if(UserAttrWrapper::Instance()->GetUserAttr){
        m_pUserAttr = UserAttrWrapper::Instance()->GetUserAttr(m_strUserName.c_str(), pExc);
    }

    return (nullptr==m_pUserAttr)?false:true;
}


void UserContextInfo::SetDBServer(const char* szServer)
{
    if (!CommonFun::CaseInsensitiveEquals(m_strDBServer, szServer))
    {
        m_strDBServer = szServer;
        theLog->WriteLog(log_info, "set current server name:%s", m_strDBServer.c_str() );
    }
}

void UserContextInfo::SetCurrentDB(const char* szDB)
{
    if (!CommonFun::CaseInsensitiveEquals(m_strCurrentDB, szDB))
    {
        m_strCurrentDB = szDB;
        theLog->WriteLog(log_info, "set current database:%s",  m_strCurrentDB.c_str() );
    }
}

void UserContextInfo::SetSchema(const char* szSchema)
{
    if (!CommonFun::CaseInsensitiveEquals(m_strSchema, szSchema))
    {
        m_strSchema = szSchema;
        theLog->WriteLog(log_info, "set current schema :%s",  m_strSchema.c_str() );
    }
}

void UserContextInfo::SetClientAppName(const char* szClientAppName)
{
    if (!CommonFun::CaseInsensitiveEquals(m_client_app_name, szClientAppName))
    {
        m_client_app_name = szClientAppName;
        theLog->WriteLog(log_info, "set Current app name: %s", m_client_app_name.c_str());
    }
}

void UserContextInfo::SetClientHostName(const char* szClientHostName)
{
    if (!CommonFun::CaseInsensitiveEquals(m_client_host_name, szClientHostName))
    {
        m_client_host_name = szClientHostName;
        theLog->WriteLog(log_info, "set current host name: %s", m_client_host_name.c_str());
    }
}

void UserContextInfo::SetClientIp(const char* szClientIp)
{
    if (!CommonFun::CaseInsensitiveEquals(m_client_ip, szClientIp))
    {
        m_client_ip = szClientIp;
        theLog->WriteLog(log_info, "set current client ip: %s", m_client_ip.c_str());
    }
}

void UserContextInfo::SetEMDBType(EMDB_DB_TYPE type){
    if (m_emdbtype != type)
    {
        m_emdbtype = type;
        theLog->WriteLog(log_info, "set current dbtype :%d (1 MSSQL,2 ORACLE,3 HANA,4 MySQL,5 BigQuery,6 DB2,7 PostgreSQL)",  (int)type);
    }
}

bool UserContextInfo::GetTableMetadata(const std::string& dbname, const std::string& schema, const std::string& table, MetadataVec& vec) {
    auto key = dbname + '.' + schema + '.' + table;

    {
        std::shared_lock<std::shared_mutex> lockReadMeta(_mutexMetadata);
        auto it = _map_tb2matadata.find(key);
        if (it != _map_tb2matadata.end())
        {
            vec = *(it->second);
            return true;
        }
    }

    if (_meta_func)
    {
        MetadataVec* ptr = new MetadataVec;
        _meta_func(key, *ptr);

        std::string log = "table: " + key + " metadata: ";
        for (const auto& it : *ptr)
        {
            log += it._col;
            log += " ";
        }
        theLog->WriteLog(log_info, log.c_str());

        if (ptr->size() > 0)
        {
            std::unique_lock<std::shared_mutex> lockWriteMeta(_mutexMetadata);
            _map_tb2matadata[key] = ptr;
            vec = *ptr;
            return true;
        }
        else
        {
            delete(ptr);
        }
    }

    return false;
}
