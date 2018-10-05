#include <stdint.h>
#include "../../headers/stdlib/stddef.h"
#include "../../headers/io/keyboard.h"
#include "../../headers/io/screen.h"
#include "../../headers/stdlib/stdio.h"
#include "../../headers/stdlib/string.h"
#include "../../headers/kernelShell/shellKeyboard.h"
#include "../../headers/kernelShell/kernelShell.h"

void shellFunctionHelp(){
  printf("%s", "\nIt is help page for kernel shell");
  printf("%s", "\n hello - print hello world");
  printf("%s", "\n clear - clear output");
  setScreenTextColor(RED);
  printf("%s", "\n satan - AVE SATAN");
  setScreenTextColor(LIGHT_GREY);
}

void shellFunctionHello(){
  printf("%s", "\nHello World!");
}

void shellFunctionClear(){
  clearTextGraphickScreen();
}

void shellFunctionSatan(){
  screenTextColor = RED;
  printf("%s", "\nAVE SATAN!!!");
  screenTextColor = LIGHT_GREY;
}

void checkShellFunction(){
  /*
  char* buffer = "";
  for(int i = 0; bufTex[i] != ' '; ++i){
    buffer[i] = bufTex[i];
  } */

  if(!strcmp(keyboardBuffer, "help")){
    shellFunctionHelp();
  }
  if(!strcmp(keyboardBuffer, "hello")){
    shellFunctionHello();
  }
  if(!strcmp(keyboardBuffer, "clear")){
    shellFunctionClear();
  }
  if(!strcmp(keyboardBuffer, "satan")){
    shellFunctionSatan();
  }
}

void handlerKeyboard(char* key){
  if(strlen(key) == 1){
    textGraphickPutChar(key[0]);
    setKeyboardBuffer(key);
  } else if(!strcmp(key, "backspace")){
    textGraphickDeleteChar();
    deleteCharKeyboardBuffer();
  } else if(!strcmp(key, "right_enter")){
    checkShellFunction();
    clearKeyboardBuffer();

    textGraphickNewLine();
    textGraphickPutChar('#');
    textGraphickPutChar(' ');
  }
}

void initKernelShell(){
  printf("%s", "Load kernel command shell\n# ");
  initKeyboardBuffer();

  while(1){
    updateScreen();
    handlerKeyboard(getKey());
  }
}
