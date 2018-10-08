#include "lexerUtils.h"
int int_constant(const char *s, Bool decimal, Bool octal){
    return atoi(s);
}
double float_constant(const char *s){
    return atof(s);
}