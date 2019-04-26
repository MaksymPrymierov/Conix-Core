.global isr0
.global isr1
.global isr2
.global isr3
.global isr4
.global isr5
.global isr6
.global isr7
.global isr8
.global isr9
.global isr10
.global isr11
.global isr12
.global isr13
.global isr14
.global isr15
.global isr16
.global isr17
.global isr18
.global isr19
.global isr20
.global isr21
.global isr22
.global isr23
.global isr24
.global isr25
.global isr26
.global isr27
.global isr28
.global isr29
.global isr30
.global isr31

# Divide by zero exception
isr0:
        cli
        push 0
        push 0
        jmp isrCommonStub

# Debug Exception
isr1:
        cli
        push 0
        push 1
        jmp isrCommonStub

# Non Maskable Interrupt Exception
isr2:
        cli
        push 0
        push 2
        jmp isrCommonStub

# Breakpoint Exception
isr3:
        cli
        push 0
        push 3
        jmp isrCommonStub

# Into Detected Overflow Exception
isr4:
        cli
        push 0
        push 4
        jmp isrCommonStub

# Out of Bounds Exception
isr5:
        cli
        push 0
        push 5
        jmp isrCommonStub

# Invalid Opcode Exception
isr6:
        cli
        push 0
        push 6
        jmp isrCommonStub

# No Coprocessor Exception
isr7:
        cli
        push 0
        push 7
        jmp isrCommonStub

# Double Fault Exception
isr8:
        cli
        push 8
        jmp isrCommonStub

# Coprocessor Segment Overrun Exception
isr9:
        cli
        push 0
        push 9
        jmp isrCommonStub

# Bad TSS Exception
isr10:
        cli
        push 10
        jmp isrCommonStub

# Segment Not Present Exception
isr11:
        cli
        push 11
        jmp isrCommonStub

# Stack Fault Exception
isr12:
        cli
        push 12
        jmp isrCommonStub

# General Protection Fault Exception
isr13:
        cli
        push 13
        jmp isrCommonStub

# Page Fault Exception
isr14:
        cli
        push 14
        jmp isrCommonStub

# Unknown Interrupt Exception
isr15:
        cli
        push 0
        push 15
        jmp isrCommonStub

# Coprocessor Fault Exception
isr16:
        cli
        push 0
        push 16
        jmp isrCommonStub

# Alignment Check Exception (486+)
isr17:
        cli
        push 0
        push 17
        jmp isrCommonStub

# Machine Check Exception (Pentium/586+)
isr18:
        cli
        push 0
        push 18
        jmp isrCommonStub

# Reserved Exceptions (isr19-31)
isr19:
        cli
        push 0
        push 19
        jmp isrCommonStub

isr20:
        cli
        push 0
        push 20
        jmp isrCommonStub

isr21:
        cli
        push 0
        push 21
        jmp isrCommonStub

isr22:
        cli
        push 0
        push 22
        jmp isrCommonStub

isr23:
        cli
        push 0
        push 23
        jmp isrCommonStub

isr24:
        cli
        push 0
        push 24
        jmp isrCommonStub

isr25:
        cli
        push 0
        push 25
        jmp isrCommonStub

isr26:
        cli
        push 0
        push 26
        jmp isrCommonStub

isr27:
        cli
        push 0
        push 27
        jmp isrCommonStub

isr28:
        cli
        push 0
        push 28
        jmp isrCommonStub

isr29:
        cli
        push 0
        push 29
        jmp isrCommonStub

isr30:
        cli
        push 0
        push 30
        jmp isrCommonStub

isr31:
        cli
        push 0
        push 31
        jmp isrCommonStub

.extern faultHandler
.type faultHandler, @function

isrCommonStub:
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
        mov $faultHandler, %eax
        call *%eax

        pop %eax
        pop %gs
        pop %fs
        pop %es
        pop %ds
        popa

        add $8, %esp
        iret
