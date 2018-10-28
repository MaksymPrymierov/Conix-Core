#ifndef IRQ_H
#define IRQ_H

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

void irqInstallHandler(int irq, void (*handler) (struct regs *r));
void irqUnintallHandler(int irq);

void irqRemap();

void irqInstall();
void irqHandler(struct regs *r);

#endif
