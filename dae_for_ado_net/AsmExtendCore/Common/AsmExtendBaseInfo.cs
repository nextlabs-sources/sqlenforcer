using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtendCore
{
    static class AsmExtendBaseInfo
    {
        // Current Assembly
        public static readonly Assembly g_obCurAssemly = null;
        public static readonly AssemblyName g_obCurAssemblyName = null;
        public static readonly string g_strCurAssemblyName = "";

        // Register
        public static readonly string g_kstrRegKey_Nextlabs = "SOFTWARE\\Nextlabs";
        public static readonly string g_kstrRegItemKey_AsmExtendConfigRoot = "AsmExtendConfigRoot";
        public static readonly string g_kstrRegItemKey_AsmExtendLogRoot = "AsmExtendLogRoot";

        // Default value
        public static readonly string g_kstrAsmExtendDefaultRoot = @"C:\ProgramData\Nextlabs\DAEforWin\DotNet\"; // @"c:\MyWorkReference\";

        public enum NextLabsAction
        {
            Throw,
            Nothrow
        }

        // The guid flag to throw out exception
        public static readonly string g_kstrGuidFlagToThrowOutException = "4DC93257-50D6-47B2-9BD1-8B7851E1C888";
        // The format of the thrown message
        public static readonly string g_kstrMessageFormatToThrowOut = "{0}{\"action\": \"{1}\", message: \"{2}\"}";

        static AsmExtendBaseInfo()
        {
            try
            {
                g_obCurAssemly = Assembly.GetExecutingAssembly();
                g_obCurAssemblyName = (null == g_obCurAssemly) ? null : g_obCurAssemly.GetName();
                g_strCurAssemblyName = (null == g_obCurAssemblyName) ? "" : g_obCurAssemblyName.Name;
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
        }
    }
}
