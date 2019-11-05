#include <idt.h>
#include <kernel/kernel_lib.h>
#include <tty.h>
#include <asm.h>

static struct idt_entry idt[256];
struct idt_ptr idtp;

void idt_create_descriptor(u8 num, u32 base, u16 sel, u8 flags)
{
        idt[num].base_low  = (base & 0xFFFF);
        idt[num].base_high = (base >> 16) & 0xFFFF;

        idt[num].sel     = sel;
        idt[num].always0 = 0;
        idt[num].flags   = flags;
}

void idt_install()
{
        idtp.limit = (sizeof(struct idt_entry) * 256) - 1;
        idtp.base  = (u32)&idt;

        memset(&idt, 0, sizeof(struct idt_entry) * 256);

        idt_load();
}

static const char* exception_messages[] = {
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

void isrs_install() 
{
        idt_create_descriptor(0, (unsigned)isr0, 0x08, 0x8E);
        idt_create_descriptor(1, (unsigned)isr1, 0x08, 0x8E);
        idt_create_descriptor(2, (unsigned)isr2, 0x08, 0x8E);
        idt_create_descriptor(3, (unsigned)isr3, 0x08, 0x8E);
        idt_create_descriptor(4, (unsigned)isr4, 0x08, 0x8E);
        idt_create_descriptor(5, (unsigned)isr5, 0x08, 0x8E);
        idt_create_descriptor(6, (unsigned)isr6, 0x08, 0x8E);
        idt_create_descriptor(7, (unsigned)isr7, 0x08, 0x8E);
        idt_create_descriptor(8, (unsigned)isr8, 0x08, 0x8E);
        idt_create_descriptor(9, (unsigned)isr9, 0x08, 0x8E);
        idt_create_descriptor(10, (unsigned)isr10, 0x08, 0x8E);
        idt_create_descriptor(11, (unsigned)isr11, 0x08, 0x8E);
        idt_create_descriptor(12, (unsigned)isr12, 0x08, 0x8E);
        idt_create_descriptor(13, (unsigned)isr13, 0x08, 0x8E);
        idt_create_descriptor(14, (unsigned)isr14, 0x08, 0x8E);
        idt_create_descriptor(15, (unsigned)isr15, 0x08, 0x8E);
        idt_create_descriptor(16, (unsigned)isr16, 0x08, 0x8E);
        idt_create_descriptor(17, (unsigned)isr17, 0x08, 0x8E);
        idt_create_descriptor(18, (unsigned)isr18, 0x08, 0x8E);
        idt_create_descriptor(19, (unsigned)isr19, 0x08, 0x8E);
        idt_create_descriptor(20, (unsigned)isr20, 0x08, 0x8E);
        idt_create_descriptor(21, (unsigned)isr21, 0x08, 0x8E);
        idt_create_descriptor(22, (unsigned)isr22, 0x08, 0x8E);
        idt_create_descriptor(23, (unsigned)isr23, 0x08, 0x8E);
        idt_create_descriptor(24, (unsigned)isr24, 0x08, 0x8E);
        idt_create_descriptor(25, (unsigned)isr25, 0x08, 0x8E);
        idt_create_descriptor(26, (unsigned)isr26, 0x08, 0x8E);
        idt_create_descriptor(27, (unsigned)isr27, 0x08, 0x8E);
        idt_create_descriptor(28, (unsigned)isr28, 0x08, 0x8E);
        idt_create_descriptor(29, (unsigned)isr29, 0x08, 0x8E);
        idt_create_descriptor(30, (unsigned)isr30, 0x08, 0x8E);
        idt_create_descriptor(31, (unsigned)isr31, 0x08, 0x8E);
}

void fault_handler(struct regs *r)
{
        if (r->int_no < 32) {
                tty out;
                out << "idt: Exception! System Halter!" << exception_messages[r->int_no];
                for (;;);
        }
}

static void *irq_routines[16] = { 
        0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0 
};

void irq_install_handler(u32 irq, void (*handler) (struct regs *r))
{
        irq_routines[irq] = (void*)handler;
}

void irq_unintall_handler(u32 irq)
{
        irq_routines[irq] = 0;
}

static void irq_remap()
{
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

void irq_install()
{
        irq_remap();

        idt_create_descriptor(32, (unsigned)irq0, 0x08, 0x8E);
        idt_create_descriptor(33, (unsigned)irq1, 0x08, 0x8E);
        idt_create_descriptor(34, (unsigned)irq2, 0x08, 0x8E);
        idt_create_descriptor(35, (unsigned)irq3, 0x08, 0x8E);
        idt_create_descriptor(36, (unsigned)irq4, 0x08, 0x8E);
        idt_create_descriptor(37, (unsigned)irq5, 0x08, 0x8E);
        idt_create_descriptor(38, (unsigned)irq6, 0x08, 0x8E);
        idt_create_descriptor(39, (unsigned)irq7, 0x08, 0x8E);
        idt_create_descriptor(40, (unsigned)irq8, 0x08, 0x8E);
        idt_create_descriptor(41, (unsigned)irq9, 0x08, 0x8E);
        idt_create_descriptor(42, (unsigned)irq10, 0x08, 0x8E);
        idt_create_descriptor(43, (unsigned)irq11, 0x08, 0x8E);
        idt_create_descriptor(44, (unsigned)irq12, 0x08, 0x8E);
        idt_create_descriptor(45, (unsigned)irq13, 0x08, 0x8E);
        idt_create_descriptor(46, (unsigned)irq14, 0x08, 0x8E);
        idt_create_descriptor(47, (unsigned)irq15, 0x08, 0x8E);

        __asm__ volatile("sti");
}

void irq_handler(struct regs *r)
{
        void (*handler) (struct regs *r);

        handler = (void (*)(regs*))irq_routines[r->int_no - 32];
        if (handler) {
                handler(r);
        }

        if (r->int_no >= 40) {
                outb(0xA0, 0x20);
        }

        outb(0x20, 0x20);
}
