#include "cli_commands.h"

#include <memory>
#include <iostream>
#include <exception>

#include "commands/command_decorators.h"
#include "commands/dae_for_ado_net_commands.h"
#include "commands/dae_for_jdbc_commands.h"
#include "commands/dae_for_oci_commands.h"
#include "commands/dae_for_odbc_commands.h"
#include "commands/dae_for_power_bi_commands.h"
#include "commands/dae_for_restore_sqldeveloper_jdbc_commands.h"
#include "commands/dae_for_disable_sqldeveloper_jdbc_commands.h"
#include "commands/filesystem_commands.h"
#include "commands/manipulate_all_commands.h"

#include "DAELog.h"
#include "install_items.h"
#include "install_config.h"
#include "install_items_factory.h"

namespace commands = dae_for_windows::install_manager::commands;

namespace dae_for_windows::install_manager::cli_commands
{

struct Options
{
    std::string from{};
    std::string target{};
    std::string config_path{ R"(C:\ProgramData\Nextlabs\DAEforWin\Config\install_config.xml)" };
    Architecture arch{ Architecture::kX86 };
    JdbcDriverKind jdbc_driver_kind{ JdbcDriverKind::kOracle };
};

CLI::App* add_rename_file_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("rename", "Move or rename a file.");

    command->add_option("-f,--from", opt->from, "The path to move or rename.")->required();
    command->add_option("-t,--target", opt->target, "Target parth for the move/rename operation.")->required();
    command->callback([opt]() {
        commands::RenameFilenameCommand(opt->from, opt->target).Execute();
    });

    return command;
}

CLI::App* add_sudo_rename_file_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("sudorename", "Move or rename a file as TrustedInstaller.");

    command->add_option("-f,--from", opt->from, "The path to move or rename.")->required();
    command->add_option("-t,--target", opt->target, "Target parth for the move/rename operation.")->required();
    command->callback([opt]() {
        commands::SudoRenameFilenameCommand(opt->from, opt->target).Execute();
    });

    return command;
}

CLI::App* add_list_all_installed_subcommand(CLI::App* app)
{
    auto command = app->add_subcommand("list", "List all installed components.");

    command->callback([]() {
        const auto install_list = LoadInstallList();

        theLog->WriteLog(emLogLevel::log_info, InstallList::ToString(install_list).c_str());
    });

    return command;
}

CLI::App* add_daeforodbc_install_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforODBC", "Install DAE for ODBC.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForOdbcInstallItem>(opt->arch);
        
        auto install_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::InstallDaeForOdbcCommand>(install_item)
        );

        install_command.Execute();
    });

    return command;
};

CLI::App* add_daeforodbc_uninstall_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforODBC", "Uninstall DAE for ODBC.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForOdbcInstallItem>(opt->arch);

        auto uninstall_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::UninstallDaeForOdbcCommand>(install_item)
        );

        uninstall_command.Execute();
    });

    return command;
}

CLI::App* add_daeforodbc_repair_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforODBC", "Repair DAE for ODBC.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForOdbcInstallItem>(opt->arch);

        auto repair_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::RepairDaeForOdbcCommand>(install_item)
        );

        repair_command.Execute();
    });

    return command;
}

CLI::App* add_daeforjdbc_install_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforJDBC", "Install DAE for JDBC.");

    command->add_flag("--oracle{0},--hana{1},--sqlserver{2}", opt->jdbc_driver_kind, "The JDBC driver to be accessed controlled.")->required();
    command->add_option("-t,--target", opt->target, "The JDBC driver path to be accessed controlled.")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForJdbcInstallItem>(opt->jdbc_driver_kind, opt->target);

        auto install_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::InstallDaeForJdbcCommand>(install_item)
        );

        install_command.Execute();
    });

    return command;
};

CLI::App* add_daeforjdbc_uninstall_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforJDBC", "Uninstall DAE for JDBC.");

    command->add_flag("--oracle{0},--hana{1},--sqlserver{2}", opt->jdbc_driver_kind, "The JDBC driver to be accessed controlled.")->required();
    command->add_option("-t,--target", opt->target, "The JDBC driver path to be accessed controlled.")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForJdbcInstallItem>(opt->jdbc_driver_kind, opt->target);
        
        auto uninstall_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::UninstallDaeForJdbcCommand>(install_item)
        );

        uninstall_command.Execute();
    });

    return command;
}

CLI::App* add_daeforjdbc_repair_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforJDBC", "Repair DAE for JDBC.");

    command->add_flag("--oracle{0},--hana{1},--sqlserver{2}", opt->jdbc_driver_kind, "The JDBC driver to be accessed controlled.")->required();
    command->add_option("-t,--target", opt->target, "The JDBC driver path to be accessed controlled.")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForJdbcInstallItem>(opt->jdbc_driver_kind, opt->target);

        auto repair_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::RepairDaeForJdbcCommand>(install_item)
        );

        repair_command.Execute();
    });

    return command;
}

CLI::App* add_daeforoci_install_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforOCI", "Install DAE for OCI.");
    
    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->add_option("-t,--target", opt->target, "OCI folder")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForOciInstallItem>(opt->arch, opt->target);
        
        auto install_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::InstallDaeForOciCommand>(install_item)
        );

        install_command.Execute();
    });

    return command;
};

CLI::App* add_daeforoci_uninstall_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforOCI", "Uninstall DAE for OCI.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->add_option("-t,--target", opt->target, "OCI folder")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForOciInstallItem>(opt->arch, opt->target);

        auto uninstall_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::UninstallDaeForOciCommand>(install_item)
        );

        uninstall_command.Execute();
    });

    return command;
}

