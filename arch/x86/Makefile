OBJ := out/arch/${ARCH}
SRC := arch/${ARCH}
LOCAL_CC_FLAGS := -I${SRC}/include
C_BUILD := ${CC} ${CC_FLAGS} ${LOCAL_CC_FLAGS}

KERNEL_OBJECTS += \
	${OBJ}/tty.o \
	${OBJ}/kernel.o \
#	${OBJ}/gdt.o \
#	${OBJ}/gdt.s.o \
#	${OBJ}/idt.o \
#	${OBJ}/idt.s.o \
#	${OBJ}/early_shell.o \
#	${OBJ}/keyboard.o \
#	${OBJ}/heap.o \
#	${OBJ}/asm.o \
#	${OBJ}/time.o

${OBJ}/kernel.o: ${SRC}/kernel.cpp
	${C_BUILD} $^ -o ${@}

${OBJ}/boot.o: ${SRC}/boot.s
	${C_BUILD} $^ -o ${@}

${OBJ}/tty.o: ${SRC}/tty.cpp
	${C_BUILD} $^ -o ${@}

${OBJ}/gdt.o: ${SRC}/gdt.c
	${C_BUILD} $^ -o ${@}

${OBJ}/gdt.s.o: ${SRC}/gdt.s
	${C_BUILD} $^ -o ${@}

${OBJ}/idt.o: ${SRC}/idt.c
	${C_BUILD} $^ -o ${@}

${OBJ}/idt.s.o: ${SRC}/idt.s
	${C_BUILD} $^ -o ${@}

${OBJ}/early_shell.o: ${SRC}/early_shell.c
	${C_BUILD} $^ -o ${@}

${OBJ}/keyboard.o: ${SRC}/keyboard.c
	${C_BUILD} $^ -o ${@}

${OBJ}/heap.o: ${SRC}/heap.c
	${C_BUILD} $^ -o ${@}

${OBJ}/asm.o: ${SRC}/asm.c
	${C_BUILD} $^ -o ${@}

${OBJ}/time.o: ${SRC}/time.c
	${C_BUILD} $^ -o ${@}
