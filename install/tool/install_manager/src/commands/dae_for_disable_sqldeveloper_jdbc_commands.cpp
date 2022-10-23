#include "commands/dae_for_disable_sqldeveloper_jdbc_commands.h"
#include "utils.h"
#include "DAELog.h"

#include <windows.h>
#include <tlhelp32.h>
#include <ShlObj.h>
#include <regex>
#include <fstream>
#include <boost/algorithm/string.hpp>

namespace dae_for_windows::install_manager::commands
{
void RuntimeDaeForDisableSqldeveloperJDBC::Execute()
{
    std::string ori_file = _path + "\\jdbc\\lib\\ojdbc8.jar";
    std::string backup_dir = _path + "\\backup\\";
    std::string backup_file = _path + "\\backup\\dae.jdbc";

    if (!IsDaeforociInstalled())
    {
        CLog::Instance()->WriteLog(emLogLevel::log_warning, "sqldeveloper jdbc driver need to disable only if [dae for oci] is installed.");
        return;
    }

    WIN32_FIND_DATAA fdata = { 0 };
    HANDLE hfind = FindFirstFileA(ori_file.c_str(), &fdata);
    if (hfind == NULL || hfind == INVALID_HANDLE_VALUE)
    {
        //printf("There is no jdbc driver: %s. No need to disable\n", ori_file.c_str());
        return;
    }
    FindClose(hfind);

    CreateDirectoryA(backup_dir.c_str(), NULL);

    KillSqldeveloperIfRunning();

    CopyFileA(ori_file.c_str(), backup_file.c_str(), TRUE);
    // sqldeveloper may quit incompletely, we need try delete file few times.
    while (!DeleteFileA(ori_file.c_str()))
    {
        Sleep(100);
    }

    MarkInRegistry();

    CLog::Instance()->WriteLog(emLogLevel::log_info, "Remove sqldeveloper jdbc driver %s Successfully ", ori_file.c_str());
}

void RuntimeDaeForDisableSqldeveloperJDBC::KillSqldeveloperIfRunning()
{
    HANDLE hsnap = NULL;
    for (int i = 0; i < 3; i++)
    {
        hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hsnap == INVALID_HANDLE_VALUE)
        {
            Sleep(100);
        }
        else
            break;
    }

    if (hsnap == NULL || hsnap == INVALID_HANDLE_VALUE)
    {
        CLog::Instance()->WriteLog(emLogLevel::log_error, "Check sqldeveloper whether it is running failed!");
        return;
    }
	
    PROCESSENTRY32 pe = {0};
    pe.dwSize = sizeof(pe);

    if (!Process32First(hsnap, &pe))
    {
        CloseHandle(hsnap);
        CLog::Instance()->WriteLog(emLogLevel::log_error, "Check sqldeveloper whether it is running, Process32First failed, err: %d", GetLastError());
        return;
    }

    do
    {
        if (_stricmp(pe.szExeFile, "sqldeveloper.exe") == 0
            || _stricmp(pe.szExeFile, "sqldeveloper64.exe") == 0
            || _stricmp(pe.szExeFile, "sqldeveloper64W.exe") == 0)
        {
            HANDLE hp = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);
            if (hp != NULL)
            {
                TerminateProcess(hp, 0);
                CloseHandle(hp);
            }
        }
    } while (Process32Next(hsnap, &pe));
	
    CloseHandle(hsnap);
}

void RuntimeDaeForDisableSqldeveloperJDBC::MarkInRegistry()
{
    HKEY hkey = NULL;
    DWORD err = RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Nextlabs\\DAEforWin\\2.0", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hkey);
    if (hkey == NULL)
    {
        CLog::Instance()->WriteLog(emLogLevel::log_error, "Can not open reg key HKEY_LOCAL_MACHINE\\SOFTWARE\\Nextlabs\\DAEforWin\\2.0, err: %d", err);
        return;
    }

    char wdata[1024] = { 0 };
    DWORD dwsize = sizeof(wdata);
    DWORD dwType = REG_MULTI_SZ;
    RegGetValueA(hkey, NULL, "sqldeveloper_jdbc", RRF_RT_ANY, &dwType, wdata, &dwsize);

    char* p = wdata;
    while (1)
    {
        if (*p != L'\0' && strlen(p) > 0)
        {
            p = p + strlen(p) + 1;
        }
        else
            break;
    }

    strcpy_s(p, 300, _path.c_str());

    RegSetKeyValueA(hkey, NULL, "sqldeveloper_jdbc", REG_MULTI_SZ, wdata, p + strlen(p) + 1 - wdata);

    RegCloseKey(hkey);
}

