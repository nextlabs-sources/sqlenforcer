using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtendCore
{
    class MyAutoFlag
    {
        public bool IsTrue()
        {
            lock (m_obLockForAutoFlag)
            {
                bool bOrgFlag = m_bAutoFalg;
                m_bAutoFalg = !m_bAutoFalg;
                return bOrgFlag;
            }  
        }
        public MyAutoFlag(bool bAutoFlag)
        {
            m_bAutoFalg = bAutoFlag;
        }
        private object m_obLockForAutoFlag = new object();
        private bool m_bAutoFalg = false;
    }
}
