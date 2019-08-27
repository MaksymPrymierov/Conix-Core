	.set	ALIGN,		1<<0
	.set	MEMINFO,	1<<1
	.set	FLAGS,		ALIGN | MEMINFO
	.set	MAGIC,		0x1BADB002
	.set 	CHECKSUM, 	-(MAGIC + FLAGS)

	.section .multiboot
	.align	4
	.long 	MAGIC
	.long 	FLAGS
	.long 	CHECKSUM

	.section .text
	.global _start
	.type _start, @function
_start:
	mov  	$stack_start, %esp
	push 	%ebx
	push 	%eax
	call 	main
	cli
1: hlt
	jmp 	1b

	.section .data
stack_bottom:
	.space 4096
stack_start:
