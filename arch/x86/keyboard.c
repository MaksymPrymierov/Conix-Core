#include <keyboard.h>
#include <asm.h>
#include <idt.h>
#include <tty.h>
#include <kernel/types.h>
#include <kernel/kernel_lib.h>

static struct keyboard_t keyboard_t;

int init_keyboard(struct keyboard_t data)
{
        int ret = 0;

        if (NULL != keyboard_t.init_keyboard) {
                keyboard_t.init_keyboard();
        }

        if (NULL == keyboard_t.input_handler) {
                ret = -INVAL;
                goto err;
        }

        keyboard_t = data;
        irq_install_handler(1, keyboard_t.input_handler);

        return 0;

err:
        return ret;
}

/* Default x86 keyboard driver */

static char buffer[2000];
static size_t pos = 0;

static void default_keyboard_handler(struct regs* regs)
{
        buffer[pos] = inb(DEFAULT_KEYBOARD_WRITE_PORT);
        if (pos >= 2000) {
                pos = 1999;
        }
        ++pos;
}

static struct keyboard_t default_keyboard =
{
        .driver_name = "Conix-Core keyboard driver",
        .description = "Default Conix-Core keyboard driver for x86 systems",
        .author = "Maksym Prymierov",
        .device_name = "Default Keyboard",
        .license = "GPL3.0v",
        .buffer = buffer,
        .input_handler = default_keyboard_handler,
};

int default_keyboard_init_driver(void)
{
        memset(buffer, 0, strlen(buffer));
        int ret = init_keyboard(default_keyboard);
        return ret;
}
