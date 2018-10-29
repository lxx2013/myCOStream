#ifndef _PRINT_AST_H
#define _PRINT_AST_H

#include "ast.h"

GLOBAL void PrintNode(FILE *out, Node *node, int tab_depth); // print-ast.cpp
PRIVATE void PrintConst(FILE *out, Node *node, ConstNode *u, int offset, Bool norecurse);
GLOBAL int PrintConstant(FILE *out, Node *c, Bool with_name);
PRIVATE inline void PrintId(FILE *out, Node *node, idNode *u, int offset, Bool norecurse);

#endif
