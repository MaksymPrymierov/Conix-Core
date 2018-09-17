#include <stdint.h>
#include "../headers/io/io.h"
#include "../headers/satanicShell.h"
#include "../headers/memory/gdt.h"
#include "../headers/io/screen.h"
#include "../headers/stdlib/stdio.h"

void main(void){
  textGraphickInit();
  printf("Conix Core version: 0.01\n");
  printf("Load kernel...\n");
	printf("/----------------------------------------\\\n");
  setScreenTextColor(RED);
  printf("|    AVE SATAN, AVE CONNOR41, AVE GNU!   |\n");
  setScreenTextColor(LIGHT_GREY);
	printf("\\----------------------------------------/\n");
  
  initShell(0x04);
// */
  return;
}
