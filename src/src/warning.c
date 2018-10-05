#define DEBUG
#include "basics.h"
#ifndef NO_STDARG
   #include <stdarg.h>
   #define VA_START(ap,fmt)   va_start(ap,fmt)
#else
   /*POSIX定义所遗留下的头文件varargs.h，它早在C标准化前就已经开始使用了且提供类似stdarg.h的功能。MSDN明确指出这一头文件已经过时，完全被stdarg.h取代。这个头文件不属于ISO C的一部分。文件定义在单一UNIX规范的第二个版本中。*/
   #include <varargs.h>
   extern int	vfprintf(FILE *, const char *, void *);
   #define VA_START(ap,fmt)   va_start(ap)
#endif

GLOBAL int Line = 1, Errors = 0, Warnings = 0;


GLOBAL void SyntaxError(const char *fmt, ...)
{
    va_list ap;
    VA_START(ap, fmt);
    Errors++;
    line("%s:%d: ", Filename, Line);
    char Redfmt[100];//用于输出红色提示字符的 fmt
    strcat(Redfmt,"\033[31m[ERROR]: ");
    strcat(Redfmt,fmt);
    strcat(Redfmt," \033[0m");
    vprintf(Redfmt, ap);
    va_end(ap);
}