#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_INSTALL_ITEMS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_INSTALL_ITEMS_H_

#include <map>
#include <string>
#include <ostream>
#include <filesystem>
#include <typeinfo>

namespace dae_for_windows::install_manager
{

#pragma region Enums
enum class JdbcDriverKind
{
    kOracle,
    kHana,
    kSqlServer
};

enum class Architecture
{
    kX86,
    kX64,
    kAnyCpu
};
#pragma endregion Enums

#pragma region Enum to string functions
inline std::string GetJdbcDriverKindString(JdbcDriverKind jdbc_driver_kind)
{
    const std::map<JdbcDriverKind, std::string> enum_string{
        { JdbcDriverKind::kOracle, std::string("Oracle") },
        { JdbcDriverKind::kHana, std::string("Hana") },
        { JdbcDriverKind::kSqlServer, std::string("MSSql") },
    };

    auto it = enum_string.find(jdbc_driver_kind);

    if (it == enum_string.end())
    {
        throw std::exception("Wrong JDBC driver kind");
    }

    return it->second;
}

inline std::string GetArchitectureString(Architecture arch)
{
    const std::map<Architecture, std::string> enum_string{
        { Architecture::kX86, std::string("X86") },
        { Architecture::kX64, std::string("X64") }
    };

    auto it = enum_string.find(arch);

    if (it == enum_string.end())
    {
        throw std::exception("Wrong architecture");
    }

    return it->second;
}
#pragma endregion Enum to string functions

#pragma region Constants
constexpr auto REG_KEY_DAEFORWIN = LR"(SOFTWARE\Nextlabs\DAEforWin)";
constexpr auto REG_KEY_DAEFORWIN_2 = LR"(SOFTWARE\Nextlabs\DAEforWin\2.0)";
constexpr auto REG_VALUE_NAME_NGDBC = L"jdbc_ngdbc";
constexpr auto REG_VALUE_NAME_OJDBC8 = L"jdbc_ojdbc8";
constexpr auto REG_VALUE_NAME_MSSQL = L"jdbc_mssql";
constexpr auto REG_VALUE_NAME_ODBC_X86 = L"odbc_x86";
constexpr auto REG_VALUE_NAME_ODBC_X64 = L"odbc_x64";
constexpr auto REG_VALUE_NAME_OCI_X86 = L"oci_x86";
constexpr auto REG_VALUE_NAME_OCI_X64 = L"oci_x64";
constexpr auto REG_VALUE_NAME_ADONET_X86 = L"adonet_x86";
constexpr auto REG_VALUE_NAME_ADONET_X64 = L"adonet_x64";
constexpr auto REG_VALUE_NAME_POWERBI_X64 = L"powerbi_x64";
#pragma endregion Constants

#pragma region Install item classes
class InstallItem
{
public:
    virtual bool Save() const { return false; };
    virtual bool Remove() const { return false; };
    virtual bool Equals(const InstallItem& rhs) const = 0;
    virtual bool IsFeatureInstalled() const = 0;

    bool operator==(const InstallItem& rhs)
    {
        return typeid(*this) == typeid(rhs) && this->Equals(rhs);
    }

