using System;
using System.Threading;
using System.Collections;
using System.Collections.Generic;

namespace AsmExtend.Plugin
{
    class FixedSizeDictionary<TKey, TValue>
    {
        public FixedSizeDictionary(int capacity)
        {
            this.capacity = capacity;
            list = new LinkedList<TKey>();
            dict = new Dictionary<TKey, TValue>(capacity + 1);
        }

        ~FixedSizeDictionary()
        {
            if (rwLock != null)
            {
                rwLock.Dispose();
                rwLock = null;
            }
        }

        public void Add(TKey key, TValue value)
        {
            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                dict.Add(key, value);
                list.AddLast(key);

                if (dict.Count > capacity)
                {
                    if (dict.Remove(list.First.Value))
                    {
                        list.RemoveFirst();
                    }
                }
            }
        }
        public bool Remove(TKey key)
        {
            using (var writeLock = new Common.WriteLockProxy(rwLock))
            {
                if (dict.Remove(key))
                {
                    return list.Remove(key);
                }
                return false;
            }
        }

        public bool ContainsKey(TKey key)
        {
            using (var readLock = new Common.ReadLockProxy(rwLock))
            {
                return dict.ContainsKey(key);
            }
        }

        public TValue this[TKey key]
        {
            get
            {
                using (var readLock = new Common.ReadLockProxy(rwLock))
                {
                    return dict[key];
                }
            }

            set
            {
                using (var writeLock = new Common.WriteLockProxy(rwLock))
                {
                    if (ContainsKey(key))
                    {
                        dict[key] = value;
                    }
                    else
                    {
                        throw new KeyNotFoundException();
                    }
                }
            }
        }

        public Dictionary<TKey, TValue>.KeyCollection Keys => dict.Keys;

        public Dictionary<TKey, TValue>.ValueCollection Values => dict.Values;

        public int Count => dict.Count;

        private int capacity;
        private LinkedList<TKey> list;
        private Dictionary<TKey, TValue> dict;
        private ReaderWriterLockSlim rwLock = new ReaderWriterLockSlim();
    }
}
