using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtend.Plugin.Common
{
    static class AsmExtendBaseInfo
    {
        // Register
        public static readonly string g_kstrRegKey_Nextlabs = "SOFTWARE\\Nextlabs";
        public static readonly string g_kstrRegItemKey_AsmExtendConfigRoot = "AsmExtendConfigRoot";
        public static readonly string g_kstrRegItemKey_AsmExtendLogRoot = "AsmExtendLogRoot";
        // Default value
        public static readonly string g_kstrAsmExtendDefaultRoot = @"C:\ProgramData\Nextlabs\DAEforWin\DotNet\"; // @"c:\MyWorkReference\";
        public static readonly string g_kstrDefaultConfigFilePath = String.Format("{0}Config\\System.data.AsmExtend.xml", g_kstrAsmExtendDefaultRoot);
    }
}
