#include "../../headers/sys/sys.h"
#include "../../headers/ints/ints.h"
#include "../../headers/io/ports.h"
#include "../../headers/stdlib/stdlib.h"

int timerTicks = 0;

void timerPhase(int hz){
  int divisor = 1193180;
  outb(0x43, 0x36);
  outb(0x40, divisor & 0xFF);
  outb(0x40, divisor >> 8);
}

void timerHandler(struct regs *r){
  ++timerTicks;
  if(timerTicks % 18 == 0){
    printf("%d", "timer");
  }
}

void timerInstall(){
  irqInstallHandler(0, timerHandler);
}

void timerWait(int ticks){
  unsigned long eticks;

  eticks = timerTicks + ticks;
  while(timerTicks < eticks);
}
