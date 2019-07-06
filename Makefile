ifndef ARCH
	ARCH := i686
endif
CC := /usr/local/cross/bin/${ARCH}-elf-gcc
LD := /usr/local/cross/bin/${ARCH}-elf-ld
ifndef CC_FLAGS
	CC_FLAGS := -O2 -mno-red-zone -nostdlib -lgcc -static-libgcc -std=c99 -Iinclude -c
endif 

KERNEL_OBJECTS := arch/${ARCH}/boot.o

all: out/out_check out/arch/${ARCH}/kernel.bin

include Check.mk
include arch/${ARCH}/Makefile

out/arch/${ARCH}/kernel.bin: out/${KERNEL_OBJECTS}
	${LD} -T link.ld -o ${@} ${^}

clean:
	rm -rfv ./out