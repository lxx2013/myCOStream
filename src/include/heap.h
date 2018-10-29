#ifndef _HEAP_H_
#define _HEAP_H_
/* 申请内存相关 */

#include "defines.h"
#define HeapNew(T) ((T *)HeapAllocate(1, sizeof(T))) // ast.cpp
#define HeapNewArray(T, c) ((T *)HeapAllocate(c, sizeof(T)))

GLOBAL void *HeapAllocate(int number, int size);
GLOBAL void HeapFree(void *ptr);

#endif  /* ifndef _HEAP_H_ */