#include <tty.h>
#include <gdt.h>
#include <idt.h>
#include <keyboard.h>
#include <heap.h>
#include <kernel/queue.h>

#include <early_shell.h>

static u16 video_mem[25 * 80];
static struct early_shell_data early_shell_data;

static void init_shell(void)
{
        early_shell_data.user_name = "conix-core";
        early_shell_data.printf = early_printk;

        early_shell_init_session(&early_shell_data);
}

int main(void* heap_top, void* heap_bottom)
{
	ssize_t status;

	status = text_graphic_init(video_mem);
	if (status) {
		goto end;
	}
	early_printk("kernel: kernel starting...\n");
        
        gdt_init();
        early_printk("kernel: init GDT\n");
        
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

        init_shell();

        while (1);

end:
        return 0;
}
