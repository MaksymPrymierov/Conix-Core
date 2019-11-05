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
static bool debug = 0;

void heap_init(void* heap_top, void* heap_bottom)
{
        heap_t = (heap_item*)heap_top;
        heap_b = (heap_item*)heap_bottom;
        last_item = heap_b;

        heap_top_adress = (uintptr_t)heap_top;
        heap_bottom_adress = (uintptr_t)heap_bottom;
        heap_size = heap_top_adress - heap_bottom_adress;

        memset(heap_b, 0, sizeof(struct heap_item));
}

void* sbrk(intptr_t mem)
{
        intptr_t ret = (intptr_t)heap_b;
       
        while (1) {
                if ((intptr_t)heap_b != heap_bottom_adress &&
                        (intptr_t)heap_b - heap_bottom_adress >
                        mem + HEAP_ITEM_SIZE) {
                        ret = heap_bottom_adress;
                        heap_b = (struct heap_item*)heap_bottom_adress;
                        goto ret;
                } else if (ret + HEAP_ITEM_SIZE + 
                        ((struct heap_item*)ret)->size ==
                        (intptr_t)(((struct heap_item*)ret)->next)) {
                        ret = (intptr_t)(((struct heap_item*)ret)->next);
                        continue;
                } else if (((struct heap_item*)ret)->next == NULL) {
                        goto ret;
                } else if ((intptr_t)(((struct heap_item*)ret)->next) -
                        (ret + HEAP_ITEM_SIZE + 
                        ((struct heap_item*)ret)->size) >= mem) {
                        void* next = ((struct heap_item*)ret)->next;
                        ret = ret + HEAP_ITEM_SIZE 
                                + ((struct heap_item*)ret)->size;
                        ((struct heap_item*)ret)->next = next;
                        goto ret;
                } else {
                        if ((void*)ret != last_item) {
                                ret = (uintptr_t)(((struct heap_item*)ret)
                                      ->next);
                                continue;
                        }
                        ret = NOMEM;
                        goto ret;
                }
        }

ret:
        return (struct heap_item*)ret;
}

void* hkmalloc(size_t mem)
{
        void* ret;

        if (!mem) {
                ret = NULL;
                goto ret;
        }
      
        struct heap_item* memory = sbrk(HEAP_ITEM_SIZE + mem);
        if ((void*)NOMEM == memory) {
                ret = (void*)NOMEM;
                goto ret;
        }

        if (memory == last_item) {
                // Set item size
                last_item->size = mem;

                // Set pointer on data
                last_item->memory = last_item + 1;

                // Allocate memory on new empty item
                last_item->next = last_item->memory + last_item->size;

                // Fill the new item
                last_item->next->last = last_item;
                last_item->next->memory = last_item->next;

                // Replace last_item on new item
                last_item = last_item->next;

                ret = last_item->last->memory;
                goto ret;
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

                ret = memory->memory;
                goto ret;
        }

ret:
        if (debug) {
                dbg("Allote a new memory: %u\n", ret);
        }

        return ret;
}

void hkfree(void* mem)
{
        struct heap_item* item = mem - HEAP_ITEM_SIZE;
        if (item != heap_b) {
                item->last->next = item->next;
                item->next->last = item->last;
        } else {
                item->next->last = NULL;
                heap_b = item->next;
        }

        if (debug) {
                dbg("Free the memory on adress: %u\n", mem);
        }
}
