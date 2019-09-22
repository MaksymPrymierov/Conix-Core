#ifndef STRING_H
#define STRING_H

#include <kernel/types.h>

struct string
{
        char* data;
        size_t size;
};

extern int string_init(struct string* s, size_t size);
extern int string_set(struct string* s, const char* string);
extern void string_clear(struct string* s);
extern int string_append(struct string* s, const char* str);
extern _Bool string_cmp(struct string* str1, struct string* str2);
extern _Bool string_cmp_native(struct string* str1, const char* str2);
extern int string_add_memory(struct string* s, size_t size);
extern void string_delete(struct string* s);

#endif
