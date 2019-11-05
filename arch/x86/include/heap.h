#pragma once

#include <kernel/types.h>

struct heap_node
{
        struct heap_node* next;
        struct heap_node* last;
        size_t size;
        void* memory;
};

void heap_init(void* heap_top, void* heap_bottom);
void* sbrk(uintptr_t mem);
void* malloc(size_t mem);
