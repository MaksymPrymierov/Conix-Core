.global gdtFlush
.extern gp
gdtFlush:
        lgdt (gp)
        mov $0x10, %ax
        mov %ax, %ds
        mov %ax, %es
        mov %ax, %fs
        mov %ax, %gs
        mov %ax, %ss
        ljmp $0x08, $flush2
flush2:
        ret
