#ifndef CONIXCORE_GDT
#define CONIXCORE_GDT

#include <stdint.h>
 
#define CX_PIC_FIRST_PORT_1 0x20
#define CX_PIC_FIRST_PORT_2 0x21

#define CX_PIC_SECND_PORT_1 0xA0
#define CX_PIC_SECND_PORT_2 0xA1

#define IRQ_HANDLER(name) void name(); \
	asm(#name ": pusha \n call _" #name " \n movb $0x20, %al \n outb %al, $0x20 \n outb %al, $0xA0 \n popa \n iret"); \
	void _ ## name()

#define SYSCALL_IRQ_HANDLER(name) void name(); \
asm(#name ": pusha \n call _" #name " \n movb $0x20, %al \n outb %al, $0x20 \n outb %al, $0xA0 \n popa \n iret"); \
	void _ ## name()

void set_int_handler(uint8_t index, void *handler, uint8_t type);

//Check if interrupts table written
static inline _Bool isInterruptsWrk()
{
    unsigned long flags;
    asm volatile ( "pushf\n\t"
                   "pop %0"
                   : "=g"(flags) );
    return flags & (1 << 9);
}

typedef struct {
	uint16_t address_0_15;
	uint16_t selector;
	uint8_t reserved;
	uint8_t type;
	uint16_t address_16_31;
} __attribute__((packed)) IntDesc;

typedef struct {
	uint16_t limit;
	void *base;
} __attribute__((packed)) IDTR;

typedef struct {
	uint16_t limit0_15;
	uint16_t base0_15;

	uint8_t base16_23;
	uint8_t accessFlags;
	uint8_t limit16_19:4;
	uint8_t granularity:4;
	uint8_t base24_31;
}__attribute__((packed)) GDT_ENTRY;

typedef struct {
	uint16_t limit;
	uint32_t base;
}__attribute__((packed)) GDT_DESC;

void enableGDT();
void GDT_setEntryProperties(uint32_t id, uint32_t base, uint32_t limit, uint8_t accessFlags, uint8_t granularity);
extern void load_gdt(uint32_t);
extern _Bool checkA20();
//Prepare PIC for STI, (modify interrupts vectors to 0x20, 0xA0)
void enableInterrupts();
//turn A20 line On
void enableA20();

#endif
