ifndef ARCH
	ARCH := x86
endif
CC := gcc
ASM := as
LD := ld
ifndef CC_FLAGS
	CC_FLAGS := -O2 -m32 -mno-red-zone -nostdlib -lgcc -static-libgcc \
		    -std=c99 -Iinclude -c -fno-stack-protector -Wall \
		    -Werror
endif 

KERNEL_OBJECTS := arch/${ARCH}/boot.o

all: out/out_check out/arch/${ARCH}/kernel.bin

include Check.mk
include arch/${ARCH}/Makefile
include kernel/Makefile

out/arch/${ARCH}/kernel.bin: out/${KERNEL_OBJECTS}
	${LD} -m elf_i386 -T arch/${ARCH}/link.ld -o ${@} ${^}

clean:
	rm -rfv ./out
