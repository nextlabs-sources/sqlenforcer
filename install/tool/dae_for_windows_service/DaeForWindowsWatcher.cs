using System;
using System.IO;
using System.Diagnostics;
using System.ComponentModel;

namespace dae_for_windows_service
{
    enum Architecture
    {
        X86,
        X64
    }
    enum JdbcDriverKind
    {
        Oracle,
        Hana,
        SqlServer
    };

    internal abstract class DaeForWindowsWatcher : IDisposable
    {
        public DaeForWindowsWatcher(FileInfo target)
        {
            target_ = target;
            try
            {
                watcher_ = new FileSystemWatcher(target_.DirectoryName);
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

            watcher_.NotifyFilter = NotifyFilters.Size | NotifyFilters.CreationTime | NotifyFilters.FileName | NotifyFilters.LastWrite;
            watcher_.Changed += OnChanged;
            watcher_.Created += OnCreated;
            watcher_.Deleted += OnDeleted;
            watcher_.Renamed += OnRenamed;

            watcher_.Error += OnError;

            watcher_.Filter = target_.Name;
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

        protected abstract void OnChanged(object sender, FileSystemEventArgs e);
        protected abstract void OnCreated(object sender, FileSystemEventArgs e);
        protected abstract void OnDeleted(object sender, FileSystemEventArgs e);
        protected abstract void OnRenamed(object sender, RenamedEventArgs e);

        private void OnError(object sender, ErrorEventArgs e)
        {
            Logger.Instance.Error(e.GetException());
        }

        public void Dispose()
        {
            if (watcher_ != null)
                watcher_.Dispose();
        }

        public static void RunInstallManager(string arg)
        {
            using (Process process = new Process())
            {
                process.StartInfo = new ProcessStartInfo
                {
                    FileName = @"C:\Program Files\NextLabs\DAEforWin\bin\install_manager.exe", // TODO: path
                    Arguments = arg,
                    RedirectStandardError = true,
                    RedirectStandardOutput = true,
                    UseShellExecute = false,
                    Verb = "runas"
                };

                process.Start();
            }
        }

        protected void OnChangedHandle(object sender, FileSystemEventArgs e, string commandArgs)
        {
            delayFunction.Debounce(() =>
            {
                Logger.Instance.Info($"{e.ChangeType}: {e.FullPath}");
                RunInstallManager(commandArgs);
            }).Invoke();
        }

        public FileInfo Target { get => target_; }

        private FileInfo target_ = null;
        private FileSystemWatcher watcher_ = null;
        private DelayFunction delayFunction = new DelayFunction();
    }

    sealed class DaeForJdbcWatcher : DaeForWindowsWatcher
    {
        public DaeForJdbcWatcher(FileInfo target, JdbcDriverKind jdbcDriverKind) : base(target)
        {
            jdbcDriverKind_ = jdbcDriverKind;
        }

        protected override void OnChanged(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnCreated(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnDeleted(object sender, FileSystemEventArgs e)
        {
            // Do nothing
        }

        protected override void OnRenamed(object sender, RenamedEventArgs e)
        {
            // Do nothing
        }

        private void DoRepair(object sender, FileSystemEventArgs e)
        {
            try
            {
                switch (jdbcDriverKind_)
                {
                    case JdbcDriverKind.Oracle:
                        {
                            OnChangedHandle(sender, e, $"-l repair DAEforJDBC --oracle -t {Target.FullName}");
                        }
                        break;
                    case JdbcDriverKind.Hana:
                        {
                            OnChangedHandle(sender, e, $"-l repair DAEforJDBC --hana -t {Target.FullName}");
                        }
                        break;
                    case JdbcDriverKind.SqlServer:
                        {
                            OnChangedHandle(sender, e, $"-l repair DAEforJDBC --sqlserver -t {Target.FullName}");
                        }
                        break;
                    default:
                        {
                            throw new InvalidEnumArgumentException();
                        }
                }
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex);
            }
        }

        private JdbcDriverKind jdbcDriverKind_;
    }

    sealed class DaeForAdoNetWatcher : DaeForWindowsWatcher
    {
        public DaeForAdoNetWatcher(FileInfo target, Architecture arch) : base(target)
        {
            arch_ = arch;
        }

        protected override void OnChanged(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnCreated(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnDeleted(object sender, FileSystemEventArgs e)
        {
            // do nothing
        }

        protected override void OnRenamed(object sender, RenamedEventArgs e)
        {
            // do nothing
        }

        private void DoRepair(object sender, FileSystemEventArgs e)
        {
            try
            {
                OnChangedHandle(sender, e, $"-l repair DAEforADONET --{arch_}");
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex);
            }
        }

        private Architecture arch_;
    }

    sealed class DaeForOciWatcher : DaeForWindowsWatcher
    {
        public DaeForOciWatcher(FileInfo target, Architecture arch) : base(target)
        {
            arch_ = arch;
        }

        protected override void OnChanged(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnCreated(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnDeleted(object sender, FileSystemEventArgs e)
        {
            // do nothing
        }

        protected override void OnRenamed(object sender, RenamedEventArgs e)
        {
            // do nothing
        }

        private void DoRepair(object sender, FileSystemEventArgs e)
        {
            try
            {
                OnChangedHandle(sender, e, $"-l repair DAEforOCI --{arch_} -t {Target.DirectoryName}");
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex);
            }
        }

        private Architecture arch_;
    }

    sealed class DaeForOdbcWatcher : DaeForWindowsWatcher
    {
        public DaeForOdbcWatcher(FileInfo target, Architecture arch) : base(target)
        {
            arch_ = arch;
        }

        protected override void OnChanged(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnCreated(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnDeleted(object sender, FileSystemEventArgs e)
        {
            // do nothing
        }

        protected override void OnRenamed(object sender, RenamedEventArgs e)
        {
            // do nothing
        }

        private void DoRepair(object sender, FileSystemEventArgs e)
        {
            try
            {
                OnChangedHandle(sender, e, $"-l repair DAEforODBC --{arch_}");
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex);
            }
        }

        private Architecture arch_;
    }

    sealed class DaeForPowerBiWatcher : DaeForWindowsWatcher
    {
        public DaeForPowerBiWatcher(FileInfo target, Architecture arch) : base(target)
        {
            arch_ = arch;
        }

        protected override void OnChanged(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnCreated(object sender, FileSystemEventArgs e)
        {
            DoRepair(sender, e);
        }

        protected override void OnDeleted(object sender, FileSystemEventArgs e)
        {
            // do nothing
        }

        protected override void OnRenamed(object sender, RenamedEventArgs e)
        {
            // do nothing
        }

        private void DoRepair(object sender, FileSystemEventArgs e)
        {
            try
            {
                OnChangedHandle(sender, e, $"-l repair DAEforPowerBI --{arch_} -t {Target.FullName}");
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex);
            }
        }

        private Architecture arch_;
    }

    sealed class DaeForSqldeveloperJdbcWatcher : DaeForWindowsWatcher
    {
        public DaeForSqldeveloperJdbcWatcher(FileInfo target) : base(target) { }

        protected override void OnChanged(object sender, FileSystemEventArgs e)
        {
            DoDisable(sender, e);
        }

        protected override void OnCreated(object sender, FileSystemEventArgs e)
        {
            DoDisable(sender, e);
        }

        protected override void OnDeleted(object sender, FileSystemEventArgs e)
        {
            // do nothing
        }

        protected override void OnRenamed(object sender, RenamedEventArgs e)
        {
            if (e.FullPath.Equals(Target.FullName, StringComparison.OrdinalIgnoreCase))
                DoDisable(sender, e);
        }

        private void DoDisable(object sender, FileSystemEventArgs e)
        {
            if (!DaeInstallStatus.IsDaeForOciInstalled())
                return;

            int i = Target.FullName.LastIndexOf(@"\jdbc\lib\");
            string path = Target.FullName.Substring(0, i);

            try
            {
                OnChangedHandle(sender, e, $"-l runtime DisableSqldeveloperJDBC -t \"{path}\"");
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex);
            }
        }
    }
}
