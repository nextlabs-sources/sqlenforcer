#include "commands/dae_for_restore_sqldeveloper_jdbc_commands.h"
#include "utils.h"
#include "DAELog.h"

#include <windows.h>

namespace dae_for_windows::install_manager::commands
{
void RuntimeDaeForRestoreSqldeveloperJDBC::Execute()
{
    std::vector<std::wstring> lists;

    if (!IsDaeforociUninstalled())
    {
        CLog::Instance()->WriteLog(emLogLevel::log_warning, "sqldeveloper jdbc driver need to restore only if [dae for oci] is uninstalled.");
        return;
    }

    GetRestoreList(lists);

    if (lists.size() == 0)
    {
        //CLog::Instance()->WriteLog(emLogLevel::log_info, "no sqldeveloper jdbc driver need to restore.");
        return;
    }

    for each (std::wstring path in lists)
    {
        Restore(path);
    }

    CleanMarkInRegistry();
}

void RuntimeDaeForRestoreSqldeveloperJDBC::GetRestoreList(std::vector<std::wstring>& lists)
{
    HKEY hkey = NULL;
    DWORD err = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Nextlabs\\DAEforWin\\2.0", 0, KEY_READ | KEY_WOW64_64KEY, &hkey);
    if (hkey == NULL)
    {
        CLog::Instance()->WriteLog(emLogLevel::log_error, "Can not open reg key HKEY_LOCAL_MACHINE\\SOFTWARE\\Nextlabs\\DAEforWin\\2.0, err: %d", err);
        return;
    }

    WCHAR wdata[1024] = { 0 };
    DWORD dwsize = sizeof(wdata);
    DWORD dwType = REG_MULTI_SZ;
    RegGetValueW(hkey, NULL, L"sqldeveloper_jdbc", RRF_RT_ANY, &dwType, wdata, &dwsize);

    RegCloseKey(hkey);

    WCHAR* p = wdata;
    while (1)
    {
        if (*p != L'\0' && wcslen(p) > 0)
        {
            std::wstring tmp = p;
            lists.push_back(tmp);

            p = p + wcslen(p) + 1;
        }
        else
            break;
    }
}

void RuntimeDaeForRestoreSqldeveloperJDBC::Restore(const std::wstring& path)
{
    std::wstring back_dir = path + L"\\backup";
    std::wstring back_file = path + L"\\backup\\dae.jdbc";
    std::wstring real_file = path + L"\\jdbc\\lib\\ojdbc8.jar";

    WIN32_FIND_DATAW fdata = { 0 };
    HANDLE hfind = FindFirstFileW(back_file.c_str(), &fdata);
    if (hfind == NULL || hfind == INVALID_HANDLE_VALUE)
    {
        RemoveDirectoryW(back_dir.c_str());
        //CLog::Instance()->WriteLog(emLogLevel::log_info, "There is no backup jdbc driver to restore in %s", dae_for_windows::install_manager::utils::ToString(back_file));
        return;
    }
    FindClose(hfind);

    MoveFileExW(back_file.c_str(), real_file.c_str(), MOVEFILE_REPLACE_EXISTING);

    DeleteFileW(back_file.c_str());
    RemoveDirectoryW(back_dir.c_str());

    CLog::Instance()->WriteLog(emLogLevel::log_info, "Restore sqldeveloper jdbc driver: %s Successfully", utils::ToString(real_file).c_str());
}

void RuntimeDaeForRestoreSqldeveloperJDBC::CleanMarkInRegistry()
{
    HKEY hkey = NULL;
    DWORD err = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Nextlabs\\DAEforWin\\2.0", 0, KEY_ALL_ACCESS | KEY_WOW64_64KEY, &hkey);
    if (hkey == NULL)
    {
        CLog::Instance()->WriteLog(emLogLevel::log_error, "Can not open reg key HKEY_LOCAL_MACHINE\\SOFTWARE\\Nextlabs\\DAEforWin\\2.0, err: %d", err);
        return;
    }

    RegSetKeyValueA(hkey, NULL, "sqldeveloper_jdbc", REG_MULTI_SZ, NULL, 0);

    RegCloseKey(hkey);
}

bool RuntimeDaeForRestoreSqldeveloperJDBC::IsDaeforociUninstalled()
{
    HKEY hkey = NULL;
    DWORD err = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Nextlabs\\DAEforWin\\2.0", 0, KEY_READ | KEY_WOW64_64KEY, &hkey);
    if (hkey == NULL)
    {
        CLog::Instance()->WriteLog(emLogLevel::log_error, "Can not open reg key HKEY_LOCAL_MACHINE\\SOFTWARE\\Nextlabs\\DAEforWin\\2.0, err: %d", err);
        return true;
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
        return false;
    else
        return true;
}
}