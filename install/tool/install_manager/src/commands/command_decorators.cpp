#include "commands/command_decorators.h"

#include "constants.h"
#include "commands/service_commands.h"

namespace dae_for_windows::install_manager::commands
{

TransactionCommandDecorator::TransactionCommandDecorator(std::shared_ptr<Command> command)
    : TransactionCommand({}), command_(command)
{}

PauseAndContinueServiceDecorator::PauseAndContinueServiceDecorator(std::shared_ptr<Command> command)
    : TransactionCommandDecorator(command)
{
    commands_.push_back(
        std::make_shared<PauseServiceCommand>(constants::DAE_FOR_WINDOWS_SERVICE_NAME)
    );

    commands_.push_back(
        command_
    );

    commands_.push_back(
        std::make_shared<ContinueServiceCommand>(constants::DAE_FOR_WINDOWS_SERVICE_NAME)
    );
}

} // namespace dae_for_windows::install_manager::commands