#include "../../headers/io/keyboard.h"
#include "../../headers/stdlib/stdio.h"
#include "../../headers/conixLibs/kernelShell.h"

void initKernelShell(){
  printf("Load kernel command shell\n");
  while(1)
    writeKey(getScancode());
  return;
}

