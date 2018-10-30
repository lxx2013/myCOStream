#include "lexerUtils.h"
#define DEBUG
#include "basics.h"

Node *int_constant(const char *s, Coord coord, Bool decimal, Bool octal)
{
  Node *c;
  TARGET_ULONG value;
  value = strtol(s,NULL,0);
  c = MakeConstSintTextCoord(s,(TARGET_INT)value, coord);
  return (c);
}

double float_constant(const char *s){
    return atof(s);
}

/*获取 coordinates(坐标) , 即该匹配的单词的行好 line 和偏移 offset*/
void GetCoord(Coord *pcoord,char* yytext)
{
  debug("[lexerUtils.cpp GetCoord] yytext:%s\n",yytext);
  char *s;
  int offset;
  debug("[lexerUtils.cpp GetCoord] {line_start:%s}",line_start);

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
  debug("\n[lexerUtils.cpp GetCoord] pcoord:{line:%d,file:%d,offset:%d,includedp:%d}",pcoord->line,pcoord->file,pcoord->offset,pcoord->includedp);
}
