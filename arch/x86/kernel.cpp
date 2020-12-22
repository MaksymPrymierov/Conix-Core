#include <tty.h>
#include <gdt.h>
#include <idt.h>
#include <heap.h>
#include <keyboard.h>
#include <kernel/tests/list.h>
#include <kernel/tests/queue.h>
#include <kernel/tests/vector.h>
#include <kernel/tests/string.h>

int main(void* heap_top, void* heap_bottom)
{
        conix::kernel::io::tty log;

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

        conix::kernel::tests::test_vector test_v;
        conix::kernel::tests::test_string test_s;
        conix::kernel::tests::test_list test_l;
        conix::kernel::tests::test_queue test_q;

        test_v.start();
        test_s.start();
        test_l.start();
        test_q.start();

        size_t key_code;
        char symbol[2] = {'\0'};
        bool symbol_mode = false;
        conix::kernel::arch::x86::keyboard k;
        k.enable_int();

        while (1) {
                if (symbol_mode) {
                        if (!k.empty()) {
                                symbol[0] = k.get_key();

                                if (symbol[0] == '`') {
                                        log << "\nsymbol mode has been disabled\n";
                                        symbol_mode = false;
                                        continue;
                                }

                                log << symbol;
                        }
                } else {
                        if (!k.empty()) {
                                key_code = k.get_key_number();

                                if (key_code == 1) {
                                        log << "\nsymbol mode has been enabled\n";
                                        symbol_mode = true;
                                        continue;
                                }

                                log << key_code << "\n";
                        }
                }
        }

        return 0;
}
