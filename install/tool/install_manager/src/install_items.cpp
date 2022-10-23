#include "install_items.h"

#include <ostream>
#include <sstream>
#include <filesystem>

#include <winreg/WinReg.hpp>

#include "utils.h"

namespace fs = std::filesystem;

namespace dae_for_windows::install_manager
{

#pragma region DaeForOdbcInstallItem
DaeForOdbcInstallItem::DaeForOdbcInstallItem(Architecture arch)
    : arch_(arch)
{}

bool DaeForOdbcInstallItem::Save() const
{
    bool ret = false;
    const auto arch = get_arch();
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    if (arch == Architecture::kX86)
    {
        key.SetDwordValue(REG_VALUE_NAME_ODBC_X86, 1);
        ret = true;
    }
    else if (arch == Architecture::kX64)
    {
        key.SetDwordValue(REG_VALUE_NAME_ODBC_X64, 1);
        ret = true;
    }

    return ret;
}

bool DaeForOdbcInstallItem::Remove() const
{
    bool ret = false;
    const auto arch = get_arch();
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    if (arch == Architecture::kX86)
    {
        key.SetDwordValue(REG_VALUE_NAME_ODBC_X86, 0);
        ret = true;
    }
    else if (arch == Architecture::kX64)
    {
        key.SetDwordValue(REG_VALUE_NAME_ODBC_X64, 0);
        ret = true;
    }

    return ret;
}

bool DaeForOdbcInstallItem::Equals(const InstallItem& rhs) const
{
    const auto& r = dynamic_cast<const DaeForOdbcInstallItem&>(rhs);

    if (this == &r)
    {
        return true;
    }

    return this->get_arch() == r.get_arch();
}

bool DaeForOdbcInstallItem::IsFeatureInstalled() const
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN };
    return 1 == key.GetDwordValue(L"odbc_feature_installed");
}

Architecture DaeForOdbcInstallItem::get_arch() const
{
    return arch_;
}
#pragma endregion DaeForOdbcInstallItem

#pragma region DaeForJdbcInstallItem
DaeForJdbcInstallItem::DaeForJdbcInstallItem(
    JdbcDriverKind jdbc_driver_kind,
    fs::path target_path
)
    : jdbc_driver_kind_(jdbc_driver_kind),
      target_path_(target_path)
{}
bool DaeForJdbcInstallItem::Save() const
{
    bool ret = false;
    const auto& jdbc_driver_kind = get_jdbc_driver_kind();
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    if (jdbc_driver_kind == JdbcDriverKind::kOracle)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_OJDBC8);
        
        data_vector.insert(data_vector.cbegin(), get_target_path().wstring());
        key.SetMultiStringValue(REG_VALUE_NAME_OJDBC8, data_vector);
        ret = true;
    }
    else if (jdbc_driver_kind == JdbcDriverKind::kHana)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_NGDBC);
        
        data_vector.insert(data_vector.cbegin(), get_target_path().wstring());
        key.SetMultiStringValue(REG_VALUE_NAME_NGDBC, data_vector);
        ret = true;
    }
    else if (jdbc_driver_kind == JdbcDriverKind::kSqlServer)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_MSSQL);

        data_vector.insert(data_vector.cbegin(), get_target_path().wstring());
        key.SetMultiStringValue(REG_VALUE_NAME_MSSQL, data_vector);
        ret = true;
    }

    return ret;
}

bool DaeForJdbcInstallItem::Remove() const
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    const auto& jdbc_driver_kind = get_jdbc_driver_kind();
    const auto& target_path = get_target_path();

    if (jdbc_driver_kind == JdbcDriverKind::kOracle)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_OJDBC8);
        data_vector.erase(
            std::remove(data_vector.begin(), data_vector.end(), target_path.wstring()),
            data_vector.end()
        );

        key.SetMultiStringValue(REG_VALUE_NAME_OJDBC8, data_vector);

        return true;
    }
    else if (jdbc_driver_kind == JdbcDriverKind::kHana)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_NGDBC);
        data_vector.erase(
            std::remove(data_vector.begin(), data_vector.end(), target_path.wstring()),
            data_vector.end()
        );

        key.SetMultiStringValue(REG_VALUE_NAME_NGDBC, data_vector);

        return true;
    }
    else if (jdbc_driver_kind == JdbcDriverKind::kSqlServer)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_MSSQL);
        data_vector.erase(
            std::remove(data_vector.begin(), data_vector.end(), target_path.wstring()),
            data_vector.end()
        );

        key.SetMultiStringValue(REG_VALUE_NAME_MSSQL, data_vector);

        return true;
    }

    return false;
}

