#ifndef ASM_H
#define ASM_H

#include <kernel/types.h>

static void outb(u16 port, u8 val)
{
        __asm__ volatile("outb %0, %1" 
                      : : "a"(val), "Nd"(port));
}

#endif
