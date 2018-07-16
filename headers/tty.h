#ifndef CONIXCORE_TTY
#define CONIXCORE_TTY

char *tty[9];
unsigned short current_tty = 1;

void init_tty();
void change_tty();
void update_tty();
void save_buffer_tty();
void welcome_tty();
#endif
