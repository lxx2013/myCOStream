#include "ast.h"
GLOBAL Coord UnknownCoord = {
	/* line:   */ 0,
	/* offset: */ 0,
	/* file:   */ 0,
	/* includedp: */ FALSE
};

GLOBAL Node *NewNode(NodeType typ)
{
	Node *create = HeapNew(Node);
	create->typ = typ;
	create->coord = UnknownCoord;
	create->parenthesized = FALSE;
	//create->analysis.livevars = NULL;
	return(create);
}

/*************************************************************************/
/*                          Expression nodes                             */
/*************************************************************************/
GLOBAL Node *MakeConstSintTextCoord(const char * text,int value, Coord coord)
{
	Node *node = NewNode(Const);
	node->u.Const.type = "Sint";
	node->u.Const.value.i = value;
	node->u.Const.text = text;
	node->coord = coord;
	return (node);
}
GLOBAL Node *MakeConstDoubleTextCoord(const char *text, double value, Coord coord)
{
	Node *node = NewNode(Const);
	node->u.Const.type = "Double";
	node->u.Const.value.d = value;
	node->u.Const.text = text;
	node->coord = coord;
	return (node);
}
GLOBAL Node *MakeIdCoord(const char* text, Coord coord)
{
	Node *create = NewNode(Id);
	create->u.id.text = text;
	create->u.id.decl = NULL;
	create->coord = coord;
	return(create);
}