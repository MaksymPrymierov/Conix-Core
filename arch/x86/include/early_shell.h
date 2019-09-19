#ifndef EARLY_SHELL_H
#define EARLY_SHELL_H

#include <kernel/types.h>

struct early_shell_data
{
        const char* user_name;
        int (*printf) (const char*, ...);
};

extern void early_shell_init_session(struct early_shell_data* data);

#endif
