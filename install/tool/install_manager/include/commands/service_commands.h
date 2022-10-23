#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_SERVICE_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_SERVICE_COMMANDS_H_

#include <string>

#include <tchar.h>

#include "ServiceLib/ServiceController.h"

#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class StartServiceCommand : public Command
{
public:
    StartServiceCommand(const std::string& service_name);
public:
    void Execute() override;
    void Undo() override;
private:
    std::string service_name_;
    ServiceController service_;
    ServiceStatus original_service_status_;
};

class StopServiceCommand : public Command
{
public:
    StopServiceCommand(const std::string& service_name);
public:
    void Execute() override;
    void Undo() override;
private:
    std::string service_name_;
    ServiceController service_;
    ServiceStatus original_service_status_;
};

class PauseServiceCommand : public Command
{
public:
    PauseServiceCommand(const std::string& service_name);
public:
    void Execute() override;
    void Undo() override;
private:
    std::string service_name_;
    ServiceController service_;
    ServiceStatus original_service_status_;
};

class ContinueServiceCommand : public Command
{
public:
    ContinueServiceCommand(const std::string& service_name);
public:
    void Execute() override;
    void Undo() override;
private:
    std::string service_name_;
    ServiceController service_;
    ServiceStatus original_service_status_;
};

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_SERVICE_COMMANDS_H_