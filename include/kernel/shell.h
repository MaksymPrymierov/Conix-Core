#pragma once

#include <kernel/types.h>
#include <kernel/string.h>
#include <tty.h>

namespace conix {
namespace kernel {

class shell
{
public:
        enum class keyboard : u8
        {
                esp = 0x01,
                digit_start = 0x02,
                digit_end = 0x0D,
                backspace = 0x0E,
                tab = 0x0F,
                letter_start_part1 = 0x10,
                letter_end_part1 = 0x1B,
                left_enter = 0x1C,
                left_ctrl = 0x1D,
                letter_start_part2 = 0x1E,
                letter_end_part2 = 0x29,
                left_shift = 0x2A,
                letter_start_part3 = 0x2B,
                letter_end_part3 = 0x35,
                right_shift = 0x36,
                left_alt = 0x38,
                space = 0x39,
                caps_lock = 0x3A,
                start_function_key = 0x3B,
                end_function_key = 0x44,
                scroll_lock = 0x46,
                alt_plus_ptrscr = 0x54,
                F11 = 0x57,
                F12 = 0x58,
                release_key = 0x80
        };

        constexpr static const char digits_lowcase[] = "1234567890-=";
        constexpr static const char letters_lowcase_part1[] = "qwertyuiop[]";
        constexpr static const char letters_lowcase_part2[] = "asdfghjkl;'`";
        constexpr static const char letters_lowcase_part3[] = "\\zxcvbnm,./";

        constexpr static const char digits_uppercase[] = "!@#$%^&*()_+";
        constexpr static const char letters_uppercase_part1[] = "QWERTYUIOP{}";
        constexpr static const char letters_uppercase_part2[] = "ASDFGHJKL:\"~";
        constexpr static const char letters_uppercase_part3[] = "|ZXCVBNM<>?";

        shell();

        void exec()
        {
                output << "> ";
        }

private:
        io::tty output;
        std::string buffer;
};

};
};
