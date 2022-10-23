#include "EMDBFileIter.h"
#include "Utility.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


CEMDBFileIter::CEMDBFileIter(const char* cPath):m_path(cPath), m_dir(NULL), m_file(NULL)
{
	m_dir = opendir(cPath);
}

CEMDBFileIter::~CEMDBFileIter()
{
	if (m_dir)
	{
		closedir(m_dir);
	}
}

bool CEMDBFileIter::next()
{
	if (m_dir)
	{
		if ((m_file = readdir(m_dir)) != NULL)
		{
			char* find = strstr(m_file->d_name, ".json");
			if (NULL == find||
				strcmp(find, ".json") != 0)
			{
				return next();
			}
			
			string strFilePath = m_path + "/" + m_file->d_name;

			
			m_curFileName = m_file->d_name;

			m_curFileContent = get_file_content(strFilePath);

			return true;
		}
	}
	
	return false;
}

const char * CEMDBFileIter::get_file_name()
{
	return m_curFileName.c_str();
}

const char * CEMDBFileIter::get_file_content()
{
	return	m_curFileContent.c_str();
}


std::string CEMDBFileIter::get_file_content(const std::string & path )
{
    std::fstream file(path);

    if (!file) {
        throw runtime_error("Can not read file: " + path);
    }

    std::string content = Utility::readFstream(file);
    Utility::removeUTF8BOM(content);
	
	return content;
}

void CEMDBFileIter::clear()
{
	if (m_dir)
	{
		closedir(m_dir);
		m_dir = NULL;
	}
}
