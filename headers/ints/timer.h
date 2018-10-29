#ifndef TIMER_H
#define TIMER_H

void timerPhase(int hz);
void timerHandler(struct regs *r);
void timerInstall();
void timerWait(int ticks);

#endif