bool DaeForJdbcInstallItem::Equals(const InstallItem& rhs) const
{
    const auto& r = dynamic_cast<const DaeForJdbcInstallItem&>(rhs);

    if (this == &r)
    {
        return true;
    }

    return fs::equivalent(this->get_target_path(), r.get_target_path());
}

bool DaeForJdbcInstallItem::IsFeatureInstalled() const
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN };
    return 1 == key.GetDwordValue(L"jdbc_feature_installed");
}

JdbcDriverKind DaeForJdbcInstallItem::get_jdbc_driver_kind() const
{
    return jdbc_driver_kind_;
}

fs::path DaeForJdbcInstallItem::get_target_path() const
{
    return target_path_;
}
#pragma endregion DaeForJdbcInstallItem

#pragma region DaeForOciInstallItem
DaeForOciInstallItem::DaeForOciInstallItem(
    Architecture arch,
    fs::path target_path
) : arch_(arch),
    target_path_(target_path)
{}

bool DaeForOciInstallItem::Save() const
{
    bool ret = false;
    const auto arch = get_arch();
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    if (arch == Architecture::kX86)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_OCI_X86);
        
        data_vector.insert(data_vector.cbegin(), get_target_path().wstring());
        key.SetMultiStringValue(REG_VALUE_NAME_OCI_X86, data_vector);
        ret = true;
    }
    else if (arch == Architecture::kX64)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_OCI_X64);

        data_vector.insert(data_vector.cbegin(), get_target_path().wstring());
        key.SetMultiStringValue(REG_VALUE_NAME_OCI_X64, data_vector);
        ret = true;
    }

    return ret;
}

bool DaeForOciInstallItem::Remove() const
{
    bool ret = false;
    const auto arch = get_arch();
    const auto target_path = get_target_path();
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    if (arch == Architecture::kX86)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_OCI_X86);

        data_vector.erase(
            std::remove(data_vector.begin(), data_vector.end(), target_path.wstring()),
            data_vector.end()
        );
        key.SetMultiStringValue(REG_VALUE_NAME_OCI_X86, data_vector);
        ret = true;
    }
    else if (arch == Architecture::kX64)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_OCI_X64);

        data_vector.erase(
            std::remove(data_vector.begin(), data_vector.end(), target_path.wstring()),
            data_vector.end()
        );
        key.SetMultiStringValue(REG_VALUE_NAME_OCI_X64, data_vector);
        ret = true;
    }

    return ret;
}

bool DaeForOciInstallItem::Equals(const InstallItem& rhs) const
{
    const auto& r = dynamic_cast<const DaeForOciInstallItem&>(rhs);

    if (this == &r)
    {
        return true;
    }

    return (this->get_arch() == r.get_arch())
        && fs::equivalent(this->get_target_path(), r.get_target_path());
}

bool DaeForOciInstallItem::IsFeatureInstalled() const
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN };
    return 1 == key.GetDwordValue(L"oci_feature_installed");
}

Architecture DaeForOciInstallItem::get_arch() const
{
    return arch_;
}

fs::path DaeForOciInstallItem::get_target_path() const
{
    return target_path_;
}
#pragma endregion DaeForOciInstallItem

#pragma region DaeForAdoNetInstallItem
DaeForAdoNetInstallItem::DaeForAdoNetInstallItem(Architecture arch)
    : arch_(arch)
{}

bool DaeForAdoNetInstallItem::Save() const
{
    bool ret = false;
    const auto arch = get_arch();
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    if (arch == Architecture::kX86)
    {
        key.SetDwordValue(REG_VALUE_NAME_ADONET_X86, 1);
    }
    else if (arch == Architecture::kX64)
    {
        key.SetDwordValue(REG_VALUE_NAME_ADONET_X64, 1);
    }

    return ret;
}

bool DaeForAdoNetInstallItem::Remove() const
{
    bool ret = false;
    const auto arch = get_arch();
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    if (arch == Architecture::kX86)
    {
        key.SetDwordValue(REG_VALUE_NAME_ADONET_X86, 0);
    }
    else if (arch == Architecture::kX64)
    {
        key.SetDwordValue(REG_VALUE_NAME_ADONET_X64, 0);
    }

    return ret;
}

bool DaeForAdoNetInstallItem::Equals(const InstallItem& rhs) const
{
    const auto& r = dynamic_cast<const DaeForAdoNetInstallItem&>(rhs);

    if (this == &r)
    {
        return true;
    }

    return this->get_arch() == r.get_arch();
}

