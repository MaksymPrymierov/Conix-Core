BOOTSEG		= 0x07C0 
ALIGN		= 1 << 0
MEMINFO		= 1 << 1
FLAGS		= ALIGN | MEMINFO
MAGIC		= 0x1BADB002
CHECKSUM	= -(MAGIC + FLAGS)

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
