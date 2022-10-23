#include "commands/dae_for_ado_net_commands.h"

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

static constexpr auto ORI_SYSTEM_DATA_DLL_NAME = "System.Data.dll";
static constexpr auto NEW_SYSTEM_DATA_DLL_NAME = "System.Data.ori.dll";

static constexpr auto ORI_SYSTEM_DATA_X86_DLL_PARENT_PATH = R"(C:\Windows\Microsoft.NET\assembly\GAC_32\System.Data)";
static constexpr auto ORI_SYSTEM_DATA_X64_DLL_PARENT_PATH = R"(C:\Windows\Microsoft.NET\assembly\GAC_64\System.Data)";

InstallDaeForAdoNetCommand::InstallDaeForAdoNetCommand(std::shared_ptr<DaeForAdoNetInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto& arch = install_item_->get_arch();
    const auto& nxl_system_data_dll_path = GetNxlSystemDataDllPath(arch);
    const auto& system_data_dll_path = GetSystemDataDllPath(arch);
    const auto& system_data_dll_parent_path = system_data_dll_path.parent_path();

    commands_.push_back(
        std::make_shared<SudoRenameFilenameCommand>(
            system_data_dll_parent_path,
            ORI_SYSTEM_DATA_DLL_NAME,
            NEW_SYSTEM_DATA_DLL_NAME
        )
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(nxl_system_data_dll_path, system_data_dll_path)
    );

    commands_.push_back(
        std::make_shared<SaveInstallItemCommand>(install_item_)
    );
}

void InstallDaeForAdoNetCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ADO.NET feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto& arch = install_item_->get_arch();
    const auto& arch_string = GetArchitectureString(arch);

    if (IsInstalled())
    {
        const auto info_msg_format = "DAE for ADO.NET(%s) has been installed.";
        theLog->WriteLog(emLogLevel::log_info, info_msg_format, arch_string.c_str());
    }
    else
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully installed DAE for ADO.NET(%s).";

            theLog->WriteLog(emLogLevel::log_info, info_msg_format, arch_string.c_str());
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when install DAE for ADO.NET(%s).\nError messages:\n\t%s";
            theLog->WriteLog(emLogLevel::log_error, err_msg_format, arch_string.c_str(), e.what());
        }
    }
}

bool InstallDaeForAdoNetCommand::IsInstalled()
{
    const auto& arch = install_item_->get_arch();
    const auto& new_system_data_dll_path = GetSystemDataDllParentPath(arch) / NEW_SYSTEM_DATA_DLL_NAME;

    return fs::exists(new_system_data_dll_path);
}

UninstallDaeForAdoNetCommand::UninstallDaeForAdoNetCommand(std::shared_ptr<DaeForAdoNetInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto& arch = install_item_->get_arch();
    const auto& system_data_dll_path = GetSystemDataDllPath(arch);
    const auto& system_data_dll_parent_path = system_data_dll_path.parent_path();

    commands_.push_back(std::make_shared<RemoveFileCommand>(
        system_data_dll_path
        ));

    commands_.push_back(std::make_shared<SudoRenameFilenameCommand>(
        system_data_dll_parent_path,
        NEW_SYSTEM_DATA_DLL_NAME,
        ORI_SYSTEM_DATA_DLL_NAME
        ));

    commands_.push_back(
        std::make_shared<RemoveInstallItemCommand>(install_item_)
    );
}

void UninstallDaeForAdoNetCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ADO.NET feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto& arch = install_item_->get_arch();
    const auto& arch_string = GetArchitectureString(arch);

    if (IsInstalled())
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully uninstalled DAE for ADO.NET(%s).";
            theLog->WriteLog(emLogLevel::log_info, info_msg_format, arch_string.c_str());
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when uninstall DAE for ADO.NET(%s).\nError messages:\n\t%s";
            theLog->WriteLog(emLogLevel::log_error, err_msg_format, arch_string.c_str(), e.what());
        }
    }
    else
    {
        const auto info_msg_format = "DAE for ADO.NET(%s) did not installed.";
        theLog->WriteLog(emLogLevel::log_info, info_msg_format, arch_string.c_str());
    }
}

bool UninstallDaeForAdoNetCommand::IsInstalled()
{
    const auto& arch = install_item_->get_arch();
    const auto& new_system_data_dll_path = GetSystemDataDllParentPath(arch) / NEW_SYSTEM_DATA_DLL_NAME;

    return fs::exists(new_system_data_dll_path);
}

