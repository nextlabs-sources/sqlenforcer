#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_INSTALL_ITEM_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_INSTALL_ITEM_COMMANDS_H_

#include <memory>

#include "install_items.h"
#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class SaveInstallItemCommand : public Command
{
public:
    SaveInstallItemCommand(std::shared_ptr<InstallItem> install_item);
public:
    void Execute() override;
    void Undo() override;
private:
    std::shared_ptr<InstallItem> install_item_;
    bool done_ = false;
};

class RemoveInstallItemCommand : public Command
{
public:
    RemoveInstallItemCommand(std::shared_ptr<InstallItem> install_item);
public:
    void Execute() override;
    void Undo() override;
private:
    std::shared_ptr<InstallItem> install_item_;
    bool done_;
};

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_INSTALL_ITEM_COMMANDS_H_