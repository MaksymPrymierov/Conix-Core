# SPDX-License-Identifier: GPL-3.0-only
#-*- ConixCore -*- -------------------------------------------------------
#
#   Copyright (C) 2019-2021 Maksym Prymierov
#
#-------------------------------------------------------------------------

OBJ := out/kernel
SRC := kernel
LOCAL_CC_FLAGS := -Iarch/${ARCH}/include
C_BUILD := ${CC} ${CC_FLAGS} ${LOCAL_CC_FLAGS}

KERNEL_OBJECTS += \
	${OBJ}/kernel_lib.o \
	${OBJ}/memory.o \

${OBJ}/kernel_lib.o: ${SRC}/kernel_lib.cpp
	${C_BUILD} $^ -o ${@}

clean-kernel_lib: ${OBJ}/kernel_lib.o
	rm ${^}

${OBJ}/memory.o: ${SRC}/memory.cpp
	${C_BUILD} $^ -o ${@}
