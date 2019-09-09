#include <early_shell.h>

static struct early_shell_data early_shell_data;

static void echo(const char* text)
{
        early_shell_data.printf("%s", text);
}

static void execute_session(void)
{
        early_shell_data.printf("%s # ", early_shell_data.user_name);       
}

void early_shell_init_session(struct early_shell_data data)
{
        early_shell_data = data;
        echo("kernel: init early shell\n");

        execute_session();
}
