#include <cstring>

#include "../include/EMDBTask.h"
#include "../include/EMDBFileIter.h"



ITask * make_task(const char *json_task, const char*name, const char*sqlpath)
{
	CEMDBTask* pTask = new CEMDBTask();
	pTask->set_name(name);
	pTask->set_value(json_task);
	pTask->set_sqlpath(sqlpath);
	pTask->parse();
	if ( !pTask->check() )
	{
		delete pTask;
		pTask = NULL;
	}

	return pTask;
}

void free_task(ITask *pT)
{
	if (pT)
	{
		((CEMDBTask *)pT)->clear();
	}

}

std::shared_ptr<IFileIter> make_file_iter(const char *directory_name)
{
	if (NULL == directory_name && strlen(directory_name) == 0)
	{
		return NULL;
	}

	auto pRet = std::make_shared<CEMDBFileIter>(directory_name);

	if (!pRet->Opened())
	{
	    pRet = NULL;
	}

	return pRet;
}

void free_file_iter(IFileIter * file)
{
	if (file) {
		((CEMDBFileIter*)file)->clear();
	}
}
