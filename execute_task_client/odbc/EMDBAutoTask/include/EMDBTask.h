#pragma once
#include "Task.h"
#include "EMDBResultSet.h"
#include <iostream>  
#include <vector> 
struct  TASK_Prepare
{
	std::string strConnect;
	std::string strSql;
};

struct Task_Action
{
	std::string connect;
	std::string sql;
	CEMDBResultSet result;
};
typedef std::vector<Task_Action*> Task_ActionVec;


class CEMDBTask :
	public ITask
{
public:
	CEMDBTask();
	~CEMDBTask();

	virtual bool do_prepare();
	virtual unsigned int get_action_count();
	virtual std::shared_ptr<IResultSet> execute_by_index(unsigned int);
	virtual IResultSet *get_expect_result_set_by_index(unsigned int);
	virtual const char *get_task_name();

	
	void set_name(const char* name) ;
	void set_value(const char* value);
	void set_sqlpath(const char* value);

	void parse();
	bool check();
	void clear();
private:
	std::string m_strTaskName;
	std::string m_strValue;
	std::string m_strSqlPath;

	TASK_Prepare m_taskPrepare;
	Task_ActionVec m_vecAction;

};
