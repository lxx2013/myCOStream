#include<iostream>
#include "ast.h"

int main(){
    yyparse();
    std::cout<<std::endl<<"[main.cpp] yyparse() end"<<std::endl;
    return 0;
}
