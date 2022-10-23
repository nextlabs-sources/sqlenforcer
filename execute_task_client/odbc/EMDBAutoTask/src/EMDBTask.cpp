#include "../include/EMDBTask.h"
#include "../include/EMDBFileIter.h"
#include <json/json.h>
#include "../include/nanodbc.h"
#include "../include/nanodbc_nxl.h"
#include <condition_variable>
#include <list>
#include "../include/microtest.h"
#include "sql.h"
#include "../include/ConfigManager.h"

#ifndef SQL_TINYINT
#define SQL_TINYINT -6
#endif // !SQL_TINYINT
#ifndef SQL_BIGINT
#define SQL_BIGINT -5
#endif // !SQL_BIGINT

CEMDBTask::CEMDBTask()
{
}


CEMDBTask::~CEMDBTask()
{
	for (auto caction : m_vecAction)
	{
		if (caction)
		{
			delete caction;
		}
	}
	m_vecAction.clear();
	
}

bool CEMDBTask::do_prepare()
{
	//drop and create table
	try {
        auto connstr =  NANODBC_TEXT(m_taskPrepare.strConnect);
        auto sql = NANODBC_TEXT(m_taskPrepare.strSql);
        ORIGINAL::nanodbc::connection conn(connstr);
        auto result = ORIGINAL::nanodbc::execute(conn, sql);
	}
	catch (ORIGINAL::nanodbc::database_error const& e) {
		mt::printFailed(e.what());
		return false;
	}

	return true;
}

unsigned int CEMDBTask::get_action_count()
{
	return m_vecAction.size();
}

std::shared_ptr<IResultSet> CEMDBTask::execute_by_index(unsigned int index)
{
	if (m_vecAction.size()<= index)
	{
		return NULL;
	}
	Task_Action * pAction = m_vecAction[index];
	if (NULL == pAction)
	{
		return NULL;
	}

	auto pRet = std::make_shared<CEMDBResultSet>();
	//execute action at index from list
	auto cnn_str_ = pAction->connect;
    auto sql_ = pAction->sql;

	try {
        NXL::nanodbc::connection conn(cnn_str_);
		NXL::nanodbc::result results = NXL::nanodbc::execute(conn, sql_);

        pRet->Push_Ret(1);
        short columns = results.columns();

        // https://github.com/nanodbc/nanodbc/issues/113
        if (columns == 0)
        {
            return pRet;
        }

		NXL::nanodbc::string const null_value = NANODBC_TEXT("null");
		for (short col = 0; col < columns; ++col) {
			NXL::nanodbc::string colname = results.column_name(col);
			pRet->Push_Header(colname);
		}

		while (results.next()) {
			Act_recordVec * vec = new Act_recordVec(); 
			for (short col = 0; col < columns; ++col) {
				if (results.is_null(col))
				{
					vec->push_back(new Act_record_Null());
					continue;
				}
				int itype = results.column_datatype(col);
				switch (itype)
				{
				case SQL_BIGINT:
				case SQL_INTEGER:
				case SQL_SMALLINT:
				case SQL_TINYINT:
					{
					int value = results.get<int>(col, 0);
					Act_record_I* record = new Act_record_I(value);
					vec->push_back(record);
					}
					break;
				case SQL_NUMERIC:
				case SQL_DECIMAL:
				case SQL_FLOAT:
				case SQL_REAL:
				case SQL_DOUBLE:
					{
					double value = results.get<double>(col, 0.0);
					Act_record_D* record = new Act_record_D(value);
					vec->push_back(record);
					}
					break;
				default: {
					NXL::nanodbc::string value = results.get<NXL::nanodbc::string>(col, null_value);
					Act_record_S* record = new Act_record_S(value);
					vec->push_back(record);
					}
					break;
				}
				
			}
			pRet->Push_Record(vec);
		}
		
	}
	catch (NXL::nanodbc::database_error const& e) {
        mt::printFailed(e.what());
        mt::printFailed(("Connect String: " + cnn_str_).c_str());
		return pRet;
	}


	return pRet;
}

IResultSet * CEMDBTask::get_expect_result_set_by_index(unsigned int index)
{
	return &(m_vecAction[index]->result);
}

const char * CEMDBTask::get_task_name()
{
	return m_strTaskName.c_str();
}

