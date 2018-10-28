#include "../../headers/stdlib/stdlib.h"
#include "../../headers/sys/sys.h"

unsigned char *exceptionMessages[] = 
{
  "Division By Zero Exception",
  "Debug Exception",
  "Non Maskable Interrupt Exception",
  "Breakpoint Exception",
  "Into Detected Overflow Exception",
  "Out of Bounds Exception",
  "Invalid Opcode Exception",
  "No Coprocessor Exception",
  "Double Fault Exception",
  "Coprocessor Segment Overrun Exception",
  "Bad TSS Exception",
  "Segment Not Present Exception",
  "Stack Fault Exception",
  "General Protection Fault Exception",
  "Page Fault Exception",
  "Unknown Interrupt Exception",
  "Coprocessor Fault Exception",
  "Alignment Check Exception (486+)",
  "Machine Check Exception (Pentium/586+)",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions",
  "Reserved Exceptions"
};

void isrsInstall(){
  idtSetGate(0, (unsigned long)isr0, 0x08, 0x8E);
  idtSetGate(1, (unsigned long)isr1, 0x08, 0x8E);
  idtSetGate(2, (unsigned long)isr2, 0x08, 0x8E);
  idtSetGate(3, (unsigned long)isr3, 0x08, 0x8E);
  idtSetGate(4, (unsigned long)isr4, 0x08, 0x8E);
  idtSetGate(5, (unsigned long)isr5, 0x08, 0x8E);
  idtSetGate(6, (unsigned long)isr6, 0x08, 0x8E);
  idtSetGate(7, (unsigned long)isr7, 0x08, 0x8E);
  idtSetGate(8, (unsigned long)isr8, 0x08, 0x8E);
  idtSetGate(9, (unsigned long)isr9, 0x08, 0x8E);
  idtSetGate(10, (unsigned long)isr10, 0x08, 0x8E);
  idtSetGate(11, (unsigned long)isr11, 0x08, 0x8E);
  idtSetGate(12, (unsigned long)isr12, 0x08, 0x8E);
  idtSetGate(13, (unsigned long)isr13, 0x08, 0x8E);
  idtSetGate(14, (unsigned long)isr14, 0x08, 0x8E);
  idtSetGate(15, (unsigned long)isr15, 0x08, 0x8E);
  idtSetGate(16, (unsigned long)isr16, 0x08, 0x8E);
  idtSetGate(17, (unsigned long)isr17, 0x08, 0x8E);
  idtSetGate(18, (unsigned long)isr18, 0x08, 0x8E);
  idtSetGate(19, (unsigned long)isr19, 0x08, 0x8E);
  idtSetGate(20, (unsigned long)isr20, 0x08, 0x8E);
  idtSetGate(21, (unsigned long)isr21, 0x08, 0x8E);
  idtSetGate(22, (unsigned long)isr22, 0x08, 0x8E);
  idtSetGate(23, (unsigned long)isr23, 0x08, 0x8E);
  idtSetGate(24, (unsigned long)isr24, 0x08, 0x8E);
  idtSetGate(25, (unsigned long)isr25, 0x08, 0x8E);
  idtSetGate(26, (unsigned long)isr26, 0x08, 0x8E);
  idtSetGate(27, (unsigned long)isr27, 0x08, 0x8E);
  idtSetGate(28, (unsigned long)isr28, 0x08, 0x8E);
  idtSetGate(29, (unsigned long)isr29, 0x08, 0x8E);
  idtSetGate(30, (unsigned long)isr30, 0x08, 0x8E);
  idtSetGate(31, (unsigned long)isr31, 0x08, 0x8E);
}

void faultHandler(struct regs *r){
  if(r->intNo < 32){
    printf("%s", exceptionMessages[r->intNo]);
    printf("%s", " Exception. System Halter!\n");
    for (;;);
  }
}

