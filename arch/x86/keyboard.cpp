#include <keyboard.h>

#include <asm.h>
#include <idt.h>
#include <registers.h>
#include <kernel/queue.h>
#include <kernel/types.h>

static bool keyboard_is_running = false;
static conix::kernel::std::queue<size_t> *qb = nullptr;

extern "C" void keyboard_int_handler(struct regs *r)
{
        if (qb != nullptr) {
                qb->push(inb(KEYBOARD_DATA_REGISTER));
        }
}

namespace conix {
namespace kernel {
namespace arch {
namespace x86 {

keyboard::keyboard()
{
        if (keyboard_is_running) {
                valid_keyboard = false;
                return;
        }

        keyboard_is_running = true;
        valid_keyboard = true;
        qb = &buffer;
}

keyboard::~keyboard()
{
        if (valid_keyboard) {
                keyboard_is_running = false;
        }
        disable_int();
        qb = nullptr;
}

void keyboard::enable_int()
{
        irq_install_handler(KEYBOARD_IRQ_NUMBER, keyboard_int_handler);
}

void keyboard::disable_int()
{
        irq_unintall_handler(KEYBOARD_IRQ_NUMBER);
}

bool keyboard::empty()
{
        return buffer.empty();
}

size_t keyboard::get_key_number()
{
        size_t key = buffer.front();
        buffer.pop();

        return key;
}

}; // x86
}; // arch
}; // kernel
}; // conix
