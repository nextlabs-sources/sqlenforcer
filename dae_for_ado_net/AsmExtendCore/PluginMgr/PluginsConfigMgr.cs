using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml;

namespace AsmExtendCore
{
    class PluginsConfigMgr
    {
        #region Config file readonly values
        public static readonly string g_strConfigFileNameEndFlag = ".AsmExtend.xml";
        public static readonly string g_kstrDefaultConfigFilePath = String.Format("{0}Config\\System.data{1}", AsmExtendBaseInfo.g_kstrAsmExtendDefaultRoot, g_strConfigFileNameEndFlag);
        #endregion

        #region XML Values
        public static readonly string g_kstrXmlNodeName_PluginsConfig = "pluginsConfig";
        public static readonly string g_kstrXmlNodeName_Plugins = "plugins";
        public static readonly string g_kstrXmlNodeName_Plugin = "plugin";
        public static readonly string g_kstrXmlNodeName_Binding = "binding";
        public static readonly string g_kstrXmlNodeName_BindingMethod = "bindingMethod";

        public static readonly string g_kstrXmlNodeAttr_Path = "path";
        public static readonly string g_kstrXmlNodeAttr_Name = "name";
        public static readonly string g_kstrXmlNodeAttr_ProcessorArchitecture = "processorArchitecture";
        public static readonly string g_kstrXmlNodeAttr_PublicKeyToken = "publicKeyToken";
        public static readonly string g_kstrXmlNodeAttr_Culture = "culture";
        public static readonly string g_kstrXmlNodeAttr_Version = "version";
        public static readonly string g_kstrXmlNodeAttr_Source = "source";
        public static readonly string g_kstrXmlNodeAttr_Target = "target";
        public static readonly string g_kstrXmlNodeAttr_Parameters = "parameters";
        public static readonly string g_kstrXmlNodeAttr_BindReturn = "bindReturn";
        #endregion

        #region Members
        private readonly string ConfigFilePath = GetConfigFilePath();
        #endregion

        #region Singleton
        static private object s_obLockForInstance = new object();
        static private PluginsConfigMgr s_obPluginsConfigMgrIns = null;
        static public PluginsConfigMgr GetInstance()
        {
            if (null == s_obPluginsConfigMgrIns)
            {
                lock (s_obLockForInstance)
                    if (null == s_obPluginsConfigMgrIns)
                    {
                        s_obPluginsConfigMgrIns = new PluginsConfigMgr();
                    }
            }
            return s_obPluginsConfigMgrIns;
        }
        private PluginsConfigMgr()
        {
        }
        #endregion

