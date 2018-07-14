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
  rm bin/*
fi
ls kernel 2>/dev/null >/dev/null
if (( $? == 0 ))
then
  rm kernel
fi

cd $SRCF
SRC=( $(ls *.c *.s) )
cd ..

for ((i=0; i != ${#SRC[@]}; i++))
do
  $C $SRCF/${SRC[i]} -o bin/${SRC[i]}.o
  errCheck
done

$LD link.ld -o kernel bin/*.o
errCheck
echo "Build Complete"
