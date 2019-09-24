#ifndef THEADS_H
#define THEADS_H

extern void last_intraction(void* stack);
extern void execute_task(void* adress, void* stack);
extern void switch_task(void);
extern void thead_init(int i);

#endif
