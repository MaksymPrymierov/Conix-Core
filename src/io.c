#include "../headers/stddef.h"
#include "../headers/string.h"
#include "../headers/stdlib.h"

char *vidptr = (char*)0xb8000;
unsigned int i = 0;
unsigned int j = 0;

void clearScreen(short color){
  while(j < 80 * 25 * 2){
    vidptr[j] = ' ';
    vidptr[j+1] = color;
    j = j + 2;
  }

  j = 0;
  i = 0;
}

void printText(char *str, short color){
  int buffer;

  while(str[j] != '\0'){
    if(str[j] == '\n'){
      buffer = 0;
      buffer = i / 160;

      if(buffer == 0)
        buffer = 160 - i; 
      else{
        buffer = 160 * (buffer + 1);
        buffer = buffer - i;
      }

      i = i + buffer - 2;

     } else{
        vidptr[i] = str[j];
      }

    vidptr[i+1] = color;
    ++j;
    i = i + 2;
  }

  j = 0;
}

void printNumber(int n, short color){
  char* s;
  itoa(n, s);
  printText(s, color);
}
