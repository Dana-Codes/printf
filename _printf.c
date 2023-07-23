#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int main() {
    _printf("Hello, %s! This is a test %c and a percent %%.\n", "John", 'C');
    return 0;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            switch (*format) {
                case 'c':
                    c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                case 's': {
                    const char *str = va_arg(args, const char*);
                    while (*str != '\0') {
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
                    putchar(*format);
                    count++;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }

        format++; // Move to the next character in the format string
    }

    va_end(args);
    return count;
}

