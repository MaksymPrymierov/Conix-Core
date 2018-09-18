#define KEY_LOG_NUM
#define C_KEYBOARD
#include <stdint.h>
#include "../../headers/stdlib/stddef.h"
#include "../../headers/io/keyboard.h"
#include "../../headers/io/screen.h"
#include "../../headers/stdlib/string.h"

char* keys[] = {
  "", "esc", "1", "2", "3", "4", "5", "6", "7",
  "8", "9", "0", "-", "=", "backspace", "tab", "q", "w",
  "e", "r", "t", "y", "u", "i", "o", "p", "[",
  "]", "right_enter", "right_ctrl", "a", "s", "d", "f", "g",
  "h", "j", "k", "l", ";", "'", "`", "right_shift", "\\", 
  "z", "x", "c", "v", "b", "n", "m", ",", ".", 
  "/", "left_shift", "*", "left_alt", " ", "caps_lock", "f1", "f2", "f2",
  "f3", "f4", "f5", "f6", "f7", "f8", "f9", "f10", "num_lock",
  "rollen", "num_7", "num_8", "num_9", "num_-", "num_4", "num_5", "num_6", "num_+",
  "num_1", "num_2", "num_3", "num_0", "num_.", "none", "none", "none", "none",
  "f11", "f12"
};

char* getKey(){
  return keys[getScancode()];
}

static inline uint8_t inb(uint16_t port){
	uint8_t ret;
	asm volatile ( "inb %1, %0"
	                  : "=a"(ret)
	                  : "Nd"(port) );
	return ret;
	}

uint8_t getScancode(){
	while (!(inb(0x64) & 1));
	return inb(0x60);
}
