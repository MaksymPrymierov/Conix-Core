#include "../../headers/sys/sys.h"
#include "../../headers/ints/ints.h"
#include "../../headers/stdlib/stdlib.h"
#include "../../headers/io/io.h"

unsigned int scancode;

void keyboardHandler(struct regs *r){
  scancode = inb(0x60);
}

void keyboardInstall(){
  irqInstallHandler(1, keyboardHandler);
}

unsigned int getScancode(){
  while (!(inb(0x64) & 1));
  return scancode;
}
