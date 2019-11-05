#pragma once

#include <kernel/types.h>

class tty
{
public:
        static const constexpr u16 height = 25;
        static const constexpr u16 width = 80;
        static const constexpr u16 capacity = 2000;
        static const constexpr u16 last_line = 1920;
        static const constexpr u16 color = 0x0700;
        static const constexpr u32 memory_address = 0xb8000;

        tty();
        void clear();

private:
        u16 *memory; 
        u16 buffer[capacity];

        void update();
        void print_string(const char *string);
};
