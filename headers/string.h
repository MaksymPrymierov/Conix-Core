#ifndef CONIXCORE_STRING
#define CONIXCORE_STRING

/*
 * Type for string variables
 */
typedef char* string;

/*
 * Returns the number of elements 
 * in a string without regard to the null character
 */
size_t strlen(char *str);
/*
 * Combines two lines.
 */
char*  strcat(char *str, char *add_str);
#endif
