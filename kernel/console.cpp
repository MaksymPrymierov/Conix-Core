// SPDX-License-Identifier: GPL-3.0-only
/* -*- ConixCore -*- ------------------------------------------------------- *
 *
 *   Copyright (C) 2021 Maksym Prymierov
 *
 * ------------------------------------------------------------------------- */

#include <kernel/console.h>

#include <kernel/tty.h>

namespace conix {
namespace kernel {
namespace io {

static tty* _out;
static tty* _in;

void set_tty_out(tty* out)
{
        _out = out;
}

void set_tty_in(tty* in)
{
        _in = in;
}

tty& out()
{
        return (*_out);
}

tty& in()
{
        return (*_in);
}

}; // io
}; // kernel
}; // conix
