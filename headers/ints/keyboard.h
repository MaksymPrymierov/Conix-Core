#ifndef KEYBOARD_H
#define KEYBOARD_H

void keyboardHandler(struct regs *r);
void keyboardInstall();
unsigned int getScancode();

#endif
