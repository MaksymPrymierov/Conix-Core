#include "../headers/stddef.h"
#include "../headers/int.h"
#include "../headers/string.h"
#include "../headers/stdlib.h"

char* reverse(char *str){
        char tmp, *src, *dst;
        size_t len;
        if (str != NULL){
                len = strlen(str);
                if (len > 1){
                        src = str;
                        dst = src + len - 1;
                        while(src < dst){
                                tmp = *src;
                                *src++ = *dst;
                                *dst-- = tmp;
                        }
                }
        }
        return str;
}

void itoa(int n, char s[]){
        int i, sign;

        if ((sign = n) < 0)
                n = -n;
        i = 0;

        do {
                s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);

        if (sign < 0)
                s[i++] = '-';

        reverse(s);
        s[i] = '\0';
        return;
}
