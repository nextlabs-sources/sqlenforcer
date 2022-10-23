using System;

namespace AsmExtend.Plugin
{
    class EvalResult : IDisposable
    {
        public EvalResult()
        {
            emdbResultHandle = NewResult();
        }

        public void Dispose()
        {
            FreeResult(this);
        }

        private static IntPtr NewResult()
        {
            IntPtr handle = default(IntPtr);
            var RT = EmdbSdkWrapper.EMDBNewResult(ref handle);

            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBNewResult Failed!");
            }

            return handle;
        }

        private static void FreeResult(EvalResult emdbResult)
        {
            var RT = EmdbSdkWrapper.EMDBFreeResult(emdbResult.emdbResultHandle);

            if (EmdbSdkWrapper.EMDBReturn.EMDB_SUCCESS != RT)
            {
                throw new EmdbException("EMDBFreeResult Failed!");
            }
        }

        public IntPtr Handle => emdbResultHandle;

        public EmdbSdkWrapper.EMDBResultCode Code
        {
            get => code;
            set => code = value;
        }
        public string Detail
        {
            get => detail;
            set => detail = value;
        }

        private IntPtr emdbResultHandle;

        private EmdbSdkWrapper.EMDBResultCode code;
        private string detail;
    }
}
