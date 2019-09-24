	.section .text
	.globl last_intraction
last_intraction:
	ret

	.section .text
	.globl execute_task
execute_task:
	pop %eax
	pop %ebx
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
	push %ecx
	mov %esp, %ecx

	mov %eax, %esp
	call *%ebx

	mov %ecx, %esp
	pop %ecx

        pop %gs
        pop %fs
        pop %es
        pop %ds
        popa

	add $8, %esp
	iret
