using System;
using Microsoft.Win32;

namespace dae_for_windows_service
{
    class DaeInstallStatus
    {
        public static bool IsDaeForOciInstalled()
        {
            try
            {
                using (RegistryKey dae_key = Registry.LocalMachine.OpenSubKey("SOFTWARE\\Nextlabs\\DAEforWin\\2.0"))
                {
                    string[] oci_x64 = dae_key.GetValue("oci_x64") as string[];
                    string[] oci_x86 = dae_key.GetValue("oci_x86") as string[];

                    bool res = false;

                    foreach (string s in oci_x64)
                    {
                        if (!string.IsNullOrEmpty(s))
                        {
                            res = true;
                            break;
                        }
                    }

                    foreach (string s in oci_x86)
                    {
                        if (!string.IsNullOrEmpty(s))
                        {
                            res = true;
                            break;
                        }
                    }

                    return res;
                }
            }
            catch (Exception e)
            {
                Logger.Instance.Error("Open reg key Local_machine\\SOFTWARE\\Nextlabs\\DAEforWin\\2.0 failed! msg: " + e.Message);
                return false;
            }
        }
    }
}
