using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Text;
using System.Threading;

namespace AsmExtend.Plugin.Common
{
    class WriteLockProxy : IDisposable
    {
        public WriteLockProxy(ReaderWriterLockSlim obReaderWriterLockSlim) { m_rwReaderWriterLockSlim = obReaderWriterLockSlim; m_rwReaderWriterLockSlim.EnterWriteLock(); }
        public void Dispose() { m_rwReaderWriterLockSlim.ExitWriteLock(); }
        private ReaderWriterLockSlim m_rwReaderWriterLockSlim = null;
    }
    class ReadLockProxy : IDisposable
    {
        public ReadLockProxy(ReaderWriterLockSlim obReaderWriterLockSlim) { m_rwReaderWriterLockSlim = obReaderWriterLockSlim; m_rwReaderWriterLockSlim.EnterReadLock(); }
        public void Dispose() { m_rwReaderWriterLockSlim.ExitReadLock(); }
        private ReaderWriterLockSlim m_rwReaderWriterLockSlim = null;
    }

    class CommonHelper
    {
        #region null object helper
        // Get solid string, avoid null object. If the string(strIn) is null, it will return empty string("").
        static public string GetSolidString(string strIn, bool bDoTrim)
        {
            if (String.IsNullOrEmpty(strIn))
            {
                return "";
            }
            else
            {
                return bDoTrim ? strIn.Trim() : strIn;
            }
        }
        static public string[] TrimStringArray(string[] szIn)
        {
            string[] szOut = new string[0];
            if (null != szIn && 0 < szIn.Length)
            {
                szOut = new string[szIn.Length];
                for (int i = 0; i < szIn.Length; ++i)
                {
                    szOut[i] = CommonHelper.GetSolidString(szIn[i], true);
                }
            }
            return szOut;
        }
        static public string JoinArray(string strSep, string[] szIn, bool bNeedTrim)
        {
            string strOut = "";
            if ((null != szIn) && (0 < szIn.Length))
            {
                if (bNeedTrim)
                {
                    string[] szTrimmed = TrimStringArray(szIn);
                    strOut = String.Join(strSep, szTrimmed);
                }
                else
                {
                    strOut = String.Join(strSep, szIn);
                }
            }
            return strOut;
        }

        // Get object string value, avoid null object
        static public string GetObjectStringValue<T>(T obT)
        {
            return (null != obT) ? obT.ToString() : "";
        }
        #endregion

