
#ifndef _AST_H_
#define _AST_H_

#include "basics.h"
/* definition of Node data structure */
typedef struct nodeStruct Node;
typedef Node ChildNode;

typedef enum {
  /* expression nodes */
  Const, Id
} NodeType;



/*************************************************************************/
/*                          Expression nodes                             */
/*************************************************************************/
typedef struct {
	const char* text;
	Node *decl;  
	/* type is decl->u.decl.type */
	Node *value;
} idNode;
typedef struct {
	const char *text;  /* text will be NULL if constant was not derived from source, but computed by type-checker. */
	const char *type;  /* type is required to be one of: Sint, Uint, Slong, Ulong, Float, Double, or Adcl(Char) */
	union {
	  int    i;
	  long   l;
	  float         f;
	  double        d;
	  const char *  s;
	} value;
} ConstNode;

/*************************************************************************/
/*                            Node definition                            */
/*************************************************************************/
struct nodeStruct {
	NodeType typ;
	Coord coord; /* location of first terminal in production */
	short pass;/* pass is incremented for each top-level call to PrintNode, 以防止 PrintNode 陷入死循环 */
	short parenthesized; //标记源代码中这段是否被包裹于括号中

	/* data-flow analysis information */
	// Analysis analysis;

	union {
	 	idNode id;
        ConstNode Const;
	 } u;
};
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
                            AST constructors
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
GLOBAL Node *MakeConstSintTextCoord(const char *text, int value, Coord coord);
GLOBAL Node *MakeConstDoubleTextCoord(const char *text, double value, Coord coord);

GLOBAL Node *MakeIdCoord(const char* text, Coord coord);

#endif /* ifndef _AST_H_ */
