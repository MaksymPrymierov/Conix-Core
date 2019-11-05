#include <tty.h>
#include <kernel/kernel_lib.h>

static u16 buffer[2000];
static size_t cursor;

tty::tty()
{
        memory = reinterpret_cast<u16*>(memory_address);
        clear();
}

void tty::clear()
{
	for (size_t i = 0; i < capacity; ++i) {
                buffer[i] = 0;
	}

        update();
}

void tty::update()
{
        for (size_t i = 0; i < capacity; ++i) {
                memory[i] = buffer[i];
	}
}

void tty::scroll_down()
{
        memmove(buffer, buffer + width, (capacity - width) * 2);
        memset((buffer + capacity) - width, 0, width * 2);
        cursor = (cursor / width - 1) * width; 
}

void tty::print_string(const char *string)
{
        for (size_t i = 0; i < strlen(string); ++i) {
                switch (string[i]) {
                case '\n':
			cursor = (cursor / width + 1) * width;
                        break;
		case '\b':
			--cursor;
			buffer[cursor] = ' ';
			break;
                default:
                        if (cursor >= capacity) {
                                scroll_down();
                        }
                        buffer[cursor] = color + string[i];
                        ++cursor;
                }
        }
        update();
}

tty::stream tty::operator<<(const char* string)
{
        print_string(string);
        return stream(this);
}

tty::stream::stream(tty *t) :
        tt(t)
{  }

tty::stream tty::stream::operator<<(const char* string)
{
        tt->print_string(string);
        return stream(tt);
}
