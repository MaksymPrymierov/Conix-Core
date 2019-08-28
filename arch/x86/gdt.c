#include <gdt.h>

static struct gdt_entry gdt[5];
struct gdt_ptr gp;

void create_descriptor(int num, u32 base, u32 limit, u8 access, u8 gran)
{
        gdt[num].base_low    = (base & 0xFFFF);
        gdt[num].base_middle = (base >> 16) & 0xFF;
        gdt[num].base_high   = (base >> 24) & 0xFF;

        gdt[num].limit_low    = (limit & 0xFFFF);
        gdt[num].granularity = ((limit >> 16) & 0x0F);

        gdt[num].granularity |= (gran & 0xF0);
        gdt[num].access = access;
}

void gdt_init(void)
{
        gp.limit = (sizeof(struct gdt_entry) * 5) - 1;
        gp.base  = (u32)&gdt;

        create_descriptor(0, 0, 0, 0, 0);
        create_descriptor(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);
        create_descriptor(2, 0, 0xFFFFFFFF, 0x92, 0xCF);
        create_descriptor(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);
        create_descriptor(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);
            
        gdt_flush();
}
