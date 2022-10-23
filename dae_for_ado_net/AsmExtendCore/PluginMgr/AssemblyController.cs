using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtendCore
{
    class AssemblyController : ComparableBase
    {
        private static readonly string g_kstr_Star = "*";
        private static readonly string g_kstrSep_Architecture = "|";
        private static readonly string g_kstrSep_Process = "|";

        public readonly string Dir = "";  // Standard file directory which end with "\"
        public readonly string Name = ""; // Assembly name without extension
        public readonly HashSet<ProcessorArchitecture> SupportArchitectures = new HashSet<ProcessorArchitecture>() { ProcessorArchitecture.MSIL };   // MSIL, X86, IA64, Amd64, Arm
        public readonly string PublicKeyToken = "";
        public readonly string Culture = "";
        public readonly string Version = "";
        private Assembly m_obAssembly = null;
        private HashSet<string> m_setTargetProcess = new HashSet<string>(StringComparer.OrdinalIgnoreCase);

        public AssemblyController(string strDir, string strName, string strProcessorArchitecture, string strPublicKeyToken, string strCulture, string strVersion, string strTargetProcess)
            : base(EstablisUniqueString(strDir, strName, strProcessorArchitecture, strPublicKeyToken, strCulture, strVersion))
        {
            Dir = CommonHelper.GetStandardFolderPath(CommonHelper.GetSolidString(strDir, true));
            Name = CommonHelper.GetSolidString(strName, true);
            SupportArchitectures = CommonHelper.ConvertEnumStringToCollection<HashSet<ProcessorArchitecture>, ProcessorArchitecture>(strProcessorArchitecture, g_kstrSep_Architecture, null, ProcessorArchitecture.MSIL);
            PublicKeyToken = CommonHelper.GetSolidString(strPublicKeyToken, true);
            Culture = CommonHelper.GetSolidString(strCulture, true);
            Version = CommonHelper.GetSolidString(strVersion, true);
            CommonHelper.SplitAndSetStringItemToCollection(ref m_setTargetProcess, strTargetProcess, g_kstrSep_Process, true, true);
        }
        public Assembly GetAssembly()
        {
            if (IsSupportCurrentProcess())
            {
                if (null == m_obAssembly)
                {
                    m_obAssembly = InnerLoadAssembly();
                }
            }
            else
            {
                Logger.WriteLine("Current process do not support by assembly:[{0}] according config, no need load", Name);
            }
            return m_obAssembly;
        }
        private Assembly InnerLoadAssembly()
        {
            Assembly obAssemblyRet = null;
            try
            {
                if (String.IsNullOrEmpty(Name))
                {
                    Logger.WriteLine("Try to load an assembly but the assembly name:[{0}] is empty", Name);
                }
                else
                {
                    if (String.IsNullOrEmpty(Dir))
                    {
                        // Load with assembly strong name
                        string strAssembleStrongName = GetAssemblyStrongName();
                        obAssemblyRet = Assembly.Load(strAssembleStrongName);
                    }
                    else
                    {
                        // Load with assembly file path
                        string strAssemblyFileFullPath = "";
                        ProcessorArchitecture emCurProcessorArchitecture = CommonHelper.GetCurrentAssemblyArchitecture(ProcessorArchitecture.MSIL);

                        bool bSupportMSIL = false;
                        if ((null == SupportArchitectures) || (0 == SupportArchitectures.Count))
                        {
                            // The same as current assembly architecture, if not exist, load from MSIL
                            strAssemblyFileFullPath = GetAssemblyFileFullPath(emCurProcessorArchitecture, true);
                        }
                        else
                        {
                            bSupportMSIL = SupportArchitectures.Contains(ProcessorArchitecture.MSIL);
                            if (SupportArchitectures.Contains(emCurProcessorArchitecture))
                            {
                                // Load the same as current assembly architecture, if support MSIL, load from MSIL
                                strAssemblyFileFullPath = GetAssemblyFileFullPath(emCurProcessorArchitecture, bSupportMSIL);
                            }
                            else
                            {
                                if (bSupportMSIL)
                                {
                                    // Load from MSIL
                                    strAssemblyFileFullPath = GetAssemblyFileFullPath(ProcessorArchitecture.MSIL, bSupportMSIL);
                                }
                                else
                                {
                                    // Do not load
                                }
                            }
                        }
                        Logger.WriteLine("Begin load plugin assemly from:[{0}]", strAssemblyFileFullPath);
                        if (File.Exists(strAssemblyFileFullPath))
                        {
                            obAssemblyRet = Assembly.LoadFrom(strAssemblyFileFullPath);
                        }
                        else
                        {
                            Logger.WriteLine("Failed load plugin assemly from:[{0}], the file not exist", strAssemblyFileFullPath);
                        }
                        Logger.WriteLine("End load plugin assemly from:[{0}] with return assembly object:[{1}]", strAssemblyFileFullPath, obAssemblyRet);
                    }
                }
            }
            catch (ReflectionTypeLoadException ex)
            {
                StringBuilder sb = new StringBuilder();
                foreach (Exception exSub in ex.LoaderExceptions)
                {
                    sb.AppendLine(exSub.Message);
                    FileNotFoundException exFileNotFound = exSub as FileNotFoundException;
                    if (exFileNotFound != null)
                    {
                        if (!string.IsNullOrEmpty(exFileNotFound.FusionLog))
                        {
                            sb.AppendLine("Fusion Log:");
                            sb.AppendLine(exFileNotFound.FusionLog);
                        }
                    }
                    sb.AppendLine();
                }
                string errorMessage = sb.ToString();
                Logger.WriteLine(errorMessage);
            }
            catch (Exception ex)
            {
                Logger.WriteLine("Exception during load assembly:[{0}{1} {2} {3} {4}]", Dir, Name, PublicKeyToken, Culture, Version);
                Logger.WriteLine(ex);
            }
            return obAssemblyRet;
        }
        private bool IsSupportCurrentProcess()
        {
            bool bSupportRet = false;
            try
            {
                if (null == m_setTargetProcess)
                {
                    // Must config, default do not support any process
                    bSupportRet = false;
                }
                else
                {
                    if (m_setTargetProcess.Contains(g_kstr_Star))
                    {
                        bSupportRet = true;
                    }
                    else
                    {
                        Process obCurProcess = Process.GetCurrentProcess();
                        if (null != obCurProcess)
                        {
                            bSupportRet = m_setTargetProcess.Contains(obCurProcess.ProcessName + ".exe");
                        }
                        else
                        {
                            Logger.WriteLine("Cannot get current process info, cannot check if current process need support");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return bSupportRet;
        }
        private string GetAssemblyStrongName()
        {
            string strAssembleStrongName = string.Format("{0}, Version={1}, Culture={2}, PublicKeyToken={3}", Name, Version, Culture, PublicKeyToken);
            return strAssembleStrongName;
        }
        private string GetAssemblyFileFullPath(ProcessorArchitecture emProcessorArchitecture, bool bDefaultSupportMSIL)
        {
            string strAssemblyFileFullPath = "";
            switch (emProcessorArchitecture)
            {
            case ProcessorArchitecture.X86:
            {
                strAssemblyFileFullPath = Dir + "x86\\" + Name + ".dll";
                if (!File.Exists(strAssemblyFileFullPath) && bDefaultSupportMSIL)
                {
                    strAssemblyFileFullPath = Dir + Name + ".dll";
                }
                break;
            }
            case ProcessorArchitecture.IA64:
            case ProcessorArchitecture.Amd64:
            {
                strAssemblyFileFullPath = Dir + "x64\\" + Name + ".dll";
                if (!File.Exists(strAssemblyFileFullPath) && bDefaultSupportMSIL)
                {
                    strAssemblyFileFullPath = Dir + Name + ".dll";
                }
                break;
            }
            default:
            {
                strAssemblyFileFullPath = Dir + Name + ".dll";
                break;
            }
            }
            return strAssemblyFileFullPath;
        }
        private static string EstablisUniqueString(string strDirIn, string strNameIn, string strProcessorArchitectureIn, 
            string strPublicKeyTokenIn, string strCultureIn, string strVersionIn)
        {
            string strDir = CommonHelper.GetStandardFolderPath(CommonHelper.GetSolidString(strDirIn, true));
            string strName = CommonHelper.GetSolidString(strNameIn, true);
            string strProcessorArchitecture = CommonHelper.GetStandardStructString(strProcessorArchitectureIn, g_kstrSep_Architecture, ProcessorArchitecture.MSIL);
            string strPublicKeyToken = CommonHelper.GetSolidString(strPublicKeyTokenIn, true);
            string strCulture = CommonHelper.GetSolidString(strCultureIn, true);
            string strVersion = CommonHelper.GetSolidString(strVersionIn, true);

            return String.Format("{0}::{1}::{2}::{3}::{4}::{5}", 
                strDir, strName, strProcessorArchitecture, strPublicKeyToken, strCulture, strVersion);
        }
    }
}
