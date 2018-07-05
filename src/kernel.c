#include "../headers/io.h"

void main(void){
        const char *str = "Ave Satan Ave Hell!!! Ave Connor41!!!";
        char *vidptr = (char*)0xb8000;
        unsigned int i = 0;
        unsigned int j = 0;

        clearScreen(vidptr, i, j);
        printText(str, vidptr, i, j);

        return;
}
