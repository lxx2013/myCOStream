%{
    #pragma ident "c4.l,v 1.21 1995/05/11 18:54:14 rcm Exp" //将指定的字符串放在可执行文件的 .comment 部分。https://blog.csdn.net/lowfly_xy/article/details/5414041
    
    //#include <ctype.h>
    #include "ast.h"

    #define DEBUGLEX
    #ifdef DEBUGLEX
    #define RETURN_TOKEN(x) return(print_token(x), x)
    #else
    #define RETURN_TOKEN(x) return(x)
    #endif
%}

/*状态定义也叫环境定义，它定义了匹配正规式时所处的状态的名字。状态定义以%s开始，后跟所定义的状态的名字，注意%s也要顶行首写https://blog.csdn.net/wp1603710463/article/details/50365495*/
%s C 

/*标识符(变量名) 以字母开头,后面跟着字母或数字或下划线*/
identifier ([a-zA-Z_][0-9a-zA-Z_]*)   

/*指数部分,例如 e3 或 E-3*/
exponent_part ([eE][-+]?[0-9]+)
/*小数部分,例如123.456 或123.或.123 注意 '123.'和'.123'这两种写法是符合标准的,但是看起来很奇怪所以不推荐后来这样写,建议替换为为'123.0'和'0.123'*/
fractional_constant ([0-9]*"."[0-9]+)|([0-9]+".")
/*浮点字面值可以用十进制或科学计数法（指数用E或e）表示，默认为double，在数值后加F或f表示单精度，加L或l表示扩展精度*/
floating_constant ((({fractional_constant}{exponent_part}?)|([0-9]+{exponent_part}))[FfLl]?)

integer_suffix_opt ([uU]?[lL]?[lL]?)|([lL][uU][lL]?)|([lL][lL][uU])
decimal_constant ("0"{integer_suffix_opt}|[1-9][0-9]*{integer_suffix_opt})
octal_constant ("0"[0-7]*{integer_suffix_opt})
hex_constant ("0"[xX][0-9a-fA-F]+{integer_suffix_opt})

simple_escape ([abfnrtv'"?\\])
octal_escape  ([0-7][^'\n]*)
hex_escape ("x"[^'\n]*)
bad_escape ([\\][^abfnrtv'"?\\x0-7\n ])

escape_sequence ([\\]({simple_escape}|{octal_escape}|{hex_escape}))
c_char ([^'\\\n]|{escape_sequence})
s_char ([^"\\\n]|{escape_sequence})

any_white ([ \011\013\014\015])
hwhite ([ \011])

%%

<INITIAL,C>.*                    {   char tmp[20];
                                    CharToText(tmp, *yytext); //这一行暂且不用了
                                    SyntaxError("Unexpected character: %s \n", yytext); }

%%

/*****第1步,获取文件名****/
GLOBAL char *Filename;
GLOBAL char *FileNames[MAX_FILES] = {"unknown"};
GLOBAL void SetFile(const char *name, int line){
  return ;
} 

/*获取 coordinates(坐标) , 即该匹配的单词的行好 line 和偏移 offset*/
/*PRIVATE inline void GetCoord(Coord *pcoord)
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
*/

int main(){
    yylex();
}
//<<flex 与 bison>>第144页:  当词法分析器到达文件的末尾时,它可以选择性地调用yywrap()来了解下一步操作.可以让 yywrap 返回1或者%option noyywrap 来终止词法分析操作.
int yywrap()
{
   return 1;
}