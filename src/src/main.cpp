#include<iostream>
#include "ast.h"

int main(){
    yyparse();
    std::cout<<"Hello main.cpp"<<std::endl;
    return 0;
}
