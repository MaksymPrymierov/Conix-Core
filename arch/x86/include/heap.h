#ifndef HEAP_H
#define HEAP_H

#include <kernel/types.h>

#define HEAP_ITEM_SIZE sizeof(struct heap_item)

struct heap_item
{
        struct heap_item* next;
        struct heap_item* last;
        size_t size;
        void* memory;
};

extern void heap_init(void* heap_top, void* heap_bottom);
extern void* sbrk(intptr_t mem);
extern void* hkmalloc(size_t mem);
extern void hkfree(void *mem);

#endif
