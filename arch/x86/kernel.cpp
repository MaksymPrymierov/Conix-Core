// SPDX-License-Identifier: GPL-3.0-only
/* -*- ConixCore -*- ------------------------------------------------------- *
 *
 *   Copyright (C) 2019-2021 Maksym Prymierov
 *
 * ------------------------------------------------------------------------- */

#include <tty.h>
#include <gdt.h>
#include <idt.h>
#include <heap.h>
#include <keyboard.h>
#include <kernel/tests/list.h>
#include <kernel/tests/queue.h>
#include <kernel/tests/vector.h>
#include <kernel/tests/string.h>
#include <kernel/tests/binary_tree.h>
#include <kernel/tests/map.h>

#include "config/config.h"

int main(void* heap_top, void* heap_bottom)
{
        conix::kernel::io::tty log;

        log.clear();

        log << KERNEL_NAME << " " << KERNEL_VERSION << " " << 
               KERNEL_LICENSE << "\n";
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
        conix::kernel::tests::test_binary_tree test_bt;
        conix::kernel::tests::test_map test_m;

        conix::kernel::std::string s;

        while (1) {
                log << "Enter the test name to start: ";
                log >> s;

                if (s == "vector") {
                        test_v.start();
                } else if (s == "string") {
                        test_s.start();
                } else if (s == "list") {
                        test_l.start();
                } else if (s == "queue") {
                        test_q.start();
                } else if (s == "binary_tree") {
                        test_bt.start();
                } else if (s == "map") {
                        test_m.start();
                } else {
                        log << "Test not found\n";
                }
        }
        return 0;
}
