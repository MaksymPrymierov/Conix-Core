.global irq0
.global irq1
.global irq2
.global irq3
.global irq4
.global irq5
.global irq6
.global irq7
.global irq8
.global irq9
.global irq10
.global irq11
.global irq12
.global irq13
.global irq14
.global irq15

irq0:
	cli
	push $0
	push $32
	jmp irqCommonStub

irq1:
	cli
	push $0
	push $33
	jmp irqCommonStub

irq2:
	cli
	push $0
	push $34
	jmp irqCommonStub

irq3:
	cli
	push $0
	push $35
	jmp irqCommonStub

irq4:
	cli
	push $0
	push $36
	jmp irqCommonStub

irq5:
	cli
	push $0
	push $37
	jmp irqCommonStub

irq6:
	cli
	push $0
	push $38
	jmp irqCommonStub

irq7:
	cli
	push $0
	push $39
	jmp irqCommonStub

irq8:
	cli
	push $0
	push $40
	jmp irqCommonStub

irq9:
	cli
	push $0
	push $41
	jmp irqCommonStub

irq10:
	cli
	push $0
	push $42
	jmp irqCommonStub

irq11:
	cli
	push $0
	push $43
	jmp irqCommonStub

irq12:
	cli
	push $0
	push $44
	jmp irqCommonStub

irq13:
	cli
	push $0
	push $45
	jmp irqCommonStub

irq14:
	cli
	push $0
	push $46
	jmp irqCommonStub

irq15:
	cli
	push $0
	push $47
	jmp irqCommonStub

.extern irqHandler

irqCommonStub:
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
	mov $irqHandler, %eax
	call *%eax

	pop %eax
	pop %gs
	pop %fs
	pop %es
	pop %ds
	popa

	add $8, %esp
	iret
