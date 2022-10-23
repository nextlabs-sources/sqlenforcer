using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;

namespace AsmExtendCore
{
    public static class MethodBindingInvoker
    {
        public static bool CheckAndInvokeBindMethodEx<TClass>(ThreadRuntimeMgr obThreadRuntimeMgr,
            MethodBase obMethodBase, TClass pThis, List<Object> lsParameters)
        {
            bool bPreventExecuteHostOrgBody = false;

            object obRetValueOut = null;
            bPreventExecuteHostOrgBody = CheckAndInvokeBindMethodEx(ref obRetValueOut, obThreadRuntimeMgr, obMethodBase, pThis, lsParameters);

            return bPreventExecuteHostOrgBody;
        }
        public static bool CheckAndInvokeBindMethodEx<TReturn, TClass>(ref TReturn tyRetValueOut, ThreadRuntimeMgr obThreadRuntimeMgr,
            MethodBase obMethodBase, TClass pThis, List<Object> lsParameters)
        {
            bool bPreventExecuteHostOrgBody = false;
            RefRecorder obRefRecoder = null;
            bool bExceptionNeedThrowOut = false;
            try
            {

                // Base parameters check
                if ((null == obThreadRuntimeMgr) || (null == obMethodBase))
                {
                    Logger.WriteLine("Try to check and invoke bind method but the pass base objcet ThreadRuntimeMgr:[{0}] or MethodBase:[{1}] is null", obThreadRuntimeMgr, obMethodBase);
                    return bPreventExecuteHostOrgBody;
                }

                bool bNeedInvokeBindMethod = false;
                string strRefRecorderKey = ThreadRuntimeMgr.CreateThreadMethodRTKey(obMethodBase);

                // Need check bind method
                MethodBindingMgr theMethodBindingMgrIns = MethodBindingMgr.GetInstance();
                List<MyMethodInfo> lsMethodInfo = theMethodBindingMgrIns.GetBindMethodInfo(obMethodBase);
                if (null == lsMethodInfo || 0 >= lsMethodInfo.Count)
                {
                    Logger.WriteLine("Current method:[{0}] no binding targets", obMethodBase.DeclaringType);
                }
                else
                {
                    // Invoke current binding method
                    Logger.WriteLine("Begin check and invoke binding method for:[{0}]", obMethodBase.DeclaringType);

                    obRefRecoder = obThreadRuntimeMgr.GetRefRecorder(strRefRecorderKey);
                    if (null == obRefRecoder)
                    {
                        // Exception, invoke org method
                        Logger.WriteLine("Do not find the method:[{0}] RefRecorder object, directly execute org method body. maybe this is an error, please check", obMethodBase.DeclaringType);
                    }
                    else
                    {
                        if (obRefRecoder.IsInRecursion())
                        {
                            // Bind method call back, invoke org method
                            Logger.WriteLine("Recursion invoke method:[{0}], maybe this is called by bind mehtod or host reinvoke", obMethodBase.DeclaringType);
                        }
                        else
                        {
                            // Invoke proxy
                            bNeedInvokeBindMethod = true;
                        }
                    }
                    object obRetValueOut = null;
                    if (bNeedInvokeBindMethod)
                    {
                        bPreventExecuteHostOrgBody = MethodBindingInvoker.InvokeMethodsBindTargets(out obRetValueOut, obMethodBase, pThis, lsParameters);
                    }
                    else
                    {
                        // Inner re-invoke host mehtod, we also can just return fase at here but if so, we cannot release RefRecorder if the org method throw exception out
                        // After we invoke the re-invoke the host method, we must return ture to avoid host mehtod invoke twice (one is by us, one is it self)
                        bool bNeedRemoveAutoFlag = false;
                        try
                        {
                            MyAutoFlag obHostInokveFlag = obThreadRuntimeMgr.GetAutoFlag(strRefRecorderKey, true);
                            if (obHostInokveFlag.IsTrue())
                            {
                                Exception exInvokeTarget = null;
                                obRetValueOut = InvokeMethodBase(obMethodBase, pThis, lsParameters, out exInvokeTarget);
                                if (null == exInvokeTarget)
                                {
                                    // Invoke success, prevent org method body execute again
                                    bPreventExecuteHostOrgBody = true;
                                    Logger.WriteLine("Invoke host method:[{0}] success, prevent org host body execute again and return", obMethodBase.DeclaringType);
                                }
                                else
                                {
                                    if (IsNeedToBeThrownOutException(exInvokeTarget))
                                    {
                                        // Invoke success, but the org method body exception
                                        // prevent org method body execute again and keep exception throw out
                                        Logger.WriteLine("Invoke host method:[{0}] success, but the host method throw some exception. Just keep throw it and prevent org host body execute again and return", obMethodBase.DeclaringType);
                                        bPreventExecuteHostOrgBody = true;
                                        bExceptionNeedThrowOut = true;
                                        // throw exInvokeTarget.InnerException;
                                        throw exInvokeTarget;   // In host method to convert this exception
                                    }
                                    else
                                    {
                                        // Invoke failed, maybe some loggic error happend, let org method body execute
                                        // bPreventExecuteHostOrgBody = false;
                                        Logger.WriteLine("Invoke host method:[{0}] failed, maybe some pass-in or code error issue happend, please check", obMethodBase.DeclaringType);
                                    }
                                }
                            }
                            else
                            {
                                Logger.WriteLine("Auto flag is false for invoke method:[{0}] need execute org mehtod body, case by re-invoke host method", obMethodBase.DeclaringType);
                                bNeedRemoveAutoFlag = true;
                            }
                        }
                        finally
                        {
                            if (bNeedRemoveAutoFlag)
                            {
                                obThreadRuntimeMgr.RemoveAutoFlag(strRefRecorderKey);
                            }
                        }
                    }

                    if (obRetValueOut is TReturn)
                    {
                        tyRetValueOut = (TReturn)obRetValueOut;
                    }
                }
            }
            finally
            {
                if (null != obRefRecoder)
                {
                    obRefRecoder.ReleaseRef();
                }
            }
            return bPreventExecuteHostOrgBody;
        }
        public static bool IsNeedToBeThrownOutException(Exception exIn)
        {
            bool bRet = false;

            string strErrMessage = exIn.Message;
            string pattern = string.Format("{0}\\s*{{\\s*\"action\"\\s*:\\s*\"(.*)\"\\s*,\\s*\"message\":\\s*\"(.*)\"\\s*}}", AsmExtendBaseInfo.g_kstrGuidFlagToThrowOutException);

            Regex regex = new Regex(pattern);
            Match match = regex.Match(strErrMessage);

            if (match.Success && match.Groups[1].Value == AsmExtendBaseInfo.NextLabsAction.Throw.ToString())
            {
                bRet = true;
            }

            return bRet;
        }

