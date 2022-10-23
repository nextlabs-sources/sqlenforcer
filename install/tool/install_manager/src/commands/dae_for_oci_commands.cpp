#include "commands/dae_for_oci_commands.h"

#include <iostream>

#include "DAELog.h"
#include "utils.h"
#include "constants.h"
#include "install_items_factory.h"
#include "commands/filesystem_commands.h"
#include "commands/install_item_commands.h"
#include "commands/service_commands.h"
#include "commands/dae_for_disable_sqldeveloper_jdbc_commands.h"
#include "commands/dae_for_restore_sqldeveloper_jdbc_commands.h"

namespace fs = std::filesystem;

namespace dae_for_windows::install_manager::commands
{

static constexpr auto OCI_DLL_NAME = "oci.dll";
static constexpr auto NEW_OCI_DLL_NAME = "oci_ms.dll";

InstallDaeForOciCommand::InstallDaeForOciCommand(std::shared_ptr<DaeForOciInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto arch = install_item_->get_arch();
    const auto& oci_dll_parent_path = install_item_->get_target_path();
    const auto& nxl_oci_dll_path = GetNxlOciDllPath(arch);

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(oci_dll_parent_path, OCI_DLL_NAME, NEW_OCI_DLL_NAME)
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(nxl_oci_dll_path, oci_dll_parent_path)
    );

    commands_.push_back(
        std::make_shared<SaveInstallItemCommand>(install_item_)
    );

    commands_.push_back(
        std::make_shared<RuntimeDaeForDisableAllSqldeveloperJDBC>()
    );
}

void InstallDaeForOciCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The OCI feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto arch_string = GetArchitectureString(install_item_->get_arch());
    const auto target_path = install_item_->get_target_path();
    const auto target_path_string = target_path.string();

    if (IsInstalled())
    {
        const auto info_msg_format = "DAE for OCI(%s) has been installed in %s.";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            arch_string.c_str(),
            target_path_string.c_str()
        );
    }
    else
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully installed DAE for OCI(%s) in %s.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                arch_string.c_str(),
                target_path_string.c_str()
            );
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when install DAE for OCI(%s) in %s.\nError messages:\n\t%s";
            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                arch_string.c_str(),
                target_path_string.c_str(),
                e.what()
            );
        }
    }
}

bool InstallDaeForOciCommand::IsInstalled()
{
    const auto& new_oci_dll_path = install_item_->get_target_path() / NEW_OCI_DLL_NAME;
    return fs::exists(new_oci_dll_path);
}

UninstallDaeForOciCommand::UninstallDaeForOciCommand(std::shared_ptr<DaeForOciInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto& oci_dll_parent_path = install_item_->get_target_path();

    commands_.push_back(
        std::make_shared<RemoveFileCommand>(oci_dll_parent_path / OCI_DLL_NAME)
    );

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(oci_dll_parent_path, NEW_OCI_DLL_NAME, OCI_DLL_NAME)
    );

    commands_.push_back(
        std::make_shared<RemoveInstallItemCommand>(install_item_)
    );

    // restore sqldeveloper jdbc driver when has uninstalled [dae for oci]
    commands_.push_back(
        std::make_shared<RuntimeDaeForRestoreSqldeveloperJDBC>()
    );
}

void UninstallDaeForOciCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The OCI feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto& arch = install_item_->get_arch();
    const auto& arch_string = GetArchitectureString(arch);
    const auto& target_path = install_item_->get_target_path();
    const auto target_path_string = target_path.string();

    if (IsInstalled())
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully uninstalled DAE for OCI(%s) in %s";
            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                arch_string.c_str(),
                target_path_string.c_str()
            );
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when uninstall DAE for OCI(%s) in %s.\nError messages:\n\t%s";
            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                arch_string.c_str(),
                target_path_string.c_str(),
                e.what()
            );
        }
    }
    else
    {
        const auto info_msg_format = "DAE for OCI(%s) did not installed in %s.";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            arch_string.c_str(),
            target_path_string.c_str()
        );
    }
}

bool UninstallDaeForOciCommand::IsInstalled()
{
    const auto& new_oci_dll_path = install_item_->get_target_path() / NEW_OCI_DLL_NAME;
    return fs::exists(new_oci_dll_path);
}

RepairDaeForOciCommand::RepairDaeForOciCommand(std::shared_ptr<DaeForOciInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto arch = install_item_->get_arch();
    const auto oci_dll_parent_path = install_item_->get_target_path();
    const auto nxl_oci_dll_path = GetNxlOciDllPath(arch);

    commands_.push_back(
        std::make_shared<RemoveFileCommand>(oci_dll_parent_path / NEW_OCI_DLL_NAME)
    );

    commands_.push_back(
        std::make_shared<RenameFilenameCommand>(oci_dll_parent_path, OCI_DLL_NAME, NEW_OCI_DLL_NAME)
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(nxl_oci_dll_path, oci_dll_parent_path)
    );
}

void RepairDaeForOciCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The OCI feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto arch = install_item_->get_arch();
    const auto arch_string = GetArchitectureString(arch);
    const auto oci_dll_parent_path = install_item_->get_target_path();
    const auto oci_dll_parent_path_string = oci_dll_parent_path.string();
    const auto oci_dll_path = oci_dll_parent_path / OCI_DLL_NAME;
    const auto nxl_oci_dll_path = GetNxlOciDllPath(arch);

    if (IsInstalled())
    {
        if (utils::IsSameFile(oci_dll_path.string(), nxl_oci_dll_path.string()))
        {
            const auto info_msg_format = "DAE for OCI(%s) installed normally in %s. There is no need to repair it.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                arch_string.c_str(),
                oci_dll_parent_path_string.c_str()
            );
        }
        else
        {
            try
            {
                TransactionCommand::Execute();

                const auto info_msg_format = "Successfully repair DAE for OCI(%s) in %s";
                theLog->WriteLog(
                    emLogLevel::log_info,
                    info_msg_format,
                    arch_string.c_str(),
                    oci_dll_parent_path_string.c_str()
                );
            }
            catch (const std::exception& e)
            {
                const auto err_msg_format = "Error happened when repair DAE for OCI(%s) in %s.\nError messages:\n\t%s";
                theLog->WriteLog(
                    emLogLevel::log_error,
                    err_msg_format,
                    arch_string.c_str(),
                    oci_dll_parent_path_string.c_str(),
                    e.what()
                );
            }
        }
    }
    else
    {
        const auto info_msg_format = "DAE for OCI(%s) did not installed in %s.";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            arch_string.c_str(),
            oci_dll_parent_path_string.c_str()
        );
    }
}

bool RepairDaeForOciCommand::IsInstalled()
{
    const auto install_list = LoadInstallList();

    return install_list.Contains(install_item_);
}

fs::path GetNxlOciDllParentPath(const Architecture arch)
{
    const auto install_path = utils::GetInstallPath();
    fs::path nxl_oci_dll_parent_path(install_path);

    switch (arch)
    {
    case Architecture::kX86:
    {
        nxl_oci_dll_parent_path.append(R"(OCI\bin32\)");
    } break;
    case Architecture::kX64:
    {
        nxl_oci_dll_parent_path.append(R"(OCI\bin64\)");
    } break;
    default:
    {
        throw std::out_of_range("Wrong architecture.");
    }
    }

    return nxl_oci_dll_parent_path;
}

fs::path GetNxlOciDllPath(const Architecture arch)
{
    return GetNxlOciDllParentPath(arch) / OCI_DLL_NAME;
}

} // namespace dae_for_windows::install_manager::commands
