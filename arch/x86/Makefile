KERNEL_OBJECTS += \
	out/arch/${ARCH}/text_graphic.o \
	out/arch/${ARCH}/kernel.o

out/arch/${ARCH}/kernel.o: arch/${ARCH}/kernel.c
	${CC} ${CC_FLAGS} $^ -o ${@}

out/arch/${ARCH}/boot.o: arch/${ARCH}/boot.s
	${CC} ${CC_FLAGS} $^ -o ${@}

out/arch/${ARCH}/text_graphic.o: arch/${ARCH}/text_graphic.c
	${CC} ${CC_FLAGS} $^ -o ${@}
