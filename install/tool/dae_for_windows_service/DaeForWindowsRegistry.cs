using System;
using System.IO;
using System.Collections.Generic;

using Microsoft.Win32;

namespace dae_for_windows_service
{
    class DaeForWindowsRegistry
    {
        public static DaeForWindowsRegistry Load()
        {
            DaeForWindowsRegistry daeRegistry = new DaeForWindowsRegistry();

            using (RegistryKey key = Registry.LocalMachine.OpenSubKey("SOFTWARE\\Nextlabs\\DAEforWin\\2.0"))
            {
                if (key != null)
                {
                    bool isDaeForAdoNetX64Installed = Convert.ToBoolean(key.GetValue("adonet_x64"));

                    if (isDaeForAdoNetX64Installed)
                    {
                        string[] systemDataDlls = Directory.GetFiles(@"C:\Windows\Microsoft.NET\assembly\GAC_64\System.Data", "System.Data.dll", SearchOption.AllDirectories);

                        if (systemDataDlls != null && systemDataDlls.Length > 0)
                        {
                            daeRegistry.adoNetX64Target = new FileInfo(systemDataDlls[0]);
                        }
                    }

                    bool isDaeForAdoNetX86Installed = Convert.ToBoolean(key.GetValue("adonet_x86"));

                    if (isDaeForAdoNetX86Installed)
                    {
                        string[] systemDataDlls = Directory.GetFiles(@"C:\Windows\Microsoft.NET\assembly\GAC_32\System.Data", "System.Data.dll", SearchOption.AllDirectories);

                        if (systemDataDlls != null && systemDataDlls.Length > 0)
                        {
                            daeRegistry.adoNetX86Target = new FileInfo(systemDataDlls[0]);
                        }
                    }

                    string[] jdbcNgdbcTargets = key.GetValue("jdbc_ngdbc") as string[];

                    if (jdbcNgdbcTargets != null)
                    {
                        daeRegistry.jdbcNgdbcTargets.Clear();

                        foreach (string target in jdbcNgdbcTargets)
                        {
                            if (!string.IsNullOrEmpty(target))
                            {
                                daeRegistry.jdbcNgdbcTargets.Add(new FileInfo(target));
                            }
                        }
                    }

                    string[] jdbcOjdbc8Targets = key.GetValue("jdbc_ojdbc8") as string[];

                    if (jdbcOjdbc8Targets != null)
                    {
                        daeRegistry.jdbcOjdbc8Targets.Clear();

                        foreach (string target in jdbcOjdbc8Targets)
                        {
                            if (!string.IsNullOrEmpty(target))
                            {
                                daeRegistry.jdbcOjdbc8Targets.Add(new FileInfo(target));
                            }
                        }
                    }

                    string[] jdbcMssqlTargets = key.GetValue("jdbc_mssql") as string[];

                    if (jdbcMssqlTargets != null)
                    {
                        daeRegistry.jdbcMssqlTargets.Clear();

                        foreach (string target in jdbcMssqlTargets)
                        {
                            if (!string.IsNullOrEmpty(target))
                            {
                                daeRegistry.jdbcMssqlTargets.Add(new FileInfo(target));
                            }
                        }
                    }

                    string[] ociX64Targets = key.GetValue("oci_x64") as string[];

                    if (ociX64Targets != null)
                    {
                        foreach (string target in ociX64Targets)
                        {
                            if (!string.IsNullOrEmpty(target))
                            {
                                string ociPath = target + "\\oci.dll";
                                daeRegistry.ociX64Targets.Add(new FileInfo(ociPath));
                            }
                        }
                    }

                    string[] ociX86Targets = key.GetValue("oci_x86") as string[];

                    if (ociX86Targets != null)
                    {
                        foreach (string target in ociX86Targets)
                        {
                            if (!string.IsNullOrEmpty(target))
                            {
                                string ociPath = target + "\\oci.dll";
                                daeRegistry.ociX86Targets.Add(new FileInfo(ociPath));
                            }
                        }
                    }

                    bool isDaeForOdbcX64Installed = Convert.ToBoolean(key.GetValue("odbc_x64"));

                    if (isDaeForOdbcX64Installed)
                    {
                        string[] systemDataDlls = Directory.GetFiles(@"C:\Windows\System32\", "odbc32.dll");

                        if (systemDataDlls != null && systemDataDlls.Length > 0)
                        {
                            daeRegistry.odbcX64Target = new FileInfo(systemDataDlls[0]);
                        }
                    }

                    bool isDaeForOdbcX86Installed = Convert.ToBoolean(key.GetValue("odbc_x86"));

                    if (isDaeForOdbcX86Installed)
                    {
                        string[] systemDataDlls = Directory.GetFiles(@"C:\Windows\SysWOW64\", "odbc32.dll");

                        if (systemDataDlls != null && systemDataDlls.Length > 0)
                        {
                            daeRegistry.odbcX86Target = new FileInfo(systemDataDlls[0]);
                        }
                    }

                    string[] powerbiX64Targets = key.GetValue("powerbi_x64") as string[];

                    if (powerbiX64Targets != null)
                    {
                        foreach (string target in powerbiX64Targets)
                        {
                            if (!string.IsNullOrEmpty(target))
                            {
                                daeRegistry.powerbiX64Targets.Add(new FileInfo(target));
                            }
                        }
                    }
                }
            }

            return daeRegistry;
        }
        public FileInfo AdoNetX64Target { get => adoNetX64Target; }
        public FileInfo AdoNetX86Target { get => adoNetX86Target; }
        public List<FileInfo> JdbcNgdbcTargets { get => jdbcNgdbcTargets; }
        public List<FileInfo> JdbcOjdbc8Targets { get => jdbcOjdbc8Targets; }
        public List<FileInfo> JdbcMssqlTargets { get => jdbcMssqlTargets; }
        public List<FileInfo> OciX64Targets { get => ociX64Targets; }
        public List<FileInfo> OciX86Targets { get => ociX86Targets; }
        public FileInfo OdbcX64Target { get => odbcX64Target; }
        public FileInfo OdbcX86Target { get => odbcX86Target; }
        public List<FileInfo> PowerbiX64Targets { get => powerbiX64Targets; }

        private FileInfo adoNetX64Target;
        private FileInfo adoNetX86Target;
        private List<FileInfo> jdbcNgdbcTargets = new List<FileInfo>();
        private List<FileInfo> jdbcOjdbc8Targets = new List<FileInfo>();
        private List<FileInfo> jdbcMssqlTargets = new List<FileInfo>();
        private List<FileInfo> ociX64Targets = new List<FileInfo>();
        private List<FileInfo> ociX86Targets = new List<FileInfo>();
        private FileInfo odbcX64Target;
        private FileInfo odbcX86Target;
        private List<FileInfo> powerbiX64Targets = new List<FileInfo>();
    }
}
