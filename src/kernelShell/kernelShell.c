#include "../../headers/conix.h"

void shellFunctionHelp()
{
        printf("%s", "\nIt is help page for kernel shell");
        printf("%s", "\n hello  - print hello world");
        printf("%s", "\n clear  - clear output");
        setScreenTextColor(RED);
        printf("%s", "\n satan  - AVE SATAN");
        setScreenTextColor(LIGHT_GREY);
}

void shellFunctionHello()
{
        printf("%s", "\nHello World!");
}

void shellFunctionClear()
{
        clearTextGraphickScreen();
}

void shellFunctionSatan()
{
        screenTextColor = RED;
        printf("%s", "\nAVE SATAN!!!");
        screenTextColor = LIGHT_GREY;
}

void checkShellFunction()
{
        if (!strcmp(keyboardBuffer, "help")) {
                shellFunctionHelp();
        }

        if (!strcmp(keyboardBuffer, "hello")) {
                shellFunctionHello();
        }

        if (!strcmp(keyboardBuffer, "clear")) {
                shellFunctionClear();
        }

        if (!strcmp(keyboardBuffer, "satan")) {
                shellFunctionSatan();
        }
}

void shellHandlerKeyboard(char* key) 
{
        if (strlen(key) == 1) {
                textGraphickPutChar(key[0]);
                setKeyboardBuffer(key);
        } else if (!strcmp(key, "backspace")) {
                textGraphickDeleteChar();
                deleteCharKeyboardBuffer();
        } else if (!strcmp(key, "right_enter")) {
                checkShellFunction();
                clearKeyboardBuffer();

                textGraphickNewLine();
                textGraphickPutChar('#');
                textGraphickPutChar(' ');
        }
}

void initKernelShell()
{
        printf("%s", "Load kernel command shell\n# ");
        initKeyboardBuffer();
}
