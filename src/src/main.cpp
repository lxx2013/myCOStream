#include<iostream>
#include "ast.h"

GLOBAL Bool PrintLineOffset = FALSE;

int main(){
    yyparse();
    std::cout<<std::endl<<"[main.cpp] yyparse() end"<<std::endl;
    return 0;
}
