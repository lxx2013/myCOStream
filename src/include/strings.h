#ifndef _STRINGS_H
#define _STRINGS_H

#include "defines.h"


/*  copy_string:
    Copy string to create location, and return the create location.
*/
PRIVATE char *copy_string(const char *string);
PRIVATE short hash_function(const char *string);
GLOBAL char *UniqueString(const char *string);   /* strings.c */

#endif
