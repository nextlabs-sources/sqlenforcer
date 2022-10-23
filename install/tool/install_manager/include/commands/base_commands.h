#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_BASE_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_BASE_COMMANDS_H_

#include <memory>
#include <vector>

namespace dae_for_windows::install_manager::commands
{

class Command
{
public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
};

class MacroCommand : public Command
{
public:
    MacroCommand(std::vector<std::shared_ptr<Command>> commands);
public:
    void Execute() override;
    void Undo() override;
protected:
    std::vector<std::shared_ptr<Command>> commands_;
};

class TransactionCommand : public MacroCommand
{
public:
    TransactionCommand(std::vector<std::shared_ptr<Command>> commands);
public:
    void Execute() override;
};

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_BASE_COMMANDS_H_