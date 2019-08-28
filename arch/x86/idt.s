	.section .text
	.globl idt_load
	.extern idtp
idt_load:
        lidt (idtp)
        ret

	.globl isr0
	.globl isr1
	.globl isr2
	.globl isr3
	.globl isr4
	.globl isr5
	.globl isr6
	.globl isr7
	.globl isr8
	.globl isr9
	.globl isr10
	.globl isr11
	.globl isr12
	.globl isr13
	.globl isr14
	.globl isr15
	.globl isr16
	.globl isr17
	.globl isr18
	.globl isr19
	.globl isr20
	.globl isr21
	.globl isr22
	.globl isr23
	.globl isr24
	.globl isr25
	.globl isr26
	.globl isr27
	.globl isr28
	.globl isr29
	.globl isr30
	.globl isr31

# Divide by zero exception
isr0:
        cli
        push 0
        push 0
        jmp isr_common_stub

# Debug Exception
isr1:
        cli
        push 0
        push 1
        jmp isr_common_stub

# Non Maskable Interrupt Exception
isr2:
        cli
        push 0
        push 2
        jmp isr_common_stub

# Breakpoint Exception
isr3:
        cli
        push 0
        push 3
        jmp isr_common_stub

# Into Detected Overflow Exception
isr4:
        cli
        push 0
        push 4
        jmp isr_common_stub

# Out of Bounds Exception
isr5:
        cli
        push 0
        push 5
        jmp isr_common_stub

# Invalid Opcode Exception
isr6:
        cli
        push 0
        push 6
        jmp isr_common_stub

# No Coprocessor Exception
isr7:
        cli
        push 0
        push 7
        jmp isr_common_stub

# Double Fault Exception
isr8:
        cli
        push 8
        jmp isr_common_stub

# Coprocessor Segment Overrun Exception
isr9:
        cli
        push 0
        push 9
        jmp isr_common_stub

# Bad TSS Exception
isr10:
        cli
        push 10
        jmp isr_common_stub

# Segment Not Present Exception
isr11:
        cli
        push 11
        jmp isr_common_stub

# Stack Fault Exception
isr12:
        cli
        push 12
        jmp isr_common_stub

# General Protection Fault Exception
isr13:
        cli
        push 13
        jmp isr_common_stub

# Page Fault Exception
isr14:
        cli
        push 14
        jmp isr_common_stub

# Unknown Interrupt Exception
isr15:
        cli
        push 0
        push 15
        jmp isr_common_stub

# Coprocessor Fault Exception
isr16:
        cli
        push 0
        push 16
        jmp isr_common_stub

# Alignment Check Exception (486+)
isr17:
        cli
        push 0
        push 17
        jmp isr_common_stub

# Machine Check Exception (Pentium/586+)
isr18:
        cli
        push 0
        push 18
        jmp isr_common_stub

# Reserved Exceptions (isr19-31)
isr19:
        cli
        push 0
        push 19
        jmp isr_common_stub

isr20:
        cli
        push 0
        push 20
        jmp isr_common_stub

isr21:
        cli
        push 0
        push 21
        jmp isr_common_stub

isr22:
        cli
        push 0
        push 22
        jmp isr_common_stub

isr23:
        cli
        push 0
        push 23
        jmp isr_common_stub

isr24:
        cli
        push 0
        push 24
        jmp isr_common_stub

isr25:
        cli
        push 0
        push 25
        jmp isr_common_stub

isr26:
        cli
        push 0
        push 26
        jmp isr_common_stub

isr27:
        cli
        push 0
        push 27
        jmp isr_common_stub

isr28:
        cli
        push 0
        push 28
        jmp isr_common_stub

isr29:
        cli
        push 0
        push 29
        jmp isr_common_stub

isr30:
        cli
        push 0
        push 30
        jmp isr_common_stub

isr31:
        cli
        push 0
        push 31
        jmp isr_common_stub

.extern fault_handler
.type fault_handler, @function
isr_common_stub:
        pusha
        push %ds
        push %es
        push %fs
        push %gs

        mov $0x10, %ax
        mov %ax, %ds
        mov %ax, %es
        mov %ax, %fs
        mov %ax, %gs
        mov %esp, %eax

        push %eax
        mov $fault_handler, %eax
        call *%eax

        pop %eax
        pop %gs
        pop %fs
        pop %es
        pop %ds
        popa

        add $8, %esp
        iret

	.globl irq0
	.globl irq1
	.globl irq2
	.globl irq3
	.globl irq4
	.globl irq5
	.globl irq6
	.globl irq7
	.globl irq8
	.globl irq9
	.globl irq10
	.globl irq11
	.globl irq12
	.globl irq13
	.globl irq14
	.globl irq15

irq0:
        cli
        push $0
        push $32
        jmp irq_common_stub

irq1:
        cli
        push $0
        push $33
        jmp irq_common_stub

irq2:
        cli
        push $0
        push $34
        jmp irq_common_stub

irq3:
        cli
        push $0
        push $35
        jmp irq_common_stub

irq4:
        cli
        push $0
        push $36
        jmp irq_common_stub

irq5:
        cli
        push $0
        push $37
        jmp irq_common_stub

irq6:
        cli
        push $0
        push $38
        jmp irq_common_stub

irq7:
        cli
        push $0
        push $39
        jmp irq_common_stub

irq8:
        cli
        push $0
        push $40
        jmp irq_common_stub

irq9:
        cli
        push $0
        push $41
        jmp irq_common_stub

irq10:
        cli
        push $0
        push $42
        jmp irq_common_stub

irq11:
        cli
        push $0
        push $43
        jmp irq_common_stub

irq12:
        cli
        push $0
        push $44
        jmp irq_common_stub

irq13:
        cli
        push $0
        push $45
        jmp irq_common_stub

irq14:
        cli
        push $0
        push $46
        jmp irq_common_stub

irq15:
        cli
        push $0
        push $47
        jmp irq_common_stub

	.extern irq_handler
	.type irq_handler, @function
irq_common_stub:
        pusha
        push %ds
        push %es
        push %fs
        push %gs

        mov $0x10, %ax
        mov %ax, %ds
        mov %ax, %es
        mov %ax, %fs
        mov %ax, %gs
        mov %esp, %eax

        push %eax
        mov $irq_handler, %eax
        call *%eax

        pop %eax
        pop %gs
        pop %fs
        pop %es
        pop %ds
        popa

        add $8, %esp
        iret
