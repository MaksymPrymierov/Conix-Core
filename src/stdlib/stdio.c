#include "../../headers/stdlib/stdlib.h"
#include "../../headers/io/screen.h"

static void print(const char* text)
{
        for (int i = 0; i < strlen(text); ++i) {
                textGraphickPutChar(text[i]);
        }
}

int printf(const char* maket, ...)
{
        va_list args;
        char *type, *buff;
        size_t len;
        int ret = 0;

        va_start(args, maket);

        if (!strcmp(maket, "%s")) {
                buff = va_arg(args, char *);
                print(buff);

                ret = strlen(buff);
                goto out;
        }

        if (!strcmp(maket, "%d")) {
                itoa(va_arg(args, int), buff, 10);
                print(buff);

                ret = strlen(buff);
                goto out;
        }

        va_end(args);

        out:
                return ret;
}
