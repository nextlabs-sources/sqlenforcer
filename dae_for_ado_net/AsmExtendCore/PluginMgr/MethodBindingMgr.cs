using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtendCore
{
    class MethodBindingMgr
    {
        #region Singleton
        static private object s_obLockForInstance = new object();
        static private MethodBindingMgr s_obMethodBindingMgrIns = null;
        static public MethodBindingMgr GetInstance()
        {
            if (null == s_obMethodBindingMgrIns)
            {
                lock (s_obLockForInstance)
                    if (null == s_obMethodBindingMgrIns)
                    {
                        s_obMethodBindingMgrIns = new MethodBindingMgr();
                    }
            }
            return s_obMethodBindingMgrIns;
        }
        private MethodBindingMgr()
        {
            try
            {
                PluginsConfigMgr thePluginsConfigMgrIns = PluginsConfigMgr.GetInstance();
                m_lsMethodBinding = thePluginsConfigMgrIns.GetMethodBindings();
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
        }
        #endregion

        public List<MyMethodInfo> GetBindMethodInfo(MethodBase obSourceMethodBase)
        {
            List<MyMethodInfo> lsMethodInfo = null;
            try
            {
                if ((null != m_lsMethodBinding) && (0 < m_lsMethodBinding.Count))
                {
                    lsMethodInfo = new List<MyMethodInfo>();
                    MethodDeclaringInfo obSourceMethodDeclaringInfo = MethodDeclaringInfo.EstablishMethodDeclaringInfo(obSourceMethodBase);
                    foreach (MethodBinding obMethodBindingItem in m_lsMethodBinding)
                    {
                        try
                        {
                            MyMethodInfo obMethodInfo = obMethodBindingItem.GetBindMethodInfo(obSourceMethodDeclaringInfo);
                            if (null != obMethodInfo)
                            {
                                lsMethodInfo.Add(obMethodInfo);
                            }
                        }
                        catch (Exception ex)
                        {
                            Logger.WriteLine(ex);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return lsMethodInfo;
        }

        #region
        private List<MethodBinding> m_lsMethodBinding = new List<MethodBinding>();
        #endregion
    }
}
