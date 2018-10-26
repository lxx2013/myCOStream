#ifndef LEXERUTILS_H
#define LEXERUTILS_H
/* 该文件用于纪录只被 lexer.l 所使用的函数 */
#include<stdlib.h>
#include "Coord.h"
#include "global_variable.h"

typedef int Bool;
int int_constant(const char *s, Bool decimal, Bool octal);
double float_constant(const char *s);
void GetCoord(Coord *pcoord,char* yytext);

static char *line_start;

#undef YY_INPUT
#define YY_INPUT(buf, result, max_size) \
    if (fgets(buf, max_size, yyin)==0) { result=0; } \
    else { line_start = (char *)buf; result = strlen(buf); }
#endif