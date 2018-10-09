#!/bin/bash

C="/usr/local/cross/bin/i686-elf-gcc -O2 -ffreestanding -mno-red-zone -nostdlib -lgcc -c"
LD="/usr/local/cross/bin/i686-elf-ld -T"
SRCF="src"

errCheck(){
  if (( $? != 0 ))
  then
    echo "Error"
    exit 1
  fi
}

cd bin 2>/dev/null
if  (( $? == 1 ))
then
  mkdir -v bin
else
  cd ..
  rm -rfv bin/*
fi
ls kernel 2>/dev/null >/dev/null
if (( $? == 0 ))
then
  rm kernel
fi
mkdir bin/{io,stdlib,memory,conixLibs,kernelShell}

cd $SRCF
SRC=( $(ls *.c *.s io/{*.c,*.s} stdlib/*.c conixLibs/*.c kernelShell/*.c) )
cd ..

for ((i=0; i != ${#SRC[@]}; i++))
do
  $C $SRCF/${SRC[i]} -o bin/${SRC[i]}.o
  errCheck
done

$LD link.ld -o kernel bin/*.o bin/io/*.o bin/stdlib/*.o bin/conixLibs/*.o bin/kernelShell/*.o
errCheck
echo "Build Complete"
