#include <stdint.h>
#include <stdarg.h>
#include "../../headers/stdlib/stddef.h"
#include "../../headers/stdlib/string.h"
#include "../../headers/io/screen.h"
#include "../../headers/stdlib/stdio.h"

void print(unsigned int num, const char* text){
  unsigned int buff = num;
  num++;
  while(num--){
    if(strlen(text) < buff - num)
      return;

    textGraphickPutChar(text[buff - num]);
  }
}

void printf(const char* maket, ...){
  va_list args;
  va_start(args, maket);

  print(strlen(maket), maket);
  
  va_end(args);
}
