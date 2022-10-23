#include "install_config.h"

#include <string>
#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "DAELog.h"
#include "utils.h"

using boost::property_tree::ptree;
namespace xml_parser = boost::property_tree::xml_parser;

namespace dae_for_windows::install_manager
{

InstallConfig::InstallConfig(const std::string& config_path)
    : config_path_(config_path),
      daeforodbc_x86_target_(false),
      daeforodbc_x64_target_(false),
      daeforadonet_x86_target_(false),
      daeforadonet_x64_target_(false),
      daeforoci_x86_targets_(),
      daeforoci_x64_targets_(),
      daeforjdbc_ojdbc8_targets_(),
      daeforjdbc_ngdbc_targets_(),
      daeforjdbc_mssql_targets_(),
      daeforpowerbi_x64_targets_()
{
  ptree pt;
  xml_parser::read_xml(config_path, pt);

  set_daeforodbc_x86_target(pt);
  set_daeforodbc_x64_target(pt);
  set_daeforadonet_x86_target(pt);
  set_daeforadonet_x64_target(pt);
  set_daeforoci_x86_targets(pt);
  set_daeforoci_x64_targets(pt);
  set_daeforjdbc_ojdbc8_targets(pt);
  set_daeforjdbc_ngdbc_targets(pt);
  set_daeforjdbc_mssql_targets(pt);
  set_daeforpowerbi_x64_targets(pt);
}

std::string InstallConfig::get_config_path() const noexcept
{
  return config_path_;
}

bool InstallConfig::get_daeforodbc_x86_target() const noexcept
{
  return daeforodbc_x86_target_;
}

bool InstallConfig::get_daeforodbc_x64_target() const noexcept
{
  return daeforodbc_x64_target_;
}

bool InstallConfig::get_daeforadonet_x86_target() const noexcept
{
  return daeforadonet_x86_target_;
}

bool InstallConfig::get_daeforadonet_x64_target() const noexcept
{
  return daeforadonet_x64_target_;
}

std::vector<std::string> InstallConfig::get_daeforoci_x86_targets() const noexcept
{
  return daeforoci_x86_targets_;
}

std::vector<std::string> InstallConfig::get_daeforoci_x64_targets() const noexcept
{
  return daeforoci_x64_targets_;
}

std::vector<std::string> InstallConfig::get_daeforjdbc_ojdbc8_targets() const noexcept
{
  return daeforjdbc_ojdbc8_targets_;
}

std::vector<std::string> InstallConfig::get_daeforjdbc_ngdbc_targets() const noexcept
{
  return daeforjdbc_ngdbc_targets_;
}

std::vector<std::string> InstallConfig::get_daeforjdbc_mssql_targets() const noexcept
{
    return daeforjdbc_mssql_targets_;
}

std::vector<std::string> InstallConfig::get_daeforpowerbi_x64_targets() const noexcept
{
  return daeforpowerbi_x64_targets_;
}

void InstallConfig::set_daeforodbc_x86_target(const ptree& tree) noexcept
{
  try
  {
    const auto& daeforodbc_config_tree = tree.get_child("installConfig.components.DAEforODBC");
    const auto& architectures = daeforodbc_config_tree.get_child("<xmlattr>.targetArchitecture").data();

    for (const auto& arch : utils::SplitString(architectures, '|'))
    {
      if (utils::CaseInsensitiveEquals("X86", arch))
      {
        daeforodbc_x86_target_ = true;
        return;
      }
    }
  }
  catch (const std::exception& e)
  {
    const auto err_msg_format = "Fail to read config for DAEforODBC(x86). Error massage: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

void InstallConfig::set_daeforodbc_x64_target(const ptree& tree) noexcept
{
  try
  {
    const auto& daeforodbc_config_tree = tree.get_child("installConfig.components.DAEforODBC");
    const auto& architectures = daeforodbc_config_tree.get_child("<xmlattr>.targetArchitecture").data();

    for (const auto& arch : utils::SplitString(architectures, '|'))
    {
      if (utils::CaseInsensitiveEquals("X64", arch))
{
        daeforodbc_x64_target_ = true;
        return;
      }
    }
  }
  catch (const std::exception& e)
{
    const auto err_msg_format = "Fail to read config for DAEforODBC(x64). Error massage: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

void InstallConfig::set_daeforadonet_x86_target(const ptree& tree) noexcept
{
  try
  {
    const auto& daeforadonet_config_tree = tree.get_child("installConfig.components.DAEforADONET");
    const auto& architectures = daeforadonet_config_tree.get_child("<xmlattr>.targetArchitecture").data();

    for (const auto& arch : utils::SplitString(architectures, '|'))
{
      if (utils::CaseInsensitiveEquals("X86", arch))
{
        daeforadonet_x86_target_ = true;
        return;
      }
    }
  }
  catch (const std::exception& e)
{
    const auto err_msg_format = "Fail to read config for DAEforADONET(x86). Error massage: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

void InstallConfig::set_daeforadonet_x64_target(const ptree& tree) noexcept
{
  try
{
    const auto& daeforadonet_config_tree = tree.get_child("installConfig.components.DAEforADONET");
    const auto& architectures = daeforadonet_config_tree.get_child("<xmlattr>.targetArchitecture").data();

    for (const auto& arch : utils::SplitString(architectures, '|'))
{
      if (utils::CaseInsensitiveEquals("X64", arch))
{
        daeforadonet_x64_target_ = true;
        return;
      }
    }
  }
  catch (const std::exception& e)
{
    const auto err_msg_format = "Fail to read config for DAEforADONET(x64). Error massage: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

void InstallConfig::set_daeforoci_x86_targets(const ptree& tree) noexcept
{
  try
{
    const auto& targets_tree = tree.get_child("installConfig.components.DAEforOCI.x86Targets");
    const auto& target_range = targets_tree.equal_range("x86Target");

    for (auto it = target_range.first; it != target_range.second; ++it)
{
      const auto& data = it->second.data();

      if (!data.empty())
{
        daeforoci_x86_targets_.push_back(it->second.data());
      }
    }
  }
  catch (const std::exception& e)
{
    const auto err_msg_format = "Fail to read config for DAEforOCI(x86). Error massage: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

void InstallConfig::set_daeforoci_x64_targets(const ptree& tree) noexcept
{
  try
{
    const auto& targets_tree = tree.get_child("installConfig.components.DAEforOCI.x64Targets");
    const auto& target_range = targets_tree.equal_range("x64Target");

    for (auto it = target_range.first; it != target_range.second; ++it)
{
      const auto& data = it->second.data();

      if (!data.empty())
{
        daeforoci_x64_targets_.push_back(it->second.data());
      }
    }
  }
  catch (const std::exception& e)
{
    const auto err_msg_format = "Fail to read config for DAEforOCI(x64). Error massage: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

void InstallConfig::set_daeforjdbc_ojdbc8_targets(const boost::property_tree::ptree& tree) noexcept
{
  try
{
    const auto& targets_tree = tree.get_child("installConfig.components.DAEforJDBC.ojdbc8");
    const auto& target_range = targets_tree.equal_range("target");

    for (auto it = target_range.first; it != target_range.second; ++it)
{
      const auto& data = it->second.data();

      if (!data.empty())
{
        daeforjdbc_ojdbc8_targets_.push_back(it->second.data());
      }
    }
  }
  catch (const std::exception& e)
{
    const auto err_msg_format = "Fail to read config for DAEforJDBC(ojdbc8). Error message: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

void InstallConfig::set_daeforjdbc_ngdbc_targets(const boost::property_tree::ptree& tree) noexcept
{
  try
{
    const auto& targets_tree = tree.get_child("installConfig.components.DAEforJDBC.ngdbc");
    const auto& target_range = targets_tree.equal_range("target");

    for (auto it = target_range.first; it != target_range.second; ++it)
{
      const auto& data = it->second.data();

      if (!data.empty())
{
        daeforjdbc_ngdbc_targets_.push_back(it->second.data());
      }
    }
  }
  catch (const std::exception& e)
{
    const auto err_msg_format = "Fail to read config for DAEforJDBC(ngdbc). Error message: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

void InstallConfig::set_daeforjdbc_mssql_targets(const boost::property_tree::ptree& tree) noexcept
{
    try
    {
        const auto& targets_tree = tree.get_child("installConfig.components.DAEforJDBC.mssql");
        const auto& target_range = targets_tree.equal_range("target");

        for (auto it = target_range.first; it != target_range.second; ++it)
        {
            const auto& data = it->second.data();

            if (!data.empty())
            {
                daeforjdbc_mssql_targets_.push_back(it->second.data());
            }
        }
    }
    catch (const std::exception& e)
    {
        const auto err_msg_format = "Fail to read config for DAEforJDBC(mssql). Error message: %s";
        theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
    }
}

void InstallConfig::set_daeforpowerbi_x64_targets(const boost::property_tree::ptree& tree) noexcept
{
  try
{
    const auto& targets_tree = tree.get_child("installConfig.components.DAEforPowerBI.x64Targets");
    const auto& target_range = targets_tree.equal_range("x64Target");

    for (auto it = target_range.first; it != target_range.second; ++it)
{
      const auto& data = it->second.data();

      if (!data.empty())
{
        daeforpowerbi_x64_targets_.push_back(it->second.data());
      }
    }
  }
  catch (const std::exception& e)
{
    const auto err_msg_format = "Fail to read config for DAEforPowerBI(x64). Error massage: %s";
    theLog->WriteLog(emLogLevel::log_error, err_msg_format, e.what());
  }
}

}