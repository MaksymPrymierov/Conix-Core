#pragma once
#include <kernel/types.h>

struct memory_allocator
{
        void* (*malloc)(size_t);
        void (*free)(void*);
};

void* malloc(size_t size);
void free(void* mem);

void* operator new(unsigned int size);
void operator delete(void* p, unsigned int size);

void set_allocator(memory_allocator &allocator);
