#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function that handles conversion specifiers: c, s, and %
 *
 * @format: The format string
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char c;
    char *str;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; /* Move past '%' */

            switch (*format)
            {
                case 'c':
                    c = (char)va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;

                case 's':
                    str = va_arg(args, char*);
                    while (*str != '\0')
                    {
                        putchar(*str);
                        printed_chars++;
                        str++;
                    }
                    break;

                case '%':
                    putchar('%');
                    printed_chars++;
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    printed_chars += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }

        format++; /* Move to the next character */
    }

    va_end(args);

    return printed_chars;
}

