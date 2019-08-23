	.section ".text", "ax"
	.globl	memset
	.type	memset, @function
memset:
	push	%edi

	mov	0x8(%esp), %edi
	mov	0xc(%esp), %eax
	mov	0x10(%esp), %ecx

	push	%edi

	cld
	rep stosb

	pop %eax
	pop %edi
	ret
