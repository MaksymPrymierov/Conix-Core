define path_
${O}arch/${ARCH}/$(file)
endef

arch/${ARCH}/kernel.bin: ${path_}kernel.o ${path_}boot.o ${path_}text_graphic.o
	${LD} -T link.ld -o ${@} ${^}

arch/${ARCH}/kernel.o: ${path_}kernel.c
	${CC} ${CC_FLAGS} $^ -o ${@}

arch/${ARCH}/boot.o: ${path_}boot.s
	${CC} ${CC_FLAGS} $^ -o ${@}

arch/${ARCH}/text_graphic.o: ${path_}text_graphic.c
	${CC} ${CC_FLAGS} $^ -o ${@}