#include <kernel/memory.h>

static memory_allocator mallocator;

void set_allocator(memory_allocator &allocator)
{
        mallocator = allocator;
}

void* malloc(size_t size)
{
        return mallocator.malloc(size);
}

void free(void* mem)
{
        mallocator.free(mem);
}

void* operator new(unsigned int size)
{
        return mallocator.malloc(size);
}

void operator delete(void* p, unsigned int size)
{
        mallocator.free(p);
}

void* operator new[](unsigned int size)
{
        return mallocator.malloc(size);
}

void operator delete[](void* p, unsigned int size)
{
        mallocator.free(p);
}
