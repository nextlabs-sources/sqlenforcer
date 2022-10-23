#include "utils.h"

#include <string>
#include <chrono>
#include <locale>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <exception>
#include <system_error>

#include "NSudo/NSudoAPI.h"
#include "winreg/WinReg.hpp"

namespace fs = std::filesystem;

namespace dae_for_windows::install_manager::utils
{

    bool IsFileExist(std::string parent_path, std::string filename)
    {
        for (auto& p : std::filesystem::recursive_directory_iterator(parent_path))
        {
            if (p.path().filename().string() == filename)
            {
                return true;
            }
        }

        return false;
    }

    bool IsSameFile(const std::string& filename1, const std::string& filename2)
    {
        if (filename1 == filename2)
        {
            return true;
        }

        if (fs::file_size(filename1) != fs::file_size(filename2))
        {
            return false;
        }


        std::ifstream file1(filename1, std::ifstream::binary);
        std::ifstream file2(filename2, std::ifstream::binary);

        std::istreambuf_iterator<char> end_of_file;
        std::istreambuf_iterator<char> begin1(file1);
        std::istreambuf_iterator<char> begin2(file2);

        return std::equal(begin1, end_of_file, begin2);
    }

    void SudoRunCommandString(const std::string& command_str)
    {
        HRESULT result = NSudoCreateProcess(
            NSUDO_USER_MODE_TYPE::TRUSTED_INSTALLER,
            NSUDO_PRIVILEGES_MODE_TYPE::ENABLE_ALL_PRIVILEGES,
            NSUDO_MANDATORY_LABEL_TYPE::HIGH,
            NSUDO_PROCESS_PRIORITY_CLASS_TYPE::HIGH,
            NSUDO_SHOW_WINDOW_MODE_TYPE::DEFAULT,
            1000, // Wait for the created process to end
            false,
            ToWstring(command_str).c_str(),
            nullptr
        );

        if (S_OK != result)
        {
            const std::string error_message = std::system_category().message(result);
            throw std::exception(error_message.c_str());
        }
    }

    fs::path GetFilePathRecursively(std::string parent_path, std::string filename)
    {
        for (const auto& p : fs::recursive_directory_iterator(parent_path))
        {
            if (p.path().filename().string() == filename)
            {
                return p.path();
            }
        }
    }

    std::wstring ToWstring(
        const std::string& str,
        const std::locale& loc
    )
    {
        std::vector<wchar_t> buf(str.size());
        std::use_facet<std::ctype<wchar_t>>(loc).widen(
            str.data(),
            str.data() + str.size(),
            buf.data()
        );

        return std::wstring(buf.data(), buf.size());
    }

    std::string ToString(
        const std::wstring& str,
        const std::locale& loc
    )
    {
        std::vector<char> buf(str.size());
        std::use_facet<std::ctype<wchar_t>>(loc).narrow(
            str.data(),
            str.data() + str.size(),
            '?', buf.data()
        );

        return std::string(buf.data(), buf.size());
    }

    long long GetMillisecondsSinceEpoch()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
                  std::chrono::system_clock::now().time_since_epoch()
               ).count();
    }

    std::vector<std::string> SplitString(const std::string& str, const char& separator)
    {
        std::istringstream iss(str);
        std::string segment;
        std::vector<std::string> result{};

        while (std::getline(iss, segment, separator))
        {
            result.push_back(segment);
        }

        return result;
    }

    bool CaseInsensitiveEquals(const std::string& s1, const std::string& s2)
    {
#ifndef _WIN32
        return 0 == strcasecmp(s1.c_str(), s2.c_str());
#else
        return 0 == stricmp(s1.c_str(), s2.c_str());
#endif
    }

    std::wstring GetInstallPath()
    {
        winreg::RegKey key{ HKEY_LOCAL_MACHINE, L"SOFTWARE\\Nextlabs\\DAEforWin", KEY_READ | KEY_WOW64_64KEY };
        
        return key.GetStringValue(L"install_path");
    }

    std::string GetLastErrorMessage()
    {
        return GetErrorMessage(GetLastError());
    }

    std::string GetErrorMessage(DWORD dw)
    {
        // Retrieve the system error message for the last-error code
        LPVOID lpMsgBuf;

        FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            dw,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPTSTR)&lpMsgBuf,
            0, NULL);

        std::string text = (LPCTSTR)lpMsgBuf;

        LocalFree(lpMsgBuf);

        return text;
    }

    bool IsRegValueExist(
                    const std::wstring& valueName,
                    const std::wstring& subKey,
                    const HKEY hKeyParent,
                    const REGSAM desiredAccess) noexcept
    {
        winreg::RegKey key{ hKeyParent, subKey, desiredAccess };

        try
        {
            key.QueryValueType(valueName);
        }
        catch (...)
        {
            return false;
        }

        return true;
    }

} // namespace dae_for_windows::install_manager::util