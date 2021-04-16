// SPDX-License-Identifier: GPL-3.0-only
/* -*- ConixCore -*- ------------------------------------------------------- *
 *
 *   Copyright (C) 2021 Maksym Prymierov
 *
 * ------------------------------------------------------------------------- */

#include <kernel/tty.h>

namespace conix {
namespace kernel {
namespace io {

void set_tty_out(tty* out);
void set_tty_in(tty* in);

tty& out();
tty& in();

}; // io
}; // kernel
}; // io
