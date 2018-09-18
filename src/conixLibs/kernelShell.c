#include <stdint.h>
#include "../../headers/stdlib/stddef.h"
#include "../../headers/io/keyboard.h"
#include "../../headers/io/screen.h"
#include "../../headers/stdlib/stdio.h"
#include "../../headers/stdlib/string.h"
#include "../../headers/conixLibs/kernelShell.h"

char *bufTex = "";

void clearBuffer(){
  size_t len = strlen(bufTex);
  for(size_t i = 0; i < len + 1; i++){
    bufTex[i] = ' ';
  }
  bufTex[0] = '\0';
}

void setTextBuffer(char *s){
  strcat(bufTex, s);
}

void shellFunctionHelp(){
  printf("%s", "\nIt is help page for kernel shell");
}

void checkShellFunction(){
  if(!strcmp(bufTex, "help")){
    shellFunctionHelp();
  }
}

void handlerKeyboard(char* key){
  if(strlen(key) == 1){
    textGraphickPutChar(key[0]);
    setTextBuffer(key);
  } else if(!strcmp(key, "backspace")){
    textGraphickDeleteChar();
  } else if(!strcmp(key, "right_enter")){
    checkShellFunction();
    clearBuffer();

    textGraphickNewLine();
    textGraphickPutChar('#');
    textGraphickPutChar(' ');
  }
}

void initKernelShell(){
  printf("%s", "Load kernel command shell\n# ");
  while(1){
    handlerKeyboard(getKey());
//    writeKey(getScancode());
  }
}
