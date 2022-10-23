using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;

namespace AsmExtendCore
{
    class RefRecorder
    {
        // ThreadID, MethodID, RefCount
        public RefRecorder()
        {
            AddRef();
        }

        public int AddRef() { ++m_nRef; return m_nRef; }
        public int ReleaseRef() 
        {
            if (0 < m_nRef)
            {
                --m_nRef;
            }
            return m_nRef; 
        }
        public bool IsInRecursion() { return (1 < m_nRef); }
        private int m_nRef;
    }
}
