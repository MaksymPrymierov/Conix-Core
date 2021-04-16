// SPDX-License-Identifier: GPL-3.0-only
/* -*- ConixCore -*- ------------------------------------------------------- *
 *
 *   Copyright (C) 2019-2021 Maksym Prymierov
 *
 * ------------------------------------------------------------------------- */

#include <kernel/tty.h>

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
        k.enable_int();
}

tty::~tty()
{
        k.disable_int();
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
                memory[i - offset] = color + buffer[i];
        }
        move_cursor(static_cast<u16>(cursor - offset));
}

void tty::scroll_down()
{
        memmove(buffer, buffer + width, (capacity - width) * 2);
        memset((buffer + capacity) - width, 0, width * 2);
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

void tty::print_string(const char *string, size_t s)
{
        for (size_t i = 0; i < s; ++i) {
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

void tty::print_string(const char* string)
{
        print_string(string, strlen(string));
}

void tty::print_string(const std::string& str)
{
        print_string(str.c_str(), str.size());
}

void tty::print_number(int number)
{
        num_to_str<int>(number, tmp_number, 10);
        print_string(tmp_number);
        memset(tmp_number, 0, sizeof(tmp_number));
}

void tty::input_string(char* string, size_t s)
{
        bool can_write = true;
        size_t i = 0;
        char buffer[2] = { '\0' };

        while (1) {
                buffer[0] = k.get_key();

                if (buffer[0] == '\0') {
                        continue;
                } else if ((buffer[0] == ' ' || i == s - 1) && can_write) {
                        string[i] = '\0';
                        can_write = false;
                } else if (buffer[0] == '\n') {
                        if (can_write) {
                                string[i] = '\0';
                        }
                        break;
                }

                if (can_write) {
                        string[i] = buffer[0];
                        ++i;
                }

                print_string(buffer);
        }

        print_string("\n");
}

void tty::input_string(std::string& str)
{
        bool can_write = true;
        char buffer[2] = { '\0' };
        str.clear();

        while (true) {
                buffer[0] = k.get_key();

                if (buffer[0] == '\0') {
                        continue;
                } else if (buffer[0] == ' ' && can_write) {
                        str.append('\0');
                        can_write = false;
                } else if (buffer[0] == '\n') {
                        if (can_write) {
                                str.append('\0');
                        }
                        break;
                }

                if (can_write) {
                        str.append(buffer[0]);
                }
                print_string(buffer);
        }
        print_string("\n");
}

void tty::get_line(char* string, size_t s)
{
        bool can_write = true;
        size_t i = 0;
        char buffer[2] = {'\0'};
        k.enable_int();

        while (1) {
                buffer[0] = k.get_key();

                if (buffer[0] == '\0') {
                        continue;
                } else if (i == s - 1 && can_write) {
                        string[i] = '\0';
                        can_write = false;
                } else if (buffer[0] == '\n') {
                        if (can_write) {
                                string[i] = '\0';
                        }
                        break;
                }

                if (can_write) {
                        string[i] = buffer[0];
                        ++i;
                }

                print_string(buffer);
        }

        print_string("\n");
        k.disable_int();
}

void tty::get_line(std::string& str)
{
        char buffer[2] = { '\0' };
        k.enable_int();
        str.clear();

        while (true) {
                buffer[0] = k.get_key();

                if (buffer[0] == '\0') {
                        continue;
                } else if (buffer[0] == '\n') {
                        str.append('\0');
                        break;
                }

                str.append(buffer[0]);
                print_string(buffer);
        }

        print_string("\n");
        k.disable_int();
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

tty::stream tty::operator>>(char* string)
{
        input_string(string, strlen(string));
        return stream(this);
}

tty::stream tty::operator>>(std::string& str)
{
        input_string(str);
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

tty::stream tty::stream::operator>>(char* string)
{
        tt->input_string(string, strlen(string));
        return stream(tt);
}

tty::stream tty::stream::operator>>(std::string& str)
{
        tt->input_string(str);
        return stream(tt);
}

}; // io
}; // kernel
}; // conix
