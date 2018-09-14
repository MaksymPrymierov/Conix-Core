#ifndef CONIXCORE_IO
#define CONIXCORE_IO

#define LINE_NUMBERS 25
#define COLLUM_NUMBERS 160

/* ======= Examples of colors (chort color) =======
 * 0x00 - Example number
 * The first byte indicates the background color.
 * The second is for the color of the text.
 * =============== Table of colors ================
 *     0 - Black, 1 - Blue, 2 - Green, 3 - Cyan,
 *     4 - Red, 5 - Magenta, 6 - Brown,
 *     7 - Light Grey, 8 - Dark Grey, 9 - Light Blue,
 *     10/a - Light Green, 11/b - Light Cyan,
 *     12/c - Light Red, 13/d - Light Magenta,
 *     14/e - Light Brown, 15/f – White.
 * ====================== END ======================
 */

char screenBuffer[LINE_NUMBERS][COLLUM_NUMBERS];

void initScreen(short color);
/*
 * The function fills 0x8000 with a space character.
 */
void clearScreen(short color);
/*
 * The function fills 0x8000 with the variable char* 
 * and colors the text in color in the variable (short color).
 */
void printText(char *str, short color);
/*
 * The function fills conventions (int in) into an char* 
 * and outputs 0x8000 and colors the color of (shart color).
 */
void printNumber(int n, short color);
void deleteSyn(short color);
#endif
