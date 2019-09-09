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

	.section .bss
	.align 	16
stack_bottom:
	.skip 	16384
stack_top:

	.section .text
	.global _start
	.type _start, @function
_start:
	.extern heap_buttom
	.extern heap_top

	mov  	$stack_top, %esp
	push 	$heap_bottom
	push 	$heap_top 
	call 	main
	cli
1: hlt
	jmp 	1b

.size _start, . - _start
