#define KEY_LOG_PRINT
#define C_KEYBOARD
#include <stdint.h>
#include "../../headers/stdlib/stddef.h"
#include "../../headers/io/keyboard.h"
#include "../../headers/io/io.h"
#include "../../headers/io/screen.h"
#include "../../headers/stdlib/string.h"

void clearBuffer(){
  for(int i = 0; i <= bufTexNum; ++i)
  bufTex[i] = ' ';
  bufTexNum = 0;
}

void setTextBuffer(char s){
  bufTex[bufTexNum] = s;
  ++bufTexNum;
  bufTex[bufTexNum] = '\0';
}

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

void writeKey(char hex){
  short color = screenTextColor;
  switch(hex){
#ifdef KEY_LOG_PRINT
    case 0x11:
      printText("q", color);
      setTextBuffer('q');
      break;
    case 0x12:
      printText("w", color);
      setTextBuffer('w');
      break;
    case 0x13:
      printText("e", color);
      setTextBuffer('e');
      break;
    case 0x14:
      printText("r", color);
      setTextBuffer('r');
      break;
    case 0x15:
      printText("t", color);
      setTextBuffer('t');
      break;
    case 0x16:
      printText("y", color);
      setTextBuffer('y');
      break;
    case 0x17:
      printText("u", color);
      setTextBuffer('u');
      break;
    case 0x18:
      printText("i", color);
      setTextBuffer('i');
      break;
    case 0x19:
      printText("o", color);
      setTextBuffer('o');
      break;
    case 0x1A:
      printText("p", color);
      setTextBuffer('p');
      break;
    case 0x1F:
      printText("a", color);
      setTextBuffer('a');
      break;
    case 0x20:
      printText("s", color);
      setTextBuffer('s');
      break;
    case 0x21:
      printText("d", color);
      setTextBuffer('d');
      break;
    case 0x22:
      printText("f", color);
      setTextBuffer('f');
      break;
    case 0x23:
      printText("g", color);
      setTextBuffer('g');
      break;
    case 0x24:
      printText("h", color);
      setTextBuffer('h');
      break;
    case 0x25:
      printText("j", color);
      setTextBuffer('j');
      break;
    case 0x26:
      printText("k", color);
      setTextBuffer('k');
      break;
    case 0x27:
      printText("l", color);
      setTextBuffer('l');
      break;
    case 0x2D:
      printText("z", color);
      setTextBuffer('z');
      break;
    case 0x2E:
      printText("x", color);
      setTextBuffer('x');
      break;
    case 0x2F:
      printText("c", color);
      setTextBuffer('c');
      break;
    case 0x30:
      printText("v", color);
      setTextBuffer('v');
      break;
    case 0x31:
      printText("b", color);
      setTextBuffer('b');
      break;
    case 0x32:
      printText("n", color);
      setTextBuffer('n');
      break;
    case 0x33:
      printText("m", color);
      setTextBuffer('m');
      break;
    case 0x3:
      printText("1", color);
      setTextBuffer('1');
      break;
    case 0x4:
      printText("2", color);
      setTextBuffer('2');
      break;
    case 0x5:
      printText("3", color);
      setTextBuffer('3');
      break;
    case 0x6:
      printText("4", color);
      setTextBuffer('4');
      break;
    case 0x7:
      printText("5", color);
      setTextBuffer('5');
      break;
    case 0x8:
      printText("6", color);
      setTextBuffer('6');
      break;
    case 0x9:
      printText("7", color);
      setTextBuffer('7');
      break;
    case 0xA:
      printText("8", color);
      setTextBuffer('8');
      break;
    case 0xB:
      printText("9", color);
      setTextBuffer('9');
      break;
    case 0xC:
      printText("0", color);
      setTextBuffer('0');
      break;
    case 0x1D:
      printText("\n", color);
      printText("# > ", color);
      if(strcmp(bufTex, "satan") == 0){
        printText("\n AVE CONNOR \n# > ", color);
      }
      clearBuffer();
      break;
    case 0x3A:
      printText(" ", color);
      setTextBuffer(' ');
      break;
    case 0xF:
      deleteSyn(color);
      break;
#endif
    default:

#ifdef KEY_LOG_NUM
      printNumber(hex, 0x07);
#endif
      ;
  }
}