void CEMDBTask::set_name(const char* strname)
{
	m_strTaskName = strname;
}

void CEMDBTask::set_value(const char* strvalue)
{
	m_strValue = strvalue;
}

void CEMDBTask::set_sqlpath(const char* value)
{
	m_strSqlPath = value;
}

void CEMDBTask::parse()
{
	Json::Reader reader;
	Json::Value root;
	if (reader.parse(m_strValue, root))
	{
		std::string upload_id = root["TASK_DESCRIPTION"].asString();
		Json::Value jsPREPARE = root["PREPARE"];
		if (jsPREPARE.isNull())
		{
			return ;
		}
		else
		{
		    string connect_str_name = jsPREPARE["ODBC_CONNECT_STR"].asString();
			m_taskPrepare.strConnect = ConfigManager::getConnStr(connect_str_name);
			std::string strTemp = m_strSqlPath + "/"+ jsPREPARE["SQL_PATH"].asString();
			m_taskPrepare.strSql = CEMDBFileIter::get_file_content(strTemp.c_str());
		}

		//action array
		Json::Value jsACTIONS = root["ACTION"];
		if (jsACTIONS.isNull())
		{
			return;
		}
		int iactionsize = jsACTIONS.size();
		for (int i = 0; i < iactionsize; ++i)
		{
			Task_Action * pAction = new Task_Action();
			//action
			Json::Value jsACTION = jsACTIONS[i];
			string connect_str_name = jsACTION["ODBC_CONNECT_STR"].asString();
			pAction->connect = ConfigManager::getConnStr(connect_str_name);
			std::string strTemp = m_strSqlPath + "/" + jsACTION["SQL_PATH"].asString();
			pAction->sql = CEMDBFileIter::get_file_content(strTemp.c_str());
			Json::Value jsRet = jsACTION["EXPECT_RET"];
			if (!jsRet.isNull())
			{
				int ret = jsRet["RETURN"].asInt();
				pAction->result.Push_Ret(ret);
				Json::Value jsResult = jsRet["RESULT_SET"];

				if (!jsResult.isNull())
				{
					int isize = jsResult["PROPERTIES"].size();
					for (int j = 0; j < isize; ++j)
					{
						pAction->result.Push_Header(jsResult["PROPERTIES"][j].asString());
					}


					isize = jsResult["records"].size();
					for (int j = 0; j < isize; ++j)
					{
						Act_recordVec * vec = new Act_recordVec();
						int len = jsResult["records"][j].size();
						for (int k = 0; k < len; ++k)
						{
							Json::Value jsvalue = jsResult["records"][j][k];
							if (jsvalue.isNull())
							{
								vec->push_back(new Act_record_Null());
							}
//							Do not use jsvalue.isDouble(), because it do not run as we thought.
//							It will return true when the type is intValue, uintValue and realValue
							else if (jsvalue.type() == Json::realValue)
                            {
                                Act_record_D * pR = new Act_record_D(jsvalue.asDouble());
                                vec->push_back(pR);
                            }
//							Do not use jsvalue.isInt() for the same reason before
                            else if(jsvalue.type() == Json::intValue || jsvalue.type() == Json::uintValue)
							{
								Act_record_I * pR = new Act_record_I(jsvalue.asInt());
								vec->push_back(pR);
							}
							else if (jsvalue.isString())
							{
								Act_record_S * pR = new Act_record_S(jsvalue.asString());
								vec->push_back(pR);
							}
						}
						pAction->result.Push_Record(vec);
					}

				}
			}
			m_vecAction.push_back(pAction);
		}
	}
}

bool CEMDBTask::check()
{
	if (m_taskPrepare.strConnect.empty())
	{
		return false;
	}
	if (m_taskPrepare.strSql.empty())
	{
		return false;
	}
	int iSize = m_vecAction.size();
	if (iSize == 0)
	{
		return false;
	}
	for (int i = 0 ; i < iSize; ++i)
	{
		if (m_vecAction[i]->connect.empty())
		{
			return false;
		}
		if (m_vecAction[i]->sql.empty())
		{
			return false;
		}
	}
	return true;
}

void CEMDBTask::clear()
{
	for (auto caction : m_vecAction)
	{
		if (caction)
		{
			delete caction;
		}
	}
	m_vecAction.clear();
}
