#ifndef IRQ_H
#define IRQ_H

/* IRQs handlers */
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

/* Setting a pointer to a handler function in an IRQ processor */
void irqInstallHandler(int irq, void (*handler) (struct regs *r));

/* Deleting a pointer to a function handler from an IRQ handler */
void irqUnintallHandler(int irq);

/* Normally, IRQs 0 to 7 are mapped to entries 8 to 15. This
*  is a problem in protected mode, because IDT entry 8 is a
*  Double Fault! Without remapping, every time IRQ0 fires,
*  you get a Double Fault Exception, which is NOT actually
*  what's happening. We send commands to the Programmable
*  Interrupt Controller (PICs - also called the 8259's) in
*  order to make IRQ0 to 15 be remapped to IDT entries 32 to
*  47 */
void irqRemap();

/* Installation IRQ and enable interrupts */
void irqInstall();

/*
 * The standard function is processing interrupts for all IRQs.
 */
void irqHandler(struct regs *r);

#endif
