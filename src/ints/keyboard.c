#include "../../headers/conix.h"

void keyboardHandler(struct regs *r)
{
        shellHandlerKeyboard(getKey(inb(0x60)));
}

void keyboardInstall()
{
        irqInstallHandler(1, keyboardHandler);
}