bool RuntimeDaeForDisableSqldeveloperJDBC::IsDaeforociInstalled()
{
    HKEY hkey = NULL;
    DWORD err = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Nextlabs\\DAEforWin\\2.0", 0, KEY_READ | KEY_WOW64_64KEY, &hkey);
    if (hkey == NULL)
    {
        CLog::Instance()->WriteLog(emLogLevel::log_error, "Can not open reg key HKEY_LOCAL_MACHINE\\SOFTWARE\\Nextlabs\\DAEforWin\\2.0, err: %d", err);
        return false;
    }

    WCHAR oci64[512] = { 0 };
    WCHAR oci32[512] = { 0 };
    DWORD size64 = sizeof(oci64);
    DWORD size32 = sizeof(oci32);
    DWORD dwType = REG_MULTI_SZ;
    RegGetValueW(hkey, NULL, L"oci_x64", RRF_RT_ANY, &dwType, oci64, &size64);
    RegGetValueW(hkey, NULL, L"oci_x86", RRF_RT_ANY, &dwType, oci32, &size32);

    RegCloseKey(hkey);

    if (wcslen(oci64) > 0 || wcslen(oci32) > 0)
        return true;
    else
        return false;
}


void RuntimeDaeForDisableAllSqldeveloperJDBC::Execute()
{
    std::vector<std::string> paths;
    GetInstallPaths(paths);

    for each (std::string path in paths)
    {
        RuntimeDaeForDisableSqldeveloperJDBC tool(path);
        tool.Execute();
    }
}

void RuntimeDaeForDisableAllSqldeveloperJDBC::GetInstallPaths(std::vector<std::string>& paths)
{
    std::vector<std::string> sqldevelopers;

    WIN32_FIND_DATAA users_data = { 0 };
    HANDLE hfindusers = FindFirstFileA("c:\\users\\*", &users_data);
    if (hfindusers != NULL && hfindusers != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (strcmp(users_data.cFileName, ".") == 0 || strcmp(users_data.cFileName, "..") == 0
                || _stricmp(users_data.cFileName, "default") == 0 || _stricmp(users_data.cFileName, "public") == 0
                || _stricmp(users_data.cFileName, "default user") == 0 || _stricmp(users_data.cFileName, "All users") == 0)
                continue;

            if (!(users_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                continue;

            std::string str("c:\\users\\");
            str.append(users_data.cFileName);
            str.append("\\AppData\\Roaming\\SQL Developer");

            sqldevelopers.push_back(str);

        } while (FindNextFileA(hfindusers, &users_data));

        FindClose(hfindusers);
    }

    for each (std::string find_path in sqldevelopers)
    {
        WIN32_FIND_DATAA fdata = { 0 };
        HANDLE hfind = FindFirstFileA((find_path + "\\*.*").c_str(), &fdata);
        if (hfind != NULL && hfind != INVALID_HANDLE_VALUE)
        {
            do
            {
                if (strcmp(fdata.cFileName, ".") == 0 || strcmp(fdata.cFileName, "..") == 0)
                    continue;

                if (!(fdata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
                    continue;

                std::string filename(fdata.cFileName);
                std::regex reg("^system\\d+(\\.\\d+)+");
                if (std::regex_match(filename, reg))
                {
                    std::string config = find_path + "\\" + filename + "\\o.sqldeveloper\\ide.properties";

                    try
                    {
                        std::ifstream fs(config);
                        if (fs.good())
                        {
                            std::string line;
                            while (!fs.eof()) {
                                std::getline(fs, line);

                                if (line.find("Ide.InstallPath=") != -1)
                                {
                                    std::string path = line.substr(16, line.length());
                                    boost::replace_all(path, "\\\\", "\\");

                                    size_t i = path.rfind("\\sqldeveloper\\bin\\");
                                    if (i != -1) {
                                        path = path.substr(0, i);
                                    }

                                    paths.push_back(path);
                                    break;
                                }
                            }
                            fs.close();
                        }
                    }
                    catch (std::exception e)
                    {

                    }
                }
            } while (FindNextFileA(hfind, &fdata));

            FindClose(hfind);
        }
    }
}
}