#ifndef EMDB_AUTO_TASK_CONFIGMANAGER_H
#define EMDB_AUTO_TASK_CONFIGMANAGER_H

#include <json/json.h>
#include <json/value.h>
#include <string>
using std::string;

class ConfigManager {
public:
    static void init(string path);
    static string getConnStr(string name);

private:
    static Json::Value config;
};

#endif //EMDB_AUTO_TASK_CONFIGMANAGER_H
