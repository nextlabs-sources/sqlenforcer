using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtendCore
{
    class MyMethodInfo
    {
        public MethodInfo MethodInfoIns = null;
        public bool BindReturn = false;
        
        public MyMethodInfo(MethodInfo obMethodInfo, bool bBindReturn)
        {
            MethodInfoIns = obMethodInfo;
            BindReturn = bBindReturn;
        }
    }
    class MethodDeclaringInfo : ComparableBase
    {
        public readonly string DeclaringType;
        public readonly string MethodName;
        public readonly string[] ParameterTypes;        // Parameter types
        public readonly bool BindReturn;

        public MethodDeclaringInfo(string strDeclaringType, string strMethodName, string[] szParameterTypes, bool bBindReturn)
            : base(EstablisUniqueString(strDeclaringType, strMethodName, szParameterTypes))
        {
            DeclaringType = CommonHelper.GetSolidString(strDeclaringType, true);
            MethodName = CommonHelper.GetSolidString(strMethodName, true);
            ParameterTypes = CommonHelper.TrimStringArray(szParameterTypes, true);
            BindReturn = bBindReturn;
        }

        public static MethodDeclaringInfo EstablishMethodDeclaringInfo(MethodBase obMethodBase)
        {
            MethodDeclaringInfo obMethodHelper = null;
            try
            {
                string strDeclaringType = obMethodBase.DeclaringType.FullName;
                string strMethodName = obMethodBase.Name;
                ParameterInfo[] szParameterInfo = obMethodBase.GetParameters();
                string[] szParameters = null;
                if ((null != szParameterInfo) && (0 < szParameterInfo.Length))
                {
                    szParameters = new string[szParameterInfo.Length];
                    for (int i = 0; i < szParameterInfo.Length; ++i)
                    {
                        szParameters[i] = szParameterInfo[i].ParameterType.FullName;
                    }
                }
                obMethodHelper = new MethodDeclaringInfo(strDeclaringType, strMethodName, szParameters, false);
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return obMethodHelper;
        }
        private static string EstablisUniqueString(string strDeclaringTypeIn, string strMethodNameIn, string[] szParameterTypesIn)
        {
            string strDeclaringType = CommonHelper.GetSolidString(strDeclaringTypeIn, true);
            string strMethodName = CommonHelper.GetSolidString(strMethodNameIn, true);
            string strParameterTypes = CommonHelper.JoinArray(",", szParameterTypesIn, true, true);

            return String.Format("{0}::{1}::{2}", strDeclaringType, strMethodName, strParameterTypes);
        }
    }
}
