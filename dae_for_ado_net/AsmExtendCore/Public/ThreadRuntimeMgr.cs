using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtendCore
{
    public class ThreadRuntimeMgr
    {
        public static string CreateThreadMethodRTKey(MethodBase theMeThodBaseIn)
        {
            string strRefRecorderKey = "";
            try
            {
                string strNamespace = theMeThodBaseIn.DeclaringType.Namespace;
                string strClassName = theMeThodBaseIn.DeclaringType.Name;
                string strFunctionName = theMeThodBaseIn.Name;
                return CreateThreadMethodRTKey(strNamespace, strClassName, strFunctionName);
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return strRefRecorderKey;
        }
        private static string CreateThreadMethodRTKey(string strNamespace, string strClassName, string strFunctionName)
        {
            string strRefRecorderKey = "";
            try
            {
                int nCurThreadID = System.Threading.Thread.CurrentThread.ManagedThreadId;
                strRefRecorderKey = string.Format("{0}::{1}::{2}::{3}", strNamespace, strClassName, strFunctionName, nCurThreadID);
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return strRefRecorderKey;
        }

        public ThreadRuntimeMgr() { }

        internal void RemoveRefRecorder(string strRefRecorderKey, bool bForce)
        {
            try
            {
                if (String.IsNullOrEmpty(strRefRecorderKey))
                {
                    Logger.WriteLine("Try to remove RefRecoder object but the pass in key:[{0}] is null, this maybe a logic error please check", strRefRecorderKey);
                }
                else
                {
                    lock (m_obLockForDicRefRecorder)
                    {
                        if (null != m_dicRefRecorder)
                        {
                            RefRecorder obRecorder = null;
                            bool bFind = m_dicRefRecorder.TryGetValue(strRefRecorderKey, out obRecorder);
                            if (bFind)
                            {
                                // Remove
                                int nRef = obRecorder.ReleaseRef();
                                if (bForce || (0 == nRef))
                                {
                                    m_dicRefRecorder.Remove(strRefRecorderKey);
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
        }
        internal RefRecorder GetRefRecorder(string strRefRecorderKey)
        {
            RefRecorder obRecorderRet = null;
            try
            {
                if (String.IsNullOrEmpty(strRefRecorderKey))
                {
                    Logger.WriteLine("Try to get RefRecoder object but the pass in key:[{0}] is null, this maybe a logic error please check", strRefRecorderKey);
                }
                else
                {
                    lock (m_obLockForDicRefRecorder)
                    {
                        if (null == m_dicRefRecorder)
                        {
                            m_dicRefRecorder = new Dictionary<string, RefRecorder>();
                            obRecorderRet = new RefRecorder();
                            m_dicRefRecorder.Add(strRefRecorderKey, obRecorderRet);
                        }
                        else
                        {
                            bool bFind = m_dicRefRecorder.TryGetValue(strRefRecorderKey, out obRecorderRet);
                            if (bFind)
                            {
                                // add reference
                                obRecorderRet.AddRef();
                            }
                            else
                            {
                                // new
                                obRecorderRet = new RefRecorder();
                                m_dicRefRecorder.Add(strRefRecorderKey, obRecorderRet);
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return obRecorderRet;
        }

        internal void RemoveAutoFlag(string strAutoFlagKey)
        {
            try
            {
                lock (m_obLockForDicMyAutoFlag)
                {
                    CommonHelper.RemoveKeyValuesFromDic(m_dicMyAutoFlag, strAutoFlagKey);
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
        }
        internal MyAutoFlag GetAutoFlag(string strAutoFlagKey, bool bDefaultFlag)
        {
            MyAutoFlag obAutoFlagRet = null;
            try
            {
                if (String.IsNullOrEmpty(strAutoFlagKey))
                {
                    Logger.WriteLine("Try to get auto flag object but the pass in key:[{0}] is null, this maybe a logic error please check", strAutoFlagKey);
                }
                else
                {
                    lock (m_obLockForDicMyAutoFlag)
                    {
                        if (null == m_dicMyAutoFlag)
                        {
                            m_dicMyAutoFlag = new Dictionary<string, MyAutoFlag>();
                            obAutoFlagRet = new MyAutoFlag(bDefaultFlag);
                            m_dicMyAutoFlag.Add(strAutoFlagKey, obAutoFlagRet);
                        }
                        else
                        {
                            bool bFind = m_dicMyAutoFlag.TryGetValue(strAutoFlagKey, out obAutoFlagRet);
                            if (bFind)
                            {
                                // Return
                            }
                            else
                            {
                                // new
                                obAutoFlagRet = new MyAutoFlag(bDefaultFlag);
                                m_dicMyAutoFlag.Add(strAutoFlagKey, obAutoFlagRet);
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return obAutoFlagRet;
        }

        private object m_obLockForDicRefRecorder = new object();
        private Dictionary<string, RefRecorder> m_dicRefRecorder = new Dictionary<string, RefRecorder>();

        private object m_obLockForDicMyAutoFlag = new object();
        private Dictionary<string, MyAutoFlag> m_dicMyAutoFlag = new Dictionary<string, MyAutoFlag>();
    }
}
