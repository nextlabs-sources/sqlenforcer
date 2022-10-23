#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_JDBC_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_JDBC_COMMANDS_H_

#include <memory>
#include <filesystem>

#include "base_commands.h"
#include "install_items.h"

namespace dae_for_windows::install_manager::commands
{

class InstallDaeForJdbcCommand : public TransactionCommand
{
public:
    InstallDaeForJdbcCommand(std::shared_ptr<DaeForJdbcInstallItem> install_item);
public:
    void Execute() override;
private:
    /// <summary>
    /// Check if the target of install_item has DaeForJdbc installed.
    /// </summary>
    /// <returns>
    /// Return true when the target of install_item has DaeForJdbc installed.
    /// Otherwise, return false
    /// </returns>
    bool IsInstalled() const;

    /// <summary>
    /// Search for the installed item corresponding to the install_item target from the registry.
    /// </summary>
    /// <returns>
    /// If find, it returns the correspond installed item.
    /// Otherwise, it returns null shared_ptr.
    /// </returns>
    std::shared_ptr<DaeForJdbcInstallItem> SearchForInstalledItem() const;
private:
    std::shared_ptr<DaeForJdbcInstallItem> install_item_;
};

class UninstallDaeForJdbcCommand : public TransactionCommand
{
public:
    UninstallDaeForJdbcCommand(std::shared_ptr<DaeForJdbcInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForJdbcInstallItem> install_item_;
};

class RepairDaeForJdbcCommand : public TransactionCommand
{
public:
    RepairDaeForJdbcCommand(std::shared_ptr<DaeForJdbcInstallItem> install_item);
public:
    void Execute() override;
private:
    bool IsInstalled();
private:
    std::shared_ptr<DaeForJdbcInstallItem> install_item_;
};

std::filesystem::path GetNxlJdbcDriverPath(const JdbcDriverKind jdbc_driver_kind);

std::string GetJdbcDriverFilename(const JdbcDriverKind jdbc_driver_kind);

std::filesystem::path GetBackupDirectoryPath(const std::filesystem::path target_file);

std::filesystem::path GetBackupFilePath(const std::filesystem::path target_file, const JdbcDriverKind jdbc_driver_kind);

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_DAE_FOR_JDBC_COMMANDS_H_