#include <arch/i686/text_graphic.h>
#include <stdarg.h>

static u16 *video_mem = (u16*)(u8*)TEXT_GRAPHIC_MEMORY;
static size_t cursor = 0;
static u16 *video_buffer;

static void update_screen();
static void clear_screen();

static void update_screen()
{
	for (size_t i = 0; i < TEXT_GRAPHIC_CAPACITY; ++i) {
		video_mem[i] = video_buffer[i];
	}
}

static void clear_screen()
{
	for (size_t i = 0; i < TEXT_GRAPHIC_CAPACITY; ++i) {
		video_buffer[i] = 0;
	}

	update_screen();
}

int text_graphic_init(u16 *vid_buf)
{
	ssize_t ret;

	if (NULL == vid_buf) {
		ret = NOMEM;
		goto err;
	}

	video_buffer = vid_buf;

	clear_screen();
	printk("kernel: text graphic is initialized\n");

	return 0;

err:
	return ret;
}

int printk(const char* form, ...)
{
	va_list factor;
	va_start(factor, form);

	for (size_t i = 0; form[i]; ++i) {
		if (cursor == TEXT_GRAPHIC_CAPACITY) {
			cursor = TEXT_GRAPHIC_LAST_LINE;
		}

		if (form[i] == '\n') {
        		cursor = (cursor / TEXT_GRAPHIC_WIDTH + 1) * TEXT_GRAPHIC_WIDTH;
        		continue;
		}

		if (form[i] != '%') {
			video_buffer[cursor] = TEXT_GRAPHIC_COLOR + form[i];
			++cursor;
			continue;
		}
	}

	update_screen();
	va_end(factor);

	return 0;
}