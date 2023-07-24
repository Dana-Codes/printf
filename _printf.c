#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    int count; /* To keep track of the number of characters printed */
    char ch;

    va_start(args, format);

    count = 0; // Initialize count

    while (*format) {
        if (*format == '%') {
            format++; /* Move to the character after '%' */

            /* Check for valid conversion specifier */
            switch (*format) {
                case 'c':
                    ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                case 's': {
                    char *str = va_arg(args, char *);
                    while (*str) {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++; /* Move to the next character in the format string */
    }

    va_end(args);
    return count;
}

