#ifndef CONIXCORE_SCREEN
#define CONIXCORE_SCREEN

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

#define VIDEO_MEM 0xB8000

#define TEXT_LINE_NUMBERS   25
#define TEXT_COLLUM_NUMBERS 160
#define START_VIDEO_BUFFER  160

char screenTextBuffer[TEXT_LINE_NUMBERS * TEXT_COLLUM_NUMBERS * 2];
unsigned int cursorPos;
unsigned int i;
char *vidptr;
uint8_t screenTextColor;

void textGraphickInit();
void clearTextGraphickScreen();
void textGraphickPutChar(char c);
void textGraphickDeleteChar();
void updateScreen();
void textGraphickNewLine();

inline void setScreenTextColor(uint8_t color){
  screenTextColor = color;
}

#endif
