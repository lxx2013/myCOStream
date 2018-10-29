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
GLOBAL Node *MakeConstSint(int value)
{
	Node *node = NewNode(Const);
	node->u.Const.type = "Sint";
	node->u.Const.value.i = value;
	node->u.Const.text = NULL;
	return node;
}
GLOBAL Node *MakeConstSintTextCoord(const char * text,int value, Coord coord)
{
	Node *create = MakeConstSint(value);
	create->u.Const.text = text;
	create->coord = coord;
	return (create);
}

GLOBAL Node *MakeId(const char* text)
{
	Node *create = NewNode(Id);

	create->u.id.text = text;
	create->u.id.decl = NULL;
	return(create);
}
GLOBAL Node *MakeIdCoord(const char* text, Coord coord)
{
	Node *create = MakeId(text);
	create->coord = coord;
	return(create);
}