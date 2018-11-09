#!/bin/bash

C="/usr/local/cross/bin/i686-elf-gcc -O2 -ffreestanding -mno-red-zone -nostdlib -lgcc -c"
LD="/usr/local/cross/bin/i686-elf-ld -T"
SRCF="src"
BIN="bin/*.o bin/io/*.o bin/stdlib/*.o bin/sys/*.o bin/kernelShell/*.o bin/ints/*.o"
SRC="*.c *.s io/*.c stdlib/*.c sys/*.c sys/*.s kernelShell/*.c ints/*.c"

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
mkdir bin/{io,stdlib,sys,kernelShell,ints}

cd $SRCF
SRC=( $(ls $SRC) )
cd ..

for ((i=0; i != ${#SRC[@]}; i++))
do
  $C $SRCF/${SRC[i]} -o bin/${SRC[i]}.o
  errCheck
done

$LD link.ld -o kernel $BIN
errCheck
echo "Build Complete"
