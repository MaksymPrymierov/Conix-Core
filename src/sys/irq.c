#include "../../headers/sys/sys.h"
#include "../../headers/io/ports.h"

void *irqRoutines[16] = 
{ 
    0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0 
};

void irqInstallHandler(int irq, void (*handler) (struct regs *r)){
  irqRoutines[irq] = handler;
}

void irqUnintallHandler(int irq){
  irqRoutines[irq] = 0;
}

void irqRemap(){
  outb(0x20, 0x11);
  outb(0xA0, 0x11);
  outb(0x21, 0x20);
  outb(0xA1, 0x28);
  outb(0x21, 0x04);
  outb(0xA1, 0x02);
  outb(0x21, 0x01);
  outb(0xA1, 0x01);
  outb(0x21, 0x00);
  outb(0xA1, 0x00);
}

void irqInstall(){
  irqRemap();

  idtSetGate(32, (unsigned long)irq0, 0x08, 0x8E);
  idtSetGate(33, (unsigned long)irq1, 0x08, 0x8E);
  idtSetGate(34, (unsigned long)irq2, 0x08, 0x8E);
  idtSetGate(35, (unsigned long)irq3, 0x08, 0x8E);
  idtSetGate(36, (unsigned long)irq4, 0x08, 0x8E);
  idtSetGate(37, (unsigned long)irq5, 0x08, 0x8E);
  idtSetGate(38, (unsigned long)irq6, 0x08, 0x8E);
  idtSetGate(39, (unsigned long)irq7, 0x08, 0x8E);
  idtSetGate(40, (unsigned long)irq8, 0x08, 0x8E);
  idtSetGate(41, (unsigned long)irq9, 0x08, 0x8E);
  idtSetGate(42, (unsigned long)irq10, 0x08, 0x8E);
  idtSetGate(43, (unsigned long)irq11, 0x08, 0x8E);
  idtSetGate(44, (unsigned long)irq12, 0x08, 0x8E);
  idtSetGate(45, (unsigned long)irq13, 0x08, 0x8E);
  idtSetGate(46, (unsigned long)irq14, 0x08, 0x8E);
  idtSetGate(47, (unsigned long)irq15, 0x08, 0x8E);
}

void irqHandler(struct regs *r){
  void (*handler) (struct regs *r);

  handler = irqRoutines[r->intNo - 32];
  if(handler){
    handler(r);
  }

  if(r->intNo >= 40){
    outb(0xA0, 0x20);
  }

  outb(0x20, 0x20);
}
