#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_CLI_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_CLI_COMMANDS_H_

#include <CLI/CLI.hpp>

namespace dae_for_windows::install_manager::cli_commands
{

CLI::App* add_rename_file_subcommand(CLI::App* app);

CLI::App* add_list_all_installed_subcommand(CLI::App* app);

CLI::App* add_daeforodbc_install_subcommand(CLI::App* app);
CLI::App* add_daeforodbc_uninstall_subcommand(CLI::App* app);
CLI::App* add_daeforodbc_repair_subcommand(CLI::App* app);

CLI::App* add_daeforjdbc_install_subcommand(CLI::App* app);
CLI::App* add_daeforjdbc_uninstall_subcommand(CLI::App* app);
CLI::App* add_daeforjdbc_repair_subcommand(CLI::App* app);

CLI::App* add_daeforoci_install_subcommand(CLI::App* app);
CLI::App* add_daeforoci_uninstall_subcommand(CLI::App* app);
CLI::App* add_daeforoci_repair_subcommand(CLI::App* app);

CLI::App* add_daeforadonet_install_subcommand(CLI::App* app);
CLI::App* add_daeforadonet_uninstall_subcommand(CLI::App* app);
CLI::App* add_daeforadonet_repair_subcommand(CLI::App* app);

CLI::App* add_daeforpowerbi_install_subcommand(CLI::App* app);
CLI::App* add_daeforpowerbi_uninstall_subcommand(CLI::App* app);
CLI::App* add_daeforpowerbi_repair_subcommand(CLI::App* app);

CLI::App* add_all_install_subcommand(CLI::App* app);
CLI::App* add_all_uninstall_subcommand(CLI::App* app);
CLI::App* add_all_repair_subcommand(CLI::App* app);

CLI::App* add_daefordisable_sqldeveloperjdbc_runtime_subcommand(CLI::App* app);
CLI::App* add_daeforrestore_sqldeveloperjdbc_runtime_subcommand(CLI::App* app);

} // namespace dae_for_windows::install_manager::cli_commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_CLI_COMMANDS_H_