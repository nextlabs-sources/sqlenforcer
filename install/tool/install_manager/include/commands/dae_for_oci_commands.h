#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_OCI_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_OCI_COMMANDS_H_

#include <memory>
#include <filesystem>

#include "commands/base_commands.h"

#include "install_items.h"

namespace dae_for_windows::install_manager::commands
{

class InstallDaeForOciCommand : public TransactionCommand
{
public:
    InstallDaeForOciCommand(std::shared_ptr<DaeForOciInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForOciInstallItem> install_item_;
};

class UninstallDaeForOciCommand : public TransactionCommand
{
public:
    UninstallDaeForOciCommand(std::shared_ptr<DaeForOciInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForOciInstallItem> install_item_;
};

class RepairDaeForOciCommand : public TransactionCommand
{
public:
    RepairDaeForOciCommand(std::shared_ptr<DaeForOciInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForOciInstallItem> install_item_;
};

std::filesystem::path GetNxlOciDllParentPath(const Architecture arch);

std::filesystem::path GetNxlOciDllPath(const Architecture arch);

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_OCI_COMMANDS_H_