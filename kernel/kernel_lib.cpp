#include <kernel/kernel_lib.h>

size_t strlen(const char *string)
{
        const char *eos = string;
        while (*eos++);
        return (size_t)(eos - string - 1);
}

int strcmp(const char *str0, const char *str1)
{
        while (*str0) {
                if (*str0 != *str1) {
                        break;
                }

                ++str0;
                ++str1;
        }

        return *reinterpret_cast<const unsigned char*>(str0) -
                *reinterpret_cast<const unsigned char*>(str1);
}

void* memset(void *src, int c, size_t n)
{
        unsigned char* p = static_cast<unsigned char*>(src);
        while(n--) {
                *p++ = (unsigned char)c;
        }
        return src;
}

const void* memcpy(void *des, const void *src, size_t n)
{
        const unsigned char *p_s = static_cast<const unsigned char*>(src);
        unsigned char *p_d = static_cast<unsigned char*>(des);
        while(n--) {
                *p_d++ = *p_s++;
        }
        return src;
}

void* memmove(void *dest, const void *src, size_t n)
{
    char* d = (char*)dest;
    const char* s = (const char*)src;

    if (s < d) {
        s += n;
        d += n;
        while (n--)
            *--d = *--s;
    } else {
        while (n--)
            *d++ = *s++;
    }

    return dest;
}
