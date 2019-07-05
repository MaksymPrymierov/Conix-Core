export ARCH=i686
export CC=/usr/local/cross/bin/${ARCH}-elf-gcc
export LD=/usr/local/cross/bin/${ARCH}-elf-ld
export CC_FLAGS=-O2 -mno-red-zone -nostdlib -lgcc -static-libgcc -std=c99 -Iinclude -c 

all: arch/${ARCH}/kernel.bin

include arch/${ARCH}/Makefile

clean:
	rm -rfv ${O}arch/i686/{*.bin,*.o}