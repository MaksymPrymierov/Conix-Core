#include <bios.h>

#define X86_EFLAGS_CF 0x1

void init_regs_bios(struct bios_regs *regs)
{
        memset(regs, 0, sizeof(*regs));
        regs->eflags |= X86_EFLAGS_CF;
        regs->ds = ds();
        regs->es = ds();
        regs->fs = fs();
        regs->gs = gs();
}
