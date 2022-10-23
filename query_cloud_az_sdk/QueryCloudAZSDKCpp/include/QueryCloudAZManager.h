#ifndef QUERY_CLOUDAZ_MANAGER_H
#define QUERY_CLOUDAZ_MANAGER_H

#include "QueryCloudAZManager.h"
#include "ConnectionPool.h"
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/mutex.hpp>

enum
{
	CELOG_EMERG = 0,  /** Emergency */
	CELOG_ALERT = 1,  /** Alert */
	CELOG_CRIT = 2,  /** Critical */
	CELOG_ERR = 3,  /** Error */
	CELOG_WARNING = 4,  /** Warning */
	CELOG_NOTICE = 5,  /** Notice */
	CELOG_INFO = 6,  /** Info */
	CELOG_DEBUG = 7,  /** Debug */
	CELOG_MAX              /** maximum marker */
};

class QueryCloudAZMgr
{
public:
	std::function<int(int lvl, const char* logStr)> WriteLog;

protected:
	QueryCloudAZMgr();
	QueryCloudAZMgr(const QueryCloudAZMgr&) {}


public:
	static QueryCloudAZMgr* Instance()
	{
		static QueryCloudAZMgr* theMgr = NULL;
		if (theMgr==NULL)
		{
			theMgr = new QueryCloudAZMgr();
		}
		return theMgr;
	}

	//get member
public:
	const std::string& GetPCHost() { return m_strPCHost; }
	const std::string& GetPCPort() { return m_strPCPort; }
	const std::string& GetOAuthHost() { return m_strOAuthHost ; }
	const std::string& GetOAuthPort() { return m_strOAuthPort; }
	const std::string& GetClientID() { return m_strClientID; }
	const std::string& GetClientSecret() { return m_strClientSecret; }

	void GetToken(std::string& token, std::string& tokenType) {
		boost::shared_lock<boost::shared_mutex> lock(m_mutexToken);	// read lock
		token = m_Token;
		tokenType = m_TokenType;
	}
 

public:
	bool Init(const char* wszPCHost, const char* wszPcPort,
		const char* wszOAuthServiceHost, const char* wszOAuthPort,
		const char* strClientId, const char* wszClientSecret, int nConnectionCount,
		const std::function<int(int lvl, const char* logStr)>& cb);
	QueryStatus  CheckSingleResource(const IPolicyRequest* ceRequest, IPolicyResult** pcResult);
	QueryStatus  CheckMultiResource (const IPolicyRequest** pcRequest, int nRequestCount, IPolicyResult** pcResult);
	IPolicyRequest*  CreatePolicyRequest();
	IAttributes* CreateCEAttr();

	void  FreePolicyRequest(IPolicyRequest* pRequest);
	void  FreePolicyResult(IPolicyResult* pResult);
	void  FreeCEAttr(IAttributes* pAttr);


private:
	bool RequestToken();
	//static DWORD WINAPI RefreshTokenThread(LPVOID lpParam);

private:
	bool ErrCheck(CloudAZConnection* pConn, QueryStatus qs);

private:
	std::string m_strPCHost;
	std::string m_strPCPort;
	std::string m_strOAuthHost;
	std::string m_strOAuthPort;
	std::string m_strClientID;
	std::string m_strClientSecret;

	ConnctionPool m_connPool;

	std::string m_Token;
	std::string m_TokenType;
	int m_nTokenExpier;
	boost::shared_mutex m_mutexToken;

	static const int MaxTryTimes = 4;
};


#endif