        #region Register
        // If you do not want regsiter redirect, you can using to open the base key Microsoft.Win32.RegistryKey.OpenBaseKey(LocalMachine, Microsoft.Win32.RegistryView.Registry64);
        // Microsoft.Win32.Registry.LocalMachine
        // Microsoft.Win32.RegistryHive
        static public string ReadRegisterKey(Microsoft.Win32.RegistryHive emRegistryHive, Microsoft.Win32.RegistryView emRegistryView, string strSubKeyPath, string strItemKey)
        {
            string strItemValue = "";
            try
            {
                Microsoft.Win32.RegistryKey obRootKey = Microsoft.Win32.RegistryKey.OpenBaseKey(emRegistryHive, emRegistryView);
                strItemValue = ReadRegisterKey(obRootKey, strSubKeyPath, strItemKey);
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return strItemValue;
        }
        static public string ReadRegisterKey(Microsoft.Win32.RegistryKey obRootRegistryKey, string strSubKeyPath, string strItemKey)
        {
            string strItemValue = "";
            Microsoft.Win32.RegistryKey obSubRegistryKey = null;
            try
            {
                if ((null != obRootRegistryKey) && (!string.IsNullOrEmpty(strSubKeyPath)) && (!string.IsNullOrEmpty(strItemKey)))
                {
                    obSubRegistryKey = obRootRegistryKey.OpenSubKey(strSubKeyPath);
                    if (null != obSubRegistryKey)
                    {
                        object obItemValue = obSubRegistryKey.GetValue(strItemKey);
                        if (null != obItemValue)
                        {
                            strItemValue = obItemValue.ToString();
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Logger.WriteLine("Read register key {0}/{1}:{2} failed, {3}\n", obRootRegistryKey, strSubKeyPath, strItemKey, ex.Message);
            }
            finally
            {
                if (null != obSubRegistryKey)
                {
                    obSubRegistryKey.Close();
                }
            }
            return strItemValue;
        }
        #endregion

        static public T ConvertStringToEnum<T>(string strValue, bool bIgnoreCase, T emDefault)
        {
            try
            {
                return (T)Enum.Parse(typeof(T), strValue, bIgnoreCase);
            }
            catch (Exception ex)
            {
                Logger.WriteLine("Convert:[{0}] to enum:[{1}] failed, please check.{2}\n", strValue, typeof(T).ToString(), ex.Message);
            }
            return emDefault;
        }
        static public bool ConverStringToBoolFlag(string strIn, bool bDefaultValue)
        {
            bool bRet = bDefaultValue;
            if (null != strIn)
            {
                try
                {
                    bRet = Convert.ToBoolean(strIn);
                }
                catch (Exception ex)
                {
                    Logger.WriteLine("Convert:[{0}] to boolean failed, please check.{1}\n", strIn, ex.Message);
                }
            }
            return bRet;
        }

        static public string GetStandardFolderPath(string strFolderPath)
        {
            if (null == strFolderPath)
            {
                strFolderPath = "";
            }
            else if (0 < strFolderPath.Length)
            {
                if (!strFolderPath.EndsWith("\\"))
                {
                    strFolderPath += "\\";
                }
            }
            return strFolderPath;
        }

        public static T LoadFromXml<T>(string filePath)
        {
            T result = default(T);
            try
            {
                if (File.Exists(filePath))
                {
                    using (FileStream fs = new FileStream(filePath, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
                    {
                        using (StreamReader reader = new StreamReader(fs))
                        {
                            System.Xml.Serialization.XmlSerializer xmlSerializer = new System.Xml.Serialization.XmlSerializer(typeof(T));
                            result = (T)xmlSerializer.Deserialize(reader);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                if (ex is IOException)
                {
                    throw ex;
                }
                else
                {
                    Logger.WriteLine(ex);
                }
            }
            return result;
        }

        public static Assembly LoadAssemble(string strAssembleName)
        {
            Assembly resultAssemble = null;
            try
            {
                resultAssemble = Assembly.Load(strAssembleName);
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
                Logger.WriteLine(ex);
            }
            return resultAssemble;
        }

        public static Type[] GetTypesFromAssemble(Assembly assemble)
        {
            Type[] types = null;
            try
            {
                types = assemble.GetTypes();
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
                Logger.WriteLine(ex);
            }
            return types;
        }

        public static object GetTypeInstance(Type tyIn)
        {
            object obRet = null;
            try
            {
                obRet = Activator.CreateInstance(tyIn);
            }
            catch (Exception ex)
            {
                Logger.WriteLine(ex);
            }
            return obRet;
        }

        static public void SubStringBuilder(ref StringBuilder strBuilder, int nSubLength)
        {
            if (null != strBuilder)
            {
                if (strBuilder.Length >= nSubLength)
                {
                    strBuilder.Length -= nSubLength;
                }
                else
                {
                    strBuilder.Length = 0;
                }
            }
        }

        #region Array helper
        static public T GetArrayValueByIndex<T>(T[] szTIn, int nIndex, T tDefaultValue)
        {
            if ((0 <= nIndex) && (szTIn.Length > nIndex))
            {
                return szTIn[nIndex];
            }
            return tDefaultValue;
        }
        #endregion

        #region Dictionary helper
        static public TVALUE GetValueByKeyFromDic<TKEY, TVALUE>(Dictionary<TKEY, TVALUE> dicMaps, TKEY tKey, TVALUE tDefaultValue)
        {
            if (null != dicMaps)
            {
                if (dicMaps.ContainsKey(tKey))
                {
                    return dicMaps[tKey];
                }
            }
            return tDefaultValue;
        }
        static public void AddKeyValuesToDic<TKEY, TVALUE>(Dictionary<TKEY, TVALUE> dicMaps, TKEY tKey, TVALUE tValue)
        {
            if (null != dicMaps)
            {
                if (dicMaps.ContainsKey(tKey))
                {
                    dicMaps[tKey] = tValue;
                }
                else
                {
                    dicMaps.Add(tKey, tValue);
                }
            }
        }
        static public void RemoveKeyValuesFromDic<TKEY, TVALUE>(Dictionary<TKEY, TVALUE> dicMaps, TKEY tKey)
        {
            if (null != dicMaps)
            {
                if (dicMaps.ContainsKey(tKey))
                {
                    dicMaps.Remove(tKey);
                }
            }
        }
        static public string ConnectionDicKeyAndValues<TKEY, TVALUE>(Dictionary<TKEY, TVALUE> dicMaps, bool bRemoveEmptyItem, bool bEndWithKeySep, string strSepKeys, string strSepKeyAndValues)
        {
            if (null != dicMaps)
            {
                StringBuilder strOut = new StringBuilder();
                foreach (KeyValuePair<TKEY, TVALUE> pairItem in dicMaps)
                {
                    if ((!bRemoveEmptyItem) || (!string.IsNullOrEmpty(pairItem.Key.ToString()) && (!string.IsNullOrEmpty(pairItem.Value.ToString()))))
                    {
                        strOut.Append(pairItem.Key.ToString() + strSepKeyAndValues + pairItem.Value.ToString() + strSepKeys);
                    }
                }
                if (!bEndWithKeySep)
                {
                    SubStringBuilder(ref strOut, strSepKeys.Length);
                }
                return strOut.ToString();
            }
            return null;
        }
        static public Dictionary<string, TVALUE> DistinctDictionaryIgnoreKeyCase<TVALUE>(Dictionary<string, TVALUE> dicMaps)
        {
            Dictionary<string, TVALUE> dicCheckedMaps = new Dictionary<string, TVALUE>();
            foreach (KeyValuePair<string, TVALUE> pairItem in dicMaps)
            {
                CommonHelper.AddKeyValuesToDic(dicCheckedMaps, pairItem.Key.ToLower(), pairItem.Value);
            }
            return dicCheckedMaps;
        }
        #endregion

        #region Exception helper
        static public string GetFormatedExceptionMessage(Exception ex)
        {
            string ret = ex.Message;
            Exception innerEx = ex.InnerException;

            while (innerEx != null)
            {
                ret += "\n\tInner exception message:" + innerEx.Message;
                innerEx = innerEx.InnerException;
            }

            return ret;
        }
        #endregion
    }
}
