#!/bin/bash

errCheck(){
	if (( $? != 0 ))
	then
		print "ERROR"
		exit $?
	fi
}

printf "Start instaling compiller gcc and g++ for i686-elf and binutils\n"
mkdir -v $HOME/conix-compiller
errCheck
cd $HOME/conix-compiller

printf "Download binutils src\n"
wget https://ftp.gnu.org/gnu/binutils/binutils-2.31.1.tar.xz
errCheck

printf "Extract src binutils\n"
tar -xvf binutils-*
errCheck

printf "Download gcc src\n"
wget https://ftp.gnu.org/gnu/gcc/gcc-8.2.0/gcc-8.2.0.tar.gz
errCheck

printf "Extract src gcc\n"
tar -xvf gcc-*
errCheck

printf "Preparation...\n"
sudo mkdir -v /usr/local/cross
errCheck
export PREFIX="/usr/local/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

printf "Configure binutils\n"
mkdir -v build-binutils
errCheck
cd build-binutils
../binutils-2.31.1/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
errCheck

printf "Start compile binutils\n"
make
errCheck

printf "Install binutils\n"
sudo make install
errCheck
printf "Install binutils complete"

printf "Configure gcc"
cd $HOME/conix-compiller
which -- $TARGET-as || echo $TARGET-as is not in the PATH
errCheck
mkdir -v build-gcc
errCheck
cd build-gcc
../gcc-8.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
errCheck

printf "Start compile gcc"
make all-gcc
errCheck
make all-target-libgcc
errCheck
sudo make install-gcc
errCheck
sudo make install-target-libgcc
errCheck

printf "Build complite"
exit 0
