using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtend.Plugin.Common
{
    static class Logger
    {
        // Log path
        private static bool g_kbInited = false;
        private static readonly Process g_kCurProcess = System.Diagnostics.Process.GetCurrentProcess();
        private static readonly string g_kstrLogRootStandardPath = "";
        private static readonly string g_kstrCurAssemblyFlag = "";
        private static readonly string g_kstrtLogFileName = "";
        private static readonly string g_kstrLogFilePath = "";

        static Logger()
        {
            try
            {
                g_kbInited = false;
                g_kCurProcess = System.Diagnostics.Process.GetCurrentProcess();
                g_kstrLogRootStandardPath = GetLogRootStandardPath();
                Assembly obCurAssembly = Assembly.GetExecutingAssembly();
                AssemblyName obAssemblyName = (null == obCurAssembly) ? null : obCurAssembly.GetName();
                if ((null == g_kCurProcess) || (String.IsNullOrEmpty(g_kstrLogRootStandardPath)) || (null == obCurAssembly) || (null == obAssemblyName))
                {
                    // Error, ignore
                    Logger.WriteLine("Init logger base info failed");
                }
                else
                {
                    g_kstrCurAssemblyFlag = GetCurAssemblyNameFlag(obAssemblyName);
                    g_kstrtLogFileName = String.Format("{0}.{1}.{2}.log", g_kCurProcess.ProcessName, g_kstrCurAssemblyFlag, g_kCurProcess.Id);
                    if (Directory.Exists(g_kstrLogRootStandardPath + obAssemblyName.Name))
                    {
                        // Module folder exist
                        g_kstrLogFilePath = g_kstrLogRootStandardPath + obAssemblyName.Name + "\\" + g_kstrtLogFileName;
                    }
                    else if (Directory.Exists(g_kstrLogRootStandardPath + g_kCurProcess.ProcessName))
                    {
                        // Process folder exist
                        g_kstrLogFilePath = g_kstrLogRootStandardPath + g_kCurProcess.ProcessName + "\\" + g_kstrtLogFileName;
                    }
                    else
                    {
                        // Default
                        g_kstrLogFilePath = g_kstrLogRootStandardPath + g_kstrtLogFileName;
                    }
                    g_kbInited = true;
                }
            }
            catch (Exception ex)
            {
                // Exception, ignore
                Logger.WriteLine(ex);
            }
        }

        public static void WriteLine(Exception ex)
        {
            try
            {
                Logger.WriteLine("Exception message:[{0}], stack:[{1}]\n", ex.Message, ex.StackTrace);
                if (null != ex.InnerException)
                {
                    Logger.WriteLine("Inner exception message:[{0}], stack:[{1}]\n", ex.InnerException.Message, ex.InnerException.StackTrace);
                }
            }
            catch
            {

            }
        }
        public static void WriteLine(string strFormat, params object[] szArgs)
        {
            try
            {
                Logger.WriteLine(String.Format(strFormat, szArgs));
            }
            catch
            {
            }
        }
        public static void WriteLine(string strLogInfo)
        {
            try
            {
                if (g_kbInited)
                {
                    using (FileStream obLogFileStream = new FileStream(g_kstrLogFilePath, FileMode.Append, FileAccess.Write))
                    {
                        using (StreamWriter obLogFileStreamWriter = new StreamWriter(obLogFileStream))
                        {
                            obLogFileStreamWriter.WriteLine(strLogInfo);
                        }
                    }
                }
            }
            catch
            {
            }
        }

        private static string GetLogRootStandardPath()
        {
            string strLogRootPathRet = AsmExtendBaseInfo.g_kstrAsmExtendDefaultRoot;
            try
            {
                string strLogRoot = CommonHelper.ReadRegisterKey(Microsoft.Win32.RegistryHive.LocalMachine, Microsoft.Win32.RegistryView.Registry64,
                    AsmExtendBaseInfo.g_kstrRegKey_Nextlabs, AsmExtendBaseInfo.g_kstrRegItemKey_AsmExtendLogRoot);
                if (!String.IsNullOrEmpty(strLogRoot))
                {
                    strLogRootPathRet = strLogRoot;
                }
            }
            catch
            {
                // No log here, maybe the log do not finished initialize
            }
            return CommonHelper.GetStandardFolderPath(strLogRootPathRet);
        }
        private static string GetCurAssemblyNameFlag(AssemblyName obAssemblyName)
        {
            string strFlagRet = "";
            try
            {
                String[] szNames = obAssemblyName.FullName.Split(',');
                if (4 == szNames.Length)
                {
                    int nStartIndex = szNames[3].IndexOf('=');
                    if (0 < nStartIndex && nStartIndex < szNames[3].Length)
                    {
                        string strPublicToken = szNames[3].Substring(nStartIndex + 1);
                        if ((!String.IsNullOrEmpty(strPublicToken)) && (0 != String.Compare(strPublicToken, "null", StringComparison.OrdinalIgnoreCase)))
                        {
                            strFlagRet = obAssemblyName.Name + "_" + obAssemblyName.Version + "_" + strPublicToken;
                        }
                    }
                }
                if (String.IsNullOrEmpty(strFlagRet))
                {
                    strFlagRet = obAssemblyName.Name + "_" + obAssemblyName.Version;
                }
            }
            catch
            {
                // No log here, maybe the log do not finished initialize
                strFlagRet = Guid.NewGuid().ToString();
            }
            return strFlagRet;
        }
    }
}
