#include <stdint.h>
#include "../../headers/stdlib/stddef.h"
#include "../../headers/stdlib/string.h"

size_t strlen(char* str){
  char *begin = str;

  while (*str++);
  return str - begin - 1;
}

char* strcat(char *str, char* add_str){
  size_t i,j;

  for (i = 0; str[i] != '\0'; i++);
  for (j = 0; add_str[j] != '\0'; j++)
    str[i+j] = add_str[j];

  str[i+j] = '\0';

  return str;
}

int strcmp(char *first, char *second){
  size_t lenF, lenS;
  lenF = strlen(first);
  lenS = strlen(second);
  if(lenF > lenS) return 1;
  if(lenF < lenS) return -1;
  
  for(int i = 0; i < lenF; ++i){
    if(first[i] > second[i]) return 1;
    if(first[i] < second[i]) return -1;
  }
  return 0;
}
