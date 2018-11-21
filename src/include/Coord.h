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
#define PRINT_COORD(out, c)  

#endif