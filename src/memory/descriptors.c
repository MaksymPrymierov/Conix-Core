#include <stdint.h>
#include "../../headers/stdlib/stddef.h"
#include "../../headers/stdlib/stdio.h"
#include "../../headers/stdlib/stdlib.h"
#include "../../headers/memory/descriptors.h"
#include "../../headers/io/ports.h"

#define LOG_OFF

GDT_ENTRY entries[5];
GDT_DESC gdt_ptr;

IntDesc *idt = (void*)0x0;
IDTR idtr;

void enableInterrupts(){
  //*((size_t*)0xFFFFEFF0) = 0x8000 | 3;
  _memset(idt, 0, 256 * sizeof(IntDesc));
  idtr.limit = 256 * sizeof(IntDesc);
  idtr.base = idt;

  asm("lidtl (,%0,)"::"a"(&idtr));

  unsigned char mask1 = inb(CX_PIC_FIRST_PORT_2);
  unsigned char mask2 = inb(CX_PIC_SECND_PORT_2);

  outb(CX_PIC_FIRST_PORT_1, 0x11);
  outb(CX_PIC_FIRST_PORT_2, (uint8_t)0x20);
  outb(CX_PIC_FIRST_PORT_2, 4);
  outb(CX_PIC_FIRST_PORT_2, 1);

  outb(CX_PIC_SECND_PORT_1, 0x11);
  outb(CX_PIC_SECND_PORT_2, (uint8_t)0x28);
  outb(CX_PIC_SECND_PORT_2, 2);
  outb(CX_PIC_SECND_PORT_2, 1);

  outb(CX_PIC_FIRST_PORT_2, 0x0);
  outb(CX_PIC_SECND_PORT_2, 0x0);
}

void set_int_handler(uint8_t index, void *handler, uint8_t type) {
  asm("pushf");
  asm("cli"); //Turn off interrupts
	idt[index].selector = 8;
  idt[index].address_0_15 = (size_t)handler & 0xFFFF;
	idt[index].address_16_31 = ((size_t)handler ) >> 16;
	idt[index].type = type;
	idt[index].reserved = 0;

 // printf("Int handler (ptr:) %i (index:) %i (IRQ%i)\n", (uint32_t)handler, index, index % 16);
	asm("popf");
  asm("sti"); //Enable interrupts
}

void enableGDT(){
  gdt_ptr.limit = sizeof(GDT_ENTRY) * 5 - 1;
  gdt_ptr.base = (uint32_t)&entries[0];

  GDT_setEntryProperties(0,0,0,0,0);
  GDT_setEntryProperties(1,0,0xFFFFFFFF, 0x9A,0xCF);
  GDT_setEntryProperties(2,0,0xFFFFFFFF, 0x92,0xCF);
  GDT_setEntryProperties(3,0,0xFFFFFFFF, 0xFA,0xCF);
  GDT_setEntryProperties(4,0,0xFFFFFFFF, 0xF2,0xCF);

    asm("lgdt (,%0,)"::"a"(&gdt_ptr));
   load_gdt((uint32_t)&gdt_ptr);
}

void GDT_setEntryProperties(uint32_t id, uint32_t base, uint32_t limit, uint8_t accessFlags, uint8_t granularity){
  GDT_ENTRY* entry = &entries[id];

  entry->base0_15 = base & 0xFFFF;
  entry->base16_23 = (base & 0xFF0000) >> 16;
  entry->base24_31 = (base & 0xFF000000) >> 24;

  entry->limit0_15 = limit & 0xFFFF;
  entry->limit16_19 = (limit) >> 16;

  entry->granularity = granularity & 0x0F;
  entry->accessFlags = accessFlags;
}

 void enableA20(){
//  _printf("Enabling A20\n");
  asm("in $0x92, %al");
  asm("or $2, %al");
  asm("out %al, $0x92");
}
