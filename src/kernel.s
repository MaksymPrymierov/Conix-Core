#define ASM_FILE
#include "../headers/multiboot.h"

        .text
        .align 4
        .long 0x1BADB002
        .long 0x00
        .long - (0x1BADB002 + 0x00)
        
        .globl start
        .extern main

start:
        cli
        #mov %esp,stack_space
        movl    $(stack + 0x4000), %esp
        call main
        hlt

.bss
stack:
