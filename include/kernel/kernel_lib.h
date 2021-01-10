// SPDX-License-Identifier: GPL-3.0-only
/* -*- ConixCore -*- ------------------------------------------------------- *
 *
 *   Copyright (C) 2019-2021 Maksym Prymierov
 *
 * ------------------------------------------------------------------------- */

#pragma once

#include <kernel/types.h>

size_t strlen(const char* string);
int strcmp(const char* str0, const char* str1);

extern void* memset(void *src, int c, size_t n);
const extern void* memcpy(void *des, const void *src, size_t n);
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
        size_t i;
        if (num < 0) {
                str[0] = '-';
                ++str;
                num *= -1;
        }

        i = num_counts<T>(num, base) - 1;

        if (str == nullptr || base > sizeof(numbers)) {
                return;
        }
        if (num < base) {
                str[i] = numbers[num];
                str[i + 1] = '\0';
        } else {
                num_to_str<T>(num / base, str, base);
                str[i] = numbers[num % base];
        }
}
