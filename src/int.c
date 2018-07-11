#include "../headers/int.h"

int getLengthInt(int n){
  int num = 1, i = 0;

  while(n / num > 1){
    num *= 10;
    ++i;
  }

  return i;
}

int getMemberInt(int n, int member){
  int learge = getLengthInt(n);
  int num = powInt(10, learge);
  int result = 0;

  for(int i = 0; i < member; ++i){
    result = n / num;
    n = n - (num * result);
    num = num / 10;
  }

  return result;
}

int powInt(int n, int p){
    int result = n;

    for(int i = 1; i < p; ++i){
      if(p == 0){
        result = 0;
        break;
      }
      if(p == 1){
        break;
      }
      n *= result;
    }

    return n;
}
