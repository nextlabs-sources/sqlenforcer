#include "commands/base_commands.h"

#include <stack>

namespace dae_for_windows::install_manager::commands
{

MacroCommand::MacroCommand(std::vector<std::shared_ptr<Command>> commands)
    : commands_(commands)
{}

void MacroCommand::Execute()
{
    for (auto& command : commands_)
    {
        command->Execute();
    }
}

void MacroCommand::Undo()
{
    for (auto it = commands_.crbegin(); it != commands_.crend(); ++it)
    {
        (*it)->Undo();
    }
}

TransactionCommand::TransactionCommand(std::vector<std::shared_ptr<Command>> commands)
    : MacroCommand(commands)
{}

void TransactionCommand::Execute()
{
    std::stack<std::shared_ptr<Command>> undo_stack;

    try
    {
        for (const auto& command : commands_)
        {
            command->Execute();
            undo_stack.push(command);
        }
    }
    catch (...)
    {
        while (!undo_stack.empty())
        {
            undo_stack.top()->Undo();
            undo_stack.pop();
        }

        throw;
    }
}

} // namespace dae_for_windows::install_manager::commands
