#include "commands/dae_for_jdbc_commands.h"

#include <iostream>

#include "DAELog.h"
#include "utils.h"
#include "constants.h"
#include "install_items_factory.h"
#include "commands/filesystem_commands.h"
#include "commands/install_item_commands.h"
#include "commands/service_commands.h"

namespace fs = std::filesystem;

namespace dae_for_windows::install_manager::commands
{

static constexpr auto NXL_BACKUP_FOLDER_NAME = "backup";
static constexpr auto NXL_BACKUP_FILENAME_SUFFIX = ".backup";

InstallDaeForJdbcCommand::InstallDaeForJdbcCommand(
    std::shared_ptr<DaeForJdbcInstallItem> install_item
) : TransactionCommand({}), install_item_(install_item)
{
    const auto target_path = install_item->get_target_path();
    const auto target_path_string = target_path.string();
    const auto target_path_cstring = target_path_string.c_str();
    const auto jdbc_driver_kind = install_item->get_jdbc_driver_kind();
    const auto jdbc_driver_kind_string = GetJdbcDriverKindString(jdbc_driver_kind);
    const auto jdbc_driver_kind_cstring = jdbc_driver_kind_string.c_str();

    const auto backup_directory_path = GetBackupDirectoryPath(target_path);
    const auto backup_file_path = GetBackupFilePath(target_path, jdbc_driver_kind);

    if (!fs::exists(target_path))
    {
        const auto err_msg_format = "Error happened when install DAE for JDBC(%s) in %s. "
                                    "The target \"%s\" does not exist!";

        const auto err_msg = utils::StringFormat(err_msg_format,
                                                 jdbc_driver_kind_cstring,
                                                 target_path_cstring,
                                                 target_path_cstring);

        throw std::invalid_argument(err_msg.c_str());
    }

    if (!fs::is_regular_file(target_path) || target_path.extension() != ".jar")
    {
        const auto err_msg_format = "Error happened when install DAE for JDBC(%s) in %s. "
                                    "The target file \"%s\" is not a JAR file!";

        const auto err_msg = utils::StringFormat(err_msg_format,
                                                 jdbc_driver_kind_cstring,
                                                 target_path_cstring,
                                                 target_path_cstring);

        throw std::invalid_argument(err_msg.c_str());
    }

    if (!fs::exists(backup_directory_path))
    {
        commands_.push_back(
            std::make_shared<CreateDirectoryCommand>(
                backup_directory_path
                )
        );
    }

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(
            target_path,
            backup_file_path
            )
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(GetNxlJdbcDriverPath(jdbc_driver_kind), target_path)
    );

    commands_.push_back(
        std::make_shared<SaveInstallItemCommand>(install_item_)
    );
}

void InstallDaeForJdbcCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The JDBC feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto jdbc_driver_kind = install_item_->get_jdbc_driver_kind();
    const auto jdbc_driver_kind_string = GetJdbcDriverKindString(jdbc_driver_kind);
    const auto jdbc_driver_kind_cstring = jdbc_driver_kind_string.c_str();
    const auto target_path = install_item_->get_target_path();
    const auto target_path_string = target_path.string();
    const auto target_path_cstring = target_path_string.c_str();

    if (IsInstalled())
    {
        const auto installed_item = SearchForInstalledItem();
        const auto installed_jdbc_dirver_kind = installed_item->get_jdbc_driver_kind();
        const auto installed_jdbc_driver_kind_string = GetJdbcDriverKindString(installed_jdbc_dirver_kind);
        const auto install_jdbc_driver_kind_cstring = installed_jdbc_driver_kind_string.c_str();

        const auto info_msg_format = "DAE for JDBC(%s) has been installed in %s.";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            install_jdbc_driver_kind_cstring,
            target_path_cstring
        );
    }
    else
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully installed DAE for JDBC(%s) in %s.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                jdbc_driver_kind_cstring,
                target_path_cstring
            );
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when install DAE for JDBC(%s) in %s. Error message:\n\t%s";

            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                jdbc_driver_kind_cstring,
                target_path_cstring,
                e.what()
            );
        }
    }
}

bool InstallDaeForJdbcCommand::IsInstalled() const
{
    const auto list = LoadInstallList();
    return list.Contains(this->install_item_);
}

std::shared_ptr<DaeForJdbcInstallItem> InstallDaeForJdbcCommand::SearchForInstalledItem() const
{
    const auto list = LoadInstallList();
    const auto target_path = install_item_->get_target_path();

    return list.SearchDaeForJdbcInstallItem(target_path);
}

UninstallDaeForJdbcCommand::UninstallDaeForJdbcCommand(
    std::shared_ptr<DaeForJdbcInstallItem> item
) : TransactionCommand({}), install_item_(item)
{
    const auto target_path = install_item_->get_target_path();
    const auto jdbc_driver_kind = install_item_->get_jdbc_driver_kind();
    const auto backup_directory_path = GetBackupDirectoryPath(target_path);
    const auto backup_file_path = GetBackupFilePath(target_path, jdbc_driver_kind);

    commands_.push_back(
        std::make_shared<RemoveFileCommand>(target_path)
    );

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(
            backup_file_path,
            target_path
            )
    );

    commands_.push_back(
        std::make_shared<RemoveDirectoryCommand>(backup_directory_path)
    );

    commands_.push_back(
        std::make_shared<RemoveInstallItemCommand>(install_item_)
    );
}

void UninstallDaeForJdbcCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The JDBC feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto jdbc_driver_kind = install_item_->get_jdbc_driver_kind();
    const auto jdbc_driver_kind_string = GetJdbcDriverKindString(jdbc_driver_kind);
    const auto jdbc_driver_kind_cstring = jdbc_driver_kind_string.c_str();

    const auto target_path = install_item_->get_target_path();
    const auto target_path_string = target_path.string();
    const auto target_path_cstring = target_path_string.c_str();

    if (IsInstalled())
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully uninstalled DAE for JDBC(%s) in %s.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                jdbc_driver_kind_cstring,
                target_path_cstring
            );
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when uninstall DAE for JDBC(%s) in %s.\nError messages:\n\t%s";

            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                jdbc_driver_kind_cstring,
                target_path_cstring,
                e.what()
            );
        }
    }
    else
    {
        const auto info_msg_format = "DAE for JDBC(%s) did not installed in %s.";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            jdbc_driver_kind_cstring,
            target_path_cstring
        );
    }
}

bool UninstallDaeForJdbcCommand::IsInstalled()
{
    const auto list = LoadInstallList();

    return list.Contains(this->install_item_);
}

RepairDaeForJdbcCommand::RepairDaeForJdbcCommand(std::shared_ptr<DaeForJdbcInstallItem> item)
    : TransactionCommand({}), install_item_(item)
{
    const auto target_path = install_item_->get_target_path();
    const auto jdbc_driver_kind = install_item_->get_jdbc_driver_kind();

    const auto backup_directory_path = GetBackupDirectoryPath(target_path);
    const auto backup_file_path = GetBackupFilePath(target_path, jdbc_driver_kind);

    if (!fs::exists(backup_directory_path))
    {
        commands_.push_back(
            std::make_shared<CreateDirectoryCommand>(
                backup_directory_path
                )
        );
    }

    commands_.push_back(
        std::make_shared<RemoveFileCommand>(backup_file_path)
    );

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(
            target_path,
            backup_file_path
        )
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(GetNxlJdbcDriverPath(jdbc_driver_kind), target_path)
    );
}

void RepairDaeForJdbcCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The JDBC feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto jdbc_driver_path = install_item_->get_target_path();
    const auto jdbc_driver_kind = install_item_->get_jdbc_driver_kind();
    const auto jdbc_driver_kind_string = GetJdbcDriverKindString(jdbc_driver_kind);
    const auto jdbc_driver_kind_cstring = jdbc_driver_kind_string.c_str();

    const auto target_path = install_item_->get_target_path();
    const auto target_path_string = target_path.string();
    const auto target_path_cstring = target_path_string.c_str();

    const auto nxl_jdbc_driver_path = GetNxlJdbcDriverPath(jdbc_driver_kind);

    if (IsInstalled())
    {
        if (utils::IsSameFile(nxl_jdbc_driver_path.string(), jdbc_driver_path.string()))
        {
            const auto info_msg_format = "DAE for JDBC(%s) normally installed in %s. There is not need to repair it.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                jdbc_driver_kind_cstring,
                target_path_cstring
            );
        }
        else
        {
            try
            {
                TransactionCommand::Execute();

                const auto info_msg_format = "Successfully repair DAE for JDBC(%s) in %s.";

                theLog->WriteLog(
                    emLogLevel::log_info,
                    info_msg_format,
                    jdbc_driver_kind_cstring,
                    target_path_cstring
                );
            }
            catch (const std::exception& e)
            {
                const auto err_msg_format = "Error happened when repair DAE for JDBC(%s) in %s.\nError messages:\n\t%s";

                theLog->WriteLog(
                    emLogLevel::log_error,
                    err_msg_format,
                    jdbc_driver_kind_cstring,
                    target_path_cstring,
                    e.what()
                );
            }
        }
    }
    else
    {
        const auto info_msg_format = "DAE for JDBC(%s) did not installed in %s.";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            jdbc_driver_kind_cstring,
            target_path_cstring
        );
    }
}

bool RepairDaeForJdbcCommand::IsInstalled()
{
    const auto install_list = LoadInstallList();

    return install_list.Contains(install_item_);
}

fs::path GetNxlJdbcDriverPath(const JdbcDriverKind jdbc_driver_kind)
{
    const auto install_path = utils::GetInstallPath();
    const auto jdbc_driver_filename = GetJdbcDriverFilename(jdbc_driver_kind);

    fs::path jdbc_driver_path{ install_path };
    jdbc_driver_path /= "JDBC";
    jdbc_driver_path /= jdbc_driver_filename;

    return jdbc_driver_path;
}

std::string GetJdbcDriverFilename(const JdbcDriverKind jdbc_driver_kind)
{
    std::string jdbc_driver_filename;

    switch (jdbc_driver_kind)
    {
    case JdbcDriverKind::kOracle:
    {
        jdbc_driver_filename = "ojdbc8.jar";
    } break;
    case JdbcDriverKind::kHana:
    {
        jdbc_driver_filename = "ngdbc.jar";
    } break;
    case JdbcDriverKind::kSqlServer:
    {
        jdbc_driver_filename = "mssql-jdbc.jar";
    } break;
    default:
    {
        throw std::out_of_range("Wrong JDBC driver type");
    }
    }

    return jdbc_driver_filename;
}

std::filesystem::path GetBackupDirectoryPath(const fs::path target_file)
{
    const auto backup_directory_path = target_file.parent_path() / NXL_BACKUP_FOLDER_NAME;
    return backup_directory_path;
}

std::filesystem::path GetBackupFilePath(const fs::path target_file, const JdbcDriverKind jdbc_driver_kind)
{
    const auto backup_directory_path = GetBackupDirectoryPath(target_file);
    const auto jdbc_driver_kind_string = GetJdbcDriverKindString(jdbc_driver_kind);
    const auto backup_file_path =
        backup_directory_path / target_file.filename().concat(NXL_BACKUP_FILENAME_SUFFIX).concat(jdbc_driver_kind_string);

    return backup_file_path;
}

} // namespace dae_for_windows::install_manager::commands
