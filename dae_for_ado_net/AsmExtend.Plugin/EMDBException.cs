using System;
using System.Text;
using System.Text.RegularExpressions;
using System.Data.Common;

namespace AsmExtend.Plugin
{
    enum ExceptionAction
    {
        Throw,
        Nothrow
    }

    sealed class EmdbException : DbException
    {
        // The guid flag to throw out exception
        private static readonly string g_kstrGuidFlagToThrowOutException = "4DC93257-50D6-47B2-9BD1-8B7851E1C888";
        // The format of the thrown message
        private static readonly string g_kstrMessageFormatToThrowOut = "{0}{{\"action\": \"{1}\", \"message\": \"{2}\"}}";

        /// <summary>
        /// Wrapper the exception into need to be thrown out exception.
        /// Other exception may not be thrown out to the application.
        /// Of course, the actual processing will depend on the plug-in caller.
        /// </summary>
        /// <param name="ex">The exception need to be throw out</param>
        /// <param name="msg">The message of wrappered exception</param>
        /// <returns>Wrappered throw out exception</returns>
        internal static Exception WrapperIntoThrowOutException(Exception ex, string msg = "")
        {
            string message = string.Format(g_kstrMessageFormatToThrowOut, g_kstrGuidFlagToThrowOutException, ExceptionAction.Throw, msg);
            return new Exception(message, ex);
        }

        public static bool IsNeedToBeThrownOutException(Exception exIn)
        {
            bool bRet = false;

            string strErrMessage = exIn.Message;
            string pattern = string.Format("{0}\\s*{{\\s*\"action\"\\s*:\\s*\"(.*)\"\\s*,\\s*\"message\":\\s*\"(.*)\"\\s*}}", g_kstrGuidFlagToThrowOutException);

            Regex regex = new Regex(pattern);
            Match match = regex.Match(strErrMessage);

            if (match.Success && match.Groups[1].Value == ExceptionAction.Throw.ToString())
            {
                bRet = true;
            }

            return bRet;
        }

        public EmdbException(string message) : base(message) { }
    }
}
