using System.IO;

using log4net;

[assembly: log4net.Config.XmlConfigurator(Watch = true)]
namespace dae_for_windows_service
{
    // Workaround to fix bug 69658 comment 7
    // Details: https://stackoverflow.com/a/35691425/9006561
    class CustomFileAppender : log4net.Appender.RollingFileAppender
    {
        private bool isFirstTime = true;
        protected override void OpenFile(string fileName, bool append)
        {
            if (isFirstTime)
            {
                isFirstTime = false;
                return;
            }

            base.OpenFile(fileName, append);
        }
    }

    public sealed class Logger
    {
        private static readonly Logger instance = new Logger("serviceLogger");

        // Explicit static constructor to tell C# compiler
        // not to mark type as beforefieldinit
        static Logger()
        { }

        private Logger(string name)
        {
            logger = LogManager.GetLogger(name);
        }

        public static Logger Instance
        {
            get => instance;
        }

        public void Debug(object message)
        {
            logger.Debug(message);
        }

        public void Info(object message)
        {
            logger.Info(message);
        }

        public void Warn(object message)
        {
            logger.Warn(message);
        }

        public void Error(object message)
        {
            logger.Error(message);
        }

        public void Fatal(object message)
        {
            logger.Fatal(message);
        }

        private ILog logger;
    }
}
