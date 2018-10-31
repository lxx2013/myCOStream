#ifndef _LIST_H_
#define _LIST_H_

#include "defines.h"
struct liststruct
{
    Generic *element;
    struct liststruct *next;
};
typedef struct liststruct List;

#endif