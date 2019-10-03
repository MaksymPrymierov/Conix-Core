#include <kernel/test.h>

#include <kernel/kernel_lib.h>
#include <kernel/queue.h>

_Bool ASSERT_OK(int n)
{
        if (!n) {
                early_printk("ERROR: file %s, line %d, function %s\n",
                        __FILE__, __LINE__, __FUNCTION__);
                return 0;
        } else {
                early_printk("OK: file %s, line %d, function %s\n",
                         __FILE__, __LINE__, __FUNCTION__);
                return 1;
        }
}

void run_string_test(void)
{
        ASSERT_EQ(0, strlen(""));
        ASSERT_EQ(1, strlen(" "));
        ASSERT_EQ(4, strlen("test"));
        ASSERT_EQ(4, strlen("test\0"));
        ASSERT_EQ(5, strlen("test\n"));
}

void run_queue_test(void)
{
        /* Initializing tests */
        struct queue_char queue;
        queue_char_init(&queue);
        ASSERT_EQ(0, queue.size);
        ASSERT_EQ(NULL, queue.first_item);
        ASSERT_EQ(NULL, queue.end_item);
        ASSERT_EQ(NOINI, queue_char_show(&queue));
        queue_char_pop(&queue);
        ASSERT_EQ(0, queue.size);

        /* Item add\remove tests */
        ASSERT_EQ(0, queue_char_push(&queue, 't'));
        ASSERT_EQ('t', queue_char_show(&queue));
        ASSERT_EQ(1, queue.size);
        ASSERT_EQ(0, queue_char_push(&queue, 'e'));
        ASSERT_EQ('e', queue_char_show(&queue));
        ASSERT_EQ(2, queue.size);
        ASSERT_EQ(0, queue_char_push(&queue, 's'));
        queue_char_pop(&queue);
        ASSERT_EQ('e', queue_char_show(&queue));
        ASSERT_EQ(2, queue.size);

        /* Release queue test */
        queue_char_clear(&queue);
        ASSERT_EQ(0, queue.size);
        ASSERT_EQ(NULL, queue.first_item);
        ASSERT_EQ(NULL, queue.end_item);
        ASSERT_EQ(NOINI, queue_char_show(&queue));
        queue_char_pop(&queue);
        ASSERT_EQ(0, queue.size);
}
