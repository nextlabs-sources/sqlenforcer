#pragma once

#include <sys/types.h>
#include <iostream>

#include "Task.h"

#ifdef _WIN32
#include "dirent.h"
#else
#include <dirent.h>
#endif

class CEMDBFileIter :public IFileIter
{
public:
	CEMDBFileIter(const char* cPath);
	~CEMDBFileIter();
	virtual bool next() ;
	virtual const char *get_file_name() ;
	virtual const char *get_file_content() ;

	static std::string get_file_content(const std::string & path);

	bool Opened() {
		return m_dir != NULL;
	};
	void clear();
private:
	std::string m_path;
	DIR* m_dir;
	dirent * m_file;//describe file name

	std::string m_curFileName;
	std::string m_curFileContent;

};

