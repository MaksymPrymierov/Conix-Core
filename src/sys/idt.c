#include "../../headers/stdlib/stdlib.h"
#include "../../headers/sys/sys.h"

void idtSetGate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags){
  asm("pushf");
  asm("cli");

  idt[num].baseLow  = (base & 0xFFFF);
  idt[num].baseHigh = (base >> 16) & 0xFFFF;

  idt[num].sel     = sel;
  idt[num].always0 = 0;
  idt[num].flags   = flags;

  asm("popf");
  asm("sti");
}

void idtInstall(){
  idtp.limit = (sizeof(struct idtEntry) * 256) - 1;
  idtp.base  = (unsigned long)&idt[0];

  memset(&idt, 0, sizeof(struct idtEntry) * 256);

  idtLoad((unsigned long)&idtp);
}
