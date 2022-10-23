using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;

namespace AsmExtendCore
{
    class MethodBinding
    {
        public MethodBinding(AssemblyController obAssemblyController, Dictionary<MethodDeclaringInfo, MethodDeclaringInfo> dicMethodBindInfo)
        {
            m_obAssemblyController = obAssemblyController;
            m_dicMethodDeclaringBindInfo = dicMethodBindInfo;
            m_dicBindMethodInfo = new Dictionary<MethodDeclaringInfo, MyMethodInfo>();
        }
        public MyMethodInfo GetBindMethodInfo(MethodDeclaringInfo obSourceMethodDeclaringInfo)
        {
            MyMethodInfo obBindMethodInfo = null;
            MethodDeclaringInfo obBindMethodDeclaringInfo = GetBindMethodDeclaringInfo(obSourceMethodDeclaringInfo);
            if (null == obBindMethodDeclaringInfo)
            {
                // Bind method do not exist, ignore
            }
            else
            {
                if (!IsBindMethodInfoInited)
                {
                    InitBindMethodInfo();
                }
                obBindMethodInfo = InnerGetBindSystemMethodInfo(obBindMethodDeclaringInfo);
            }
            return obBindMethodInfo;
        }

        #region Inner methods
        private bool InitBindMethodInfo()
        {
            try
            {
                if (!IsBindMethodInfoInited)
                {
                    using (WriteLockProxy obReadLockProxy = new WriteLockProxy(m_rwLockBindMethodInfo))
                    {
                        if (!IsBindMethodInfoInited)
                        {
                            // To make sure only establish once
                            m_dicBindMethodInfo = EstablishBindMethodInfo(m_obAssemblyController, m_dicMethodDeclaringBindInfo.Values);
                            IsBindMethodInfoInited = (null != m_dicBindMethodInfo);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return IsBindMethodInfoInited;
        }
        private MethodDeclaringInfo GetBindMethodDeclaringInfo(MethodDeclaringInfo obSourceMethodDeclaringInfo)
        {
            MethodDeclaringInfo obBindMethodDeclaringInfo = null;
            try
            {
                if (null == obSourceMethodDeclaringInfo)
                {
                    // ignore
                }
                else
                {
                    MethodDeclaringInfo obTargetMethodDeclaringInfo = CommonHelper.GetValueByKeyFromDic(m_dicMethodDeclaringBindInfo, obSourceMethodDeclaringInfo, null);
                    if (null == obTargetMethodDeclaringInfo)
                    {
                        // ignore
                    }
                    else
                    {
                        obBindMethodDeclaringInfo = obTargetMethodDeclaringInfo;
                    }
                }                
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return obBindMethodDeclaringInfo;
        }
        private MyMethodInfo InnerGetBindSystemMethodInfo(MethodDeclaringInfo obMethodDeclaringInfo)
        {
            using (ReadLockProxy obReadLockProxy = new ReadLockProxy(m_rwLockBindMethodInfo))
            {
                return CommonHelper.GetValueByKeyFromDic(m_dicBindMethodInfo, obMethodDeclaringInfo, null);
            }
        }
        #endregion

        #region Statis methods
        private static Dictionary<MethodDeclaringInfo, MyMethodInfo> EstablishBindMethodInfo(AssemblyController obAssemblyController,
            ICollection<MethodDeclaringInfo> obCollectionMethodDeclaringInfo)
        {
            Dictionary<MethodDeclaringInfo, MyMethodInfo> dicBindMethodInfo = null;
            try
            {
                if ((null != obCollectionMethodDeclaringInfo) && (0 < obCollectionMethodDeclaringInfo.Count))
                {
                    if (null == obAssemblyController)
                    {
                        Logger.WriteLine("Try to init PluginBindMgr but the assemble controller is null");
                    }
                    else
                    {
                        Assembly obAssembly = obAssemblyController.GetAssembly();
                        if (null == obAssembly)
                        {
                            Logger.WriteLine("Try to get assembly from assemble controller:[{0},{1}] failed", obAssemblyController.Name, obAssemblyController.PublicKeyToken);
                        }
                        else
                        {
                            dicBindMethodInfo = new Dictionary<MethodDeclaringInfo, MyMethodInfo>();
                            Dictionary<string, HashSet<MethodDeclaringInfo>> dicNeatenMethodDeclaringInfo = NeatenMethodDeclaringInfo(obCollectionMethodDeclaringInfo);
                            // Loop bind method into to bind MethodInfo object
                            foreach (KeyValuePair<string, HashSet<MethodDeclaringInfo>> pairMethodDeclaringInfoItem in dicNeatenMethodDeclaringInfo)
                            {
                                try
                                {
                                    string strDeclaringType = pairMethodDeclaringInfoItem.Key;
                                    Type tyDeclaring = obAssembly.GetType(strDeclaringType);
                                    if (null == tyDeclaring)
                                    {
                                        Logger.WriteLine("Try to get declaring type:[{0}] from assemble controller:[{1},{2}] failed",
                                            strDeclaringType, obAssemblyController.Name, obAssemblyController.PublicKeyToken);
                                    }
                                    else
                                    {
                                        foreach (MethodDeclaringInfo obMethodDeclaringInfoItem in pairMethodDeclaringInfoItem.Value)
                                        {
                                            try
                                            {
                                                // For bind method do not consider the overwrite
                                                MethodInfo obMethodInfo = tyDeclaring.GetMethod(obMethodDeclaringInfoItem.MethodName);
                                                if (null == obMethodInfo)
                                                {
                                                    Logger.WriteLine("Try to get mehtod:[{0}] from assemble controller:[{1},{2}] in type:[{3}] failed",
                                                obMethodDeclaringInfoItem.MethodName, obAssemblyController.Name, obAssemblyController.PublicKeyToken, strDeclaringType);
                                                }
                                                else
                                                {
                                                    CommonHelper.AddKeyValuesToDic(dicBindMethodInfo, obMethodDeclaringInfoItem, new MyMethodInfo(obMethodInfo, obMethodDeclaringInfoItem.BindReturn));
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
                            }
                        }
                    }
                }
                else
                {
                    // No need Init, just new an empty collection and return
                    dicBindMethodInfo = new Dictionary<MethodDeclaringInfo, MyMethodInfo>();
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return dicBindMethodInfo;
        }
        private static Dictionary<string, HashSet<MethodDeclaringInfo>> NeatenMethodDeclaringInfo(ICollection<MethodDeclaringInfo> obCollectionMethodDeclaringInfo)
        {
            Dictionary<string, HashSet<MethodDeclaringInfo>> dicNeatenMethodDeclaringInfo = new Dictionary<string, HashSet<MethodDeclaringInfo>>();
            if (null != obCollectionMethodDeclaringInfo)
            {
                foreach (MethodDeclaringInfo obMethodDeclaringInfoItem in obCollectionMethodDeclaringInfo)
                {
                    if (null != obMethodDeclaringInfoItem)
                    {
                        HashSet<MethodDeclaringInfo> setMethodDeclaringInfo = null;
                        string strDeclaringType = obMethodDeclaringInfoItem.DeclaringType;
                        bool bFind = dicNeatenMethodDeclaringInfo.TryGetValue(strDeclaringType, out setMethodDeclaringInfo);
                        if (bFind && null != setMethodDeclaringInfo)
                        {
                            setMethodDeclaringInfo.Add(obMethodDeclaringInfoItem);
                        }
                        else
                        {
                            setMethodDeclaringInfo = dicNeatenMethodDeclaringInfo[strDeclaringType] = new HashSet<MethodDeclaringInfo>();
                            setMethodDeclaringInfo.Add(obMethodDeclaringInfoItem);
                        }
                    }
                }
            }
            return dicNeatenMethodDeclaringInfo;
        }
        #endregion

        #region Members
        private bool IsBindMethodInfoInited = false;
        private readonly AssemblyController m_obAssemblyController = null;
        private readonly Dictionary<MethodDeclaringInfo, MethodDeclaringInfo> m_dicMethodDeclaringBindInfo = new Dictionary<MethodDeclaringInfo, MethodDeclaringInfo>();    // Source,Target
        private ReaderWriterLockSlim m_rwLockBindMethodInfo = new ReaderWriterLockSlim(); // no-recursion lock
        private Dictionary<MethodDeclaringInfo, MyMethodInfo> m_dicBindMethodInfo = new Dictionary<MethodDeclaringInfo, MyMethodInfo>();
        #endregion
    }
}
