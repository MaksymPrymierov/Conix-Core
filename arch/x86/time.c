#include <time.h>
#include <asm.h>
#include <tty.h>
#include <idt.h>

static void pit_handler(struct regs *r)
{
//        early_printk("+");
}

void pit_install(void)
{
        irq_install_handler(0, pit_handler);
}
