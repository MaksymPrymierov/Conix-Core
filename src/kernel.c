#include <stdint.h>
#include "../headers/io/io.h"
#include "../headers/satanicShell.h"

void main(void){
  clearScreen(0x07);
  printText("Conix Core: version 0.001\n", 0x07);
  printText("Load kernel...\n", 0x07);
  printText("AVE SATAN, AVE CONNOR41, AVE GNU!\n", 0x04);
	printText("----------------------------------------\n", 0x04);
  
  initShell(0x04);

  return;
}
