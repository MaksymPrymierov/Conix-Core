#include "../../headers/stdlib/stdlib.h"
#include "../../headers/memory/gdt.h"

void createDescriptor(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran){
  gdt[num].baseLow    = (base & 0xFFFF);
  gdt[num].baseMiddle = (base >> 16) & 0xFF;
  gdt[num].baseHigh   = (base >> 24) & 0xFF;

  gdt[num].limitLow    = (limit & 0xFFFF);
  gdt[num].granularity = ((limit >> 16) & 0x0F);

  gdt[num].granularity |= (gran & 0xF0);
  gdt[num].access = access;
}

void gdtInit(){
  createDescriptor(0, 0, 0, 0, 0);

  createDescriptor(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);

  createDescriptor(2, 0, 0xFFFFFFFF, 0x9A, 0xCF);

  gdtFlush();
}
