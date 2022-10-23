#include "commands/filesystem_commands.h"

#include <string>
#include <iostream>

#include <Windows.h>

#include "DAELog.h"
#include "utils.h"

namespace fs = std::filesystem;

namespace dae_for_windows::install_manager::commands
{

CreateDirectoryCommand::CreateDirectoryCommand(const fs::path& directory_path)
    : directory_path_(directory_path)
{}

void CreateDirectoryCommand::Execute()
{
    fs::create_directory(directory_path_);
}

void CreateDirectoryCommand::Undo()
{
    fs::remove(directory_path_);
}

RemoveDirectoryCommand::RemoveDirectoryCommand(const fs::path& directory_path)
    : directory_path_(directory_path)
{}

void RemoveDirectoryCommand::Execute()
{
    if (fs::is_empty(directory_path_))
    {
        fs::remove(directory_path_);
    }
}

void RemoveDirectoryCommand::Undo()
{
    fs::create_directory(directory_path_);
}

CopyFileCommand::CopyFileCommand(const std::filesystem::path& src_path, const std::filesystem::path& target_path)
    : src_path_(src_path), target_path_(target_path)
{}

void CopyFileCommand::Execute()
{
    fs::copy(src_path_, target_path_);
}

void CopyFileCommand::Undo()
{
    fs::remove(target_path_);
}

MoveFileCommand::MoveFileCommand(
    const std::string& filename,
    const fs::path& old_parent_path,
    const fs::path& new_parent_path
) : filename_(filename), old_parent_path_(old_parent_path), new_parent_path_(new_parent_path)
{}

void MoveFileCommand::Execute()
{
    const fs::path& old_path = old_parent_path_ / filename_;
    const fs::path& new_path = new_parent_path_ / filename_;

    fs::rename(old_path, new_path);
}

void MoveFileCommand::Undo()
{
    const fs::path& old_path = old_parent_path_ / filename_;
    const fs::path& new_path = new_parent_path_ / filename_;

    fs::rename(new_path, old_path);
}

RemoveFileCommand::RemoveFileCommand(const fs::path& filepath)
    : filepath_(filepath), temp_filepath_()
{}

void RemoveFileCommand::Execute()
{
    if (fs::exists(filepath_))
    {
        const fs::path temp_filename = filepath_.filename().concat(std::to_string(utils::GetMillisecondsSinceEpoch()));
        temp_filepath_ = fs::temp_directory_path() / temp_filename;

        fs::rename(filepath_, temp_filepath_);
    }
}

void RemoveFileCommand::Undo()
{
    if (fs::exists(temp_filepath_))
    {
        fs::rename(temp_filepath_, filepath_);
    }
}

RemoveFileCommand::~RemoveFileCommand()
{
    try
    {
        if (fs::exists(temp_filepath_))
        {
            fs::remove(temp_filepath_);
        }
    }
    catch (const fs::filesystem_error& e)
    {
        if (!MoveFileEx(temp_filepath_.string().c_str(), nullptr, MOVEFILE_DELAY_UNTIL_REBOOT))
        {
            const auto err_msg_format = "Error happened in removing file %s";

            theLog->WriteLog(
                emLogLevel::log_error,
                err_msg_format,
                e.what()
            );
        }
    }
}

RenameFilenameCommand::RenameFilenameCommand(
    const fs::path& parent_path,
    const std::string& old_filename,
    const std::string& new_filename
)
    : old_filepath_(parent_path / old_filename),
    new_filepath_(parent_path / new_filename)
{}

RenameFilenameCommand::RenameFilenameCommand(
    const fs::path& old_filepath,
    const fs::path& new_filepath
) : old_filepath_(old_filepath), new_filepath_(new_filepath)
{}

void RenameFilenameCommand::Execute()
{
    fs::rename(old_filepath_, new_filepath_);
}

void RenameFilenameCommand::Undo()
{
    fs::rename(new_filepath_, old_filepath_);
}

SudoRenameFilenameCommand::SudoRenameFilenameCommand(
    const std::filesystem::path& parent_path,
    const std::string& old_filename,
    const std::string& new_filename
) : old_filepath_(parent_path / old_filename), new_filepath_(parent_path / new_filename)
{}

SudoRenameFilenameCommand::SudoRenameFilenameCommand(
    const fs::path& old_filepath,
    const fs::path& new_filepath
) : old_filepath_(old_filepath), new_filepath_(new_filepath)
{}

void SudoRenameFilenameCommand::Execute()
{
    const std::string rename_command_string = "install_manager.exe rename -f "
        + old_filepath_.string()
        + " -t " + new_filepath_.string();

    utils::SudoRunCommandString(rename_command_string);
}

void SudoRenameFilenameCommand::Undo()
{
    const std::string rename_command_string = "install_manager.exe rename -f "
        + new_filepath_.string()
        + " -t " + old_filepath_.string();

    utils::SudoRunCommandString(rename_command_string);
}

} // namespace dae_for_windows::install_manager::commands
