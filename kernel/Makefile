OBJ := out/kernel
SRC := kernel
LOCAL_CC_FLAGS := -Iarch/${ARCH}/include
C_BUILD := ${CC} ${CC_FLAGS} ${LOCAL_CC_FLAGS}

KERNEL_OBJECTS += \
	${OBJ}/kernel_lib.o \
	${OBJ}/memory.o \
	${OBJ}/shell.o \

${OBJ}/kernel_lib.o: ${SRC}/kernel_lib.cpp
	${C_BUILD} $^ -o ${@}

${OBJ}/memory.o: ${SRC}/memory.cpp
	${C_BUILD} $^ -o ${@}

${OBJ}/shell.o: ${SRC}/shell.cpp
	${C_BUILD} $^ -o ${@}
