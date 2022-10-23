using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

namespace dae_for_windows_service
{
    class DaeForSqldeveloper
    {
        private static Dictionary<string, string> _config_md5s;
        public static Dictionary<string, string> Config_MD5s { get => _config_md5s; }

        public static List<FileInfo> GetJdbcDriverPaths()
        {
            Dictionary<string, string> md5s = new Dictionary<string, string>();
            List<FileInfo> paths = new List<FileInfo>();

            DirectoryInfo users = new DirectoryInfo(@"C:\Users");
            foreach (DirectoryInfo sub_user in users.GetDirectories())
            {
                if (sub_user.Name.Equals("default", StringComparison.OrdinalIgnoreCase)
                    || sub_user.Name.Equals("public", StringComparison.OrdinalIgnoreCase))
                {
                    continue;
                }

                string sqldeveloper_appdata_path = $"c:\\users\\{sub_user.Name}\\appdata\\Roaming\\SQL Developer";
                if (Directory.Exists(sqldeveloper_appdata_path))
                {
                    DirectoryInfo di = new DirectoryInfo(sqldeveloper_appdata_path);
                    foreach (DirectoryInfo sub_dir in di.EnumerateDirectories())
                    {
                        if (Regex.IsMatch(sub_dir.Name, @"system\d+(\.\d+)+", RegexOptions.IgnoreCase))
                        {
                            string config_file = sub_dir.FullName + "\\o.sqldeveloper\\ide.properties";
                            string install_path = GetInstallPathFromConfig(config_file);
                            string config_md5 = Utils.CalcMd5FromFile(config_file);
                            md5s.Add(config_file, config_md5);

                            paths.Add(new FileInfo(install_path + "\\jdbc\\lib\\ojdbc8.jar"));
                        }
                    }
                }
            }

            _config_md5s = md5s;
            return paths;
        }

        public static string GetInstallPathFromConfig(string config)
        {
            string install_path = "";
            try
            {
                using (FileStream base_stream = File.Open(config, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
                using (StreamReader read_stream = new StreamReader(base_stream, Encoding.GetEncoding("utf-8")))
                {
                    while (!read_stream.EndOfStream)
                    {
                        string line = read_stream.ReadLine();
                        line.Trim();
                        if (line.StartsWith("Ide.InstallPath=", StringComparison.OrdinalIgnoreCase))
                        {
                            install_path = line.Substring("Ide.InstallPath=".Length);
                            install_path = install_path.Replace("\\\\", "\\");

                            int i = install_path.LastIndexOf("\\sqldeveloper\\bin\\");
                            if (i != -1)
                            {
                                install_path = install_path.Substring(0, i);
                            }
                            break;
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Logger.Instance.Error($"Read sqldeveloper config file: { config } failed! msg: {e.Message}");
            }

            return install_path;
        }

        public static List<string> GetWatcherPath()
        {
            List<string> paths = new List<string>();

            DirectoryInfo di = new DirectoryInfo(@"C:\Users");
            foreach (DirectoryInfo sub in di.GetDirectories())
            {
                if (sub.Name.Equals("default", StringComparison.OrdinalIgnoreCase) 
                    || sub.Name.Equals("public", StringComparison.OrdinalIgnoreCase)
                    || sub.Name.Equals("default user", StringComparison.OrdinalIgnoreCase)
                    || sub.Name.Equals("all users", StringComparison.OrdinalIgnoreCase))
                {
                    continue;
                }

                string sqldeveloper_path = $"c:\\users\\{sub.Name}\\appdata\\Roaming\\SQL Developer";

                if (Directory.Exists(sqldeveloper_path))
                    paths.Add(sqldeveloper_path);
                else
                    paths.Add($"c:\\users\\{sub.Name}\\appdata\\Roaming");
            }

            return paths;
        }
    }
}
