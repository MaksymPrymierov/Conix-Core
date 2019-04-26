#include "../../headers/stdlib/stdlib.h"
#include "../../headers/sys/sys.h"

void idtSetGate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
        idt[num].baseLow  = (base & 0xFFFF);
        idt[num].baseHigh = (base >> 16) & 0xFFFF;

        idt[num].sel     = sel;
        idt[num].always0 = 0;
        idt[num].flags   = flags;
}

void idtInstall()
{
        idtp.limit = (sizeof(struct idtEntry) * 256) - 1;
        idtp.base  = (unsigned int)&idt;

        memset(&idt, 0, sizeof(struct idtEntry) * 256);

        idtLoad();
}
