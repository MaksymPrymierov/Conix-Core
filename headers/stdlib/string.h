#ifndef CONIXCORE_STRING
#define CONIXCORE_STRING

/*
 * Type for string variables
 */
typedef const char* string;

/*
 * Returns the number of elements 
 * in a string without regard to the null character
 */
size_t strlen(const char *str);

/*
 * Combines two lines.
 */
char* strcat(char *str, const char *add_str);

/*
 * Copy one line to another.
 */
int strcmp(const char *first, const char* second);

/*
 * Copies a piece of memory to another location.
 */
void* memcpy(void *dst, const void *src, size_t n);

/*
 * Sets data starting at a specific address in the memory
 * and after a certain distance from the beginning.
 */
void* memset(void *s, int c, size_t n);

#endif
