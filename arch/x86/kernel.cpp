#include <tty.h>
#include <gdt.h>
#include <idt.h>
#include <heap.h>
/*#include <keyboard.h>
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
        
        idt_install();
        log << "idt: IDT tables has been installed.\n";

        isrs_install();
        log << "idt: ISR tables has been installed.\n";

        irq_install();
        log << "idt: IRQ tables has been installed.\n";

        heap_init(heap_top, heap_bottom);
        log << "memory: Heap has been initialized.\n";

     /*   
        status = default_keyboard_init_driver();
        if (!status) {
                early_printk("keyboard: install default keyboard\n");
        }

        pit_install();

        init_shell(); */

        return 0;
}
