#ifndef SCREEN_H
#define SCREEN_H

/* Table of color */
#define BLACK         0x00
#define BLUE          0x01
#define GREEN         0x02
#define CYAN          0x03
#define RED           0x04
#define MAGENTA       0x05
#define BROWN         0x06
#define LIGHT_GREY    0x07
#define DARK_GREY     0x08
#define LIGHT_BLUE    0x09
#define LIGHT_GREEN   0x0A
#define LIGHT_CYAN    0x0B
#define LIGHT_RED     0x0C
#define LIGHT_MAGENTA 0x0D
#define LIGHT_BROWN   0x0E
#define WHITE         0x0F

/*
 * Tect video memory address.
 */
#define VIDEO_MEM 0xB8000

/*
 * Maximum number of lines in text mode.
 */
#define TEXT_LINE_NUMBERS   25

/* 
 * Maximum number of collum in text mode.
 */
#define TEXT_COLLUM_NUMBERS 160

/*
 * Address of the beginning of the data displayed.
 */
#define START_VIDEO_BUFFER  160

/*
 * Maximum number of characters on the screen.
 */
#define OUTPUT_MAP TEXT_LINE_NUMBERS * TEXT_COLLUM_NUMBERS

/*
 * Sets the background color and text.
 */
#define setScreenTextColor(x) screenTextColor = x;

/*
 * Video memory buffer data from which are 
 * transferred to the video memory
 */
char screenTextBuffer[OUTPUT_MAP * 2];

/*
 * The current position of the cursor on the screen.
 */
unsigned int cursorPos;

/*
 * Pointer to video memory
 */
char *vidptr;

/*
 * Current text and background colors.
 */
uint8_t screenTextColor;

/*
 * The function textGraphickInit() sets
 * the pointer to the text memory,
 * sets the text and background color
 * and clears the screen.
 */
void textGraphickInit();

/*
 * clears the video buffer and sets the
 * cursor to the starting position.
 */
void clearTextGraphickScreen();

/*
 * Writes one character (char c) to the
 * video buffer and moves the cursor one position.
 */
void textGraphickPutChar(char c);

/*
 * Removes one character from the video buffer 
 * and returns the cursor one position.
 */
void textGraphickDeleteChar();

/*
 * Moves data from the video buffer starting from
 * the 160th position to the video memory.
 */
void updateScreen();

/*
 * Moves the cursor and text output to a new line.
 */
void textGraphickNewLine();

/*
 * Moves the cursor one position.
 */
void moveCursor();

#endif
