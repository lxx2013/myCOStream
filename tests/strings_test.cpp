#include <string.h>
#define TABLE_SIZE  231
short hash_function(const char *string)
{
    unsigned short i, k;
    unsigned long val;

    //assert(string != NULL);

    val = (short)string[0] + 1;
    for (i = 1; i < 8; i++)
    {
        if (string[i] == 0)
            break;
        k = string[i] & 0x3f;
        val *= k + 7;
    }
    return ((short)(val % TABLE_SIZE));
}
// http://www.cnblogs.com/Silababy/p/5226886.html#commentform
int getHashCode(const char *str)
{
    // 1315423911=b'1001110011001111100011010100111'
    unsigned int hash = 1315423911, ch;
    int i;
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        ch = str[i];
        hash ^= ((hash << 5) + ch + (hash >> 2));
    }
    return (hash % TABLE_SIZE);
}
#include <stdio.h>
int main()
{
    const char *str1 = "1", *str2 = "2";
    printf("string:%s , hash_function:%d ,getHashCode:%d\n", str1, hash_function(str1), getHashCode(str1));
    printf("string:%s , hash_function:%d ,getHashCode:%d\n", str2, hash_function(str2), getHashCode(str2));
}