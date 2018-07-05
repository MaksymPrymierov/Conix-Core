#!/bin/bash 

printf '[C]Start build kernel.c\n'
gcc -m32 -c src/kernel.c -o bin/conixc.o
printf '[C]Build complete kernel.c -> conixc.o \n[C]Start build io.c\n'
gcc -m32 -c src/io.c -o bin/io.o
printf '[C]Build complete io.c -> io.o \n[ASM]Start build kernel.asm\n'
nasm -f elf32 src/kernel.asm -o bin/conixasm.o
printf '[ASM]Build complete kernel.asm -> conixasm.o \n[LD]Start linking\n'
ld -m elf_i386 -T link.ld -o kernel bin/conixasm.o bin/conixc.o bin/io.o
printf '[LD]Link complete \n[GCC]Build kernel complete'
