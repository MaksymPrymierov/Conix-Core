#ifndef KERNEL_SHELL_H
#define KERNEL_SHELL_H

#include "shellKeyboard.h"

/*
 * The function initKernelShell() initializes
 * the text buffer for the command shell.
 */
void initKernelShell();

/*
 * The fucntion shellHandlerHeyboard() handles keystrokes.
 */
void shellHandlerKeyboard(char* key);

#endif
