#include <tty.h>
#include <gdt.h>

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
end:
        return 0;
}
