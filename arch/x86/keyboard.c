#include <keyboard.h>
#include <asm.h>
#include <idt.h>
#include <tty.h>

#include <kernel/kernel_lib.h>

int init_keyboard(struct keyboard_t* data)
{
        int ret = 0;

        if (NULL != data->init_keyboard) {
                data->init_keyboard();
        }

        if (NULL == data->input_handler) {
                early_printk("%d", data->input_handler);
                ret = -INVAL;
                goto err;
        }

        irq_install_handler(1, data->input_handler);

        return 0;

err:
        return ret;
}

/* Default x86 keyboard driver */

static struct queue_char keyboard_queue;

static void default_keyboard_handler(struct regs* regs)
{
        queue_char_push(&keyboard_queue, inb(DEFAULT_KEYBOARD_WRITE_PORT));
}

static struct keyboard_t default_keyboard =
{
        .driver_name = "Conix-Core keyboard driver",
        .description = "Default Conix-Core keyboard driver for x86 systems",
        .author = "Maksym Prymierov",
        .device_name = "Default Keyboard",
        .license = "GPL3.0v",
        .keyboard_queue = &keyboard_queue,
        .input_handler = default_keyboard_handler,
};

int default_keyboard_init_driver(void)
{
        int ret = init_keyboard(&default_keyboard);
        return ret;
}

u8 default_keyboard_get_scan_code(void)
{
        u8 ret = 0;
        if (!keyboard_queue.size) {
                ret = queue_char_show(&keyboard_queue);
                queue_char_pop(&keyboard_queue);
        }
        return ret;
}