    bool operator!=(const InstallItem& rhs)
    {
        return !(*this == rhs);
    }
};

class DaeForOdbcInstallItem : public InstallItem
{
public:
    DaeForOdbcInstallItem(Architecture arch);
public:
    bool Save() const override;
    bool Remove() const override;
    bool Equals(const InstallItem& rhs) const;
    bool IsFeatureInstalled() const;
public:
    Architecture get_arch() const;
private:
    Architecture arch_;
};

class DaeForJdbcInstallItem : public InstallItem
{
public:
    DaeForJdbcInstallItem(
        JdbcDriverKind jdbc_driver_kind,
        std::filesystem::path target_path
    );
public:
    bool Save() const override;
    bool Remove() const override;
    /// <summary>
    /// Check if the DaeForJdbcInstallItem equals the others.
    /// </summary>
    /// <param name="rhs">The other one to be checked.</param>
    /// <returns>
    /// Return true, if it has the same target path.
    /// Otherwise, it returns false.
    /// </returns>
    bool Equals(const InstallItem& rhs) const;
    bool IsFeatureInstalled() const;
public:
    JdbcDriverKind get_jdbc_driver_kind() const;
    std::filesystem::path get_target_path() const;
private:
    JdbcDriverKind jdbc_driver_kind_;
    std::filesystem::path target_path_;
};

class DaeForOciInstallItem : public InstallItem
{
public:
    DaeForOciInstallItem(
        Architecture arch,
        std::filesystem::path target_path
    );
public:
    bool Save() const override;
    bool Remove() const override;
    bool Equals(const InstallItem& rhs) const;
    bool IsFeatureInstalled() const;
public:
    Architecture get_arch() const;
    std::filesystem::path get_target_path() const;
private:
    Architecture arch_;
    std::filesystem::path target_path_;
};

class DaeForAdoNetInstallItem : public InstallItem
{
public:
    DaeForAdoNetInstallItem(Architecture arch);
public:
    bool Save() const override;
    bool Remove() const override;
    bool Equals(const InstallItem& rhs) const;
    bool IsFeatureInstalled() const;
public:
    Architecture get_arch() const;
private:
    Architecture arch_;
};

class DaeForPowerBiInstallItem : public InstallItem
{
public:
    DaeForPowerBiInstallItem(
        Architecture arch,
        std::filesystem::path install_path
    );
public:
    bool Save() const override;
    bool Remove() const override;
    bool Equals(const InstallItem& rhs) const;
    bool IsFeatureInstalled() const;
public:
    Architecture get_arch() const;
    std::filesystem::path get_install_path() const;
    std::filesystem::path GetSqlClientDllPath() const;
private:
    Architecture arch_;
    std::filesystem::path install_path_;
};
#pragma endregion Install item classes

#pragma region Install item list class
class InstallList
{
public:
    InstallList() = default;

public:
    std::string static ToString(const InstallList& install_list);

public:
    bool Contains(std::shared_ptr<DaeForOdbcInstallItem> info) const;
    bool Contains(std::shared_ptr<DaeForJdbcInstallItem> info) const;
    bool Contains(std::shared_ptr<DaeForOciInstallItem> info) const;
    bool Contains(std::shared_ptr<DaeForAdoNetInstallItem> info) const;
    bool Contains(std::shared_ptr<DaeForPowerBiInstallItem> info) const;

    /// <summary>
    /// Use a target path to search for the correspond DaeForJdbcInstallItem.
    /// </summary>
    /// <param name="target">The target path to be searched.</param>
    /// <returns>
    /// If find, return the correspond DaeForJdbcInstallItem.
    /// If not find, return a null shared_ptr.
    /// </returns>
    std::shared_ptr<DaeForJdbcInstallItem> SearchDaeForJdbcInstallItem(const std::filesystem::path& target_path) const;

public:
    void add_dae_for_odbc_install_item(std::shared_ptr<DaeForOdbcInstallItem> info);
    void add_dae_for_jdbc_install_item(std::shared_ptr<DaeForJdbcInstallItem> info);
    void add_dae_for_oci_install_item(std::shared_ptr<DaeForOciInstallItem> info);
    void add_dae_for_ado_net_install_item(std::shared_ptr<DaeForAdoNetInstallItem> info);
    void add_dae_for_power_bi_install_item(std::shared_ptr<DaeForPowerBiInstallItem> info);

    std::vector<std::shared_ptr<DaeForOdbcInstallItem>> get_dae_for_odbc_install_items() const;
    std::vector<std::shared_ptr<DaeForJdbcInstallItem>> get_dae_for_jdbc_install_items() const;
    std::vector<std::shared_ptr<DaeForOciInstallItem>> get_dae_for_oci_install_items() const;
    std::vector<std::shared_ptr<DaeForAdoNetInstallItem>> get_dae_for_ado_net_install_items() const;
    std::vector<std::shared_ptr<DaeForPowerBiInstallItem>> get_dae_for_power_bi_install_items() const;

private:
    std::vector<std::shared_ptr<DaeForOdbcInstallItem>> dae_for_odbc_install_items_;
    std::vector<std::shared_ptr<DaeForJdbcInstallItem>> dae_for_jdbc_install_items_;
    std::vector<std::shared_ptr<DaeForOciInstallItem>> dae_for_oci_install_items_;
    std::vector<std::shared_ptr<DaeForAdoNetInstallItem>> dae_for_ado_net_install_items_;
    std::vector<std::shared_ptr<DaeForPowerBiInstallItem>> dae_for_power_bi_install_items_;
};

std::ostream& operator<<(std::ostream& os, const InstallList& install_list);
#pragma endregion Install item list class

} // dae_for_windows::install_manager

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_INSTALL_ITEMS_H_