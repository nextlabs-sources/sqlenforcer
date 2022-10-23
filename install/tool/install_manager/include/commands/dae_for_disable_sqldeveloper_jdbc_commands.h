#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_DAE_FOR_DISABLE_SQLDEVELOPER_JDBC_COMMAND_H
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_DAE_FOR_DISABLE_SQLDEVELOPER_JDBC_COMMAND_H

#include <memory>
#include <string>
#include <vector>

#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{
class RuntimeDaeForDisableSqldeveloperJDBC : public MacroCommand
{
public:
    RuntimeDaeForDisableSqldeveloperJDBC(const std::string& path)
        : MacroCommand({})
        , _path(path)
    { }

    void Execute();

private:
    void KillSqldeveloperIfRunning();
    void MarkInRegistry();
    bool IsDaeforociInstalled();

private:
    std::string _path;
};

class RuntimeDaeForDisableAllSqldeveloperJDBC : public MacroCommand
{
public:
    RuntimeDaeForDisableAllSqldeveloperJDBC()
        : MacroCommand({})
    {}

    void Execute();

private:
    void GetInstallPaths(std::vector<std::string>& paths);
};
}

#endif