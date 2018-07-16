#ifndef CONIXCORE_KEY
#define CONIXCORE_KEY

static inline uint8_t inb(uint16_t port);
char getScancode();
void writeKey(char hex, short color);

#endif
