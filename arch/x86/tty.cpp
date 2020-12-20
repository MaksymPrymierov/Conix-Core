#include <tty.h>
#include <asm.h>
#include <registers.h>
#include <kernel/kernel_lib.h>

namespace conix {
namespace kernel {
namespace io {

static size_t cursor = 0;
static size_t offset = 0;
static u16 buffer[10000];

tty::tty()
{
        memory = reinterpret_cast<u16*>(memory_address);
        enable_cursor();
}

void tty::clear()
{
        for (size_t i = 0; i < capacity; ++i) {
                buffer[i] = color + ' ';
        }

        update();
}

void tty::update()
{
        for (size_t i = offset; i < capacity; ++i) {
                memory[i - offset] = color + buffer[i];
        }
        move_cursor(static_cast<u16>(cursor - offset));
}

void tty::scroll_down()
{
        memmove(buffer, buffer + width, (capacity - width) * 2);
        memset((buffer + capacity) - width, color + ' ', width * 2);
        cursor = (cursor / width - 1) * width;

}

void tty::handle_screen_overflow()
{
        if (cursor >= capacity) {
                scroll_down();
        }
        if (cursor >= size_of_text) {
                offset = ((cursor - size_of_text) / width + 1) * width;
        }
}

void tty::print_string(const char *string)
{
        for (size_t i = 0; i < strlen(string); ++i) {
                switch (string[i]) {
                case '\n':
                        cursor = (cursor / width + 1) * width;
                        handle_screen_overflow();
                        break;
                case '\b':
                        --cursor;
                        buffer[cursor] = ' ';
                        break;
                case '\t':
                        print_string("    ");
                        break;
                default:
                        handle_screen_overflow();
                        buffer[cursor] = string[i];
                        ++cursor;
                }
        }
        update();
}

void tty::print_string(const std::string& str)
{
        print_string(str.c_str());
}

void tty::print_number(int number)
{
        num_to_str<int>(number, tmp_number, 10);
        print_string(tmp_number);
}

void tty::move_cursor(u16 pos)
{
        outb(CRT_INDEX_REGISTER, CRT_CURSOR_LOCATION_HIGH);
        outb(CRT_DATA_REGISTER, static_cast<u8>((pos >> 8) & 0xFF));
        outb(CRT_INDEX_REGISTER, CRT_CURSOR_LOCATION_LOW);
        outb(CRT_DATA_REGISTER, static_cast<u8>(pos & 0xFF));
}

void tty::enable_cursor()
{
        outb(CRT_INDEX_REGISTER, CRT_CURSOR_START);
        outb(CRT_DATA_REGISTER, static_cast<u8>((0x1 >> 5) | 0x0));
        outb(CRT_INDEX_REGISTER, CRT_CURSOR_END);
        outb(CRT_DATA_REGISTER, static_cast<u8>(0xF));
}

tty::stream tty::operator<<(const char* string)
{
        print_string(string);
        return stream(this);
}

tty::stream tty::operator<<(const std::string& str)
{
        print_string(str);
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

tty::stream tty::stream::operator<<(const std::string& str)
{
        tt->print_string(str);
        return stream(tt);
}

tty::stream tty::stream::operator<<(int number)
{
        tt->print_number(number);
        return stream(tt);
}

}; // io
}; // kernel
}; // conix
