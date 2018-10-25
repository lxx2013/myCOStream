// 把上下文无关的 全局变量声明 从 basics.h 中剥离出来
#ifndef _GLOBAL_VARIABEL_H
#define _GLOBAL_VARIABEL_H
#include "defines.h"

/* Basic Global Variables */
GLOBAL extern int Line, LineOffset, Errors, Warnings;    /* warning.c */
GLOBAL extern char *Filename;                /* c4.l */
#define MAX_FILES       256
GLOBAL extern char *FileNames[MAX_FILES];    /* c4.l: file # to name mapping*/
GLOBAL extern unsigned int CurrentFile;      /* c4.l: current file number */
GLOBAL extern Bool CurrentIncludedp;         /* c4.l */

#endif

