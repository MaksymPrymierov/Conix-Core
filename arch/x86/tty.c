#include <tty.h>
#include <stdarg.h>
#include <kernel/kernel_lib.h>

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
	early_printk("kernel: text graphic is initialized\n");

	return 0;

err:
	return ret;
}

static void puts(const char* message)
{
        video_buffer[cursor] = TEXT_GRAPHIC_COLOR + 'A';
        for (size_t i = 0; i < strlen(message); ++i) {
                switch (message[i]) {
                case '\n':
                        cursor = (cursor / TEXT_GRAPHIC_WIDTH + 1) * TEXT_GRAPHIC_WIDTH;
                        break;
                default:
                        video_buffer[cursor] = TEXT_GRAPHIC_COLOR + message[i];
                        ++cursor;
                }
        }
        update_screen();
}

static int vfprintf(char* string, char const* fmt, va_list arg)
{
        char c;
        char* tmp_string;
        char tmp_number[65];
        int length = 0;

        while ((c = *fmt++)) {
                if ('%' == c) {
                        switch (c = *fmt++) {
                        case '%':
                                string[length] = '%';
                                ++length;
                                break;
                        case 'c':
                                string[length] = va_arg(arg, int);
                                ++length;
                                break;
                        case 's':
                                tmp_string = va_arg(arg, char*);
                                memcpy(string + length, tmp_string,
                                       strlen(tmp_string));
                                length += strlen(tmp_string);
                                break;
                        case 'd':
                        case 'u':
                        case 'x':
                        case 'o':
                                if (c == 'u') {
                                        unum_to_string(va_arg(arg, int), 
                                                       10, tmp_number);
                                } else if (c == 'd') {
                                        snum_to_string(va_arg(arg, int),
                                                       10, tmp_number);
                                } else if (c == 'x') {
                                        snum_to_string(va_arg(arg, int),
                                                       16, tmp_number);
                                } else if (c == 'o') {
                                        snum_to_string(va_arg(arg, int),
                                                       8, tmp_number);
                                }
                                memcpy(string + length, tmp_number,
                                       strlen(tmp_number));
                                length += strlen(tmp_number);
                                break;
                        }
                } else {
                        string[length] = c;
                        ++length;
                }
        }

	return length;
}

int early_printk(char const *fmt, ...) {
        va_list arg;
        int length;
        char message[1024];
        memset(message, 0, 1024);

        va_start(arg, fmt);
        length = vfprintf(message, fmt, arg);
        va_end(arg);

        puts(message);
        return length;
}
