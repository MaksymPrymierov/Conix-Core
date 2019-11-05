#pragma once
#include <kernel/types.h>
#define new(x) static_cast< x *>(malloc(sizeof(x)));
#define delete(x) free(static_cast<void*>(x));

struct memory_allocator
{
        void* (*malloc)(size_t);
        void (*free)(void*);
};

void* malloc(size_t size);
void free(void* mem);

void set_allocator(memory_allocator &allocator);
