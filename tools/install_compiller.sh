#! /bin/bash

PREFIX=/usr/local/cross
WORKDIR=$(pwd)
B_VER=2.32
G_VER=9.1.0

error()
{
        if (( $? != 0 ))
        then
                printf "error: $1"
                exit $?
        fi
}

info()
{
        printf "info: $1"
}

prepare()
{
        if ! [ -d ${WORKDIR}/build ]
        then
                mkdir -v ${WORKDIR}/build
                error "Cannot to create ${WORKDIR}/build directory\n"
        else
                info "${WORKDIR}/build directory already exists\n"
        fi

        if ! [ -d ${PREFIX} ]
        then
                sudo mkdir -v ${PREFIX}
                error "Cannot to create ${PREFIX} directory\n"
        else
                info "${PREFIX} directory already exists\n"
        fi
}

fetch()
{
        if ! [ -f ${WORKDIR}/build/binutils.tar.xz ]
        then
                wget -O ${WORKDIR}/build/binutils.tar.xz https://ftp.gnu.org/gnu/binutils/binutils-${B_VER}.tar.xz
                error "Cannot to download binutils-${B_VER}\n"
        else
                info "binutils-${B_VER} already downloaded\n"
        fi

        if ! [ -f ${WORKDIR}/build/gcc.tar.xz ]
        then
                wget -O ${WORKDIR}/build/gcc.tar.xz https://ftp.gnu.org/gnu/gcc/gcc-${G_VER}/gcc-${G_VER}.tar.xz
                error "Cannot to download gcc-${G_VER}\n"
        else
                info "gcc-${B_VER} already downloaded\n"
        fi
}

extract()
{       
        if ! [ -d ${WORKDIR}/build/binutils-${B_VER} ]
        then
                tar -xvf ${WORKDIR}/build/binutils.tar.xz -C ${WORKDIR}/build
                error "Cannot to extract binutils.tar.xz\n"
        else
                info "binutils.tar.xz already extracted\n"
        fi

        if ! [ -d ${WORKDIR}/build/gcc-${G_VER} ]
        then
                tar -xvf ${WORKDIR}/build/gcc.tar.xz -C ${WORKDIR}/build
                error "Cannot to extract gcc.tar.xz\n"
        else
                info "gcc.tar.xz already extracted\n"
        fi
}

configure()
{
        printf "Enter the target architecture [x86_64-elf]\n"
        read ARCH

        OUTPUT=${PREFIX}/${ARCH}

        if ! [ -d ${OUTPUT} ]
        then
                sudo mkdir -v ${OUTPUT}
                error "Cannot to create ${OUTPUT} directory\n"
        else
                info "${OUTPUT} directory already exists\n"
        fi

        if ! [ -d ${WORKDIR}/build/build_binutils ]
        then
                mkdir -v ${WORKDIR}/build/build_binutils
                error "Cannot to create ${WORKDIR}/build/build_binutils directory\n"
        else
                info "${WORKDIR}/build/build_binutils directory already exists\n"
        fi

        if ! [ -d ${WORKDIR}/build/build_gcc ]
        then
                mkdir -v ${WORKDIR}/build/build_gcc
                error "Cannot to create ${WORKDIR}/build/build_gcc directory\n"
        else
                info "${WORKDIR}/build/build_gcc directory already exists\n"
        fi

        cd ${WORKDIR}/build/build_binutils
        ../binutils-${B_VER}/configure \
                --target=$ARCH \
                --prefix=$OUTPUT \
                --with-sysroot \
                --disable-werror \
                --enable-threads \
                --enable-shared \
                --with-pic \
                --enable-ld=default \
                --enable-gold \
                --enable-plugins \
                --enable-deterministic-archives \
                --disable-gdb \
                --disable-nls
        error "Cannot to configure binutils\n"

        cd ${WORKDIR}/build/build_gcc
        ../gcc-${G_VER}/configure \
                --target=$ARCH \
                --prefix=$OUTPUT \
                --disable-nls \
                --enable-languages=c \
                --without-headers \
                --target=$TARGET \
                --without-headers \
                --enable-shared \
                --enable-threads=posix \
                --enable-__cxa_atexit \
                --enable-clocale=gnu \
                --enable-gnu-unique-object \
                --enable-linker-build-id \
                --enable-lto \
                --enable-plugin \
                --with-linker-hash-style=gnu \
                --enable-gnu-indirect-function \
                --disable-multilib \
                --disable-werror \
                --enable-checking=release
	error "Cannot to configure gcc\n"
}

build()
{
        cd ${WORKDIR}/build/build_binutils
        make -j$(getconf _NPROCESSORS_ONLN)
        error "Cannot to build binutils\n"

        cd ${WORKDIR}/build/build_gcc
        make all-gcc -j$(getconf _NPROCESSORS_ONLN)
        error "Cannot to build gcc\n"
        make all-target-libgcc -j$(getconf _NPROCESSORS_ONLN)
        error "Cannot to build libgcc\n"
}

install()
{
        cd ${WORKDIR}/build/build_binutils
        sudo make install
        error "Cannot to install binutils\n"

        cd ${WORKDIR}/build/build_gcc
        sudo make install-gcc
        error "Cannot to install gcc\n"
        sudo make install-target-libgcc
        error "Cannot to install libgcc\n"
}

help()
{
        printf "Usage: $0 [OPTION]\n"
        printf "Script to install the compiler and binutils to build conix-core\n"
        printf "List of options\n"
        printf "  -p, --prepare\t\tprepare the workspace.\n"
        printf "  -f, --fetch\t\tdownload source code archives.\n"
        printf "  -e, --extract\t\textract source code from archivers.\n"
        printf "  -c, --configure\tconfigure the workspace before building.\n"
        printf "  -b, --build\t\tbuild compiler and binutils.\n"
        printf "  -i, --install\t\tinstall compiler and binutils after building.\n"
        printf "  -h, --help\t\tprint this help page.\t"
        printf "\nAuthor: Maksym Prymierov. Email: <primerovmax@gmail.com>. License: GNUv3.\n"
}

while [ -n "$1" ]
do
        case $1 in
                -p | --prepare)
                        prepare
                        break ;;
                -f | --fetch)
                        fetch
                        break ;;
                -e | --extract)
                        extract
                        break ;;
                -c | --configure)
                        configure
                        break ;;
                -b | --build)
                        build
                        break ;;
                -i | --install)
                        install
                        break ;;
                -h | --help)
                        help
                        break ;;
                *)
                        prepare
                        fetch
                        extract
                        configure
                        build
                        install
        esac
        shift
done

