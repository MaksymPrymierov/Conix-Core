export ARCH=i686
export CC=/usr/local/cross/bin/${ARCH}-elf-gcc
export LD=/usr/local/cross/bin/${ARCH}-elf-ld
export CC_FLAGS=-O2 -ffreestanding -mno-red-zone -nostdlib -lgcc -std=c99 -c 

all: arch/${ARCH}/kernel.bin

include arch/${ARCH}/Makefile

clean:
	rm -rfv ${O}arch/i686/{*.bin,*.o}