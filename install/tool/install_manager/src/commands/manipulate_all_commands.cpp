#include "commands/manipulate_all_commands.h"

#include "DAELog.h"
#include "constants.h"

#include "commands/dae_for_ado_net_commands.h"
#include "commands/dae_for_jdbc_commands.h"
#include "commands/dae_for_oci_commands.h"
#include "commands/dae_for_odbc_commands.h"
#include "commands/dae_for_power_bi_commands.h"
#include "commands/service_commands.h"

namespace dae_for_windows::install_manager::commands
{

InstallAllCommand::InstallAllCommand(const InstallList& install_list)
    : MacroCommand({}), install_list_(install_list)
{
    const auto& dae_for_odbc_install_items = install_list_.get_dae_for_odbc_install_items();
    for (const auto& install_item : dae_for_odbc_install_items)
    {
        commands_.push_back(
            std::make_shared<InstallDaeForOdbcCommand>(install_item)
        );
    }

    const auto& dae_for_jdbc_install_items = install_list_.get_dae_for_jdbc_install_items();
    for (const auto& install_item : dae_for_jdbc_install_items)
    {
        try
        {
            commands_.push_back(
                std::make_shared<InstallDaeForJdbcCommand>(install_item)
            );
        }
        catch (const std::exception& e)
        {
            theLog->WriteLog(emLogLevel::log_error, "%s", e.what());
        }
    }

    const auto& dae_for_oci_install_items = install_list_.get_dae_for_oci_install_items();
    for (const auto& install_item : dae_for_oci_install_items)
    {
        commands_.push_back(
            std::make_shared<InstallDaeForOciCommand>(install_item)
        );
    }

    const auto& dae_for_ado_net_install_items = install_list_.get_dae_for_ado_net_install_items();
    for (const auto& install_item : dae_for_ado_net_install_items)
    {
        commands_.push_back(
            std::make_shared<InstallDaeForAdoNetCommand>(install_item)
        );
    }

    const auto& dae_for_power_bi_install_items = install_list_.get_dae_for_power_bi_install_items();
    for (const auto& install_item : dae_for_power_bi_install_items)
    {
        commands_.push_back(
            std::make_shared<InstallDaeForPowerBiCommand>(install_item)
        );
    }
}

void InstallAllCommand::Execute()
{
    MacroCommand::Execute();
}

UninstallAllCommand::UninstallAllCommand(const InstallList& install_list)
    : MacroCommand({}), install_list_(install_list)
{
    const auto& dae_for_odbc_install_items = install_list_.get_dae_for_odbc_install_items();
    for (const auto& install_item : dae_for_odbc_install_items)
    {
        commands_.push_back(
            std::make_shared<UninstallDaeForOdbcCommand>(install_item)
        );
    }

    const auto& dae_for_jdbc_install_items = install_list_.get_dae_for_jdbc_install_items();
    for (const auto& install_item : dae_for_jdbc_install_items)
    {
        commands_.push_back(
            std::make_shared<UninstallDaeForJdbcCommand>(install_item)
        );
    }

    const auto& dae_for_oci_install_items = install_list_.get_dae_for_oci_install_items();
    for (const auto& install_item : dae_for_oci_install_items)
    {
        commands_.push_back(
            std::make_shared<UninstallDaeForOciCommand>(install_item)
        );
    }

    const auto& dae_for_ado_net_install_items = install_list_.get_dae_for_ado_net_install_items();
    for (const auto& install_item : dae_for_ado_net_install_items)
    {
        commands_.push_back(
            std::make_shared<UninstallDaeForAdoNetCommand>(install_item)
        );
    }

    const auto& dae_for_power_bi_install_items = install_list_.get_dae_for_power_bi_install_items();
    for (const auto& install_item : dae_for_power_bi_install_items)
    {
        commands_.push_back(
            std::make_shared<UninstallDaeForPowerBiCommand>(install_item)
        );
    }
}

void UninstallAllCommand::Execute()
{
    MacroCommand::Execute();
}

RepairAllCommand::RepairAllCommand(const InstallList& install_list)
    : MacroCommand({}), install_list_(install_list)
{
    const auto dae_for_odbc_install_items = install_list_.get_dae_for_odbc_install_items();
    for (const auto& install_item : dae_for_odbc_install_items)
    {
        commands_.push_back(
            std::make_shared<RepairDaeForOdbcCommand>(install_item)
        );
    }

    const auto dae_for_jdbc_install_items = install_list_.get_dae_for_jdbc_install_items();
    for (const auto& install_item : dae_for_jdbc_install_items)
    {
        commands_.push_back(
            std::make_shared<RepairDaeForJdbcCommand>(install_item)
        );
    }

    const auto dae_for_oci_install_items = install_list_.get_dae_for_oci_install_items();
    for (const auto& install_item : dae_for_oci_install_items)
    {
        commands_.push_back(
            std::make_shared<RepairDaeForOciCommand>(install_item)
        );
    }

    const auto dae_for_ado_net_install_items = install_list_.get_dae_for_ado_net_install_items();
    for (const auto& install_item : dae_for_ado_net_install_items)
    {
        commands_.push_back(
            std::make_shared<RepairDaeForAdoNetCommand>(install_item)
        );
    }

    const auto dae_for_power_bi_install_items = install_list_.get_dae_for_power_bi_install_items();
    for (const auto& install_item : dae_for_power_bi_install_items)
    {
        commands_.push_back(
            std::make_shared<RepairDaeForPowerBiCommand>(install_item)
        );
    }
}

void RepairAllCommand::Execute()
{
    MacroCommand::Execute();
}

} // namespace dae_for_windows::install_manager::commands
