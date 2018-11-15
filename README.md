CONIX CORE
==========

  This is the monolithic core of the operating system under the x86 architecture.

Installation
------------

  To install the kernel will require the so-called cross-compiler. The script
  for installing a cross-compiler is called "installCompiler.sh". But since the
  cross-compiler will be built from sources, the following dependencies will be
  required ...

### Cross-compiler installation requirements

  * A Unix-like environment.
  * Enough memory and hard disk space.
  * GCC
  * G++    
  * Make  
  * Bison
  * Flex
  * GMP
  * MPFR
  * MPC
  * Texinfo
  * ISL
  * CLooG

#### Installing cross compiler

  * Install the above dependencies.
  * Launch ./installCompiler.sh

### Kernel Installation Requirements

  * A Unix-line environment which qemu or grub bootloader.
  
#### Installing kernel

  * Install cross compiler
  * Launch ./buils.sh
  
##### If run through qemu
  
  * Install qemu-kvm
  * Install qemu
  * Install virt-manager
  * Install virt-viewer
  * Install libvirt-bin
  * Launch ./start.sh

##### If run through grub

  * Copy the "kernel" file to the folder /boot and name it conix.
  * Open the file /boot/grub.сfg with root rights.
  * Add lines to the end of the file ...
  ```
    menuentry 'Conix' {
     set root='hd0,msdos1'
     multiboot /boot/conix ro
    }
  ```
  * Restart the computer and select conix from the list.
