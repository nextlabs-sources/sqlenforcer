#include "commands/dae_for_odbc_commands.h"

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

static constexpr auto X86_ODBC_DLL_DIRECTORY_PATH = R"(C:\Windows\SysWOW64\)";
static constexpr auto X64_ODBC_DLL_DIRECTORY_PATH = R"(C:\Windows\System32\)";

static constexpr auto ODBC_DLL_NAME = "odbc32.dll";
static constexpr auto NEW_ODBC_DLL_NAME = "odbc32_ms.dll";

InstallDaeForOdbcCommand::InstallDaeForOdbcCommand(std::shared_ptr<DaeForOdbcInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto& arch = install_item_->get_arch();
    const auto& odbc_dll_path = GetOdbcDllPath(arch);
    const auto& new_odbc_dll_path = GetNewOdbcDllPath(arch);
    const auto& nxl_odbc_dll_path = GetNxlOdbcDllPath(arch);

    commands_.push_back(
        std::make_shared<SudoRenameFilenameCommand>(odbc_dll_path, new_odbc_dll_path)
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(nxl_odbc_dll_path, odbc_dll_path)
    );

    commands_.push_back(
        std::make_shared<SaveInstallItemCommand>(install_item_)
    );
}

void InstallDaeForOdbcCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ODBC feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto& odbc_string = GetOdbcString(install_item_->get_arch());

    if (IsInstalled())
    {
        const auto info_msg_format = "DAE for %s has been installed";
        
        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            odbc_string.c_str()
        );
    }
    else
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully installed DAE for %s.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                odbc_string.c_str()
            );
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when install DAE for %s\nError messages:\n\t%s";

            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                odbc_string.c_str(),
                e.what()
            );
        }
    }
}

bool InstallDaeForOdbcCommand::IsInstalled()
{
    const auto& arch = install_item_->get_arch();
    const auto& new_odbc_dll_path = GetNewOdbcDllPath(arch);

    return fs::exists(new_odbc_dll_path);
}

UninstallDaeForOdbcCommand::UninstallDaeForOdbcCommand(std::shared_ptr<DaeForOdbcInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto& arch = install_item_->get_arch();
    const auto& odbc_dll_path = GetOdbcDllPath(arch);
    const auto& new_odbc_dll_path = GetNewOdbcDllPath(arch);

    commands_.push_back(
        std::make_shared<RemoveFileCommand>(odbc_dll_path)
    );

    commands_.push_back(
        std::make_shared<SudoRenameFilenameCommand>(new_odbc_dll_path, odbc_dll_path)
    );

    commands_.push_back(
        std::make_shared<RemoveInstallItemCommand>(install_item_)
    );
}

void UninstallDaeForOdbcCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ODBC feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto& odbc_string = GetOdbcString(install_item_->get_arch());

    if (IsInstalled())
    {
        try
        {
            TransactionCommand::Execute();

            const auto info_msg_format = "Successfully uninstalled DAE for %s.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                odbc_string.c_str()
            );
        }
        catch (const std::exception& e)
        {
            const auto err_msg_format = "Error happened when uninstall DAE for %s\nError messages:\n\t%s";

            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                odbc_string.c_str(),
                e.what()
            );
        }
    }
    else
    {
        const auto info_msg_format = "DAE for %s did not installed";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            odbc_string.c_str()
        );
    }
}

bool UninstallDaeForOdbcCommand::IsInstalled()
{
    const auto& arch = install_item_->get_arch();
    const auto& new_odbc_dll_path = GetNewOdbcDllPath(arch);

    return fs::exists(new_odbc_dll_path);
}

RepairDaeForOdbcCommand::RepairDaeForOdbcCommand(std::shared_ptr<DaeForOdbcInstallItem> install_item)
    : TransactionCommand({}), install_item_(install_item)
{
    const auto arch = install_item_->get_arch();
    const auto odbc_dll_path = GetOdbcDllPath(arch);
    const auto new_odbc_dll_path = GetNewOdbcDllPath(arch);
    const auto nxl_odbc_dll_path = GetNxlOdbcDllPath(arch);

    commands_.push_back(
        std::make_shared<RemoveFileCommand>(new_odbc_dll_path)
    );

    commands_.push_back(
        std::make_shared<SudoRenameFilenameCommand>(odbc_dll_path, new_odbc_dll_path)
    );

    commands_.push_back(
        std::make_shared<CopyFileCommand>(nxl_odbc_dll_path, odbc_dll_path)
    );
}

