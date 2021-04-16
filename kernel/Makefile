# SPDX-License-Identifier: GPL-3.0-only
#-*- ConixCore -*- -------------------------------------------------------
#
#   Copyright (C) 2019-2021 Maksym Prymierov
#
#-------------------------------------------------------------------------

OBJ := out/kernel
SRC := kernel
LOCAL_CC_FLAGS += -Iinclude
C_BUILD := ${CC} ${CC_FLAGS} ${LOCAL_CC_FLAGS}

KERNEL_OBJECTS += \
	${OBJ}/kernel_lib.o \
	${OBJ}/memory.o \
	${OBJ}/tty.o \
	${OBJ}/console.o \

${OBJ}/kernel_lib.o: ${SRC}/kernel_lib.cpp
	${C_BUILD} $^ -o ${@}

clean-kernel_lib: ${OBJ}/kernel_lib.o
	rm ${^}

${OBJ}/memory.o: ${SRC}/memory.cpp
	${C_BUILD} $^ -o ${@}

${OBJ}/tty.o: ${SRC}/tty.cpp
	${C_BUILD} $^ -o ${@}

${OBJ}/console.o: ${SRC}/console.cpp
	${C_BUILD} $^ -o ${@}
