#ifndef _AST_DEFINES_H_
#define _AST_DEFINES_H_

#include "defines.h"

#define ASTSWITCH(n, CODE)  \
    switch (n->typ) { \
        case Const:         CODE(Const, n, &n->u.Const); break; \
        case Id:            CODE(Id, n, &n->u.id); break; \
        default:            error("[ast-defines.h] unexpected node type"); break; \
    }

#endif