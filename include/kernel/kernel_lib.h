#pragma once

#include <kernel/types.h>

size_t strlen(const char* string);

extern void* memset(void *src, int c, size_t n);
extern void* memcpy(void *des, void *src, size_t n);
extern void* memmove(void *des, const void *src, size_t n);

static const char numbers[] = "0123456789abcdefABCDEF";

template <typename T>
size_t num_counts(T num, u32 base)
{
        size_t count = num == 0 ? 1 : 0;
        while (num != 0) {
                ++count;
                num /= base;
        }
        return count;
}

#pragma GCC diagnostic ignored "-Warray-bounds"
template <typename T>
void num_to_str(T num, char* str, u8 base)
{
        bool minus = num >= 0 ? false : true;
        size_t i = num_counts<T>(num, base) - 1;

        if (str == nullptr || base > sizeof(numbers)) {
                return;
        }
        if (num < base) {
                if (minus) {
                        str[i] = '-';
                        str[i + 1] = numbers[num];
                        str[num_counts(num, base) + 1] = '\0';
                        return;
                }
                str[i] = numbers[num];
                --i;
                str[num_counts(num, base) + 1] = '\0';
        } else {
                if (minus) {
                        str[0] = '-';
                        ++str;
                }

                num_to_str<T>(num / base, str, base);
                str[i] = numbers[num % base];
                --i;
        }
}
