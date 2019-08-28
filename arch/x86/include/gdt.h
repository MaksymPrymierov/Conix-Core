#ifndef GDT_H
#define GDT_H

#include <kernel/types.h>

struct gdt_entry {
        u16 limit_low;
        u16 base_low;
        u8 base_middle;
        u8 access;
        u8 granularity;
        u8 base_high;
} __attribute__ ((packed));

struct gdt_ptr {
        u16 limit;
        u32 base;
} __attribute__ ((packed));

extern void gdt_flush(void);
extern void create_descriptor(int num, u32 base, u32 limit, u8 access, u8 gran);
extern void gdt_init(void);

#endif
