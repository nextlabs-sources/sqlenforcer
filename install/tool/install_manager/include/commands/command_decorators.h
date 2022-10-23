#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_COMMAND_DECORATORS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_COMMAND_DECORATORS_H_

#include <memory>
#include <vector>

#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class TransactionCommandDecorator : public TransactionCommand
{
public:
    TransactionCommandDecorator(std::shared_ptr<Command> command);
protected:
    std::shared_ptr<Command> command_;
};

class PauseAndContinueServiceDecorator : public TransactionCommandDecorator
{
public:
    PauseAndContinueServiceDecorator(std::shared_ptr<Command> command);
};

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_COMMAND_DECORATORS_H_