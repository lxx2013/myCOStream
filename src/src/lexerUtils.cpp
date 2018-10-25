#include "lexerUtils.h"
int int_constant(const char *s, Bool decimal, Bool octal){
    return atoi(s);
}
double float_constant(const char *s){
    return atof(s);
}

/*获取 coordinates(坐标) , 即该匹配的单词的行好 line 和偏移 offset*/
PRIVATE inline void GetCoord(Coord *pcoord)
{
  char *s;
  int offset;

  pcoord->file = CurrentFile;
  pcoord->line = Line;
  pcoord->includedp = CurrentIncludedp;

  offset = 0;
  for (s = line_start; s < yytext; ++s) {
    if (*s == '\t')
      offset = ((offset / TAB_WIDTH) + 1) * TAB_WIDTH;
    else ++offset;
  }
  pcoord->offset = offset;
}
