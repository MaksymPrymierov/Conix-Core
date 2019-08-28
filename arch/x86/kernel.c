#include <tty.h>

static u16 video_mem[25 * 80];

int main(void)
{
	ssize_t status;

	status = text_graphic_init(video_mem);
	if (status) {
		goto end;
	}
	printk("kernel: kernel starting...\n");

end:
        return 0;
}