bool DaeForAdoNetInstallItem::IsFeatureInstalled() const
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN };
    return 1 == key.GetDwordValue(L"adonet_feature_installed");
}

Architecture DaeForAdoNetInstallItem::get_arch() const
{
    return arch_;
}
#pragma endregion DaeForAdoNetInstallItem

#pragma region DaeForPowerBiInstallItem
DaeForPowerBiInstallItem::DaeForPowerBiInstallItem(
    Architecture arch,
    fs::path install_path
)
    : arch_(arch), install_path_(install_path)
{}

bool DaeForPowerBiInstallItem::Save() const
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    const auto& arch = get_arch();
    const auto& install_path = get_install_path();

    if (arch == Architecture::kX64)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_POWERBI_X64);

        data_vector.insert(data_vector.cbegin(), install_path.wstring());
        key.SetMultiStringValue(REG_VALUE_NAME_POWERBI_X64, data_vector);
        return true;
    }

    return false;
}

bool DaeForPowerBiInstallItem::Remove() const
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN_2 };

    const auto& arch = get_arch();
    const auto& install_path = get_install_path();

    if (arch == Architecture::kX64)
    {
        auto data_vector = key.GetMultiStringValue(REG_VALUE_NAME_POWERBI_X64);

        data_vector.erase(
            std::remove(data_vector.begin(), data_vector.end(), install_path.wstring()),
            data_vector.end()
        );
        key.SetMultiStringValue(REG_VALUE_NAME_POWERBI_X64, data_vector);

        return true;
    }

    return false;
}

bool DaeForPowerBiInstallItem::Equals(const InstallItem& rhs) const
{
    const auto& r = dynamic_cast<const DaeForPowerBiInstallItem&>(rhs);

    if (this == &r)
    {
        return true;
    }

    return (this->get_arch() == r.get_arch())
        && fs::equivalent(this->get_install_path(), r.get_install_path());
}

bool DaeForPowerBiInstallItem::IsFeatureInstalled() const
{
    winreg::RegKey key{ HKEY_LOCAL_MACHINE, REG_KEY_DAEFORWIN };
    return 1 == key.GetDwordValue(L"adonet_feature_installed");
}

Architecture DaeForPowerBiInstallItem::get_arch() const
{
    return arch_;
}

fs::path DaeForPowerBiInstallItem::get_install_path() const
{
    return install_path_;
}

fs::path DaeForPowerBiInstallItem::GetSqlClientDllPath() const
{
    return get_install_path() / R"(bin\ADO.NET Providers\MashupSql\Microsoft.Data.SqlClient.dll)";
}
#pragma endregion DaeForPowerBiInstallItem

#pragma region InstallList

#pragma region Static Method
std::string InstallList::ToString(const InstallList& install_list)
{
    std::ostringstream oss;

    const auto dae_for_odbc_install_items = install_list.get_dae_for_odbc_install_items();
    for (const auto& install_item : dae_for_odbc_install_items)
    {
        const auto arch = install_item->get_arch();
        const auto& arch_str = GetArchitectureString(arch);

        oss << "DAE for ODBC" << "\t\t" << arch_str << std::endl;
    }

    const auto dae_for_adonet_install_items = install_list.get_dae_for_ado_net_install_items();
    for (const auto& install_item : dae_for_adonet_install_items)
    {
        const auto arch = install_item->get_arch();
        const auto& arch_str = GetArchitectureString(arch);

        oss << "DAE for ADO.NET" << "\t\t" << arch_str << std::endl;
    }

    const auto dae_for_jdbc_install_items = install_list.get_dae_for_jdbc_install_items();
    for (const auto& install_item : dae_for_jdbc_install_items)
    {
        const auto jdbc_driver_kind = install_item->get_jdbc_driver_kind();
        const auto& target_path = install_item->get_target_path();
        const auto& jdbc_driver_kind_str = GetJdbcDriverKindString(jdbc_driver_kind);

        oss << "DAE for JDBC" << "\t\t" << jdbc_driver_kind_str << "\t\t" << target_path.string() << std::endl;
    }

    const auto dae_for_oci_install_items = install_list.get_dae_for_oci_install_items();
    for (const auto& install_item : dae_for_oci_install_items)
    {
        const auto arch = install_item->get_arch();
        const auto& arch_str = GetArchitectureString(arch);
        const auto& target_path = install_item->get_target_path();

        oss << "DAE for OCI" << "\t\t" << arch_str << "\t\t" << target_path.string() << std::endl;
    }

    const auto dae_for_power_bi_install_items = install_list.get_dae_for_power_bi_install_items();
    for (const auto& install_item : dae_for_power_bi_install_items)
    {
        const auto arch = install_item->get_arch();
        const auto& arch_str = GetArchitectureString(arch);
        const auto& target_path = install_item->get_install_path();

        oss << "DAE for Power BI" << "\t" << arch_str << "\t\t" << target_path.string() << std::endl;
    }

    return oss.str();
}
#pragma endregion ToString

