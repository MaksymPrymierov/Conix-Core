#include <tty.h>
#include <gdt.h>
#include <idt.h>
#include <keyboard.h>

static u16 video_mem[25 * 80];

int main(void)
{
	ssize_t status;

	status = text_graphic_init(video_mem);
	if (status) {
		goto end;
	}
	early_printk("kernel: kernel starting...\n");
        
        gdt_init();
        early_printk("kernel: init GDT\n");
        
        idt_load();
        early_printk("kernel: init IDT\n");

        isrs_install();
        early_printk("kernel: isrs installed\n");

        irq_install();
        early_printk("kernel: irq installed\n");

        status = default_keyboard_init_driver();
        if (status) {
                early_printk("keyboard: install default keyboard\n");
        }

end:
        return 0;
}
