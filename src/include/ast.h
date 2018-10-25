
#ifndef _AST_H_
#define _AST_H_

#include "basics.h"
/* definition of Node data structure */

typedef enum {
  /* expression nodes */
  Const
} NodeType;

struct nodeStruct {
	NodeType typ;
	Coord coord; /* location of first terminal in production */

	/* pass is incremented for each top-level call to PrintNode, so 
	   that PrintNode can print out decls anywhere they are used
	   without infinite recursion on recursive data structures. */
	short pass;

	/* parenthesized is set on expressions which were parenthesized
	   in the original source:  e.g., (x+y)*(w+z) would have 
	   parenthesized==TRUE on both PLUS nodes, and parenthesized==FALSE
	   on both MULT nodes. */
	short parenthesized;

	/* data-flow analysis information */
	// Analysis analysis;

	// union {
	// 	adclNode adcl;
	// } u;
};
#endif /* ifndef _AST_H_ */
