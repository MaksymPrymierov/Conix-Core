#ifndef QUEUE
#define QUEUE

#include <kernel/types.h>

struct queue_char_item
{
        struct queue_char_item* last_item;
        char data;
};

struct queue_char
{
        struct queue_char_item* first_item;
        struct queue_char_item* end_item;
        size_t size;
};

extern void queue_char_init(struct queue_char* q);
extern int queue_char_push(struct queue_char* q, char data);
extern void queue_char_pop(struct queue_char* q);
extern char queue_char_show(struct queue_char* q);
extern void queue_char_clear(struct queue_char* q);

#endif
