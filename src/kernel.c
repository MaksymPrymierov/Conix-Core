#include <stdint.h>
#include "../headers/io/screen.h"
#include "../headers/stdlib/stdio.h"
#include "../headers/conixLibs/kernelShell.h"

void main(void){
  textGraphickInit();
  printf("%s", "Conix Core version: 0.01\n");
  printf("%s", "Load kernel...\n");
	printf("%s", "/----------------------------------------\\\n");
  setScreenTextColor(RED);
  printf("%s", "|    AVE SATAN, AVE CONNOR41, AVE GNU!   |\n");
  setScreenTextColor(LIGHT_GREY);
	printf("%s", "\\----------------------------------------/\n");
  
  initKernelShell();

  return;
}
