#include <kernel/kernel_lib.h>
#include <kernel/test.h>

#define num_counts(number, base) \
        size_t count = number == 0 ? 1 : 0; \
        while (number != 0) { \
                ++count; \
                number /= base; \
        } \
        return count;


static const char numbers[] = "0123456789abcdefABCDEF";

void snum_to_string(s64 number, u8 base, char *string)
{
        _Bool minus = 0;
        size_t i = snum_counts(number, base) - 1;

        if (NULL == string) {
                goto err;
        }

        if (number < 0) {
                minus = 1;
                number = -number;
        }

        if (number < base) {
                if (minus) {
                        string[i] = '-';
                        string[i + 1] = numbers[number];
                        goto ret;
                }

                string[i] = numbers[number];
                --i;
                goto ret;
        } else {
                if (minus) {
                        string[0] = '-';
                        ++string;
                }

                snum_to_string(number / base, base, string);
                string[i] = numbers[number % base];
                --i;
                return;
        }

ret:
        string[snum_counts(number, base) + 1] = '\0';
        return;

err:
        return;
}

void unum_to_string(u64 number, u8 base, char *string)
{
        size_t i = unum_counts(number, base) - 1;

        if (NULL == string) {
                goto err;
        }

        if (number < base) {
                string[i] = numbers[number];
                --i;
                goto ret;
        } else {
                unum_to_string(number / base, base, string);
                string[i] = numbers[number % base];
                --i;
                return;
        }

ret:
        string[snum_counts(number, base) + 1] = '\0';
        return;

err:
        return;
}

size_t snum_counts(s64 number, u8 base)
{
        num_counts(number, base);
}

size_t unum_counts(u64 number, u8 base)
{
        num_counts(number, base);
}

size_t strlen(const char *string)
{
        const char *eos = string;
        while (*eos++);
        return (size_t)(eos - string - 1);
}

void* memset(void *src, int c, size_t n)
{
        unsigned char* p = src;
        while(n--) {
                *p++ = (unsigned char)c;
        }
        return src;
}

void* memcpy(void *des, void *src, size_t n)
{
        unsigned char *p_s = src;
        unsigned char *p_d = des;
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
