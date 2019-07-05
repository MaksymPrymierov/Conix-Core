#include <arch/i686/text_graphic.h>

static u16 video_mem[25 * 80];

void main(void)
{
	ssize_t status;

	status = text_graphic_init(video_mem);
	if (status) {
		goto end;
	}
	printk("kernel: kernel starting...\n");

end:
        return;
}
