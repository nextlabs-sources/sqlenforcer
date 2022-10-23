#include "DAEEncryptTool.h"

int main(int argc, char** argv)
{
    if (2 <= argc)
    {
        // TODO change the code to make the szKey can't be crack easier directly.
        AesEncryptor theAes;

        if (2 == argc)
        {
            puts(theAes.EncryptString(argv[1]).c_str());
            return 0;
        }
        else if ('d' == argv[1][0])
        {
            puts(theAes.DecryptString(argv[2]).c_str());
            return 0;
        }
    }

    printf("usage: cfg <plain text>\n cfg d <cipher text>\n");

    return 1;
}