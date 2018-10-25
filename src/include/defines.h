// 把上下文无关的#define 从 basics.h 中剥离出来
#ifndef _DEFINES_H
#define _DEFINES_H

#define GLOBAL
#define PRIVATE static
typedef int Bool;
#define TRUE 1
#define FALSE 0

/*pretty-debug*/
// debug info is in blue
#ifdef DEBUG
#define debug(format, args...) fprintf(stdout, "\033[36m" format "\033[0m", ##args)
#else
#define debug(format, args...)
#endif
//line-column info is grey
#ifdef DEBUG
#define line(format, args...) fprintf(stdout, "\033[32m" format "\033[0m", ##args)
#else
#define line(format, args...)
#endif
// error info is in red
#define error(format, args...) fprintf(stderr, "\033[31m[ERROR]:  " format "\033[0m", ##args)
// warning info is in orange
#define warning(format, args...) fprintf(stderr, "\033[33m[WARNING]:" format "\033[30;1m", ##args)

#endif