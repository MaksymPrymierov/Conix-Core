#ifndef PORTS_H
#define PORTS_H

static inline void outl(uint16_t port, uint32_t val)
{
    asm volatile("outl %%eax, %%dx" :: "d" (port), "a"(val));
}

static inline void outb(uint16_t port, uint8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

static inline void outw(uint16_t port, uint16_t val)
{
    asm volatile ( "outw %%ax, %%dx" : : "a"(val), "d"(port) );
}

static inline uint32_t inl(uint16_t port)
{
    uint32_t ret;
    asm volatile ( "inl %%dx, %%eax"
                   : "=a"(ret)
                   : "d"(port) );
    return ret;
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

static inline uint16_t inw(uint16_t port)
{
    uint16_t ret;
    asm ( "inw %%dx, %%ax"
                   : "=a"(ret)
                   : "d"(port) );
    return ret;
}

void reboot_err();
#endif
