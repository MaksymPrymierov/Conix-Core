#ifndef SHELLKEYBOARD_H
#define SHELLKEYBOARD_H

#define setKeyboardBuffer(x) strcat(keyboardBuffer, x);
#define deleteCharKeyboardBuffer() keyboardBuffer[strlen(keyboardBuffer) - 1] = '\0';

char *keyboardBuffer;

void initKeyboardBuffer();
void clearKeyboardBuffer();

#endif
