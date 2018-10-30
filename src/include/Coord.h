/*这里存放和 定位(Coordinate) 的基础结构*/
#ifndef _COORD_H_
#define _COORD_H_

#include "defines.h"
#include "global_variable.h"

typedef struct coord {
	int line;
	short offset;
	short file;
	Bool includedp;
} Coord;
GLOBAL extern Coord UnknownCoord;
#define IsUnknownCoord(coord)  ((coord).file == UnknownCoord.file)
#define PRINT_COORD(out, c) \
{ if (PrintLineOffset) \
	fprintf(out," Coord:{file:%s,line:%d,offset:%d}", FileNames[(c).file], (int)(c).line, \
	(int)(c).offset); \
	else fprintf(out, " Coord:{file:%s,line:%d}", FileNames[(c).file], (int) (c).line); }


#endif