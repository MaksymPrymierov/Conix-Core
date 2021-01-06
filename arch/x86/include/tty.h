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
        static const constexpr u16 height = 25;
        static const constexpr u16 width = 80;
        static const constexpr u16 size_of_text = height * width;
        static const constexpr u16 capacity = 10000;
        static const constexpr u16 last_line = 1920;
        static const constexpr u16 color = 0x0700;
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

private:
        u16 *memory;
        char tmp_number[24];
        arch::x86::keyboard k;

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
};

}; // io
}; // kernel
}; // conix
