#include <heap.h>
#include <tty.h>
#include <kernel/kernel_lib.h>

#define dbg early_printk 

static struct heap_item* heap_t;
static struct heap_item* heap_b;

static struct heap_item* last_item;

static uintptr_t heap_top_adress;
static uintptr_t heap_bottom_adress;
static size_t heap_size;

void heap_init(void* heap_top, void* heap_bottom)
{
        heap_t = heap_top;
        heap_b = heap_bottom;
        last_item = heap_b;

        heap_top_adress = (uintptr_t)heap_top;
        heap_bottom_adress = (uintptr_t)heap_bottom;
        heap_size = heap_top_adress - heap_bottom_adress;

        memset(heap_b, 0, sizeof(struct heap_item));
}

void* hkmalloc(size_t mem)
{
        void* ret;

        if (!mem) {
                ret = NULL;
                goto err;
        }
       
        // Set item size
        last_item->size = mem;

        // Set pointer on data
        last_item->memory = last_item + 1;

        // Allocate memory on new empty item
        last_item->next = last_item->memory + last_item->size;

        // Fill the new item
        memset(last_item->next, 0, HEAP_ITEM_SIZE);
        last_item->next->last = last_item;
        last_item->next->memory = last_item->next;

        // Replace last_item on new item
        last_item = last_item->next;

        return last_item->last->memory;

err:
        return ret;
}
