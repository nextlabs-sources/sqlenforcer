#include <string>
#include <memory>
#include <iostream>
#include <exception>

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <CLI/CLI.hpp>

#include "DAELog.h"
#include "EMDBConfig.h"
#include "cli_commands.h"

using std::string;

namespace cli_commands = dae_for_windows::install_manager::cli_commands;

int main(int argc, char** argv) try
{
    CLI::App app{"DAE for Windows install manager"};

    app.ignore_case(true);
    app.option_defaults()->ignore_case();

    {
        bool log_flag{ false };

        app.add_flag("-l,--log", log_flag, "If has this flag, it will output the log into files.");
        app.parse_complete_callback([&log_flag] {
            if (log_flag)
            {
                theLog->InitLog("install_manager");
                try
                {
                    auto log_level = std::to_string(
                        static_cast<int>(EMDBConfig::GetInstance().get_log_level())
                    );
                    //update log level
                    theLog->UpdateLogLevel(log_level);
                }
                catch (const std::exception& e)
                {
                    theLog->WriteLog(log_error, "Failed to set log level. Use the default log level.");
                }
            }
            else
            {
                theLog->InitLog();
                try
                {
                    //update log level
                    theLog->UpdateLogLevel(emLogLevel::log_debug);
                }
                catch (const std::exception& e)
                {
                    theLog->WriteLog(log_error, "Failed to set log level. Use the default log level.");
                }
            }
        });
    }

    {   // Utile command
        cli_commands::add_rename_file_subcommand(&app);
    }

    {   // List installed command
        cli_commands::add_list_all_installed_subcommand(&app);
    }

    {   // Install
        auto install_command = app.add_subcommand("install", "Install components")->require_subcommand();

        cli_commands::add_daeforodbc_install_subcommand(install_command);
        cli_commands::add_daeforjdbc_install_subcommand(install_command);
        cli_commands::add_daeforoci_install_subcommand(install_command);
        cli_commands::add_daeforadonet_install_subcommand(install_command);
        cli_commands::add_daeforpowerbi_install_subcommand(install_command);
        cli_commands::add_all_install_subcommand(install_command);
    }

    {   // Uninstall
        auto uninstall_command = app.add_subcommand("uninstall", "Uninstall components")->require_subcommand();

        cli_commands::add_daeforodbc_uninstall_subcommand(uninstall_command);
        cli_commands::add_daeforjdbc_uninstall_subcommand(uninstall_command);
        cli_commands::add_daeforoci_uninstall_subcommand(uninstall_command);
        cli_commands::add_daeforadonet_uninstall_subcommand(uninstall_command);
        cli_commands::add_daeforpowerbi_uninstall_subcommand(uninstall_command);
        cli_commands::add_all_uninstall_subcommand(uninstall_command);
    }

    {
        // Repair
        auto repair_command = app.add_subcommand("repair", "Repair components")->require_subcommand();

        cli_commands::add_daeforodbc_repair_subcommand(repair_command);
        cli_commands::add_daeforjdbc_repair_subcommand(repair_command);
        cli_commands::add_daeforoci_repair_subcommand(repair_command);
        cli_commands::add_daeforadonet_repair_subcommand(repair_command);
        cli_commands::add_daeforpowerbi_repair_subcommand(repair_command);
        cli_commands::add_all_repair_subcommand(repair_command);
    }

    {
        // Runtime
        auto runtime_command = app.add_subcommand("runtime", "")->require_subcommand();

        cli_commands::add_daefordisable_sqldeveloperjdbc_runtime_subcommand(runtime_command);
        cli_commands::add_daeforrestore_sqldeveloperjdbc_runtime_subcommand(runtime_command);
    }

    app.require_subcommand();
    CLI11_PARSE(app, argc, argv);

    return EXIT_SUCCESS;
}
catch (const std::invalid_argument& e)
{
    const auto err_msg_format = "Some error happened when run this command.\n"
                                "Error massage:\n\t%s\n";
                                
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
}
catch (const std::exception& e)
{
    const auto err_msg_format = "Some error happened when run this command.\n"
                                "Error massage:\n\t%s\n"
                                "Please make sure you run this command in administrator privileges.\n"
                                "If you still get an error when running this command with administrator privileges, please contact support.";

    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());

    return -1;
}
