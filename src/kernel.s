  .text
  .align 4
  .long 0x1BADB002
  .long 0x00
  .long - (0x1BADB002 + 0x00)
        
  .globl start
  .extern main

start:
  cli
  movl    $(stack + 0x4000), %esp
  call main
  hlt

.bss
stack:
loop: loop jmp