#pragma region Contains
bool InstallList::Contains(std::shared_ptr<DaeForOdbcInstallItem> info) const
{
    const auto& install_items = get_dae_for_odbc_install_items();

    for (const auto& install_item : install_items)
    {
        if (*install_item == *info)
        {
            return true;
        }
    }

    return false;
}

bool InstallList::Contains(std::shared_ptr<DaeForJdbcInstallItem> info) const
{
    const auto& install_items = get_dae_for_jdbc_install_items();

    for (const auto& install_item : install_items)
    {
        if (*install_item == *info)
        {
            return true;
        }
    }

    return false;
}

bool InstallList::Contains(std::shared_ptr<DaeForOciInstallItem> info) const
{
    const auto& install_items = get_dae_for_oci_install_items();

    for (const auto& install_item : install_items)
    {
        if (*install_item == *info)
        {
            return true;
        }
    }

    return false;
}

bool InstallList::Contains(std::shared_ptr<DaeForAdoNetInstallItem> info) const
{
    const auto& install_items = get_dae_for_ado_net_install_items();

    for (const auto& install_item : install_items)
    {
        if (*install_item == *info)
        {
            return true;
        }
    }

    return false;
}

bool InstallList::Contains(std::shared_ptr<DaeForPowerBiInstallItem> info) const
{
    const auto& install_items = get_dae_for_power_bi_install_items();

    for (const auto& install_item : install_items)
    {
        if (*install_item == *info)
        {
            return true;
        }
    }

    return false;
}

#pragma endregion Contains

std::shared_ptr<DaeForJdbcInstallItem> InstallList::SearchDaeForJdbcInstallItem(const std::filesystem::path& target_path) const
{
    const auto install_items = get_dae_for_jdbc_install_items();

    for (const auto& install_item : install_items)
    {
        if (fs::equivalent(install_item->get_target_path(), target_path))
        {
            return install_item;
        }
    }

    return nullptr;
}

#pragma region Setters
void InstallList::add_dae_for_odbc_install_item(std::shared_ptr<DaeForOdbcInstallItem> info)
{
    dae_for_odbc_install_items_.push_back(info);
}

void InstallList::add_dae_for_jdbc_install_item(std::shared_ptr<DaeForJdbcInstallItem> info)
{
    dae_for_jdbc_install_items_.push_back(info);
}

void InstallList::add_dae_for_oci_install_item(std::shared_ptr<DaeForOciInstallItem> info)
{
    dae_for_oci_install_items_.push_back(info);
}

void InstallList::add_dae_for_ado_net_install_item(std::shared_ptr<DaeForAdoNetInstallItem> info)
{
    dae_for_ado_net_install_items_.push_back(info);
}

void InstallList::add_dae_for_power_bi_install_item(std::shared_ptr<DaeForPowerBiInstallItem> info)
{
    dae_for_power_bi_install_items_.push_back(info);
}
#pragma endregion Setters

#pragma region Getters
std::vector<std::shared_ptr<DaeForOdbcInstallItem>> InstallList::get_dae_for_odbc_install_items() const
{
    return dae_for_odbc_install_items_;
}

std::vector<std::shared_ptr<DaeForJdbcInstallItem>> InstallList::get_dae_for_jdbc_install_items() const
{
    return dae_for_jdbc_install_items_;
}

std::vector<std::shared_ptr<DaeForOciInstallItem>> InstallList::get_dae_for_oci_install_items() const
{
    return dae_for_oci_install_items_;
}

std::vector<std::shared_ptr<DaeForAdoNetInstallItem>> InstallList::get_dae_for_ado_net_install_items() const
{
    return dae_for_ado_net_install_items_;
}

std::vector<std::shared_ptr<DaeForPowerBiInstallItem>> InstallList::get_dae_for_power_bi_install_items() const
{
    return dae_for_power_bi_install_items_;
}
#pragma endregion Getters

std::ostream& operator<<(std::ostream& os, const InstallList& install_list)
{
    os << InstallList::ToString(install_list);

    return os;
}

#pragma endregion InstallList

} // dae_for_windows::install_manager