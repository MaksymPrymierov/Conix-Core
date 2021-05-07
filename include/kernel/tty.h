// SPDX-License-Identifier: GPL-3.0-only
/* -*- ConixCore -*- ------------------------------------------------------- *
 *
 *   Copyright (C) 2019-2021 Maksym Prymierov
 *
 * ------------------------------------------------------------------------- */

#pragma once

#include <keyboard.h>
#include <kernel/types.h>
#include <kernel/string.h>

namespace conix {
namespace kernel {
namespace io {

class tty
{
private:
        class stream
        {
        public:
                stream(tty *t);

                stream operator<<(const char* string);
                stream operator<<(const std::string& str);
                stream operator<<(int number);
                stream operator>>(char* string);
                stream operator>>(std::string& str);

        private:
                tty *tt;
        };

public:
        enum class foreground_color : u16
        {
                black         = 0x0000,
                blue          = 0x0100,
                green         = 0x0200,
                cyan          = 0x0300,
                red           = 0x0400,
                magenta       = 0x0500,
                brown         = 0x0600,
                light_gray    = 0x0700,
                dark_gray     = 0x0800,
                light_blue    = 0x0900,
                light_green   = 0x0A00,
                light_cyan    = 0x0B00,
                light_red     = 0x0C00,
                light_magenta = 0x0D00,
                yellow        = 0x0E00,
                white         = 0x0F00
        };

        enum class background_color : u16
        {
                black         = 0x0000,
                blue          = 0x1000,
                green         = 0x2000,
                cyan          = 0x3000,
                red           = 0x4000,
                magenta       = 0x5000,
                brown         = 0x6000,
                light_gray    = 0x7000,
                dark_gray     = 0x8000,
                light_blue    = 0x9000,
                light_green   = 0xA000,
                light_cyan    = 0xB000,
                light_red     = 0xC000,
                light_magenta = 0xD000,
                white         = 0xF000
        };

        static const constexpr u16 height = 25;
        static const constexpr u16 width = 80;
        static const constexpr u16 size_of_text = height * width;
        static const constexpr u16 capacity = 10000;
        static const constexpr u16 last_line = 1920;
        static const constexpr u32 memory_address = 0xb8000;

        tty();
        ~tty();
        void clear();
        
        stream operator<<(const char* string);
        stream operator<<(const std::string& str);
        stream operator<<(int number);
        stream operator>>(char* string);
        stream operator>>(std::string& str);
        void get_line(char* string, size_t s);
        void get_line(std::string& str);
        void set_foreground(foreground_color color);
        void set_background(background_color color);

private:
        u16 *memory;
        char tmp_number[24];
        arch::x86::keyboard k;
        foreground_color f_color = foreground_color::light_gray;
        background_color b_color = background_color::black;
        u16 color = static_cast<u16>(f_color) +
                    static_cast<u16>(b_color);

        void update();
        void scroll_down();
        void print_string(const char *string, size_t s);
        void print_string(const char *string);
        void print_string(const std::string& str);
        void input_string(char* string, size_t s);
        void input_string(std::string& str);
        void print_number(int number);
        void move_cursor(u16 pos);
        void enable_cursor();
        void handle_screen_overflow();
        void update_color();
};

}; // io
}; // kernel
}; // conix
