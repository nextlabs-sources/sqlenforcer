using System;
using System.IO;
using System.Text;
using System.Security.Cryptography;
using System.Runtime.InteropServices;

namespace dae_for_windows_service
{
    class Utils
    {
        public static string CalcMd5FromFile(string file)
        {
            if (string.IsNullOrEmpty(file))
                return "";

            if (!File.Exists(file))
                return "";

            StringBuilder str = new StringBuilder();
            try
            {
                using (FileStream stream = File.Open(file, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
                using (MD5 md5 = MD5.Create())
                {
                    byte[] res = md5.ComputeHash(stream);
                    foreach (byte b in res)
                    {
                        str.Append(b.ToString("x2"));
                    }
                }
            }
            catch (Exception e)
            {
                Logger.Instance.Error($"Calculate MD5 from file: {file} failed!  msg: {e}");
                return "";
            }

            return str.ToString();
        }
    }
}
