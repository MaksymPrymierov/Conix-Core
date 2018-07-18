#include <stdint.h>
#include "../headers/stddef.h"
#include "../headers/string.h"
#include "../headers/io.h"
#include "../headers/stdlib.h"
#include "../headers/keyboard.h"

void main(void){
  clearScreen(0x07);
  printText("Conix Core: version 0.001\n", 0x07);
  printText("Load kernel...\n", 0x07);
  printText("AVE SATAN, AVE CONNOR41, AVE GNU!\n", 0x04);
  char *hello = "Hello";
//  deleteFirstElements(hello, 2);
  printText(hello, 0x07);
	while(1)
		writeKey(getScancode(), 0x04);
  return;
}
