#include "../headers/io/keyboard.h"
#include "../headers/io/io.h"
#include "../headers/satanicShell.h"

void initShell(short color){
  printText("Start Load Satanic Shell\n", color);
  printText("SatanicShell # ", color);
  while(1)
    writeKey(getScancode(), color);
  return;
}
