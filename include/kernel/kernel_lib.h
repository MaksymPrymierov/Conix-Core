#pragma once

#include <kernel/types.h>

size_t strlen(const char* string);

extern void* memset(void *src, int c, size_t n);
extern void* memcpy(void *des, void *src, size_t n);
extern void* memmove(void *des, const void *src, size_t n);
