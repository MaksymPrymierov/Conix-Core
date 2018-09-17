#include <stdint.h>
#include "../../headers/io/screen.h"


void textGraphickInit(){
  vidptr = (char*)VIDEO_MEM;
  i = 0;
  j = 0;

  setScreenTextColor(LIGHT_GREY);
  clearTextGraphickScreen();
}

void setScreenTextColor(uint8_t color){
  screenTextColor = color;
}

void clearTextGraphickScreen(){
  while(i < TEXT_LINE_NUMBERS * TEXT_COLLUM_NUMBERS){
    textGraphickPutChar(' ');
  }

  j = 0;
  i = 0;
}

void textGraphickPutChar(char c){
  switch(c){
    case '\n':
      textGraphickNewLine();
      break;
    default:
      vidptr[i]   = c;
      vidptr[i+1] = screenTextColor;
      i += 2;
  }
}

void textGraphickDeleteChar(){
  if(i > 1){
    vidptr[i - 2] = ' ';
    i -= 2;
  }
}

void textGraphickNewLine(){
  int buffer = 0;
  buffer = i / TEXT_COLLUM_NUMBERS;

  if(buffer == 0)
    buffer = TEXT_COLLUM_NUMBERS - i;
  else{
    buffer = TEXT_COLLUM_NUMBERS * (buffer + 1);
    buffer = buffer - i;
  }

  i = i + buffer - 2;
}
