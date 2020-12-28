#pragma once

#include <kernel/types.h>
#include <kernel/queue.h>

#define CTRL_PRESS              29
#define LSHIFT_PRESS            42
#define RSHIFT_PRESS            54
#define ALT_PRESS               56
#define CAPS_LOCK_PRESS         58

#define CTRL_RELEASE            157
#define LSHIFT_RELEASE          170
#define RSHIFT_RELEASE          182
#define ALT_RELEASE             184
#define CAPS_LOCK_RELEASE       186

#define RIGHT_CONTROL_KEYS      224

namespace conix {
namespace kernel {
namespace arch {
namespace x86 {

class keyboard
{
private:
        bool ctrl_pressed = false;
        bool shift_pressed = false;
        bool alt_pressed = false;
        bool caps_lock_mode = false;
        bool valid_keyboard;
        std::queue<size_t> buffer;

public:
                static constexpr const char pressed_key_lowcase[] = {
                        0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
                        '\b', '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',
                        0, 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
                        '`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
                        0, 0, ' '
                };

                static constexpr const char pressed_key_uppercase[] = {
                        0, 0, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+',
                        '\b', '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}',
                        0, 0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"',
                        '~', 0, '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0,
                        0, 0, ' '
                };

        keyboard();
        ~keyboard();

        void enable_int();
        void disable_int();
        bool empty();
        size_t get_key_number();
        char get_key(size_t code);
        char get_key();
        void push_key(size_t code);
};

}; // x86
}; // arch
}; // kernel
}; // conix
