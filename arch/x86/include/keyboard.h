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
        keyboard();
        ~keyboard();

        void enable_int();
        void disable_int();
        bool empty();
        size_t get_key_number();
};

}; // x86
}; // arch
}; // kernel
}; // conix
