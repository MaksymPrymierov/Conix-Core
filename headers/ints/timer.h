#ifndef TIMER_H
#define TIMER_H

/*
 * The function timerPhase() selects the timer phase.
 */
void timerPhase(int hz);

/*
 * The function timerHandler() is a timer interrupt handler.
 * IRQ0
 */
void timerHandler(struct regs *r);

/*
 * The function timerInstall() sets the pointer to the timer
 * interrupt handler function in IDT.
 */
void timerInstall();

/*
 * The function timerWait() will be executed until the
 * specified time is reached.
 */
void timerWait(int ticks);

#endif
