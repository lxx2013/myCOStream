#include "ast.h"

/* used by HeapNew() (defined in ast.h) to allocate whole objects */
GLOBAL inline void *HeapAllocate(int number, int size)
{ 
	return calloc(number, size);
}

GLOBAL inline void HeapFree(void *ptr)
{
	free(ptr);
}

GLOBAL inline Node *NewNode(NodeType typ)
{
	Node *create = HeapNew(Node);

	create->typ = typ;
	create->coord = UnknownCoord;
	create->parenthesized = FALSE;
	//create->analysis.livevars = NULL;
	return(create);
}
GLOBAL inline Node *MakeId(const char* text)
{
	Node *create = NewNode(Id);

	create->u.id.text = text;
	create->u.id.decl = NULL;
	return(create);
}
GLOBAL inline Node *MakeIdCoord(const char* text, Coord coord)
{
	Node *create = MakeId(text);
	create->coord = coord;
	return(create);
}