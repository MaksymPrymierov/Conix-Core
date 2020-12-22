#pragma once

#include <kernel/types.h>
#include <kernel/queue.h>

namespace conix {
namespace kernel {
namespace arch {
namespace x86 {

class keyboard
{
private:
        bool valid_keyboard;
        std::queue<size_t> buffer;

public:
		static constexpr const char pressed_key_lowcase[] = {
			0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
			0, 0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',
			0, 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
			'`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
			0, 0, ' '
		};

        keyboard();
        ~keyboard();

        void enable_int();
        void disable_int();
        bool empty();
        size_t get_key_number();
        char get_key();
};

}; // x86
}; // arch
}; // kernel
}; // conix