CLI::App* add_daeforoci_repair_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforOCI", "Repair DAE for OCI.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->add_option("-t,--target", opt->target, "OCI folder")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForOciInstallItem>(opt->arch, opt->target);

        auto repair_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::RepairDaeForOciCommand>(install_item)
        );

        repair_command.Execute();
    });

    return command;
}

CLI::App* add_daeforadonet_install_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforADONET", "Install DAE for ADO.NET.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForAdoNetInstallItem>(opt->arch);

        auto install_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::InstallDaeForAdoNetCommand>(install_item)
        );

        install_command.Execute();
    });

    return command;
}

CLI::App* add_daeforadonet_uninstall_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforADONET", "Uninstall DAE for ADO.NET.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForAdoNetInstallItem>(opt->arch);

        auto uninstall_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::UninstallDaeForAdoNetCommand>(install_item)
        );

        uninstall_command.Execute();
    });

    return command;
}

CLI::App* add_daeforadonet_repair_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforADONET", "Repair DAE for ADO.NET.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->callback([opt]() {
        const auto& install_item = std::make_shared<DaeForAdoNetInstallItem>(opt->arch);

        auto repair_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::RepairDaeForAdoNetCommand>(install_item)
        );

        repair_command.Execute();
    });

    return command;
}

CLI::App* add_daeforpowerbi_install_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforPowerBI", "Install DAE for Power BI.");
    
    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->add_option("-t,--target", opt->target, "The Power BI install path to be accessed controlled.")->required();

    command->callback([opt]() {
        if (opt->arch == Architecture::kX86)
        {
            theLog->WriteLog(emLogLevel::log_info, "Not support now.");
            return;
        }

        const auto& install_item = std::make_shared<DaeForPowerBiInstallItem>(opt->arch, opt->target);

        auto install_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::InstallDaeForPowerBiCommand>(install_item)
        );

        install_command.Execute();
    });

    return command;
}

CLI::App* add_daeforpowerbi_uninstall_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforPowerBI", "Uninstall DAE for Power BI.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->add_option("-t,--target", opt->target, "The Power BI install path to be accessed controlled.")->required();

    command->callback([opt]() {
        if (opt->arch == Architecture::kX86)
        {
            theLog->WriteLog(emLogLevel::log_info, "Not support now.");
            return;
        }

        const auto& install_item = std::make_shared<DaeForPowerBiInstallItem>(opt->arch, opt->target);

        auto uninstall_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::UninstallDaeForPowerBiCommand>(install_item)
        );

        uninstall_command.Execute();
    });

    return command;
}

CLI::App* add_daeforpowerbi_repair_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DAEforPowerBI", "Repair DAE for Power BI.");

    command->add_flag("--x86{0},--x64{1}", opt->arch, "Architecture")->required();
    command->add_option("-t,--target", opt->target, "The Power BI install path to be accessed controlled.")->required();

    command->callback([opt]() {
        if (opt->arch == Architecture::kX86)
        {
            theLog->WriteLog(emLogLevel::log_info, "Not support now.");
            return;
        }

        const auto& install_item = std::make_shared<DaeForPowerBiInstallItem>(opt->arch, opt->target);

        auto repair_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::RepairDaeForPowerBiCommand>(install_item)
        );

        repair_command.Execute();
    });

    return command;
}

CLI::App* add_all_install_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("All", "Install all components.");

    command->add_option("-c,--config", opt->config_path, "Config path. If not set, use the default path:\nC:\\ProgramData\\Nextlabs\\DAEforWin\\Config\\install_config.xml");
    command->callback([opt]() {
        InstallConfig config(opt->config_path);

        const auto install_list = CreateInstallList(config);

        auto install_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::InstallAllCommand>(install_list)
        );

        install_command.Execute();
    });

    return command;
}

CLI::App* add_all_uninstall_subcommand(CLI::App* app)
{
    auto command = app->add_subcommand("All", "Uninstall all installed components");

    command->callback([]() {
        const auto install_list = LoadInstallList();

        auto uninstall_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::UninstallAllCommand>(install_list)
        );

        uninstall_command.Execute();
    });

    return command;
}

CLI::App* add_all_repair_subcommand(CLI::App* app)
{
    auto command = app->add_subcommand("All", "Repair all installed components");

    command->callback([]() {
        const auto install_list = LoadInstallList();

        auto repair_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::RepairAllCommand>(install_list)
        );

        repair_command.Execute();
    });

    return command;
}

CLI::App* add_daefordisable_sqldeveloperjdbc_runtime_subcommand(CLI::App* app)
{
    auto opt = std::make_shared<Options>();
    auto command = app->add_subcommand("DisableSqldeveloperJDBC", "Disable sqldeveloper to use JDBC driver");

    command->add_option("-t,--target", opt->target, "The install path of sqldeveloper");
    
    command->callback([opt]() {
        auto disable_command = commands::PauseAndContinueServiceDecorator(
            std::make_shared<commands::RuntimeDaeForDisableSqldeveloperJDBC>(opt->target)
        );

        disable_command.Execute();
    });

    return command;
}

CLI::App* add_daeforrestore_sqldeveloperjdbc_runtime_subcommand(CLI::App* app)
{
    auto command = app->add_subcommand("RestoreSqldeveloperJDBC", "Restore the JDBC driver of sqldeveloper");

    command->callback([]() {
        auto runtime = std::make_shared<commands::RuntimeDaeForRestoreSqldeveloperJDBC>();
        auto restore_command = commands::PauseAndContinueServiceDecorator(runtime);

        restore_command.Execute();
    });

    return command;
}

} // namespace dae_for_windows::install_manager::cli_commands