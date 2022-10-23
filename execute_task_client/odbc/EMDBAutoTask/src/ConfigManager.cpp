#include "../include/ConfigManager.h"

#include <json/json.h>
#include <fstream>
using std::ifstream;

#include <stdexcept>

#define CONNECT_STR_TYPE "ODBC_CONNECT_STR"

Json::Value ConfigManager::config;

void ConfigManager::init(string path)
{
    ifstream configFile(path);

    if (configFile)
    {
        configFile >> ConfigManager::config;
    }
    else
    {
        throw std::runtime_error("Can not read config file:" + path);
    }
}

string ConfigManager::getConnStr(string name)
{
    return ConfigManager::config[name][CONNECT_STR_TYPE].asString();
}
