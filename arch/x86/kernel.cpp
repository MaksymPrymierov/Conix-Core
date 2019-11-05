#include <tty.h>
#include <gdt.h>
/*
#include <idt.h>
#include <keyboard.h>
#include <heap.h>
#include <early_shell.h>
#include <time.h>

#include <kernel/queue.h>
#include <kernel/string.h>
#include <kernel/test.h> */

/*static u16 video_mem[25 * 80];
static struct early_shell_data early_shell_data;

static void init_shell(void)
{
        early_shell_data.user_name = "conix-core";
        early_shell_data.printf = early_printk;

        early_shell_init_session(&early_shell_data);
} */

int main(void* heap_top, void* heap_bottom)
{
        tty log;
        log << "tty: Text graphics has been initialized.\n";

        gdt_init();
        log << "gdt: GDT tables has been initialized.\n";
/*        
        idt_install();
        early_printk("kernel: init IDT\n");

        isrs_install();
        early_printk("kernel: isrs installed\n");

        irq_install();
        early_printk("kernel: irq installed\n");

        heap_init(heap_top, heap_bottom);
        early_printk("kernel: heap installed\n");
        
        status = default_keyboard_init_driver();
        if (!status) {
                early_printk("keyboard: install default keyboard\n");
        }

        pit_install();

        init_shell(); */

        return 0;
}
