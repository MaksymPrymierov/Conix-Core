OBJ := out/arch/${ARCH}
SRC := arch/${ARCH}
LOCAL_CC_FLAGS := -I${SRC}/include
C_BUILD := ${CC} ${CC_FLAGS} ${LOCAL_CC_FLAGS}

KERNEL_OBJECTS += \
	${OBJ}/tty.o \
	${OBJ}/kernel.o \
	${OBJ}/gdt.o \
	${OBJ}/gdt.s.o

${OBJ}/kernel.o: ${SRC}/kernel.c
	${C_BUILD} $^ -o ${@}

${OBJ}/boot.o: ${SRC}/boot.s
	${C_BUILD} $^ -o ${@}

${OBJ}/tty.o: ${SRC}/tty.c
	${C_BUILD} $^ -o ${@}

${OBJ}/gdt.o: ${SRC}/gdt.c
	${C_BUILD} $^ -o ${@}

${OBJ}/gdt.s.o: ${SRC}/gdt.s
	${C_BUILD} $^ -o ${@}
