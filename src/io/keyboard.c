#define KEY_LOG_NUM
#define C_KEYBOARD
#include "../../headers/conix.h"
#include "../../headers/ints/keyboard.h"

#define BEGINE_TABLE_PRESS_KEYS   0x1
#define END_TABLE_PRESS_KEYS      0x5a
#define BEGINE_TABLE_PRESSED_KEYS 0x81
#define END_TABLE_PRESSED_KEYS    0xda

char* pressKeys[] = {
  "null", "esc", "1", "2", "3", "4", "5", "6", "7",
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

char* pressedKeys[] = {
  "p_null", "p_esc", "p_1", "p_2", "p_3", "p_4", "p_5", "p_6", "p_7",
  "p_8", "p_9", "p_0", "p_-", "p_=", "p_backspace", "p_tab", "p_q", "p_w",
  "p_e", "p_r", "p_t", "p_y", "p_u", "p_i", "p_o", "p_p", "p_[",
  "p_]", "p_right_enter", "p_right_ctrl", "p_a", "p_s", "p_d", "p_f", "p_g",
  "p_h", "p_j", "p_k", "p_l", "p_;", "p_'", "p_`", "p_right_shift", "p_\\", 
  "p_z", "p_x", "p_c", "p_v", "p_b", "p_n", "p_m", "p_,", "p_.", 
  "p_/", "p_left_shift", "p_*", "p_left_alt", "p_ ", "p_caps_lock", "p_f1", "p_f2", "p_f2",
  "p_f3", "p_f4", "p_f5", "p_f6", "p_f7", "p_f8", "p_f9", "p_f10", "p_num_lock",
  "p_rollen", "p_num_7", "p_num_8", "p_num_9", "p_num_-", "p_num_4", "p_num_5", "p_num_6", "p_num_+",
  "p_num_1", "p_num_2", "p_num_3", "p_num_0", "p_num_.", "p_none", "p_none", "p_none", "p_none",
  "p_f11", "p_f12"
};

char* getKey(){
  int hex = getScancode();
  if(hex <= END_TABLE_PRESS_KEYS){
    return pressKeys[hex];
  } else if(hex >= BEGINE_TABLE_PRESSED_KEYS || hex <= END_TABLE_PRESSED_KEYS){
    return pressedKeys[hex - (BEGINE_TABLE_PRESSED_KEYS - 1)];
  }
  return pressKeys[0];
}

