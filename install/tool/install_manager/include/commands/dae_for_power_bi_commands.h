#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_POWER_BI_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_POWER_BI_COMMANDS_H_

#include <memory>
#include <filesystem>

#include "install_items.h"
#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class InstallDaeForPowerBiCommand : public TransactionCommand
{
public:
    InstallDaeForPowerBiCommand(std::shared_ptr<DaeForPowerBiInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForPowerBiInstallItem> install_item_;
};

class UninstallDaeForPowerBiCommand : public TransactionCommand
{
public:
    UninstallDaeForPowerBiCommand(std::shared_ptr<DaeForPowerBiInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForPowerBiInstallItem> install_item_;
};

class RepairDaeForPowerBiCommand : public TransactionCommand
{
public:
    RepairDaeForPowerBiCommand(std::shared_ptr<DaeForPowerBiInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForPowerBiInstallItem> install_item_;
};

std::filesystem::path GetNxlMicrosoftDataSqlClientDllPath(const Architecture arch);

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_POWER_BI_COMMANDS_H_