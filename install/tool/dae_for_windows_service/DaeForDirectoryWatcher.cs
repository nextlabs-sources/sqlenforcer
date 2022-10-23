using System;
using System.IO;
using System.Diagnostics;

namespace dae_for_windows_service
{
    internal abstract class DaeForDirectoryWatcher : IDisposable
    {
        private string target_;
        private FileSystemWatcher watcher_ = null;

        public string Target { get => target_; }

        public DaeForDirectoryWatcher(string dir)
        {
            target_ = dir;
            try
            {
                // if specified dir is not found, it will throw exception
                watcher_ = new FileSystemWatcher(dir);
            }
            catch (Exception)
            {
                if (watcher_ != null)
                {
                    watcher_.Dispose();
                    watcher_ = null;
                }
                return;
            }

            watcher_.NotifyFilter = NotifyFilters.CreationTime |
                                    NotifyFilters.DirectoryName |
                                    NotifyFilters.FileName |
                                    NotifyFilters.LastWrite |
                                    NotifyFilters.Size;

            watcher_.IncludeSubdirectories = true;

            watcher_.Error += OnError;
            watcher_.Changed += OnChanged;
            watcher_.Created += OnCreated;
            watcher_.Deleted += OnDeleted;
            watcher_.Renamed += OnRenamed;
        }

        public void Start()
        {
            if (watcher_ != null)
                watcher_.EnableRaisingEvents = true;
        }

        public void Stop()
        {
            if (watcher_ != null)
                watcher_.EnableRaisingEvents = false;
        }

        public void Dispose()
        {
            Stop();

            if (watcher_ != null)
                watcher_.Dispose();
        }

        private void OnError(object sender, ErrorEventArgs e)
        {
            Logger.Instance.Error(e.GetException());
        }

        protected abstract void OnChanged(object sender, FileSystemEventArgs e);
        protected abstract void OnCreated(object sender, FileSystemEventArgs e);
        protected abstract void OnDeleted(object sender, FileSystemEventArgs e);
        protected abstract void OnRenamed(object sender, RenamedEventArgs e);
    }

    // Detecting if there is new install sqldeveloper
    // If installed new sqldeveloper, it would create new folder in 'C:\Users\xxx\AppData\Roaming\SQL Developer\', like 'system21.2.1.204.1703'
    // And we could find real install path in config file 'ide.properties' which has key name 'Ide.InstallPath'
    class DaeForSqldeveloperWatcher : DaeForDirectoryWatcher
    {
        public DaeForSqldeveloperWatcher(string dir) : base(dir)
        {

        }

        protected override void OnCreated(object sender, FileSystemEventArgs e)
        {
            int i = e.FullPath.IndexOf("\\sql developer\\", StringComparison.OrdinalIgnoreCase);
            if (i != -1)
            {
                int f = e.FullPath.LastIndexOf(@"\o.sqldeveloper\ide.properties", StringComparison.OrdinalIgnoreCase);
                if (f != -1)
                {
                    if (DaeInstallStatus.IsDaeForOciInstalled())
                        DoDisable(DaeForSqldeveloper.GetInstallPathFromConfig(e.FullPath));
                }
            }
        }

        protected override void OnDeleted(object sender, FileSystemEventArgs e)
        {
            // do nothing
        }

        protected override void OnRenamed(object sender, RenamedEventArgs e)
        {
            // do nothing
        }

        protected override void OnChanged(object sender, FileSystemEventArgs e)
        {
            int i = e.FullPath.IndexOf("\\sql developer\\", StringComparison.OrdinalIgnoreCase);
            if (i != -1)
            {
                int f = e.FullPath.LastIndexOf(@"\o.sqldeveloper\ide.properties", StringComparison.OrdinalIgnoreCase);
                if (f != -1)
                {
                    if (DaeInstallStatus.IsDaeForOciInstalled())
                    {
                        if (!DaeForSqldeveloper.Config_MD5s.ContainsKey(e.FullPath))
                            DoDisable(DaeForSqldeveloper.GetInstallPathFromConfig(e.FullPath));
                        else
                        {
                            string md5 = Utils.CalcMd5FromFile(e.FullPath);
                            if (md5 != DaeForSqldeveloper.Config_MD5s[e.FullPath])
                                DoDisable(DaeForSqldeveloper.GetInstallPathFromConfig(e.FullPath));
                        }
                    }
                }
            }
        }

        private void DoDisable(string install_path)
        {
            if (string.IsNullOrEmpty(install_path))
                return;

            try
            {
                using (Process process = new Process())
                {
                    process.StartInfo = new ProcessStartInfo
                    {
                        FileName = @"C:\Program Files\NextLabs\DAEforWin\bin\install_manager.exe",
                        Arguments = $"-l runtime DisableSqldeveloperJDBC -t \"{install_path}\"",
                        RedirectStandardError = true,
                        RedirectStandardOutput = true,
                        UseShellExecute = false,
                        Verb = "runas"
                    };

                    process.Start();
                }
            }
            catch (Exception exception)
            {
                Logger.Instance.Error($"Run install_manager.exe failed! msg: {exception.Message}");
            }
        }
    }
}
