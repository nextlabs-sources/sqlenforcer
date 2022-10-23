#include "commands/dae_for_power_bi_commands.h"

#include <iostream>

#include "DAELog.h"
#include "utils.h"
#include "constants.h"
#include "install_items_factory.h"
#include "commands/filesystem_commands.h"
#include "commands/install_item_commands.h"
#include "commands/dae_for_ado_net_commands.h"
#include "commands/service_commands.h"

namespace fs = std::filesystem;

namespace dae_for_windows::install_manager::commands
{

static constexpr auto ORI_MICROSOFT_DATA_SQLCLIENT_DLL_NAME = "Microsoft.Data.SqlClient.dll";
static constexpr auto NEW_MICROSOFT_DATA_SQLCLIENT_DLL_NAME = "Microsoft.Data.SqlClient.ori.dll";

InstallDaeForPowerBiCommand::InstallDaeForPowerBiCommand(
    std::shared_ptr<DaeForPowerBiInstallItem> install_item
) : TransactionCommand({}), install_item_(install_item)
{
    const auto& sqlclient_dll_path = install_item_->GetSqlClientDllPath();

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(
            sqlclient_dll_path.parent_path(),
            ORI_MICROSOFT_DATA_SQLCLIENT_DLL_NAME,
            NEW_MICROSOFT_DATA_SQLCLIENT_DLL_NAME
            )
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(
            GetNxlMicrosoftDataSqlClientDllPath(Architecture::kAnyCpu),
            sqlclient_dll_path
            )
    );

    commands_.push_back(
        std::make_shared<SaveInstallItemCommand>(install_item_)
    );
}

void InstallDaeForPowerBiCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ADO.NET feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto& arch = install_item_->get_arch();
    const auto& arch_string = GetArchitectureString(arch);
    const auto& install_path = install_item_->get_install_path();
    const auto& install_path_string = install_path.string();

    if (IsInstalled())
    {
        const auto info_msg_format = "DAE for Power BI(%s) has been installed in %s";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            arch_string.c_str(),
            install_path_string.c_str()
        );
    }
    else
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully installed DAE for Power BI(%s) in %s.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                arch_string.c_str(),
                install_path_string.c_str()
            );
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when install DAE for Power BI(%s) in %s.\nError messages:\n\t%s";

            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                arch_string.c_str(),
                install_path_string.c_str(),
                e.what()
            );
        }
    }
}

bool InstallDaeForPowerBiCommand::IsInstalled()
{
    return utils::IsSameFile(
        GetNxlMicrosoftDataSqlClientDllPath(Architecture::kAnyCpu).string(),
        install_item_->GetSqlClientDllPath().string()
    );
}

UninstallDaeForPowerBiCommand::UninstallDaeForPowerBiCommand(
    std::shared_ptr<DaeForPowerBiInstallItem> install_item
) : TransactionCommand({}), install_item_(install_item)
{
    const auto& sqlclient_dll_path = install_item_->GetSqlClientDllPath();
    const auto& sqlclient_dll_parent_path = sqlclient_dll_path.parent_path();

    commands_.push_back(
        std::make_shared<RemoveFileCommand>(
            sqlclient_dll_path
        )
    );

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(
            sqlclient_dll_parent_path,
            NEW_MICROSOFT_DATA_SQLCLIENT_DLL_NAME,
            ORI_MICROSOFT_DATA_SQLCLIENT_DLL_NAME
            )
    );

    commands_.push_back(
        std::make_shared<RemoveInstallItemCommand>(install_item_)
    );
}

void UninstallDaeForPowerBiCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ADO.NET feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto& arch = install_item_->get_arch();
    const auto& arch_string = GetArchitectureString(arch);
    const auto& install_path = install_item_->get_install_path();
    const auto& install_path_string = install_path.string();

    if (IsInstalled())
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully uninstalled DAE for Power BI(%s) in %s.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                arch_string.c_str(),
                install_path_string.c_str()
            );
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when uninstall DAE for Power BI(%s) in %s.\nError messages:\n\t%s";

            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                arch_string.c_str(),
                install_path_string.c_str(),
                e.what()
            );
        }
    }
    else
    {
        const auto info_msg_format = "DAE for Power BI(%s) did not installed in %s";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            arch_string.c_str(),
            install_path_string.c_str()
        );
    }
}

bool UninstallDaeForPowerBiCommand::IsInstalled()
{
    return utils::IsSameFile(
        GetNxlMicrosoftDataSqlClientDllPath(Architecture::kAnyCpu).string(),
        install_item_->GetSqlClientDllPath().string()
    );
}

RepairDaeForPowerBiCommand::RepairDaeForPowerBiCommand(
    std::shared_ptr<DaeForPowerBiInstallItem> install_item
) : TransactionCommand({}), install_item_(install_item)
{
    const auto sqlclient_dll_path = install_item_->GetSqlClientDllPath();
    const auto sqlclient_dll_parent_path = sqlclient_dll_path.parent_path();

    commands_.push_back(
        std::make_shared<RemoveFileCommand>(
            sqlclient_dll_parent_path / NEW_MICROSOFT_DATA_SQLCLIENT_DLL_NAME
        )
    );

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(
            sqlclient_dll_path.parent_path(),
            ORI_MICROSOFT_DATA_SQLCLIENT_DLL_NAME,
            NEW_MICROSOFT_DATA_SQLCLIENT_DLL_NAME
            )
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(
            GetNxlMicrosoftDataSqlClientDllPath(Architecture::kAnyCpu),
            sqlclient_dll_path
            )
    );
}

void RepairDaeForPowerBiCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ADO.NET feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto sqlclient_dll_path = install_item_->GetSqlClientDllPath();
    const auto nxl_sqlclient_dll_path = GetNxlMicrosoftDataSqlClientDllPath(Architecture::kAnyCpu);

    const auto arch = install_item_->get_arch();
    const auto arch_string = GetArchitectureString(arch);
    const auto install_path = install_item_->get_install_path();
    const auto install_path_string = install_path.string();

    if (IsInstalled())
    {
        if (utils::IsSameFile(nxl_sqlclient_dll_path.string(), sqlclient_dll_path.string()))
        {
            const auto info_msg_format = "DAE for Power BI(%s) normally installed in %s. There is no need to repair it.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                arch_string.c_str(),
                install_path_string.c_str()
            );
        }
        else
        {
            try
            {
                TransactionCommand::Execute();

                const auto info_msg_format = "Successfully repair DAE for Power BI(%s) in %s.";

                theLog->WriteLog(
                    emLogLevel::log_info,
                    info_msg_format,
                    arch_string.c_str(),
                    install_path_string.c_str()
                );
            }
            catch (const std::exception& e)
            {
                const auto err_msg_format = "Error happened when repair DAE for Power BI(%s) in %s.\nError messages:\n\t%s";

                theLog->WriteLog(
                    emLogLevel::log_error,
                    err_msg_format,
                    arch_string.c_str(),
                    install_path_string.c_str(),
                    e.what()
                );
            }
        }
    }
    else
    {
        const auto info_msg_format = "DAE for Power BI(%s) did not installed in %s";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            arch_string.c_str(),
            install_path.c_str()
        );
    }
}

bool RepairDaeForPowerBiCommand::IsInstalled()
{
    const auto install_list = LoadInstallList();

    return install_list.Contains(install_item_);
}

fs::path GetNxlMicrosoftDataSqlClientDllPath(const Architecture arch)
{
    return GetNxlSystemDataDllParentPath(arch) / ORI_MICROSOFT_DATA_SQLCLIENT_DLL_NAME;
}

} // namespace dae_for_windows::install_manager::commands
