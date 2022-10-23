namespace AsmExtend.Plugin
{
    class DAELogger
    {
        private static string tag = "ADO.NET";

        public static void WriteLine(EMDBLogLevel level, string msg)
        {
            EmdbSdkWrapper.SQLEnforcerWriteLogWithTagA(level, tag, msg);
        }

        public static void Trace(string msg)
        {
            WriteLine(EMDBLogLevel.TRACE, msg);
        }

        public static void Debug(string msg)
        {
            WriteLine(EMDBLogLevel.DEBUG, msg);
        }

        public static void Info(string msg)
        {
            WriteLine(EMDBLogLevel.INFO, msg);
        }

        public static void Warning(string msg)
        {
            WriteLine(EMDBLogLevel.WARNING, msg);
        }
        public static void Error(string msg)
        {
            WriteLine(EMDBLogLevel.ERROR, msg);
        }

        public static void Fatal(string msg)
        {
            WriteLine(EMDBLogLevel.FATAL, msg);
        }
    }
}
