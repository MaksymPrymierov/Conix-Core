#ifndef KEYBOARD_H
#define KEYBOARD_H

/*
 * The function keyboardHandler() is keyboard interrupt handler
 * IRQ1
 */
void keyboardHandler(struct regs *r);

/*
 * The function keyboardInstall() passes point to interrupt
 * handler function in IDT
 */
void keyboardInstall();

#endif
