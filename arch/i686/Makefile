KERNEL_OBJECTS += \
	out/arch/i686/text_graphic.o \
	out/arch/i686/kernel.o

out/arch/i686/kernel.o: arch/i686/kernel.c
	${CC} ${CC_FLAGS} $^ -o ${@}

out/arch/i686/boot.o: arch/i686/boot.s
	${CC} ${CC_FLAGS} $^ -o ${@}

out/arch/i686/text_graphic.o: arch/i686/text_graphic.c
	${CC} ${CC_FLAGS} $^ -o ${@}