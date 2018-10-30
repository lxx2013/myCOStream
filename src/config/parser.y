%{
    #define DEBUG
    #include "ast.h"
    #include "print-ast.h"
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
    Node *n;
    int num; //tag:v1.0.0 临时测试用的数据类型,目的是让这一次 make 能跑通
    //List *L;
    /*
    struct {
        TypeQual   tq;
        Coord      coord;   
    } tq;*/
    Coord tok; //token coordinates
}

%token <n> IDENTIFIER
// 常量
%token <n> FLOATINGconstant INTEGERconstant OCTALconstant HEXconstant WIDECHARconstant CHARACTERconstant
// 保留字符串 /* ANSI keywords, extensions below */
%token <tok> AUTO            DOUBLE          INT             STRUCT
%token <tok> BREAK           ELSE            LONG            SWITCH
%token <tok> CASE            ENUM            REGISTER        TYPEDEF
%token <tok> CHAR            EXTERN          RETURN          UNION
%token <tok> CONST           FLOAT           SHORT           UNSIGNED
%token <tok> CONTINUE        FOR             SIGNED          VOID
%token <tok> DEFAULT         GOTO            SIZEOF          VOLATILE
%token <tok> DO              IF              STATIC          WHILE

/*-----------------Define For SPL----------------*/
%token  COMPOSITE		 INPUT			 OUTPUT			 STREAM
%token  PARAM			 ADD
%token  INIT			 WORK			 WINDOW
%token  TUMBLING		 SLIDING

%token  SPLITJOIN        SPLIT				JOIN
%token  DUPLICATE        ROUNDROBIN		PIPELINE
%token  FILEREADER       FILEWRITER

/* Multi-Character operators */
%token <tok>  ARROW            /*    ->                              */
%token <tok>  ICR DECR         /*    ++      --                      */
%token <tok>  LS RS            /*    <<      >>                      */
%token <tok>  LE GE EQ NE      /*    <=      >=      ==      !=      */
%token <tok>  ANDAND OROR      /*    &&      ||                      */
%token <tok>  ELLIPSIS         /*    ...                             */

/* modifying assignment operators */
%token <tok> '='
%token <tok> MULTassign  DIVassign    MODassign   /*   *=      /=      %=      */
%token <tok> PLUSassign  MINUSassign              /*   +=      -=              */
%token <tok> LSassign    RSassign                 /*   <<=     >>=             */
%token <tok> ANDassign   ERassign     ORassign    /*   &=      ^=      |=      */

%type <n>  basic.type.name

/*优先级标记*/
%left '='
%type <n> constant


%locations

%% 
/****************************** 常量的文法符号声明 **********************************/
test: test constant 
    | constant
    | test IF
    | test basic.type.name
    | test IDENTIFIER  {{PrintNode(stdout,$2,3); }}
    | test '(' ')' {{ debug("()\n");}}
constant: FLOATINGconstant      { PrintNode(stdout,$1,3); }
        | INTEGERconstant       { PrintNode(stdout,$1,3); }
        | OCTALconstant         { PrintNode(stdout,$1,3); }
        | HEXconstant           { PrintNode(stdout,$1,3); }
        ;
basic.type.name:  INT       { /*$$ = StartPrimType(Int_ParseOnly, $1);  */   };

/********************************************************************************
*                                EXPRESSIONS                                    *
********************************************************************************/

// primary.expression:   IDENTIFIER           { $$ = $1; }
//                     | constant
                    // | string.literal.list
                    // | '(' expression ')'    { if ($2->typ == Comma) $2->coord = $1;
                    //                         $2->parenthesized = TRUE;
                    //                         $$ = $2; }
                    // /* GCC-inspired non ANSI-C extension */
                    // | '(' lblock statement.list rblock ')'
                    //     { if (ANSIOnly)
                    //     SyntaxError("statement expressions not allowed with -ansi switch");
                    //     $$ = MakeBlockCoord(NULL, NULL, GrabPragmas($3), $1, $4); }
                    // | '(' lblock declaration.list statement.list rblock ')'
                    //     { if (ANSIOnly)
                    //     SyntaxError("statement expressions not allowed with -ansi switch");
                    //     $$ = MakeBlockCoord(NULL, $3, GrabPragmas($4), $1, $5); }
                    ;

%%
/* ----语法树结束----*/

