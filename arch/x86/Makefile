OBJ=out/arch/${ARCH}

KERNEL_OBJECTS += \
	${OBJ}/text_graphic.o \
	${OBJ}/kernel.o \
	${OBJ}/bios.o \
	${OBJ}/tty.o

${OBJ}/kernel.o: arch/${ARCH}/kernel.c
	${CC} ${CC_FLAGS} $^ -o ${@}

${OBJ}/boot.o: arch/${ARCH}/boot.s
	${CC} ${CC_FLAGS} $^ -o ${@}

${OBJ}/text_graphic.o: arch/${ARCH}/text_graphic.c
	${CC} ${CC_FLAGS} $^ -o ${@}

${OBJ}/bios.o: arch/${ARCH}/bios.c
	${CC} ${CC_FLAGS} $^ -o ${@}

${OBJ}/tty.o: arch/${ARCH}/tty.c
	${CC} ${CC_FLAGS} $^ -o ${@}