RepairDaeForAdoNetCommand::RepairDaeForAdoNetCommand(std::shared_ptr<DaeForAdoNetInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto arch = install_item_->get_arch();
    const auto nxl_system_data_dll_path = GetNxlSystemDataDllPath(arch);
    const auto system_data_dll_path = GetSystemDataDllPath(arch);
    const auto system_data_dll_parent_path = system_data_dll_path.parent_path();

    commands_.push_back(std::make_shared<RemoveFileCommand>(
        system_data_dll_parent_path / NEW_SYSTEM_DATA_DLL_NAME
    ));

    commands_.push_back(
        std::make_shared<SudoRenameFilenameCommand>(
            system_data_dll_parent_path,
            ORI_SYSTEM_DATA_DLL_NAME,
            NEW_SYSTEM_DATA_DLL_NAME
            )
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(nxl_system_data_dll_path, system_data_dll_path)
    );
}

void RepairDaeForAdoNetCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ADO.NET feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto arch = install_item_->get_arch();
    const auto& arch_string = GetArchitectureString(arch);

    const auto& nxl_system_data_dll_path = GetNxlSystemDataDllPath(arch);
    const auto& system_data_dll_path = GetSystemDataDllPath(arch);

    if (IsInstalled())
    {
        if (utils::IsSameFile(nxl_system_data_dll_path.string(), system_data_dll_path.string()))
        {
            const auto info_msg_format = "DAE for ADO.NET(%s) installed normally. There is not need to repair it.";
            theLog->WriteLog(emLogLevel::log_info, info_msg_format, arch_string.c_str());
        }
        else
        {
            try
            {
                TransactionCommand::Execute();

                const auto info_msg_format = "Successfully repair DAE for ADO.NET(%s).";
                theLog->WriteLog(emLogLevel::log_info, info_msg_format, arch_string.c_str());
            }
            catch (const std::exception& e)
            {
                const auto err_msg_format = "Error happened when repair DAE for ADO.NET(%s).\nError messages:\n\t%s";
                theLog->WriteLog(emLogLevel::log_error, err_msg_format, arch_string.c_str(), e.what());
            }
        }
    }
    else
    {
        const auto info_msg_format = "DAE for ADO.NET(%s) did not installed.";
        theLog->WriteLog(emLogLevel::log_info, info_msg_format, arch_string.c_str());
    }
}

bool RepairDaeForAdoNetCommand::IsInstalled()
{
    const auto& install_list = LoadInstallList();

    return install_list.Contains(install_item_);
}

fs::path GetSystemDataDllParentPath(const Architecture arch)
{
    return GetSystemDataDllPath(arch).parent_path();
}

fs::path GetSystemDataDllPath(const Architecture arch)
{
    std::string system_data_dll_parent_path;

    switch (arch)
    {
    case Architecture::kX86:
    {
        system_data_dll_parent_path = ORI_SYSTEM_DATA_X86_DLL_PARENT_PATH;
    } break;
    case Architecture::kX64:
    {
        system_data_dll_parent_path = ORI_SYSTEM_DATA_X64_DLL_PARENT_PATH;
    } break;
    default:
    {
        throw std::out_of_range("Wrong architecture.");
    }
    }

    return utils::GetFilePathRecursively(system_data_dll_parent_path, ORI_SYSTEM_DATA_DLL_NAME);
}

fs::path GetNxlSystemDataDllParentPath(const Architecture arch)
{
    const auto install_path = utils::GetInstallPath();
    fs::path nxl_ado_net_dll_parent_path(install_path);

    switch (arch)
    {
    case Architecture::kX86:
    {
        nxl_ado_net_dll_parent_path.append(R"(ADO.NET\x86)");
    } break;
    case Architecture::kX64:
    {
        nxl_ado_net_dll_parent_path.append(R"(ADO.NET\x64)");
    } break;
    case Architecture::kAnyCpu:
    {
        nxl_ado_net_dll_parent_path.append(R"(ADO.NET\)");
    } break;
    default:
    {
        throw std::out_of_range("Wrong architecture.");
    }
    }

    return nxl_ado_net_dll_parent_path;
}

fs::path GetNxlSystemDataDllPath(const Architecture arch)
{
    return GetNxlSystemDataDllParentPath(arch) / ORI_SYSTEM_DATA_DLL_NAME;
}

} // namespace dae_for_windows::install_manager::commands
