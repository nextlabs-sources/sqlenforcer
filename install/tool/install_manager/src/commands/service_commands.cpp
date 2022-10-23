#include "commands/service_commands.h"

#include "utils.h"

namespace dae_for_windows::install_manager::commands
{

StartServiceCommand::StartServiceCommand(const std::string& service_name)
    : service_name_(service_name),
    service_(ServiceController{ service_name }),
    original_service_status_(ServiceStatus::Unknown)
{}

void StartServiceCommand::Execute()
{
    const auto current_status = service_.GetStatus();

    if (current_status != ServiceStatus::Stopping &&
        current_status != ServiceStatus::Stopped)
    {
        return;
    }

    if (current_status == ServiceStatus::Stopping)
    {
        if (service_.WaitForStatus(ServiceStatus::Stopped, 10000ms))
        {
            original_service_status_ = ServiceStatus::Stopped;
        }
        else
        {
            const std::string& err_msg = service_name_ + ": Service stuck at stopping";
            throw std::exception(err_msg.c_str());
        }
    }

    if (!service_.Start())
    {
        const auto err_msg_format = "%s: Failed to start service. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }

    if (!service_.WaitForStatus(ServiceStatus::Running, 10000ms))
    {
        const auto err_msg_format = "%s: Service not started. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }
}

void StartServiceCommand::Undo()
{
    const auto current_status = service_.GetStatus();

    if (current_status != ServiceStatus::Running)
    {
        return;
    }

    if (original_service_status_ != ServiceStatus::Stopped)
    {
        return;
    }

    if (!service_.CanStop())
    {
        const std::string err_msg = service_name_ + ": The service can not be stopped once it has started.";
        throw std::exception(err_msg.c_str());
    }

    if (!service_.Stop())
    {
        const auto err_msg_format = "%s: Failed to stop service. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }

    if (!service_.WaitForStatus(ServiceStatus::Stopped, 10000ms))
    {
        const auto err_msg_format = "%s: Service not stopped. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }
}

StopServiceCommand::StopServiceCommand(const std::string& service_name)
    : service_name_(service_name),
    service_(ServiceController{ service_name }),
    original_service_status_(ServiceStatus::Unknown)
{}

void StopServiceCommand::Execute()
{
    const auto current_status = service_.GetStatus();

    if (current_status != ServiceStatus::Starting &&
        current_status != ServiceStatus::Running)
    {
        return;
    }

    if (current_status == ServiceStatus::Starting)
    {
        if (service_.WaitForStatus(ServiceStatus::Running, 10000ms))
        {
            original_service_status_ = ServiceStatus::Running;
        }
        else
        {
            const std::string& err_msg = service_name_ + ": Service stuck at starting";
            throw std::exception(err_msg.c_str());
        }
    }

    if (!service_.CanStop())
    {
        const std::string err_msg = service_name_ + ": Service can not be stopped once it has started.";
        throw std::exception(err_msg.c_str());
    }

    if (!service_.Stop())
    {
        const auto err_msg_format = "%s: Failed to stop service. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }

    if (!service_.WaitForStatus(ServiceStatus::Stopped, 10000ms))
    {
        const auto err_msg_format = "%s: Service not stopped. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }
}

void StopServiceCommand::Undo()
{
    const auto current_status = service_.GetStatus();

    if (current_status != ServiceStatus::Stopped)
    {
        return;
    }

    if (original_service_status_ != ServiceStatus::Running)
    {
        return;
    }

    if (!service_.Start())
    {
        const auto err_msg_format = "%s: Failed to start service. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );
        
        throw std::exception(err_msg.c_str());
    }

    if (!service_.WaitForStatus(ServiceStatus::Running, 10000ms))
    {
        const auto err_msg_format = "%s: Service not started. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }
}

PauseServiceCommand::PauseServiceCommand(const std::string& service_name)
    : service_name_(service_name),
    service_(ServiceController{ service_name }),
    original_service_status_(service_.GetStatus())
{}

void PauseServiceCommand::Execute()
{
    const auto current_status = service_.GetStatus();

    if (current_status != ServiceStatus::Starting &&
        current_status != ServiceStatus::Running)
    {
        return;
    }

    if (current_status == ServiceStatus::Starting)
    {
        if (service_.WaitForStatus(ServiceStatus::Running, 10000ms))
        {
            original_service_status_ = ServiceStatus::Running;
        }
        else
        {
            const std::string err_msg = service_name_ + ": Service stuck at starting";
            throw std::exception(err_msg.c_str());
        }
    }

    if (!service_.CanPauseContinue())
    {
        const auto err_msg = service_name_ + ": Service can not be paused and continued once it has started.";
        throw std::exception(err_msg.c_str());
    }

    if (!service_.Pause())
    {
        const auto err_msg_format = "%s: Failed to pause service. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }

    if (!service_.WaitForStatus(ServiceStatus::Paused, 10000ms))
    {
        const auto err_msg_format = "%s: Service not paused. (%d: %s)";
        const auto last_error = GetLastError();

        if (last_error != 0)
        {
            const std::string err_msg = utils::StringFormat(
                err_msg_format,
                service_name_.c_str(),
                last_error,
                utils::GetErrorMessage(last_error).c_str()
            );

            throw std::exception(err_msg.c_str());
        }
    }
}

void PauseServiceCommand::Undo()
{
    const auto current_status = service_.GetStatus();

    if (current_status != ServiceStatus::Paused)
    {
        return;
    }

    if (original_service_status_ != ServiceStatus::Running)
    {
        return;
    }

    if (!service_.CanPauseContinue())
    {
        const auto err_msg = service_name_ + ": Service can not be paused and continued once it has started.";
        throw std::exception(err_msg.c_str());
    }

    if (!service_.Continue())
    {
        const auto err_msg_format = "%s: Failed to continue service. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }

    if (!service_.WaitForStatus(ServiceStatus::Running, 10000ms))
    {
        const auto err_msg_format = "%s: Service not running. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }
}

ContinueServiceCommand::ContinueServiceCommand(const std::string& service_name)
    : service_name_(service_name),
    service_(ServiceController{ service_name_ }),
    original_service_status_(service_.GetStatus())
{}

void ContinueServiceCommand::Execute()
{
    const auto current_status = service_.GetStatus();

    if (current_status != ServiceStatus::Pausing &&
        current_status != ServiceStatus::Paused)
    {
        return;
    }

    if (current_status == ServiceStatus::Pausing)
    {
        if (service_.WaitForStatus(ServiceStatus::Paused, 10000ms))
        {
            original_service_status_ = ServiceStatus::Paused;
        }
        else
        {
            const std::string err_msg = service_name_ + ": Service stuck at pausing";
            throw std::exception(err_msg.c_str());
        }
    }

    if (!service_.CanPauseContinue())
    {
        const auto err_msg = service_name_ + ": Service can not be paused and continued once it has started.";
        throw std::exception(err_msg.c_str());
    }

    if (!service_.Continue())
    {
        const auto err_msg_format = "%s: Failed to continue service. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }

    if (!service_.WaitForStatus(ServiceStatus::Running, 10000ms))
    {
        const auto err_msg_format = "%s: Service not running. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );
        
        throw std::exception(err_msg.c_str());
    }
}

void ContinueServiceCommand::Undo()
{
    const auto current_status = service_.GetStatus();

    if (current_status != ServiceStatus::Running)
    {
        return;
    }

    if (original_service_status_ != ServiceStatus::Paused)
    {
        return;
    }

    if (!service_.CanPauseContinue())
    {
        const auto err_msg = service_name_ + ": Service can not be paused and continued once it has started.";
        throw std::exception(err_msg.c_str());
    }

    if (!service_.Pause())
    {
        const auto err_msg_format = "%s: Failed to pause service. (%d: %s)";
        const auto last_error = GetLastError();
        const std::string err_msg = utils::StringFormat(
            err_msg_format,
            service_name_.c_str(),
            last_error,
            utils::GetErrorMessage(last_error).c_str()
        );

        throw std::exception(err_msg.c_str());
    }

    if (!service_.WaitForStatus(ServiceStatus::Paused, 10000ms))
    {
        const auto err_msg_format = "%s: Service not paused. (%d: %s)";
        const auto last_error = GetLastError();

        if (last_error != 0)
        {
            const std::string err_msg = utils::StringFormat(
                err_msg_format,
                service_name_.c_str(),
                last_error,
                utils::GetErrorMessage(last_error).c_str()
            );
            throw std::exception(err_msg.c_str());
        }
    }

    if (current_status == ServiceStatus::Running &&
        original_service_status_ == ServiceStatus::Paused)
    {
        if (service_.CanPauseContinue())
        {
            service_.Pause();
            service_.WaitForStatus(ServiceStatus::Paused);
        }
        else
        {
            const std::string err_msg = "Can not pause service: " + service_name_;
            throw std::exception(err_msg.c_str());
        }
    }
}

} // namespace dae_for_windows::install_manager::commands
