#ifndef KERNEL_LIB_H
#define KERNEL_LIB_H

#include <kernel/types.h>

extern void s32_to_string(s32 n, char *s);
extern void u32_to_string(u32 n, char *s);

/* 
 * Function to determine the length of the string.
 */
extern size_t strlen(const char *string);

#endif
