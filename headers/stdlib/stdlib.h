#ifndef CONIXCORE_STDLIB
#define CONIXCORE_STDLIB

#include "stddef.h"
/*
 * Converts integer variables to a string
 */
char *itoa(int number, char *destination, int base);
void _memset(void *mem, char value, size_t count);

#endif
