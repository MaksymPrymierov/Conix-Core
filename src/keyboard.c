#define KEY_LOG_NUM
#include <stdint.h>
#include "../headers/keyboard.h"
#include "../headers/io.h"

static inline uint8_t inb(uint16_t port){
	uint8_t ret;
	asm volatile ( "inb %1, %0"
	                  : "=a"(ret)
	                  : "Nd"(port) );
	return ret;
	}

char getScancode(){
	while (!(inb(0x64) & 1));
	return inb(0x60) + 1;
}

void writeKey(char hex, short color){
  switch(hex){
#ifdef KEY_LOG_PRINT
    case 0x11:
      printText("q", color);
      break;
    case 0x12:
      printText("w", color);
      break;
    case 0x13:
      printText("e", color);
      break;
    case 0x14:
      printText("r", color);
      break;
    case 0x15:
      printText("t", color);
      break;
    case 0x16:
      printText("y", color);
      break;
    case 0x17:
      printText("u", color);
      break;
    case 0x18:
      printText("i", color);
      break;
    case 0x19:
      printText("o", color);
      break;
    case 0x1A:
      printText("p", color);
      break;
    case 0x1F:
      printText("a", color);
      break;
    case 0x20:
      printText("s", color);
      break;
    case 0x21:
      printText("d", color);
      break;
    case 0x22:
      printText("f", color);
      break;
    case 0x23:
      printText("g", color);
      break;
    case 0x24:
      printText("h", color);
      break;
    case 0x25:
      printText("j", color);
      break;
    case 0x26:
      printText("k", color);
      break;
    case 0x27:
      printText("l", color);
      break;
    case 0x2D:
      printText("z", color);
      break;
    case 0x2E:
      printText("x", color);
      break;
    case 0x2F:
      printText("c", color);
      break;
    case 0x30:
      printText("v", color);
      break;
    case 0x31:
      printText("b", color);
      break;
    case 0x32:
      printText("n", color);
      break;
    case 0x33:
      printText("m", color);
      break;
    case 0x3:
      printText("1", color);
      break;
    case 0x4:
      printText("2", color);
      break;
    case 0x5:
      printText("3", color);
      break;
    case 0x6:
      printText("4", color);
      break;
    case 0x7:
      printText("5", color);
      break;
    case 0x8:
      printText("6", color);
      break;
    case 0x9:
      printText("7", color);
      break;
    case 0xA:
      printText("8", color);
      break;
    case 0xB:
      printText("9", color);
      break;
    case 0xC:
      printText("0", color);
      break;
    case 0x1D:
      printText("\n", color);
    case 0x3A:
      printText(" ", color);
#endif
    default:
#ifdef KEY_LOG_NUM
      printNumber(hex, 0x07);
#endif
      ;
  }
}
