#ifndef _BASICS_H_
#define _BASICS_H_
/***************************************************************************************/
/****************************  通用的 #include  *****************************************/
/***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
/***************************************************************************************/
/****************************  经过我拆分的 #include  ************************************/
/***************************************************************************************/
#include "Coord.h"
#include "defines.h"
#include "strings.h"
#include "ast-defines.h"
/***************************************************************************************/
/**************************** 原项目就有的 #include ***************************************/
/***************************************************************************************/
#include "heap.h"
#include "config.h"
#include "list.h"
/***************************************************************************************/

/* Global Flags */
GLOBAL extern Bool PrintLineOffset; /* main.c */

/* pretty-printing */
void CharToText(char *array, unsigned char value);

/* warning.c */
GLOBAL void SyntaxError(const char *fmt, ...);

/* parsing phase */
GLOBAL int yyparse(void), yylex(void);

#endif  /* ifndef _BASICS_H_ */
