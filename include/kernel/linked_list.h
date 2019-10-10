#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list_node
{
        struct linked_list_node *next;
        struct linked_list_node *last;
        void *data;
};

struct linked_list
{
        struct linked_list_node *head;
        struct linked_list_node *tail;
        size_t size;
        int (*init)(void);
        int (*append)();
        int (*add)(struct linked_list*, void*);
        int (*remove)(struct linked_list*, void*);
        int (*clear)(struct linked_list*);
        int (*prepend)(struct linked_list*);
        
};

#endif /* LINKED_LIST_H */
