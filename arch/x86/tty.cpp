#include <tty.h>
#include <kernel/kernel_lib.h>

static size_t cursor = 0;
static size_t offset = 0;
static u16 buffer[10000];

tty::tty()
{
        memory = reinterpret_cast<u16*>(memory_address);
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
        for (size_t i = offset; i < capacity; ++i) {
                memory[i - offset] = buffer[i];
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
                case '\t':
                        print_string("    ");
                        break;
                default:
                        if (cursor >= capacity) {
                                scroll_down();
                        }
                        if (cursor >= size_of_text) {
                                offset = ((cursor - size_of_text) / width + 1) * width;
                        }
                        buffer[cursor] = color + string[i];
                        ++cursor;
                }
        }
        update();
}

void tty::print_number(int number)
{
        num_to_str<int>(number, tmp_number, 10);
        print_string(tmp_number);
}

tty::stream tty::operator<<(const char* string)
{
        print_string(string);
        return stream(this);
}

tty::stream tty::operator<<(int number)
{
        print_number(number);
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

tty::stream tty::stream::operator<<(int number)
{
        tt->print_number(number);
        return stream(tt);
}
