#ifndef LEXERUTILS_H
#define LEXERUTILS_H
/* 该文件用于纪录只被 lexer.l 所使用的函数 */
#include<stdlib.h>
typedef int Bool;
int int_constant(const char *s, Bool decimal, Bool octal);
double float_constant(const char *s);
#endif