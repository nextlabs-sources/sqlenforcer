#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_ODBC_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_ODBC_COMMANDS_H_

#include <memory>
#include <filesystem>

#include "install_items.h"
#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class InstallDaeForOdbcCommand : public TransactionCommand
{
public:
    InstallDaeForOdbcCommand(std::shared_ptr<DaeForOdbcInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForOdbcInstallItem> install_item_;
};

class UninstallDaeForOdbcCommand : public TransactionCommand
{
public:
    UninstallDaeForOdbcCommand(std::shared_ptr<DaeForOdbcInstallItem> install_item);
public:
    void Execute() override;
public:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForOdbcInstallItem> install_item_;
};

class RepairDaeForOdbcCommand : public TransactionCommand
{
public:
    RepairDaeForOdbcCommand(std::shared_ptr<DaeForOdbcInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForOdbcInstallItem> install_item_;
};

std::filesystem::path GetOdbcDllParentPath(const Architecture arch);

std::filesystem::path GetOdbcDllPath(const Architecture arch);

std::filesystem::path GetNewOdbcDllPath(const Architecture arch);

std::filesystem::path GetNxlOdbcDllParentPath(const Architecture arch);

std::filesystem::path GetNxlOdbcDllPath(const Architecture arch);

std::string GetOdbcString(const Architecture arch);

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_ODBC_COMMANDS_H_