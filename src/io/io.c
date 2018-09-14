#include "../../headers/io/io.h"
#include "../../headers/stdlib/stdlib.h"

char *vidptr = (char*)0xb8000;
unsigned int i = 0;
unsigned int j = 0;

void clearScreen(short color){
  while(j < LINE_NUMBERS * COLLUM_NUMBERS){
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
      buffer = i / COLLUM_NUMBERS;

      if(buffer == 0)
        buffer = COLLUM_NUMBERS - i; 
      else{
        buffer = COLLUM_NUMBERS * (buffer + 1);
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

void deleteSyn(short color) {
  vidptr[i-2] = ' ';
  vidptr[i-1] = color;

  i = i - 2;
}

void printNumber(int n, short color){
  char* s;
  itoa(n, s, 10);
  printText(s, color);
}