        #region Public methods
        public List<MethodBinding> GetMethodBindings()
        {
            List<MethodBinding> lsMethodBinding = new List<MethodBinding>();
            try
            {
                if ((!String.IsNullOrEmpty(ConfigFilePath)) && File.Exists(ConfigFilePath))
                {
                    lsMethodBinding = EstablishMethodBindings(ConfigFilePath);
                }
                else
                {
                    Logger.WriteLine("The config file:[{0}] do not exist", ConfigFilePath);
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return lsMethodBinding;
        }
        #endregion

        #region Inner methods
        private static List<MethodBinding> EstablishMethodBindings(string strConfigFilePath)
        {
            List<MethodBinding> lsMethodBinding = new List<MethodBinding>();
            try
            {
                XmlDocument xmlDoc = new XmlDocument();
                xmlDoc.Load(strConfigFilePath);

                // Init plugin
                XmlNode nodePluginsConfig = xmlDoc.SelectSingleNode(g_kstrXmlNodeName_PluginsConfig);
                lsMethodBinding = EstablishMethodBindings(nodePluginsConfig);
            }
            catch (Exception ex)
            {
                Logger.WriteLine("Analysis plugin config file:[{0}] exception, message:[{1}]\n", strConfigFilePath, ex.Message);
            }
            return lsMethodBinding;
        }
        private static List<MethodBinding> EstablishMethodBindings(XmlNode nodePluginsConfig)
        {
            List<MethodBinding> lsMethodBinding = new List<MethodBinding>();
            try
            {
                XmlNodeList nodeListPlugins = nodePluginsConfig.SelectNodes(g_kstrXmlNodeName_Plugins);
                foreach (XmlNode nodePluginsItem in nodeListPlugins)
                {
                    try
                    {
                        MethodBinding obMethodBinding = EstablishMethodBinding(nodePluginsItem);
                        lsMethodBinding.Add(obMethodBinding);
                    }
                    catch (Exception ex)
                    {
                        Logger.WriteLine("EstablishMethodBindings with PluginsConfig node exception for item:[0]", nodePluginsItem);
                        Logger.WriteLine(ex);
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine("EstablishMethodBindings with PluginsConfig node exception", ex);
            }
            return lsMethodBinding;
        }
        private static MethodBinding EstablishMethodBinding(XmlNode nodePlugins)
        {
            MethodBinding obMethodBinding = null;
            try
            {
                if (null == nodePlugins)
                {
                    Logger.WriteLine("Try to establish method binding but the plugins node object is null");
                }
                else
                {
                    string strPluginDir = XMLTools.GetAttributeValue(nodePlugins.Attributes, g_kstrXmlNodeAttr_Path);
                    XmlNodeList nodeListPlugin = nodePlugins.SelectNodes(g_kstrXmlNodeName_Plugin);
                    foreach (XmlNode nodePluginItem in nodeListPlugin)
                    {
                        try
                        {
                            // Assembly
                            AssemblyController obAssemblyController = EstablishAssemblyController(nodePluginItem, strPluginDir);

                            // Bind methods
                            XmlNodeList nodeListBinding = nodePluginItem.SelectNodes(g_kstrXmlNodeName_Binding);
                            if (null == nodeListBinding)
                            {
                                Logger.WriteLine("EstablishMethodBindings but not binding info, if readly no need bind, ignore this log");
                            }
                            else
                            {
                                Dictionary<MethodDeclaringInfo, MethodDeclaringInfo> dicMethodBindInfoTotal = new Dictionary<MethodDeclaringInfo, MethodDeclaringInfo>();
                                foreach (XmlNode nodeBinding in nodeListBinding)
                                {
                                    try
                                    {
                                        if (null != nodeBinding)
                                        {
                                            AppendMethodBindInfo(dicMethodBindInfoTotal, nodeBinding);
                                        }
                                        obMethodBinding = new MethodBinding(obAssemblyController, dicMethodBindInfoTotal);
                                    }
                                    catch (Exception ex)
                                    {
                                        Logger.WriteLine("EstablishMethodBindings with binding node exception", ex);
                                    }
                                }
                            }
                        }
                        catch (Exception ex)
                        {
                            Logger.WriteLine("EstablishMethodBindings with Plugin node exception", ex);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine("EstablishMethodBindings with PluginsConfig node exception", ex);
            }
            return obMethodBinding;
        }
        private static AssemblyController EstablishAssemblyController(XmlNode nodePlugin, string strPluginDir)
        {
            AssemblyController obAssemblyController = null;
            try
            {
                if ((null != nodePlugin) && (null != nodePlugin.Attributes))
                {
                    string strName = XMLTools.GetAttributeValue(nodePlugin.Attributes, g_kstrXmlNodeAttr_Name);
                    string strProcessorArchitecture = XMLTools.GetAttributeValue(nodePlugin.Attributes, g_kstrXmlNodeAttr_ProcessorArchitecture);
                    string strPublicKeyToken = XMLTools.GetAttributeValue(nodePlugin.Attributes, g_kstrXmlNodeAttr_PublicKeyToken);
                    string strCulture = XMLTools.GetAttributeValue(nodePlugin.Attributes, g_kstrXmlNodeAttr_Culture);
                    string strVersion = XMLTools.GetAttributeValue(nodePlugin.Attributes, g_kstrXmlNodeAttr_Version);
                    string strTargetProcess = XMLTools.GetAttributeValue(nodePlugin.Attributes, g_kstrXmlNodeAttr_Target);
                    obAssemblyController = new AssemblyController(strPluginDir, strName, strProcessorArchitecture, strPublicKeyToken, strCulture, strVersion, strTargetProcess);
                }
                else
                {
                    Logger.WriteLine("Establish assembly controller failed with an error plugin node:[{0}], empty or no attributes", nodePlugin);
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return obAssemblyController;
        }
        private static void AppendMethodBindInfo(Dictionary<MethodDeclaringInfo, MethodDeclaringInfo> dicMethodBindInfo, XmlNode nodeBinding)
        {
            try
            {
                if ((null != nodeBinding) && (null != nodeBinding.Attributes))
                {
                    if (null == dicMethodBindInfo)
                    {
                        dicMethodBindInfo = new Dictionary<MethodDeclaringInfo, MethodDeclaringInfo>();
                    }

                    string strSourceDeclaringType = XMLTools.GetAttributeValue(nodeBinding.Attributes, g_kstrXmlNodeAttr_Source);
                    string strTargetDeclaringType = XMLTools.GetAttributeValue(nodeBinding.Attributes, g_kstrXmlNodeAttr_Target);

                    XmlNodeList nodeListBindingMethod = nodeBinding.SelectNodes(g_kstrXmlNodeName_BindingMethod);
                    if ((null != nodeListBindingMethod) && (0 < nodeListBindingMethod.Count))
                    {
                        foreach (XmlNode nodeBindingMethod in nodeListBindingMethod)
                        {
                            try
                            {
                                if (null == nodeBindingMethod)
                                {
                                    Logger.WriteLine("Try to establish method binding info in the bind node:[{0}] under declaring type:[{1},{2}] but a bindind method node object is null", 
                                        nodeBinding.Name, strSourceDeclaringType, strTargetDeclaringType);
                                }
                                else
                                {
                                    MethodDeclaringInfo obSourceMethodDeclaringInfo = null;
                                    MethodDeclaringInfo obTargetMethodDeclaringInfo = null;
                                    EstablishMethodDeclaringBindingPair(nodeBindingMethod, strSourceDeclaringType, strTargetDeclaringType, out obSourceMethodDeclaringInfo, out obTargetMethodDeclaringInfo);
                                    if ((null != obSourceMethodDeclaringInfo) && (null != obTargetMethodDeclaringInfo))
                                    {
                                        CommonHelper.AddKeyValuesToDic(dicMethodBindInfo, obSourceMethodDeclaringInfo, obTargetMethodDeclaringInfo);
                                    }
                                    else
                                    {
                                        Logger.WriteLine("Try to establish method binding info in the bind node:[{0}] under declaring type:[{1},{2}], but the bindind method node:[{3}] analysis failed, no bindmethod info under this binding node",
                                            nodeBinding.Name, strSourceDeclaringType, strTargetDeclaringType, nodeBindingMethod.Name);
                                    }
                                }
                            }
                            catch (Exception ex)
                            {
                                Logger.WriteLine(ex);
                            }
                        }
                    }
                    else
                    {
                        Logger.WriteLine("Try to establish method binding info but the bind node:[{0}] do not contains any bindind method", nodeBinding);
                    }
                }
                else
                {
                    Logger.WriteLine("Establish method binding info failed with an error plugin node:[{0}], empty or no attributes", nodeBinding);
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
        }
        private static void EstablishMethodDeclaringBindingPair(XmlNode nodeBindingMethod,
            string strSourceDeclaringType, string strTargetDeclaringType, out MethodDeclaringInfo obSourceMethodDeclaringInfo, out MethodDeclaringInfo obTargetMethodDeclaringInfo)
        {
            obSourceMethodDeclaringInfo = null;
            obTargetMethodDeclaringInfo = null;
            try
            {
                // <bindingMethod source="set_CommandText" target="SetCommandText" parameters="System.String"/>
                if ((null != nodeBindingMethod) && (null != nodeBindingMethod.Attributes))
                {
                    string strSourceMethodName = XMLTools.GetAttributeValue(nodeBindingMethod.Attributes, g_kstrXmlNodeAttr_Source);
                    string strTargetMethodName = XMLTools.GetAttributeValue(nodeBindingMethod.Attributes, g_kstrXmlNodeAttr_Target);
                    string strParameters = XMLTools.GetAttributeValue(nodeBindingMethod.Attributes, g_kstrXmlNodeAttr_Parameters);
                    string[] szParameters = String.IsNullOrEmpty(strParameters) ? null : strParameters.Split(',');
                    string strBindReturn = XMLTools.GetAttributeValue(nodeBindingMethod.Attributes, g_kstrXmlNodeAttr_BindReturn);
                    bool bBindReturn = String.IsNullOrEmpty(strBindReturn) ? true : CommonHelper.ConverStringToBoolFlag(strBindReturn, true);
                    obSourceMethodDeclaringInfo = new MethodDeclaringInfo(strSourceDeclaringType, strSourceMethodName, szParameters, false);
                    obTargetMethodDeclaringInfo = new MethodDeclaringInfo(strTargetDeclaringType, strTargetMethodName, null, bBindReturn);
                }
                else
                {
                    Logger.WriteLine("Establish method declaring binding info failed with an error plugin node:[{0}], empty or no attributes", nodeBindingMethod);
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
        }
        private static string GetConfigFilePath()
        {
            string strConfigFilePath = g_kstrDefaultConfigFilePath;
            try
            {
                string strConfigFileRoot = CommonHelper.ReadRegisterKey(Microsoft.Win32.RegistryHive.LocalMachine, Microsoft.Win32.RegistryView.Registry64,
                    AsmExtendBaseInfo.g_kstrRegKey_Nextlabs, AsmExtendBaseInfo.g_kstrRegItemKey_AsmExtendConfigRoot);
                if (String.IsNullOrEmpty(strConfigFileRoot))
                {
                    strConfigFilePath = g_kstrDefaultConfigFilePath;
                }
                else
                {
                    // Find the assembly config file
                    if (String.IsNullOrEmpty(AsmExtendBaseInfo.g_strCurAssemblyName))
                    {
                        Logger.WriteLine("!!!!!!Error, currently the assembly name is null, please check");
                        strConfigFilePath = "";
                    }
                    else
                    {
                        strConfigFileRoot = CommonHelper.GetStandardFolderPath(strConfigFileRoot);
                        strConfigFilePath = strConfigFileRoot + AsmExtendBaseInfo.g_strCurAssemblyName + g_strConfigFileNameEndFlag;
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return strConfigFilePath;
        }
        #endregion
    }
}
