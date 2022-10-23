using System.ServiceProcess;

namespace dae_for_windows_service
{
    class Program
    {
        public static void Main()
        {
            ServiceBase.Run(new DaeForWindowsService());
        }
    }
}
