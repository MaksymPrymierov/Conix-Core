#include "../../headers/stdlib/stdlib.h"
#include "../../headers/sys/sys.h"

unsigned char *exceptionMessages[] = {
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

void isrsInstall() 
{
        idtSetGate(0, (unsigned)isr0, 0x08, 0x8E);
        idtSetGate(1, (unsigned)isr1, 0x08, 0x8E);
        idtSetGate(2, (unsigned)isr2, 0x08, 0x8E);
        idtSetGate(3, (unsigned)isr3, 0x08, 0x8E);
        idtSetGate(4, (unsigned)isr4, 0x08, 0x8E);
        idtSetGate(5, (unsigned)isr5, 0x08, 0x8E);
        idtSetGate(6, (unsigned)isr6, 0x08, 0x8E);
        idtSetGate(7, (unsigned)isr7, 0x08, 0x8E);
        idtSetGate(8, (unsigned)isr8, 0x08, 0x8E);
        idtSetGate(9, (unsigned)isr9, 0x08, 0x8E);
        idtSetGate(10, (unsigned)isr10, 0x08, 0x8E);
        idtSetGate(11, (unsigned)isr11, 0x08, 0x8E);
        idtSetGate(12, (unsigned)isr12, 0x08, 0x8E);
        idtSetGate(13, (unsigned)isr13, 0x08, 0x8E);
        idtSetGate(14, (unsigned)isr14, 0x08, 0x8E);
        idtSetGate(15, (unsigned)isr15, 0x08, 0x8E);
        idtSetGate(16, (unsigned)isr16, 0x08, 0x8E);
        idtSetGate(17, (unsigned)isr17, 0x08, 0x8E);
        idtSetGate(18, (unsigned)isr18, 0x08, 0x8E);
        idtSetGate(19, (unsigned)isr19, 0x08, 0x8E);
        idtSetGate(20, (unsigned)isr20, 0x08, 0x8E);
        idtSetGate(21, (unsigned)isr21, 0x08, 0x8E);
        idtSetGate(22, (unsigned)isr22, 0x08, 0x8E);
        idtSetGate(23, (unsigned)isr23, 0x08, 0x8E);
        idtSetGate(24, (unsigned)isr24, 0x08, 0x8E);
        idtSetGate(25, (unsigned)isr25, 0x08, 0x8E);
        idtSetGate(26, (unsigned)isr26, 0x08, 0x8E);
        idtSetGate(27, (unsigned)isr27, 0x08, 0x8E);
        idtSetGate(28, (unsigned)isr28, 0x08, 0x8E);
        idtSetGate(29, (unsigned)isr29, 0x08, 0x8E);
        idtSetGate(30, (unsigned)isr30, 0x08, 0x8E);
        idtSetGate(31, (unsigned)isr31, 0x08, 0x8E);
}

void faultHandler(struct regs *r)
{
        if (r->intNo < 32) {
                printf("%s", exceptionMessages[r->intNo]);
                printf("%s", " Exception. System Halter!\n");
                for (;;);
        }
}