void RepairDaeForOdbcCommand::Execute()
{
    if (!install_item_->IsFeatureInstalled())
    {
        const auto warn_msg_format = "The ODBC feature of DAEforWin is not installed.";
        theLog->WriteLog(emLogLevel::log_warning, warn_msg_format);
        return;
    }

    const auto arch = install_item_->get_arch();
    const auto odbc_string = GetOdbcString(arch);
    const auto odbc_dll_path = GetOdbcDllPath(arch);
    const auto nxl_odbc_dll_path = GetNxlOdbcDllPath(arch);

    if (IsInstalled())
    {
        if (utils::IsSameFile(odbc_dll_path.string(), nxl_odbc_dll_path.string()))
        {
            const auto info_msg_format = "DAE for %s installed normally. There is not need to repair it.";

            theLog->WriteLog(
                emLogLevel::log_info,
                info_msg_format,
                odbc_string.c_str()
            );
        }
        else
        {
            try
            {
                TransactionCommand::Execute();

                const auto info_msg_format = "Successfully repair DAE for %s.";

                theLog->WriteLog(
                    emLogLevel::log_info,
                    info_msg_format,
                    odbc_string.c_str()
                );
            }
            catch (const std::exception& e)
            {
                const auto err_msg_format = "Error happened when repair DAE for %s\nError messages:\n\t%s";

                theLog->WriteLog(
                    emLogLevel::log_error,
                    err_msg_format,
                    odbc_string.c_str(),
                    e.what()
                );
            }
        }
    }
    else
    {
        const auto info_msg_format = "DAE for %s did not installed";

        theLog->WriteLog(
            emLogLevel::log_info,
            info_msg_format,
            odbc_string.c_str()
        );
    }
}

bool RepairDaeForOdbcCommand::IsInstalled()
{
    const auto install_list = LoadInstallList();

    return install_list.Contains(install_item_);
}

fs::path GetOdbcDllParentPath(const Architecture arch)
{
    fs::path odbc_dll_parent_path;

    switch (arch)
    {
    case Architecture::kX86:
    {
        odbc_dll_parent_path = X86_ODBC_DLL_DIRECTORY_PATH;
    } break;
    case Architecture::kX64:
    {
        odbc_dll_parent_path = X64_ODBC_DLL_DIRECTORY_PATH;
    } break;
    default:
    {
        throw std::out_of_range("Wrong architecture.");
    }
    }

    return odbc_dll_parent_path;
}

fs::path GetOdbcDllPath(const Architecture arch)
{
    return GetOdbcDllParentPath(arch) / ODBC_DLL_NAME;
}

fs::path GetNewOdbcDllPath(const Architecture arch)
{
    return GetOdbcDllParentPath(arch) / NEW_ODBC_DLL_NAME;
}

fs::path GetNxlOdbcDllParentPath(const Architecture arch)
{
    const auto install_path = utils::GetInstallPath();
    fs::path nxl_odbc_dll_parent_path(install_path);

    switch (arch)
    {
    case Architecture::kX86:
    {
        nxl_odbc_dll_parent_path.append(R"(ODBC\bin32\)");
    } break;
    case Architecture::kX64:
    {
        nxl_odbc_dll_parent_path.append(R"(ODBC\bin64\)");
    } break;
    default:
    {
        throw std::out_of_range("Wrong architecture.");
    }
    }

    return nxl_odbc_dll_parent_path;
}

fs::path GetNxlOdbcDllPath(const Architecture arch)
{
    return GetNxlOdbcDllParentPath(arch) / ODBC_DLL_NAME;
}

std::string GetOdbcString(const Architecture arch)
{
    const auto& arch_string = GetArchitectureString(arch);
    const auto& odbc_string = "ODBC(" + arch_string + ")";

    return odbc_string;
}

} // namespace dae_for_windows::install_manager::commands
