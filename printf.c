#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int char_count = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move to the next character after '%'
            switch (*format) {
                case 'c': {
                    char ch = (char)va_arg(args, int);
                    putchar(ch);
                    char_count++;
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        char_count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    char_count++;
                    break;
                }
                default:
                    // Unsupported conversion specifier, just print the '%'
                    putchar('%');
                    char_count++;
                    break;
            }
        } else {
            putchar(*format);
            char_count++;
        }
        format++;
    }

    va_end(args);
    return char_count;
}

int main() {
    _printf("Hello, %s!\n", "world");
    _printf("Character: %c\n", 'A');
    _printf("Let's print a percent sign: %%\n");
    return 0;
}

