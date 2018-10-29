#include "basics.h"
//字符串处理相关函数

#define TABLE_SIZE  231
typedef struct eT {
    char *string;
    struct eT *next;
} entryType;
PRIVATE entryType *hash_table[TABLE_SIZE];

//复制一段字符串同时分配内存, 返回分配的内存地址
PRIVATE char *copy_string(const char *string)
{
    char *new_string;

    new_string = HeapNewArray(char, strlen(string)+1);
    return strcpy(new_string, string);
}

/* hash table function */
PRIVATE short hash_function(const char *string)
{
    unsigned short i, k;
    unsigned long val;

    //assert(string != NULL);
    
    val = (short) string[0] + 1;
    for(i = 1; i < 8; i++) {
	    if (string[i] == 0) break;
	    k = string[i] & 0x3f;
	    val *= k + 7;
    }
    return((short)(val % TABLE_SIZE));
}

GLOBAL char *UniqueString(const char *string)
{
    short bucket = hash_function(string);
    entryType *entry;

    for (entry = hash_table[bucket]; entry != NULL; entry = entry->next)
      if (strcmp(string, entry->string) == 0)
	    return(entry->string);

    /* not found */
    entry = HeapNew(entryType);

    entry->string = copy_string(string);
    entry->next = hash_table[bucket];
    hash_table[bucket] = entry;

    return(entry->string);
}