#include <kernel/queue.h>
#include <heap.h>
#include <tty.h>
#include <kernel/kernel_lib.h>

void queue_char_init(struct queue_char* q)
{
        memset(q, 0, sizeof(struct queue_char));
}

int queue_char_push(struct queue_char* q, char data)
{
        int ret;

        if (q->first_item == NULL) {
                q->first_item = hkmalloc(sizeof(struct queue_char_item));
                if ((int)q->first_item == NOMEM) {
                        ret = NOMEM;
                        goto error;
                }
                q->end_item = q->first_item;
                q->end_item->last_item = NULL;
                q->end_item->data = data;
                q->size = 1;
                ret = 0;
        } else {
                struct queue_char_item* new_item =
                        hkmalloc(sizeof(struct queue_char_item));
                if ((int)new_item == NOMEM) {
                        ret = NOMEM;
                        goto error;
                }
                new_item->last_item = NULL;
                new_item->data = data;
                q->end_item->last_item = new_item;
                q->end_item = new_item;
                ++q->size;
        }

        return 0;
error:
        early_printk("stack: error: out of memory\n");
        return ret;
}

void queue_char_pop(struct queue_char* q)
{
        if (q->first_item == NULL) {
                goto ret;
        } else {
                struct queue_char_item* swap =
                        q->first_item->last_item;
                hkfree(q->first_item);
                q->first_item = swap;
                --q->size;
        }

ret:
        return;
}

char queue_char_show(struct queue_char* q)
{
        char ret;

        if (q->first_item == NULL) {
                ret = NOINI;
                goto error;
        } else {
                ret = q->first_item->data;
        }

        return ret;

error:
        early_printk("stack: error: stack is not initialized\n");
        return ret;
}

void queue_char_clear(struct queue_char* q)
{
        size_t size = q->size;
        for (size_t i = 0; i < size; ++i) {
                queue_char_pop(q);
        }
}
