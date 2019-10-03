#ifndef KERNEL_LIB_H
#define KERNEL_LIB_H

#include <kernel/types.h>

/* 
 * Convert integer signed numbers to string.
 */
extern void snum_to_string(s64 number, u8 base, char *string);

/* 
 * Convert integer unsigned numbers to string.
 */
extern void unum_to_string(u64 number, u8 base, char *string);

/*
 * Get counts of integer signed numbers.
 */
extern size_t snum_counts(s64 number, u8 base);

/*
 * Get counts of integer unsigned numbers.
 */
extern size_t unum_counts(u64 number, u8 base);

/* 
 * Function to determine the length of the string.
 */
extern size_t strlen(const char *string);

extern void* memset(void *src, int c, size_t n);
extern void* memcpy(void *des, void *src, size_t n);
extern void* memmove(void *des, const void *src, size_t n);

#endif
