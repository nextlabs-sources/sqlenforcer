#include "../include/microtest.h"
#include "../include/Task.h"
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stdexcept>

#include "../include/ConfigManager.h"
#include "../include/Utility.h"

#ifdef _WIN32
#define FILE_PATH_SEPERATOR '\\'
#else
#define FILE_PATH_SEPERATOR '/'
#endif

std::string strTaskPath;
std::string strTaskFolder;
std::string strOutPath;

void RunOne();
void RunAuto();

TEST(SQL_AUTO_RUN) {
	auto& args = mt::Runtime::args();

    if (args.size() == 1)
    {
        Utility::showMenu();

        try {
			std::string connConfigPath = Utility::getConnStrConfigPath();
			ConfigManager::init(connConfigPath);
        }
        catch (std::exception &s)
        {
            std::string err = s.what();
            mt::printFailed(err.c_str());
            return;
        }

        const string conn_str = ConfigManager::getConnStr("default");

        string input;

        while (true)
        {
            std::cout << std::endl;
            std::cout << "Please input menu command, SQL or the absolute path of the SQL file:" << std::endl;

            getline(std::cin, input);

            if ("QUIT" == input || "Q" == input)
            {
                return;
            }
            else
            {
                try {
                    const string sql = Utility::getSqlStatement(input);
                    auto results = Utility::getSQLResults(conn_str, sql);
                    Utility::showSQLResults(results);
                }
                catch (std::runtime_error &e)
                {
                    mt::printFailed(e.what());
                }
            }
        }
    }
	else if (args.size() == 2) {

		strTaskFolder = args[1];
		if (strTaskFolder.empty())
		{
			return;
		}

        try {
            ConfigManager::init(strTaskFolder + "/config/connectStr_config.json");
        }
        catch (std::exception &s)
        {
            std::string err = s.what();
            mt::printFailed(err.c_str());
            return;
        }

		RunAuto();
	}
	else if (args.size() == 3) {
		strTaskPath = args[1];
		strOutPath = args[2];
		if (strTaskPath.empty() || strOutPath.empty())
		{
			return;
		}

		strTaskFolder = Utility::getcwd(strTaskPath);

        try {
			ConfigManager::init(strTaskFolder + "/config/connectStr_config.json");
        }
        catch (std::exception &s)
        {
            std::string err = s.what();
            mt::printFailed(err.c_str());
            return;
        }

		RunOne();
	}
}

TEST_MAIN()



void RunOne() {
	const char* find = strstr(strTaskPath.c_str(), ".json");
	if (NULL == find ||
		strcmp(find, ".json") != 0)
	{
		std::string err = "  [task path is error]";
		mt::printFailed(err.c_str());
		return;
	}

	if (strOutPath.empty()) {
		std::string err = "  [out path is error]";
		mt::printFailed(err.c_str());
		return;
	}

	std::ifstream t(strTaskPath);
	std::string text((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	int iPos = strTaskPath.rfind(FILE_PATH_SEPERATOR, strTaskPath.length() - 1);
	std::string strName = strTaskPath.substr(iPos+1);
	std::string strPath = strTaskPath.substr(0, iPos);
	iPos = strName.find(".json");
	std::string strN = strName.substr(0, iPos);

	ITask *task = make_task(text.c_str(), strName.c_str(), strPath.c_str());
	if (!task) {
		std::string err = strName + "  [read task error]";
		mt::printFailed(err.c_str());
		delete task;
		return;
	}

	if (!task->do_prepare()) {
		std::string err = strName + "  [prepare task error]";
		mt::printFailed(err.c_str());
		delete task;
		return;
	}


	bool flag = true;
	std::string err = "";
	for (unsigned int i = 0; i < task->get_action_count(); ++i)
	{
		auto execute_result_set = task->execute_by_index(i);
		if (!execute_result_set) {
			flag = false;
			err = strName + "  [action " + std::to_string(i) + " execute error]";
			break;
		}
		const char* strSerialize = execute_result_set->json_serialize();
		std::string strIn = strSerialize;

		int iLen = strOutPath.length();

		std::string strSubName = "_RESULTSET";
		strSubName += std::to_string(i + 1);
		std::string strPath =  strOutPath + FILE_PATH_SEPERATOR + strN  + strSubName +  + ".json";
		std::ofstream outfile(strPath, std::ios_base::out);
		outfile << strIn;
		outfile.close();
	}

	if (!flag) {
		mt::printFailed(err.c_str());
	}
	else {
		mt::printOk(strName.c_str());
	}
	delete task;
}

void RunAuto() {

	if (strTaskFolder.empty())
	{
		std::string err = "  [root path is empty error]";
		mt::printFailed(err.c_str());
		return;
	}

	auto fit = make_file_iter(strTaskFolder.c_str());
	if (!fit)
	{
		std::string err = "  [can't open path error]";
		mt::printFailed(err.c_str());
		return;
	}
	while (fit->next())
	{
		std::string file_name = fit->get_file_name();
		std::string file_content = fit->get_file_content();

		ITask *task = make_task(file_content.c_str(), file_name.c_str(), strTaskFolder.c_str());
		if (!task) {
			std::string err = file_name + "  [read task error]";
			mt::printFailed(err.c_str());
			delete task;
			continue;
		}

		if (!task->do_prepare()) {
			std::string err = file_name + "  [prepare task error]";
			mt::printFailed(err.c_str());
			delete task;
			continue;
		}

		bool flag = true;
		std::string err = "";
		for (unsigned int i = 0; i < task->get_action_count(); ++i)
		{
			IResultSet *expect_result_set = task->get_expect_result_set_by_index(i);
			if (!expect_result_set) {
				flag = false;
				err = file_name + "  [action" + std::to_string(i) + " read exprect error]";
				break;
			}
			auto execute_result_set = task->execute_by_index(i);
			if (!execute_result_set) {
				flag = false;
				err = file_name + "  [action " + std::to_string(i) + " execute error]";
				break;
			}

			if (!execute_result_set->compare_with(expect_result_set)) {
				flag = false;
				err = file_name + "  [action " + std::to_string(i) + " execute result is not expect error]";
				break;
			}
		}

		if (!flag) {
			mt::printFailed(err.c_str());
		}
		else {
			mt::printOk(file_name.c_str());
		}
		delete task;
	}
}
