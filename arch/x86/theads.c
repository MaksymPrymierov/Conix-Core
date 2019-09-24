#include <theads.h>
#include <tty.h>
#include <heap.h>

extern int k;

static void task1(void)
{
        early_printk("task1 ");
}

static void task2(void)
{
        early_printk("task2 ");
        while(1);
}

static void task3(void)
{
        early_printk("task3 ");
        while(1);
}

static void *task[] = {task1, task2, task3};
static void *stack[3];

void switch_task(void)
{
        while(1);
}

void thead_init(int i)
{
        stack[i] = hkmalloc(0x1024) + 0x1024;
        if (i == 0) {
                execute_task(task[i], stack[i]);
        }
}
