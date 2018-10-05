#include "../../headers/kernelShell/shellKeyboard.h"
#include "../../headers/stdlib/stddef.h"
#include "../../headers/stdlib/string.h"

void initKeyboardBuffer(){
  keyboardBuffer = "";
}

void clearKeyboardBuffer(){
  size_t len = strlen(keyboardBuffer);

  for(size_t i = 0; i < len + 1; ++i){
    keyboardBuffer[i] = ' ';
  }

  keyboardBuffer[0] = '\0';
}
