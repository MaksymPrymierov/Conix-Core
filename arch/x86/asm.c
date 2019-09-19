#include <asm.h>

void outb(u16 port, u8 val)
{
        __asm__ volatile("outb %0, %1"
                      : : "a"(val), "Nd"(port));
}

u8 inb(u16 port)
{
        u8 ret;
        __asm__ volatile ("inb %1, %0"
                      : "=a"(ret)
                      : "Nd"(port));
        return ret;
}
