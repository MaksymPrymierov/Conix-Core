#include <tty.h>
#include <gdt.h>
#include <idt.h>
#include <heap.h>
#include <kernel/tests/vector.h>
#include <kernel/vector.h>

int main(void* heap_top, void* heap_bottom)
{
        tty log;

        log.clear();

        log << "tty: Text graphics has been initialized.\n";

        gdt_init();
        log << "gdt: GDT tables has been initialized.\n";
        
        idt_install();
        log << "idt: IDT tables has been installed.\n";

        isrs_install();
        log << "idt: ISR tables has been installed.\n";

        irq_install();
        log << "idt: IRQ tables has been installed.\n";

        heap_init(heap_top, heap_bottom);
        log << "memory: Heap has been initialized.\n";

        test_vector test_v;
        test_v.start();

        return 0;
}
