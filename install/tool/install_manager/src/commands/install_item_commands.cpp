#include "commands/install_item_commands.h"

namespace dae_for_windows::install_manager::commands
{

SaveInstallItemCommand::SaveInstallItemCommand(
    std::shared_ptr<InstallItem> install_item
) : install_item_(install_item), done_(false)
{}

void SaveInstallItemCommand::Execute()
{
    if (!done_)
    {
        done_ = install_item_->Save();
    }
}

void SaveInstallItemCommand::Undo()
{
    if (done_)
    {
        done_ = install_item_->Remove();
    }
}

RemoveInstallItemCommand::RemoveInstallItemCommand(
    std::shared_ptr<InstallItem> install_item
) : install_item_(install_item), done_(false)
{}

void RemoveInstallItemCommand::Execute()
{
    if (!done_)
    {
        done_ = install_item_->Remove();
    }
}

void RemoveInstallItemCommand::Undo()
{
    if (done_)
    {
        done_ = install_item_->Save();
    }
}

} // namespace dae_for_windows::install_manager::commands
