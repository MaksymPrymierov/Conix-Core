#include <stdint.h>
#include "../../headers/io/io.h"

void textGraphickInit(){
  vidptr = (char*)VIDEO_MEM;
  i = 0;
  cursorPos = START_VIDEO_BUFFER;

  setScreenTextColor(LIGHT_GREY);
  clearTextGraphickScreen();
}

void scrollUp(){
  unsigned int buffer = cursorPos;
  cursorPos = 0;

  while(cursorPos < TEXT_LINE_NUMBERS * TEXT_COLLUM_NUMBERS){
    screenTextBuffer[cursorPos] = screenTextBuffer[cursorPos + TEXT_COLLUM_NUMBERS];
    ++cursorPos;
  }

  cursorPos = buffer - TEXT_COLLUM_NUMBERS;
  moveCursor();
}

void clearTextGraphickScreen(){
  cursorPos = 0;
  while(cursorPos < TEXT_LINE_NUMBERS * TEXT_COLLUM_NUMBERS + 160){
    screenTextBuffer[cursorPos] = ' ';
    screenTextBuffer[cursorPos+1] = screenTextColor;
    cursorPos += 2;
  }

  cursorPos = START_VIDEO_BUFFER;
  moveCursor();
}

void textGraphickPutChar(char c){
  switch(c){
    case '\n':
      textGraphickNewLine();
      break;
    default:
      screenTextBuffer[cursorPos] = c;
      screenTextBuffer[cursorPos+1] = screenTextColor;
      cursorPos += 2;
  }

  if(cursorPos > TEXT_COLLUM_NUMBERS * TEXT_LINE_NUMBERS) scrollUp();
  moveCursor();
}

void textGraphickDeleteChar(){
  if(cursorPos > 1){
    screenTextBuffer[cursorPos - 2] = ' ';
    cursorPos -= 2;
    moveCursor();
  }
}

void textGraphickNewLine(){
  int buffer = 0;
  buffer = cursorPos / TEXT_COLLUM_NUMBERS;

  if(buffer == 0)
    buffer = TEXT_COLLUM_NUMBERS - cursorPos;
  else{
    buffer = TEXT_COLLUM_NUMBERS * (buffer + 1);
    buffer = buffer - cursorPos;
  }

  cursorPos += buffer;
  moveCursor();
}

void updateScreen(){
  i = 0;

  while(i < TEXT_LINE_NUMBERS * TEXT_COLLUM_NUMBERS){
    vidptr[i] = screenTextBuffer[i];
    ++i;
  }

  i = 0;
}

void moveCursor(){
  int temp = cursorPos / 2;

  outb(0x3d4, 14);
  outb(0x3d5, temp >> 8);
  outb(0x3d4, 15);
  outb(0x3d5, temp);
}
