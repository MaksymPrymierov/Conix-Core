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
int   strcmp(const char *first, const char* second);

void *memcpy(void *dst, const void *src, size_t n);
void *memset(void *s, int c, size_t n);

#endif
