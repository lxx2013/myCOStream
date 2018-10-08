#ifndef _BASICS_H_
#define _BASICS_H_

#define GLOBAL
#define PRIVATE static
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
/***************************************************************************************/
/****************************  通用的 #include  *****************************************/
/***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Basic Global Variables */
GLOBAL extern int Line, LineOffset, Errors, Warnings;    /* warning.c */
GLOBAL extern char *Filename;                /* c4.l */
#define MAX_FILES       256
GLOBAL extern char *FileNames[MAX_FILES];    /* c4.l: file # to name mapping*/

/* pretty-printing */
void CharToText(char *array, unsigned char value);

/* warning.c */
GLOBAL void SyntaxError(const char *fmt, ...);

/* parsing phase */
GLOBAL int yyparse(void), yylex(void);

#endif  /* ifndef _BASICS_H_ */
