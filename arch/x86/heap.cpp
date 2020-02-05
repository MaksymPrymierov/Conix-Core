#include <heap.h>
#include <kernel/kernel_lib.h>
#include <kernel/memory.h>

static struct heap_node* heap_t;
static struct heap_node* heap_b;
static struct heap_node* last_item;

static uintptr_t heap_top_adress;
static uintptr_t heap_bottom_adress;
static size_t heap_size;

static void* sbrk(uintptr_t mem)
{
        uintptr_t bottom = reinterpret_cast<intptr_t>(heap_b);
        uintptr_t result = bottom;
        heap_node* tmp = heap_b;

        while (1) {
                if (bottom != heap_bottom_adress && static_cast<intptr_t>
                        (bottom - heap_bottom_adress) > 
                        static_cast<intptr_t>(mem + sizeof(heap_node))) {
                        heap_b = reinterpret_cast<heap_node*>
                                (heap_bottom_adress);
                        return heap_b;
                } else if (result + sizeof(heap_node) +
                        tmp->size == reinterpret_cast<size_t>(tmp->next)) {
                        result = reinterpret_cast<uintptr_t>(tmp->next);
                        tmp = tmp->next;
                        continue;
                } else if (nullptr == tmp->next) {
                        return static_cast<void*>(tmp);
                } else if (static_cast<intptr_t>
                        (reinterpret_cast<uintptr_t>(tmp->next) -
                        (result + sizeof(heap_node) + tmp->size)) >= 
                        static_cast<intptr_t>(mem)) {
                        heap_node* next = tmp->next;
                        tmp = reinterpret_cast<heap_node*>
                                (result + sizeof(heap_node) + tmp->size);
                        result = reinterpret_cast<uintptr_t>(tmp);
                        tmp->next = next;
                        return reinterpret_cast<void*>(tmp);
                } else {
                        if (result != 
                                reinterpret_cast<uintptr_t>(last_item)) {
                                result = reinterpret_cast<uintptr_t>
                                        (tmp->next);
                                tmp = tmp->next;
                                continue;
                        }
                        return reinterpret_cast<void*>(ENOMEM);
                }
        }
}

static void* x86_malloc(size_t mem)
{
        if (!mem) {
                return nullptr;
        }

        heap_node* memory = static_cast<heap_node*>
                (sbrk(mem + sizeof(heap_node)));  
        if (reinterpret_cast<heap_node*>(ENOMEM) == memory) {
                return reinterpret_cast<heap_node*>(ENOMEM);
        }

        if (memory == last_item) {
                // Set item size
                last_item->size = mem;

                // Set pointer on data
                last_item->memory = last_item + 1;

                // Allocate memory on new empty item
                last_item->next = reinterpret_cast<heap_node*>(
                        reinterpret_cast<size_t>
                        (last_item->memory) + last_item->size);

                // Fill the new item
                last_item->next->last = last_item;
                last_item->next->memory = last_item->next;

                // Replace last_item on new item
                last_item = last_item->next;

                return last_item->last->memory;
        } else {
                // Set item size
                memory->size = mem;

                // Set pointer on data
                memory->memory = memory + 1;

                // Fill the new item
                memory->last = memory->next->last;
                
                // Replace link of items
                memory->last->next = memory;
                memory->next->last = memory;

                return memory->memory;
        }
}

static void x86_free(void* mem)
{
        heap_node* item = reinterpret_cast<heap_node*>
                (reinterpret_cast<size_t>(mem) - sizeof(heap_node));
        if (item != heap_b) {
                item->last->next = item->next;
                item->next->last = item->last;
        } else {
                item->next->last = NULL;
                heap_b = item->next;
        }
}

static memory_allocator allocator =
{
        .malloc = x86_malloc,
        .free   = x86_free,
};

void heap_init(void* heap_top, void* heap_bottom)
{
        heap_t = static_cast<heap_node*>(heap_top);
        heap_b = static_cast<heap_node*>(heap_bottom);
        last_item = heap_b;
        
        heap_top_adress = reinterpret_cast<uintptr_t>(heap_top);
        heap_bottom_adress = reinterpret_cast<uintptr_t>(heap_bottom);
        heap_size = heap_top_adress - heap_bottom_adress;

        memset(heap_b, 0, sizeof(heap_node));
        set_allocator(allocator);
}
