#ifndef CONIXCORE_KEY
#define CONIXCORE_KEY
char *bufTex;
#ifdef C_KEYBOARD
int bufTexNum = 0;
void clearBuffer();
void setTextBuffer(char s);
static inline uint8_t inb(uint16_t port);
#endif

char getScancode();
void writeKey(char hex);

#endif
