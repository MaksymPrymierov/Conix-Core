#!/bin/bash

C="gcc -m32 -c"
LD="ld -m elf_i386 -T"
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
mkdir bin/{io,stdlib}

cd $SRCF
SRC=( $(ls *.c *.s io/{*.c,*.s} stdlib/*.c) )
cd ..

for ((i=0; i != ${#SRC[@]}; i++))
do
  $C $SRCF/${SRC[i]} -o bin/${SRC[i]}.o
  errCheck
done

$LD link.ld -o kernel bin/*.o bin/io/*.o bin/stdlib/*.o
errCheck
echo "Build Complete"
