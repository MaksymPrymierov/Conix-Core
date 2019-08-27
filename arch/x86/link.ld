OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH(i386)
ENTRY(_start)
SECTIONS
{
        . = 0;
        .bstext         : { *(.bstext) }
        .bsdata         : { *(.bsdata) }                

        . = 495;
        .multiboot      : { *(.multiboot) }
        .inittext       : { *(.inittext) }
        .initdata       : { *(.initdata) }
        __end_init = .;

        .text           : { *(.text) }
        .text32         : { *(.text32) }

        . = ALIGN(16);
        .rodata         : { *(.rodata*) }

        . = ALIGN(16);
        .data           : { *(.data*) }

        . = ALIGN(16);
        .bss            :
        {
                __bss_start = .;
                *(.bss)
                __bss_end = .;
        }
        . = ALIGN(16);
        _end = .;
}
