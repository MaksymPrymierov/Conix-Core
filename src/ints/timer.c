#include "../../headers/conix.h"

int timerTicks = 0;

void timerPhase(int hz){
  int divisor = 1193180;
  outb(0x43, 0x36);
  outb(0x40, divisor & 0xFF);
  outb(0x40, divisor >> 8);
}

void timerHandler(struct regs *r){
    ++timerTicks;

    updateScreen();
}

void timerInstall(){
  irqInstallHandler(0, timerHandler);
}

void timerWait(int ticks){
  unsigned long eticks;

  eticks = timerTicks + ticks;
  while(timerTicks < eticks);
}
