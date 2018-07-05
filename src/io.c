#include "../headers/io.h"

void clearScreen(char *vidptr, unsigned int i, unsigned int j){
        while(j < 80 * 25 * 2){
                vidptr[j] = ' ';
                vidptr[j+1] = 0x04;
                j = j + 2;
        }
        j = 0;
}

void printText(const char *str, char *vidptr, unsigned int i, unsigned int j){
        while(str[j] != '\0'){
                vidptr[i] = str[j];
                vidptr[i+1] = 0x04;
                ++j;
                i = i + 2;
        }
}
