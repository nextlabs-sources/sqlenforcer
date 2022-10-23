#ifndef SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_UTILS_H_
#define SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_UTILS_H_

#include <string>
#include <vector>
#include <locale>
#include <memory>
#include <filesystem>

#include <winreg/WinReg.hpp>

#include <Windows.h>

namespace dae_for_windows::install_manager::utils
{
    bool IsFileExist(std::string parent_path, std::string filename);

    bool IsSameFile(const std::string& filename1, const std::string& filename2);

    void SudoRunCommandString(const std::string& command_str);

    std::filesystem::path GetFilePathRecursively(std::string parent_path, std::string filename);

    std::wstring ToWstring(const std::string& str, const std::locale& loc = std::locale());

    std::string ToString(const std::wstring& str, const std::locale& loc = std::locale());

    long long GetMillisecondsSinceEpoch();

    std::vector<std::string> SplitString(const std::string& str, const char& separator);

    bool CaseInsensitiveEquals(const std::string& s1, const std::string& s2);

    template<typename ... Args>
    std::string StringFormat(const std::string& format, Args ... args)
    {
        int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
        if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
        auto size = static_cast<size_t>(size_s);
        auto buf = std::make_unique<char[]>(size);
        std::snprintf(buf.get(), size, format.c_str(), args ...);
        return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    }

    std::wstring GetInstallPath();

    std::string GetLastErrorMessage();

    std::string GetErrorMessage(DWORD dw);

    bool IsRegValueExist(
        const std::wstring& valueName,
        const std::wstring& subKey,
        const HKEY hKeyParent = HKEY_LOCAL_MACHINE,
        const REGSAM desiredAccess = KEY_READ | KEY_WOW64_64KEY) noexcept;
} // namespace dae_for_windows::install_manager::util

#endif  // SQLENFORCER_INSTALL_TOOL_INSTALL_MANAGER_INCLUDE_UTIL_H_