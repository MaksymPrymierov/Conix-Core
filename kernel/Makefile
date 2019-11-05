OBJ := out/kernel
SRC := kernel
LOCAL_CC_FLAGS := -Iarch/${ARCH}/include
C_BUILD := ${CC} ${CC_FLAGS} ${LOCAL_CC_FLAGS}

KERNEL_OBJECTS += \
	${OBJ}/kernel_lib.o \

${OBJ}/kernel_lib.o: ${SRC}/kernel_lib.cpp
	${C_BUILD} $^ -o ${@}

${OBJ}/queue.o: ${SRC}/queue.c
	${C_BUILD} $^ -o ${@}

${OBJ}/string.o: ${SRC}/string.c
	${C_BUILD} $^ -o ${@}

${OBJ}/test.o: ${SRC}/test.c
	${C_BUILD} $^ -o ${@}
