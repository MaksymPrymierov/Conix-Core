#!/bin/bash 
rm bin/* 
gcc -m32 -c src/int.c    -o bin/int.o
gcc -m32 -c src/io.c     -o bin/io.o
gcc -m32 -c src/kernel.c -o bin/kernel.o
gcc -m32 -c src/stdlib.c -o bin/stdlib.o
gcc -m32 -c src/string.c -o bin/string.o

as  --32    src/kernel.s -o bin/conixasm.o

ld -m elf_i386 -T link.ld -o kernel bin/*
