#ifndef SHELLKEYBOARD_H
#define SHELLKEYBOARD_H

/*
 * Sets the key pressed in the buffer.
 */
#define setKeyboardBuffer(x) strcat(keyboardBuffer, x);

/*
 * Removes one character from the text buffer.
 */
#define deleteCharKeyboardBuffer() keyboardBuffer[strlen(keyboardBuffer) - 1] = '\0';

char* keyboardBuffer;

/*
 * Returns the text ID of a key by its numeric code.
 */
char* getKey();

/*
 * Initializes the text buffer.
 */
void initKeyboardBuffer();

/*
 * Clears the text buffer.
 */
void clearKeyboardBuffer();

#endif
