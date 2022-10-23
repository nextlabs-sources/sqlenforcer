#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_MANIPULATE_ALL_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_MANIPULATE_ALL_COMMANDS_H_

#include <string>

#include "install_items.h"
#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class InstallAllCommand : public MacroCommand
{
public:
    InstallAllCommand(const InstallList& install_list);
public:
    void Execute() override;
private:
    std::string config_path_;
    InstallList install_list_;
};

class UninstallAllCommand : public MacroCommand
{
public:
    UninstallAllCommand(const InstallList& install_list);
public:
    void Execute() override;
private:
    std::string config_path_;
    InstallList install_list_;
};

class RepairAllCommand : public MacroCommand
{
public:
    RepairAllCommand(const InstallList& install_list);
public:
    void Execute() override;
private:
    InstallList install_list_;
};

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_MANIPULATE_ALL_COMMANDS_H_