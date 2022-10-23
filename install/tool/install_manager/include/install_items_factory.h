#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_INSTALL_ITEMS_FACTORY_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_INSTALL_ITEMS_FACTORY_H_

#include "install_items.h"
#include "install_config.h"

namespace dae_for_windows::install_manager
{

InstallList LoadInstallList();

InstallList CreateInstallList(const InstallConfig& install_config);

} // dae_for_windows::install_manager

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_INSTALL_ITEMS_FACTORY_H_