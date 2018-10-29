#ifndef LEXERUTILS_H
#define LEXERUTILS_H
/* 该文件用于纪录只被 lexer.l 所使用的函数 */
#include<stdlib.h>
#include "Coord.h"
#include "global_variable.h"
#include "ast.h"

typedef int Bool;
Node *int_constant(const char *s, Coord coord, Bool decimal, Bool octal);
double float_constant(const char *s);
void GetCoord(Coord *pcoord,char* yytext);
extern char* line_start;

#endif