#include "../../headers/stdlib/stdlib.h"
#include "../../headers/sys/sys.h"

void gdtSetGate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran)
{
        gdt[num].baseLow    = (base & 0xFFFF);
        gdt[num].baseMiddle = (base >> 16) & 0xFF;
        gdt[num].baseHigh   = (base >> 24) & 0xFF;

        gdt[num].limitLow    = (limit & 0xFFFF);
        gdt[num].granularity = ((limit >> 16) & 0x0F);

        gdt[num].granularity |= (gran & 0xF0);
        gdt[num].access = access;
}

void gdtInit()
{
        gp.limit = (sizeof(struct gdtEntry) * 5) - 1;
        gp.base  = (unsigned long)&gdt;

        gdtSetGate(0, 0, 0, 0, 0);
        gdtSetGate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
        gdtSetGate(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
        gdtSetGate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
        gdtSetGate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
            
        gdtFlush();
}
