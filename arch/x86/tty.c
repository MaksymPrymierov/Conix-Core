#include <tty.h>
#include <bios.h>

static void bios_putchar(int ch)
{
        struct bios_regs ireg;
        init_regs_bios(&ireg);
        ireg.bx = 0x0007;
        ireg.cx = 0x0001;
        ireg.ah = 0x0e;
        ireg.al = ch;
        int_call(0x10, &ireg, NULL);
}

void puts(const char *str)
{
        while (*str) {
                bios_putchar(*str++);
        }
}
