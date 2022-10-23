#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_CONFIG_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_CONFIG_H_

#include <string>
#include <vector>

#include <boost/property_tree/ptree.hpp>

namespace dae_for_windows::install_manager
{

class InstallConfig
{
public:
    InstallConfig(const std::string& config_path);

public:
    std::string get_config_path() const noexcept;
    bool get_daeforodbc_x86_target() const noexcept;
    bool get_daeforodbc_x64_target() const noexcept;
    bool get_daeforadonet_x86_target() const noexcept;
    bool get_daeforadonet_x64_target() const noexcept;
    std::vector<std::string> get_daeforoci_x86_targets() const noexcept;
    std::vector<std::string> get_daeforoci_x64_targets() const noexcept;
    std::vector<std::string> get_daeforjdbc_ojdbc8_targets() const noexcept;
    std::vector<std::string> get_daeforjdbc_ngdbc_targets() const noexcept;
    std::vector<std::string> get_daeforjdbc_mssql_targets() const noexcept;
    std::vector<std::string> get_daeforpowerbi_x64_targets() const noexcept;

    void set_daeforodbc_x86_target(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforodbc_x64_target(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforadonet_x86_target(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforadonet_x64_target(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforoci_x86_targets(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforoci_x64_targets(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforjdbc_ojdbc8_targets(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforjdbc_ngdbc_targets(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforjdbc_mssql_targets(const boost::property_tree::ptree& tree) noexcept;
    void set_daeforpowerbi_x64_targets(const boost::property_tree::ptree& tree) noexcept;

private:
    std::string config_path_;
    bool daeforodbc_x86_target_;
    bool daeforodbc_x64_target_;
    bool daeforadonet_x86_target_;
    bool daeforadonet_x64_target_;
    std::vector<std::string> daeforoci_x86_targets_;
    std::vector<std::string> daeforoci_x64_targets_;
    std::vector<std::string> daeforjdbc_ojdbc8_targets_;
    std::vector<std::string> daeforjdbc_ngdbc_targets_;
    std::vector<std::string> daeforjdbc_mssql_targets_;
    std::vector<std::string> daeforpowerbi_x64_targets_;
};

} // namespace dae_for_windows::install_manager

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_CONFIG_H_