        private static bool IsTargetMethodBodyException(Exception exIn)
        {
            bool bRet = false;

            if (null == exIn)
            {
                bRet = false;
            }
            else
            {
                bRet = (exIn is System.Reflection.TargetInvocationException exTargetInvocation);
            }

            return bRet;
        }

        // If there is no parameters the szParameters must be set to null cannot be empty array new object[0]
        // If the parameter is an array type, must be use new list<object>{ szArray }, cannot use .toArray() method
        // TDelegate: Action Or Func
        private static bool InvokeMethodsBindTargets(MethodBase obMethodBase, Object pThis, List<Object> lsParameters)
        {
            bool bInvokeSuccess = false;

            object obRetValueOut = null;
            bInvokeSuccess = InvokeMethodsBindTargets(out obRetValueOut, obMethodBase, pThis, lsParameters);

            return bInvokeSuccess;
        }

        private static bool InvokeMethodsBindTargets(out object obRetValueOut, MethodBase obMethodBase, Object pThis, List<Object> lsParameters)
        {
            bool bInvokeSuccess = false;
            obRetValueOut = null;

            MethodBindingMgr theMethodBindingMgrIns = MethodBindingMgr.GetInstance();
            List<MyMethodInfo> lsMethodInfo = theMethodBindingMgrIns.GetBindMethodInfo(obMethodBase);
            if (null == lsMethodInfo || 0 >= lsMethodInfo.Count)
            {
                Logger.WriteLine("Current method:[{0}] no binding targets", obMethodBase.DeclaringType);
            }
            else
            {
                Delegate pOrgMethod = CommonHelper.CreateMethodDelegate(obMethodBase, pThis);
                if (null == pOrgMethod)
                {
                    Logger.WriteLine("Cannot create delete for method:[{0}], type:[{1}]", obMethodBase.Name, obMethodBase.DeclaringType);
                }
                else
                {
                    bInvokeSuccess = InvokeBindMethods(out obRetValueOut, lsMethodInfo, pThis, pOrgMethod, lsParameters);
                }
            }

            return bInvokeSuccess;
        }
        private static bool InvokeBindMethods(out object obRetValueOut, List<MyMethodInfo> lsBindMethodInfo, Object pThis, Delegate pOrgMethod, List<Object> lsParameters)
        {
            bool bInvokeSuccess = false;
            obRetValueOut = null;

            if (null == lsBindMethodInfo || 0 >= lsBindMethodInfo.Count)
            {
                Logger.WriteLine("Try to invoke mehtods but the pass in method list is empty");
            }
            else
            {
                bool bBindReturn = false;
                object obLastRet = null;
                foreach (MyMethodInfo obBindMethodInfoItem in lsBindMethodInfo)
                {
                    if (null == obBindMethodInfoItem || null == obBindMethodInfoItem.MethodInfoIns)
                    {
                        string strMethodName = (null != obBindMethodInfoItem && null != obBindMethodInfoItem.MethodInfoIns) ? obBindMethodInfoItem.MethodInfoIns.Name : "";
                        Logger.WriteLine("Try to invoke the method:[{0}] bind methods but one of them is empty, maybe the config file has some error", strMethodName);
                    }
                    else
                    {
                        if (null == lsParameters)
                        {
                            lsParameters = new List<object>();
                        }
                        lsParameters.Insert(0, pThis);
                        lsParameters.Insert(1, pOrgMethod);
                        obLastRet = obBindMethodInfoItem.MethodInfoIns.Invoke(null, lsParameters.ToArray());
                        if (obBindMethodInfoItem.BindReturn)
                        {
                            bBindReturn = true;
                            obRetValueOut = obLastRet;
                        }
                        bInvokeSuccess = true;  // one invoke success, return success
                    }
                }
                if (bBindReturn)
                {
                    obRetValueOut = obLastRet;
                }
            }

            return bInvokeSuccess;
        }
        private static object InvokeMethodBase(MethodBase obMethodBase, Object pThis, List<Object> lsParameters, out Exception exOut)
        {
            object obRet = null;
            exOut = null;
            try
            {
                if (null == obMethodBase)
                {
                    Logger.WriteLine("Try to invoke some method by method base but the pass in object is null");
                }
                else
                {
                    if ((null == lsParameters) || (0 == lsParameters.Count))
                    {
                        obRet = obMethodBase.Invoke(pThis, null);
                    }
                    else
                    {
                        obRet = obMethodBase.Invoke(pThis, lsParameters.ToArray());
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
                exOut = ex;
            }
            return obRet;
        }

        private static bool CheckAndInvokeBindMethod(out RefRecorder obRefRecoder, ThreadRuntimeMgr obThreadRuntimeMgr,
            MethodBase obMethodBase, Object pThis, List<Object> lsParameters)
        {
            bool bInvokeSuccess = false;
            obRefRecoder = null;

            object obRetValueOut = null;
            bInvokeSuccess = CheckAndInvokeBindMethod(out obRefRecoder, out obRetValueOut, obThreadRuntimeMgr, obMethodBase, pThis, lsParameters);

            return bInvokeSuccess;
        }
        private static bool CheckAndInvokeBindMethod(out RefRecorder obRefRecoder, out object obRetValueOut, ThreadRuntimeMgr obThreadRuntimeMgr,
            MethodBase obMethodBase, Object pThis, List<Object> lsParameters)
        {
            bool bInvokeSuccess = false;
            obRefRecoder = null;
            obRetValueOut = null;

            MethodBindingMgr theMethodBindingMgrIns = MethodBindingMgr.GetInstance();
            List<MyMethodInfo> lsMethodInfo = theMethodBindingMgrIns.GetBindMethodInfo(obMethodBase);
            if (null == lsMethodInfo || 0 >= lsMethodInfo.Count)
            {
                Logger.WriteLine("Current method:[{0}] no binding targets", obMethodBase.DeclaringType);
            }
            else
            {
                // Invoke current binding method
                Logger.WriteLine("Begin check and invoke binding method for:[{0}]", obMethodBase.DeclaringType);

                string strRefRecorderKey = ThreadRuntimeMgr.CreateThreadMethodRTKey(obMethodBase);
                obRefRecoder = obThreadRuntimeMgr.GetRefRecorder(strRefRecorderKey);
                if (null == obRefRecoder)
                {
                    // Exception, invoke org method                        
                }
                else
                {
                    if (obRefRecoder.IsInRecursion())
                    {
                        // Bind method call back, invoke org method
                    }
                    else
                    {
                        // Invoke proxy
                        bInvokeSuccess = MethodBindingInvoker.InvokeMethodsBindTargets(out obRetValueOut, obMethodBase, pThis, lsParameters);
                    }
                }
            }

            return bInvokeSuccess;
        }
    }
}
