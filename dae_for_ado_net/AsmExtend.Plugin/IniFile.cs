using System.Text;
using System.Runtime.InteropServices;

namespace AsmExtend.Plugin
{
    class IniFile
    {
        [DllImport("kernel32")]
        static extern int GetPrivateProfileString(string section,
                 string key, string def, StringBuilder retVal,
            int size, string filePath);

        public IniFile(string path)
        {
            path_ = path;
        }

        public string Read(string section, string key)
        {
            StringBuilder temp = new StringBuilder(255);
            int i = GetPrivateProfileString(section, key, "", temp,
                                            255, Path);
            return temp.ToString();
        }

        string Path { get => path_; }

        string path_;
    }
}
