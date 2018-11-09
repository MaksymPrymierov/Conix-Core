#ifndef CONIXCORE_STDLIB
#define CONIXCORE_STDLIB

#include "stddef.h"
#include <stdint.h>
#include <stdarg.h>
#include "stdio.h"
#include "string.h"

/*
 * Converts integer variables to a string
 */
char *itoa(int number, char *destination, int base);

#endif
