#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_FILESYSTEM_COMMANDS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_FILESYSTEM_COMMANDS_H_

#include <filesystem>

#include "commands/base_commands.h"

namespace dae_for_windows::install_manager::commands
{

class CreateDirectoryCommand : public Command
{
public:
    CreateDirectoryCommand(const std::filesystem::path& directory_path);
public:
    void Execute() override;
    void Undo() override;
private:
    std::filesystem::path directory_path_;
};

class RemoveDirectoryCommand : public Command
{
public:
    RemoveDirectoryCommand(const std::filesystem::path& directory_path);
public:
    void Execute() override;
    void Undo() override;
private:
    std::filesystem::path directory_path_;
};

class CopyFileCommand : public Command
{
public:
    CopyFileCommand(const std::filesystem::path& src_path, const std::filesystem::path& target_path);

    void Execute() override;
    void Undo() override;

private:
    std::filesystem::path src_path_;
    std::filesystem::path target_path_;
};

class MoveFileCommand : public Command
{
public:
    MoveFileCommand(
        const std::string& filename,
        const std::filesystem::path& old_parent_path,
        const std::filesystem::path& new_parent_path
    );

public:
    void Execute() override;
    void Undo() override;

private:
    std::string filename_;
    std::filesystem::path old_parent_path_;
    std::filesystem::path new_parent_path_;
};

class RemoveFileCommand : public Command
{
public:
    RemoveFileCommand(const std::filesystem::path& filepath);
    ~RemoveFileCommand();
public:
    void Execute() override;
    void Undo() override;
private:
    std::filesystem::path filepath_;
    std::filesystem::path temp_filepath_;
};

class RenameFilenameCommand : public Command
{
public:
    RenameFilenameCommand(
        const std::filesystem::path& parent_path,
        const std::string& old_filename,
        const std::string& new_filename
    );

    RenameFilenameCommand(
        const std::filesystem::path& old_filepath,
        const std::filesystem::path& new_filepath
    );

public:
    void Execute() override;
    void Undo() override;

private:
    std::filesystem::path old_filepath_;
    std::filesystem::path new_filepath_;
};

class SudoRenameFilenameCommand : public Command
{
public:
    SudoRenameFilenameCommand(
        const std::filesystem::path& parent_path,
        const std::string& old_filename,
        const std::string& new_filename
    );

    SudoRenameFilenameCommand(
        const std::filesystem::path& old_filepath,
        const std::filesystem::path& new_filepath
    );

public:
    void Execute() override;
    void Undo() override;

private:
    std::filesystem::path old_filepath_;
    std::filesystem::path new_filepath_;
};

} // namespace dae_for_windows::install_manager::commands

#endif // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_COMMANDS_FILESYSTEM_COMMANDS_H_