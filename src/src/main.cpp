#include<iostream>
extern int yyparse();

int main(){
    yyparse();
    std::cout<<'Hello main.cpp'<<std::endl;
    return 0;
}
