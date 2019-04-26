#include <stdint.h>
#include "../../headers/io/io.h"

void textGraphickInit()
{
        vidptr = (char*)VIDEO_MEM;
        setScreenTextColor(LIGHT_GREY);
        clearTextGraphickScreen();
}

void scrollUp()
{
        unsigned int buffer = cursorPos;
        cursorPos = 0;

        while (cursorPos < OUTPUT_MAP) {
                screenTextBuffer[cursorPos] = screenTextBuffer[cursorPos + TEXT_COLLUM_NUMBERS];
                ++cursorPos;
        }

        cursorPos = buffer - TEXT_COLLUM_NUMBERS;
}

void clearTextGraphickScreen()
{
        cursorPos = 0;
        while (cursorPos < OUTPUT_MAP + 160) {
                screenTextBuffer[cursorPos] = ' ';
                screenTextBuffer[cursorPos+1] = screenTextColor;
                cursorPos += 2;
        }

        cursorPos = START_VIDEO_BUFFER;
}

void textGraphickPutChar(char c)
{
        switch (c) {
        case '\n':
                textGraphickNewLine();
                break;
        default:
                screenTextBuffer[cursorPos] = c;
                screenTextBuffer[cursorPos+1] = screenTextColor;
                cursorPos += 2;
        }

        if (cursorPos > OUTPUT_MAP) {
                scrollUp();
        }
}

void textGraphickDeleteChar()
{
        if (cursorPos > 1) {
                screenTextBuffer[cursorPos - 2] = ' ';
                cursorPos -= 2;
        }
}

void textGraphickNewLine()
{
        int buffer = 0;
        buffer = cursorPos / TEXT_COLLUM_NUMBERS;

        if (buffer == 0)
                buffer = TEXT_COLLUM_NUMBERS - cursorPos;
        else {
                buffer = TEXT_COLLUM_NUMBERS * (buffer + 1);
                buffer = buffer - cursorPos;
        }

        cursorPos += buffer;
}

void updateScreen()
{
        for (int i = 0; i < OUTPUT_MAP; ++i) {
                vidptr[i] = screenTextBuffer[i];
        }
  
        moveCursor();
}

void moveCursor()
{
        int temp = cursorPos / 2;

        outb(0x3d4, 14);
        outb(0x3d5, temp >> 8);
        outb(0x3d4, 15);
        outb(0x3d5, temp);
}
