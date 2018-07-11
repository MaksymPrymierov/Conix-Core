#include "../headers/stddef.h"
#include "../headers/string.h"

size_t strlen(char* str){
        char *begine = str;

        while (*str++);
        return str - begine - 1;
}

char* strcat(char *str, char* add_str){
        size_t i,j;

        for (i = 0; str[i] != '\0'; i++);
        for (j = 0; add_str[j] != '\0'; j++)
                str[i+j] = add_str[j];

        str[i+j] = '\0';

        return str;
}
