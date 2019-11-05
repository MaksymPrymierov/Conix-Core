#include <kernel/kernel_lib.h>

size_t strlen(const char *string)
{
        const char *eos = string;
        while (*eos++);
        return (size_t)(eos - string - 1);
}
