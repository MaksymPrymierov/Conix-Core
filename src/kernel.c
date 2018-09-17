#include <stdint.h>
#include "../headers/io/screen.h"
#include "../headers/stdlib/stdio.h"
#include "../headers/conixLibs/kernelShell.h"

void main(void){
  textGraphickInit();

  printf("Conix Core version: 0.01\n");
  printf("Load kernel...\n");
	printf("/----------------------------------------\\\n");
  setScreenTextColor(RED);
  printf("|    AVE SATAN, AVE CONNOR41, AVE GNU!   |\n");
  setScreenTextColor(LIGHT_GREY);
	printf("\\----------------------------------------/\n");
  
  initKernelShell();

  return;
}
