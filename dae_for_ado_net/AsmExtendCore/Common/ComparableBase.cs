using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AsmExtendCore
{
    abstract class ComparableBase : IComparable<ComparableBase>, IComparer<ComparableBase>, IEqualityComparer<ComparableBase>, IEquatable<ComparableBase>
    {
        public readonly string ObjUniqueString = "";

        public ComparableBase(string strUniqueString)
        {
            ObjUniqueString = null == strUniqueString ? "" : strUniqueString;
        }

        // Override default get hash code from object
        public override int GetHashCode()
        {
            return ObjUniqueString.GetHashCode();
        }
        public override bool Equals(object otherObject)
        {
            if ((null != otherObject) && (otherObject is ComparableBase))
            {
                ComparableBase other = otherObject as ComparableBase;
                return Equals(other);
            }
            return false;
        }
        // IComparable<ComparableBase>
        public int CompareTo(ComparableBase other)
        {
            if (null != other)
            {
                return ObjUniqueString.CompareTo(other.ObjUniqueString);
            }
            return 1;
        }
        // IComparer
        public int Compare(ComparableBase obFirst, ComparableBase obSecond)
        {
            if (null == obFirst)
            {
                return -1;
            }
            else
            {
                return obFirst.CompareTo(obSecond);
            }
        }
        // IEqualityComparer
        public bool Equals(ComparableBase obFirst, ComparableBase obSecond)
        {
            return (0 == Compare(obFirst, obSecond));
        }
        public int GetHashCode(ComparableBase other)
        {
            if (null == other)
            {
                return 0;
            }
            return other.GetHashCode();
        }
        // IEquatable
        public bool Equals(ComparableBase other)
        {
            return (0 == this.CompareTo(other));
        }
    }
}
