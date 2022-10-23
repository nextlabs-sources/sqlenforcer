#include "install_items_factory.h"

#include <memory>

#include <winreg/WinReg.hpp>

#include "install_items.h"
#include "install_config.h"

namespace dae_for_windows::install_manager
{

InstallList LoadInstallList()
{
    InstallList install_list;
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    const auto reg_value_data_odbc_x86 = key.GetDwordValue(REG_VALUE_NAME_ODBC_X86);
    if (reg_value_data_odbc_x86 != 0)
    {
        install_list.add_dae_for_odbc_install_item(
            std::make_shared<DaeForOdbcInstallItem>(Architecture::kX86)
        );
    }

    const auto reg_value_data_odbc_x64 = key.GetDwordValue(REG_VALUE_NAME_ODBC_X64);
    if (reg_value_data_odbc_x64 != 0)
    {
        install_list.add_dae_for_odbc_install_item(
            std::make_shared<DaeForOdbcInstallItem>(Architecture::kX64)
        );
    }

    const auto reg_value_data_adonet_x86 = key.GetDwordValue(REG_VALUE_NAME_ADONET_X86);
    if (reg_value_data_adonet_x86 != 0)
    {
        install_list.add_dae_for_ado_net_install_item(
            std::make_shared<DaeForAdoNetInstallItem>(Architecture::kX86)
        );
    }

    const auto reg_value_data_adonet_x64 = key.GetDwordValue(REG_VALUE_NAME_ADONET_X64);
    if (reg_value_data_adonet_x64 != 0)
    {
        install_list.add_dae_for_ado_net_install_item(
            std::make_shared<DaeForAdoNetInstallItem>(Architecture::kX64)
        );
    }

    const auto daeforoci_x86_targets = key.GetMultiStringValue(REG_VALUE_NAME_OCI_X86);
    for (const auto& target : daeforoci_x86_targets)
    {
        if (!target.empty())
        {
            install_list.add_dae_for_oci_install_item(
                std::make_shared<DaeForOciInstallItem>(Architecture::kX86, target)
            );
        }
    }

    const auto daeforoci_x64_targets = key.GetMultiStringValue(REG_VALUE_NAME_OCI_X64);
    for (const auto& target : daeforoci_x64_targets)
    {
        if (!target.empty())
        {
            install_list.add_dae_for_oci_install_item(
                std::make_shared<DaeForOciInstallItem>(Architecture::kX64, target)
            );
        }
    }

    const auto daeforjdbc_ojdbc8_targets = key.GetMultiStringValue(REG_VALUE_NAME_OJDBC8);

    for (const auto& target : daeforjdbc_ojdbc8_targets)
    {
        if (!target.empty())
        {
            install_list.add_dae_for_jdbc_install_item(
                std::make_shared<DaeForJdbcInstallItem>(JdbcDriverKind::kOracle, target)
            );
        }
    }

    const auto daeforjdbc_mssql_targets = key.GetMultiStringValue(REG_VALUE_NAME_MSSQL);

    for (const auto& target : daeforjdbc_mssql_targets)
    {
        if (!target.empty())
        {
            install_list.add_dae_for_jdbc_install_item(
                std::make_shared<DaeForJdbcInstallItem>(JdbcDriverKind::kSqlServer, target)
            );
        }
    }

    const auto& daeforjdbc_ngdbc_targets = key.GetMultiStringValue(REG_VALUE_NAME_NGDBC);

    for (const auto& target : daeforjdbc_ngdbc_targets)
    {
        if (!target.empty())
        {
            install_list.add_dae_for_jdbc_install_item(
                std::make_shared<DaeForJdbcInstallItem>(JdbcDriverKind::kHana, target)
            );
        }
    }

    const auto& daeforpowerbi_x64_targets = key.GetMultiStringValue(REG_VALUE_NAME_POWERBI_X64);

    for (const auto& target : daeforpowerbi_x64_targets)
    {
        if (!target.empty())
        {
            install_list.add_dae_for_power_bi_install_item(
                std::make_shared<DaeForPowerBiInstallItem>(Architecture::kX64, target)
            );
        }
    }

    return install_list;
}

InstallList CreateInstallList(const InstallConfig& install_config)
{
    InstallList install_list;

    if (install_config.get_daeforodbc_x86_target())
    {
        install_list.add_dae_for_odbc_install_item(
            std::make_shared<DaeForOdbcInstallItem>(Architecture::kX86)
        );
    }

    if (install_config.get_daeforodbc_x64_target())
    {
        install_list.add_dae_for_odbc_install_item(
            std::make_shared<DaeForOdbcInstallItem>(Architecture::kX64)
        );
    }

    if (install_config.get_daeforadonet_x86_target())
    {
        install_list.add_dae_for_ado_net_install_item(
            std::make_shared<DaeForAdoNetInstallItem>(Architecture::kX86)
        );
    }

    if (install_config.get_daeforadonet_x64_target())
    {
        install_list.add_dae_for_ado_net_install_item(
            std::make_shared<DaeForAdoNetInstallItem>(Architecture::kX64)
        );
    }

    const auto& daeforoci_x86_targets = install_config.get_daeforoci_x86_targets();

    for (const auto& target : daeforoci_x86_targets)
    {
        install_list.add_dae_for_oci_install_item(
            std::make_shared<DaeForOciInstallItem>(Architecture::kX86, target)
        );
    }

    const auto& daeforoci_x64_targets = install_config.get_daeforoci_x64_targets();

    for (const auto& target : daeforoci_x64_targets)
    {
        install_list.add_dae_for_oci_install_item(
            std::make_shared<DaeForOciInstallItem>(Architecture::kX64, target)
        );
    }

    const auto& daeforjdbc_ojdbc8_targets = install_config.get_daeforjdbc_ojdbc8_targets();

    for (const auto& target : daeforjdbc_ojdbc8_targets)
    {
        install_list.add_dae_for_jdbc_install_item(
            std::make_shared<DaeForJdbcInstallItem>(JdbcDriverKind::kOracle, target)
        );
    }

    const auto& daeforjdbc_mssql_targets = install_config.get_daeforjdbc_mssql_targets();

    for (const auto& target : daeforjdbc_mssql_targets)
    {
        install_list.add_dae_for_jdbc_install_item(
            std::make_shared<DaeForJdbcInstallItem>(JdbcDriverKind::kSqlServer, target)
        );
    }

    const auto& daeforjdbc_ngdbc_targets = install_config.get_daeforjdbc_ngdbc_targets();

    for (const auto& target : daeforjdbc_ngdbc_targets)
    {
        install_list.add_dae_for_jdbc_install_item(
            std::make_shared<DaeForJdbcInstallItem>(JdbcDriverKind::kHana, target)
        );
    }

    const auto& daeforpowerbi_x64_targets = install_config.get_daeforpowerbi_x64_targets();

    for (const auto& target : daeforpowerbi_x64_targets)
    {
        install_list.add_dae_for_power_bi_install_item(
            std::make_shared<DaeForPowerBiInstallItem>(Architecture::kX64, target)
        );
    }

    return install_list;
}

} // dae_for_windows::install_manager