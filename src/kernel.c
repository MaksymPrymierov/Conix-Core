#include "../headers/stddef.h"
#include "../headers/string.h"
#include "../headers/io.h"
#include "../headers/stdlib.h"

void main(void){
  clearScreen(0x07);
  printText("Conix: version 0.001\n", 0x07);
  printText("Load kernel...\n", 0x07);
  printText("AVE SATAN, AVE CONNOR41, AVE GNU!\n", 0x04);
  printNumber(6666666, 0xf4);

  return;
}
