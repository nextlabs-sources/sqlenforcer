#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_ADO_NET_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_ADO_NET_COMMANDS_H_

#include <memory>
#include <filesystem>

#include "install_items.h"
#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class InstallDaeForAdoNetCommand : public TransactionCommand
{
public:
    InstallDaeForAdoNetCommand(std::shared_ptr<DaeForAdoNetInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForAdoNetInstallItem> install_item_;
};

class UninstallDaeForAdoNetCommand : public TransactionCommand
{
public:
    UninstallDaeForAdoNetCommand(std::shared_ptr<DaeForAdoNetInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForAdoNetInstallItem> install_item_;
};

class RepairDaeForAdoNetCommand : public TransactionCommand
{
public:
    RepairDaeForAdoNetCommand(std::shared_ptr<DaeForAdoNetInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForAdoNetInstallItem> install_item_;
};

std::filesystem::path GetSystemDataDllParentPath(const Architecture arch);

std::filesystem::path GetSystemDataDllPath(const Architecture arch);

std::filesystem::path GetNxlSystemDataDllParentPath(const Architecture arch);

std::filesystem::path GetNxlSystemDataDllPath(const Architecture arch);

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_ADO_NET_COMMANDS_H_