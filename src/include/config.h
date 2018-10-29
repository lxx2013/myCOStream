#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <limits.h>

/* maximum number of nested block scopes */
#define MAX_NESTED_SCOPES 100

/* default warning level */
#define WARNING_LEVEL 4

typedef char TARGET_CHAR;
typedef int TARGET_INT;
typedef unsigned int TARGET_UINT;
typedef long TARGET_LONG;
typedef unsigned long TARGET_ULONG;

/* target limits */
#define TARGET_MAX_UCHAR 256
#define TARGET_MAX_INT INT_MAX
#define TARGET_MAX_UINT UINT_MAX
#define TARGET_MAX_LONG LONG_MAX
#define TARGET_MAX_ULONG ULONG_MAX

/* Basic sizes and alignments */
#define CHAR_SIZE sizeof(char)
#define CHAR_ALIGN CHAR_SIZE

#define SHORT_SIZE sizeof(short)
#define SHORT_ALIGN SHORT_SIZE

#define INT_SIZE sizeof(int)
#define INT_ALIGN INT_SIZE

#define FLOAT_SIZE sizeof(float)
#define FLOAT_ALIGN FLOAT_SIZE

#define DOUBLE_SIZE sizeof(double)
#define DOUBLE_ALIGN DOUBLE_SIZE

#define LONGDOUBLE_SIZE sizeof(long double)

#define LONGDOUBLE_ALIGN LONGDOUBLE_SIZE

#define LONG_SIZE sizeof(long)
#define LONG_ALIGN LONG_SIZE

#define LONGLONG_SIZE sizeof(long long)

#define LONGLONG_ALIGN LONGLONG_SIZE

#define POINTER_SIZE sizeof(void *)
#define POINTER_ALIGN POINTER_SIZE

#define BYTE_LENGTH CHAR_BIT
#define WORD_LENGTH (INT_SIZE * BYTE_LENGTH)

#endif /* ifndef _CONFIG_H_ */
