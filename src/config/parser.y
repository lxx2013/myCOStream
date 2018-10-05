%{
    #define DEBUG
    #include "ast.h"
    /* 原 ANSI-C.y 中不明所以的 define,对应书中写到,yydebug控制是否产生调试报告(0值不产生),YYERROR_VERBOSE 没找到描述*/
    #ifndef YYDEBUG
    int yydebug=0;
    #endif
    #define YYERROR_VERBOSE 1

    /*
    PRIVATE void WarnAboutPrecedence(OpType op, Node *node);{
      if (node->typ == Binop && !node->parenthesized) {
        OpType subop = node->u.binop.op;

        if (op == OROR && subop == ANDAND)
          WarningCoord(4, node->coord, "suggest parentheses around && in operand of ||");
        else if ((op == '|' || op == '^') &&
             (subop == '+' || subop == '-' || subop == '&' || subop == '^') &&
             op != subop)
          WarningCoord(4, node->coord, "suggest parentheses around arithmetic in operand of %c", op);
      }
    }*/

    /* bison 进行语法分析时遇到错误默认调用的错误报告函数 */
    void yyerror(const char *msg){
        SyntaxError(msg);
    }
%}

/*在 union 里声明 %token 可能有的类型*/
%union{
    //Node *n;
    int n; //tag:v1.0.0 临时测试用的数据类型,目的是让这一次 make 能跑通
    //List *L;
    /*
    struct {
        TypeQual   tq;
        Coord      coord;   
    } tq;*/
    //Coord tok; //token coordinates
}

%token <n> FLOATINGconstant INTEGERconstant OCTALconstant HEXconstant WIDECHARconstant CHARACTERconstant

/*优先级标记*/
%left '='
%type <n> constant


%locations

%% 
/****************************** 常量的文法符号声明 **********************************/
constant: FLOATINGconstant      { $$ = $1; }
        | INTEGERconstant       { $$ = $1; }
        | OCTALconstant         { $$ = $1; }
        | HEXconstant           { $$ = $1; }
        | CHARACTERconstant     { $$ = $1; }
        ;
%%
/* ----语法树结束----*/

