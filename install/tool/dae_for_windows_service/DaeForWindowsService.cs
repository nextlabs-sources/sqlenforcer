using System;
using System.IO;
using System.ServiceProcess;
using System.Collections.Generic;

namespace dae_for_windows_service
{
    sealed class DaeForWindowsService : ServiceBase
    {
        public DaeForWindowsService()
        {
            InitializeComponent();
        }

        protected override void OnStart(string[] args)
        {
            Logger.Instance.Info("Start watching files");

            try
            {
                DaeForWindowsWatcher.RunInstallManager("-l repair all");
                ReloadWatchers();
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex);
            }

            base.OnStart(args);
        }

        protected override void OnStop()
        {
            Logger.Instance.Info("Stop watching files");

            try
            {
                ClearWatchers();
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex.Message);
            }

            base.OnStop();
        }

        protected override void OnPause()
        {
            Logger.Instance.Debug("In OnPause()");

            try
            {
                ClearWatchers();
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex.Message);
            }

            base.OnPause();
        }

        protected override void OnContinue()
        {
            Logger.Instance.Debug("In OnContinue()");

            try
            {
                ReloadWatchers();
            }
            catch (Exception ex)
            {
                Logger.Instance.Error(ex.Message);
            }

            base.OnContinue();
        }

        private void InitializeComponent()
        {
            // 
            // DaeForWindowsService
            // 
            this.CanPauseAndContinue = true;
            this.ServiceName = "DAE for Windows Service";
        }

        private void ReloadWatchers()
        {
            DaeForWindowsRegistry registry = DaeForWindowsRegistry.Load();

            ClearWatchers();

            FileInfo adoNetX64Target = registry.AdoNetX64Target;

            if (adoNetX64Target != null)
            {
                DaeForAdoNetWatcher watcher = new DaeForAdoNetWatcher(adoNetX64Target, Architecture.X64);

                daeWatchers.Add(watcher);
            }

            FileInfo adoNetX86Target = registry.AdoNetX86Target;

            if (adoNetX86Target != null)
            {
                DaeForAdoNetWatcher watcher = new DaeForAdoNetWatcher(adoNetX86Target, Architecture.X86);

                daeWatchers.Add(watcher);
            }

            foreach (FileInfo target in registry.JdbcNgdbcTargets)
            {
                DaeForJdbcWatcher watcher = new DaeForJdbcWatcher(target, JdbcDriverKind.Hana);

                daeWatchers.Add(watcher);
            }

            foreach (FileInfo target in registry.JdbcOjdbc8Targets)
            {
                DaeForJdbcWatcher watcher = new DaeForJdbcWatcher(target, JdbcDriverKind.Oracle);

                daeWatchers.Add(watcher);
            }

            foreach (FileInfo target in registry.JdbcMssqlTargets)
            {
                DaeForJdbcWatcher watcher = new DaeForJdbcWatcher(target, JdbcDriverKind.SqlServer);

                daeWatchers.Add(watcher);
            }

            foreach (FileInfo target in registry.OciX64Targets)
            {
                DaeForOciWatcher watcher = new DaeForOciWatcher(target, Architecture.X64);

                daeWatchers.Add(watcher);
            }

            foreach (FileInfo target in registry.OciX86Targets)
            {
                DaeForOciWatcher watcher = new DaeForOciWatcher(target, Architecture.X86);

                daeWatchers.Add(watcher);
            }

            FileInfo odbcX64Target = registry.OdbcX64Target;

            if (odbcX64Target != null)
            {
                DaeForOdbcWatcher watcher = new DaeForOdbcWatcher(odbcX64Target, Architecture.X64);

                daeWatchers.Add(watcher);
            }

            FileInfo odbcX86Target = registry.OdbcX86Target;

            if (odbcX86Target != null)
            {
                DaeForOdbcWatcher watcher = new DaeForOdbcWatcher(odbcX86Target, Architecture.X86);

                daeWatchers.Add(watcher);
            }

            foreach (FileInfo target in registry.PowerbiX64Targets)
            {
                DaeForPowerBiWatcher watcher = new DaeForPowerBiWatcher(target, Architecture.X64);

                daeWatchers.Add(watcher);
            }

            if (DaeInstallStatus.IsDaeForOciInstalled())
            {
                foreach (FileInfo target in DaeForSqldeveloper.GetJdbcDriverPaths())
                {
                    DaeForSqldeveloperJdbcWatcher watcher = new DaeForSqldeveloperJdbcWatcher(target);

                    daeWatchers.Add(watcher);
                }

                foreach (string target in DaeForSqldeveloper.GetWatcherPath())
                {
                    DaeForSqldeveloperWatcher sqldeveloper_watcher = new DaeForSqldeveloperWatcher(target);

                    daeDirWatchers.Add(sqldeveloper_watcher);
                }
            }

            StartWatchers();
        }

        private void StartWatchers()
        {
            foreach (DaeForWindowsWatcher watcher in daeWatchers)
            {
                watcher.Start();

                Logger.Instance.Debug($"Start watching file {watcher.Target.FullName}");
            }

            foreach (DaeForDirectoryWatcher watcher in daeDirWatchers)
            {
                watcher.Start();

                Logger.Instance.Debug($"Start watching directory {watcher.Target}");
            }
        }

        private void StopWatchers()
        {
            foreach (DaeForWindowsWatcher watcher in daeWatchers)
            {
                watcher.Stop();

                Logger.Instance.Debug($"Stop watching file {watcher.Target.FullName}");
            }

            foreach (DaeForDirectoryWatcher watcher in daeDirWatchers)
            {
                watcher.Stop();

                Logger.Instance.Debug($"Stop watching directory {watcher.Target}");
            }
        }

        private void ClearWatchers()
        {
            foreach (DaeForWindowsWatcher watcher in daeWatchers)
            {
                watcher.Dispose();

                Logger.Instance.Debug($"Stop watching file {watcher.Target.FullName}");
            }

            daeWatchers.Clear();

            foreach (DaeForDirectoryWatcher watcher in daeDirWatchers)
            {
                watcher.Dispose();

                Logger.Instance.Debug($"Stop watching directory {watcher.Target}");
            }

            daeDirWatchers.Clear();
        }

        private List<DaeForWindowsWatcher> daeWatchers = new List<DaeForWindowsWatcher>();
        private List<DaeForDirectoryWatcher> daeDirWatchers = new List<DaeForDirectoryWatcher>();
    }
}
