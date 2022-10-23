using System;
using System.IO;
using System.Timers;

namespace dae_for_windows_service
{
    class DelayFunction : IDisposable
    {
        private bool disposed = false;
        private Timer debounce_timer_ = new Timer();

        public Action Debounce(Action func, int timeout = 500)
        {
            return () =>
            {
                if (debounce_timer_ != null)
                {
                    debounce_timer_.Stop();
                    debounce_timer_.Close();
                    debounce_timer_ = null;
                }

                debounce_timer_ = new Timer(timeout);
                debounce_timer_.AutoReset = false;
                debounce_timer_.Elapsed += (object o, ElapsedEventArgs e) =>
                {
                    func.Invoke();
                };

                debounce_timer_.Start();
            };
        }

        public void Dispose()
        {
            if (disposed)
            {
                return;
            }

            if (debounce_timer_ != null)
            {
                debounce_timer_.Dispose();
            }
            disposed = true;
        }

        ~DelayFunction()
        {
            Dispose();
        }
    }
}
