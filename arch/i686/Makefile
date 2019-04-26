arch/${ARCH}/kernel.bin: ${O}arch/${ARCH}/kernel.o ${O}arch/${ARCH}/boot.o
	${LD} -T link.ld -o ${@} ${^}

arch/${ARCH}/kernel.o: arch/${ARCH}/kernel.c
	${CC} ${CC_FLAGS} $^ -o ${@}

arch/${ARCH}/boot.o: arch/${ARCH}/boot.s
	${CC} ${CC_FLAGS} $^ -o ${@}