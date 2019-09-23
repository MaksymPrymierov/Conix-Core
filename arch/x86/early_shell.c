#include <early_shell.h>
#include <keyboard.h>
#include <kernel/string.h>
#include <kernel/kernel_lib.h>

/* General simple keyboard */
#define ESC                     0x01
#define DIGIT_START             0x02 // 1 -> 0
#define DIGIT_END               0x0D // 1 <- 0
#define BACKSPACE               0x0E
#define TAB                     0x0F
#define LETTER_START_PART1      0x10 // q -> ]
#define LETTER_END_PART1        0x1B // q <- ]
#define LEFT_ENTER              0x1C
#define LEFT_CTRL               0x1D
#define LETTER_START_PART2      0x1E // a -> '
#define LETTER_END_PART2        0x29 // a <- '
#define LEFT_SHIFT              0x2A
#define LETTER_START_PART3      0x2B // z -> /
#define LETTER_END_PART3        0x35 // z <- /
#define RIGHT_SHIFT             0x36
#define LEFT_ALT                0x38
#define SPACE                   0x39
#define CAPS_LOCK               0x3A
#define START_FUNCTION_KEYS     0x3B // F1 -> F10
#define END_FUNCTION_KEYS       0x44 // F1 <- F10
#define SCROLL_LOCK             0x46
#define ALT_PLUS_PTRSCR         0x54
#define F11                     0x57
#define F12                     0x58
#define RELEASE_KEY             0x80

static struct early_shell_data* early_shell_data;
static const char digit_low_case[] = "1234567890-=";
static const char digit_apper_case[] = "!@#$%^&*()_+";
static const char letters_low_case_part1[] = "qwertyuiop[]";
static const char letters_apper_case_part1[] = "QWERTYUIOP{}";
static const char letters_low_case_part2[] = "asdfghjkl;'`";
static const char letters_apper_case_part2[] = "ASDFGHJKL:\"~";
static const char letters_low_case_part3[] = "\\zxcvbnm,./";
static const char letters_apper_case_part3[] = "|ZXCVBNM<>?";
static struct string character_buffer;
static _Bool lowCase = 1;
static _Bool print = 0;

static void processing_key_code(u8 code)
{
        print = 1;
        if ((code >= DIGIT_START && code <= DIGIT_END) ||
                (code - RELEASE_KEY >= DIGIT_START &&
                code - RELEASE_KEY <= DIGIT_END)) {
                string_add(&character_buffer,
                        lowCase ? digit_low_case[code - DIGIT_START] :
                        digit_apper_case[code - DIGIT_START]);
        } else if (code >= LETTER_START_PART1 &&
                code <= LETTER_END_PART1) {
                string_add(&character_buffer,
                        lowCase ?
                        letters_low_case_part1[code - LETTER_START_PART1] :
                        letters_apper_case_part1[code -
                        LETTER_START_PART1]);
        } else if (code >= LETTER_START_PART2 &&
                code <= LETTER_END_PART2) {
                string_add(&character_buffer,
                        lowCase ?
                        letters_low_case_part2[code - LETTER_START_PART2] :
                        letters_apper_case_part2[code -
                        LETTER_START_PART2]);
        } else if (code >= LETTER_START_PART3 &&
                code <= LETTER_END_PART3) {
                string_add(&character_buffer,
                        lowCase ?
                        letters_low_case_part3[code - LETTER_START_PART3] :
                        letters_apper_case_part3[code -
                        LETTER_START_PART3]);
        } else if (code == SPACE) {
                string_add(&character_buffer, ' ');
        } else if (code == BACKSPACE) {
                string_prepend(&character_buffer);
                early_shell_data->printf("\b");
                print = 0;
        } else if (code == LEFT_ENTER) {
                if (string_cmp_native(&character_buffer, "test")) {
                        early_shell_data->printf("\nConix-Core test is successful");
                }
                string_clear(&character_buffer);
                early_shell_data->printf("\n%s # ",
                        early_shell_data->user_name);
                print = 0;
        } else if (code == LEFT_SHIFT) {
                lowCase = 0;
                print = 0;
        } else {
                print = 0;
        }
}

static void releasing_key_code(u8 code)
{
        if (code - RELEASE_KEY == LEFT_SHIFT) {
                lowCase = 1;
        }
}

static void echo(const char* text)
{
        early_shell_data->printf("%s", text);
}

static void execute_session(void)
{
        u8 scan_code = 0;
        early_shell_data->printf("%s # ", early_shell_data->user_name);
        while (1) {
                scan_code = default_keyboard_get_scan_code();
                if (scan_code >= ESC && scan_code < RELEASE_KEY) {
                        processing_key_code(scan_code);
                        if (strlen(character_buffer.data) > 0 && print) {
                                early_shell_data->printf("%c",
                                string_get_last(&character_buffer));
                        }
                } else if (scan_code >= RELEASE_KEY) {
                        releasing_key_code(scan_code);
                }

        }
}

void early_shell_init_session(struct early_shell_data* data)
{
        string_init(&character_buffer, 256);
        early_shell_data = data;
        echo("kernel: init early shell\n");

        execute_session();
}
