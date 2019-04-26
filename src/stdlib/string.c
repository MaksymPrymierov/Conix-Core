#include "../../headers/stdlib/stdlib.h"

size_t strlen(const char* str)
{
        const char *begin = str;

        while (*str++);
        return str - begin - 1;
}

char* strcat(char *str, const char* add_str)
{
        size_t i;
        size_t j;

        for (i = 0; str[i] != '\0'; i++);
        for (j = 0; add_str[j] != '\0'; j++) {
                str[i+j] = add_str[j];
        }

        str[i+j] = '\0';

        return str;
}

int strcmp(const char *first, const char *second)
{
        size_t lenF; 
        size_t lenS;
        int ret = 0;

        lenF = strlen(first);
        lenS = strlen(second);

        if (lenF > lenS) { 
                ret = 1;
                goto out;
        }

        if (lenF < lenS) {
                ret = -1;
                goto out;
        }
  
        for (int i = 0; i < lenF; ++i) {
                if (first[i] > second[i]) {
                        ret = 1;
                        goto out;
                }

                if (first[i] < second[i]) {
                        ret = -1;
                        goto out;
                }
        }

        out:
                return ret;
}

void* memcpy(void *dst, const void *src, size_t n)
{
        for (int i = 0; i < n; ++i) {
                *((unsigned char*)dst++) = *((unsigned char*)src++);
        }
}

void* memset(void *s, int c, size_t n)
{
        for (int i = 0; i < n; ++i) {
                *((unsigned char*)s++) = c;
        }
}
