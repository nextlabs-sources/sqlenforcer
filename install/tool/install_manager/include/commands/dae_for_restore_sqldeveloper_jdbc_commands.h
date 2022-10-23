#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_DAE_FOR_RESTORE_SQLDEVELOPER_JDBC_COMMAND_H
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_DAE_FOR_RESTORE_SQLDEVELOPER_JDBC_COMMAND_H

#include <memory>
#include <string>
#include <vector>

#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class RuntimeDaeForRestoreSqldeveloperJDBC : public MacroCommand
{
public:
    RuntimeDaeForRestoreSqldeveloperJDBC() : MacroCommand({}) {}
    void Execute();

private:
    void GetRestoreList(std::vector<std::wstring>& lists);
    void Restore(const std::wstring& path);
    void CleanMarkInRegistry();
    bool IsDaeforociUninstalled();
};

}

#endif