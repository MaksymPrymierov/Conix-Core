#ifndef ASM_H
#define ASM_H

#include <kernel/types.h>

extern void outb(u16 port, u8 val);
extern u8 inb(u16 port);

#endif
