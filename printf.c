#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Helper function to print a single character
 */
static int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _print_string - Helper function to print a string
 */
static int _print_string(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        _putchar(*str);
        str++;
        len++;
    }
    return len;
}

/**
 * _print_number - Helper function to print a signed integer
 */
static int _print_number(int num)
{
    unsigned int n;
    int printed_chars = 0;

    if (num < 0)
    {
        printed_chars += _putchar('-');
        n = -num;
    }
    else
    {
        n = num;
    }

    if (n > 9)
    {
        printed_chars += _print_number(n / 10);
    }

    printed_chars += _putchar('0' + n % 10);

    return printed_chars;
}

/**
 * _print_unsigned - Helper function to print an unsigned integer
 */
static int _print_unsigned(unsigned int num, int base, const char *digits)
{
    int printed_chars = 0;
    if (num >= (unsigned int)base)
    {
        printed_chars += _print_unsigned(num / base, base, digits);
    }
    _putchar(digits[num % base]);
    printed_chars++;
    return printed_chars;
}

/**
 * _printf - Custom printf function that handles conversion specifiers: c, s, %, d, i, u, o, x, and X
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
    int d;
    unsigned int u;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = va_arg(args, int);
                    printed_chars += _putchar(c);
                    break;

                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                    {
                        str = "(null)";
                    }
                    printed_chars += _print_string(str);
                    break;

                case '%':
                    printed_chars += _putchar('%');
                    break;

                case 'd':
                case 'i':
                    d = va_arg(args, int);
                    printed_chars += _print_number(d);
                    break;

                case 'u':
                    u = va_arg(args, unsigned int);
                    printed_chars += _print_unsigned(u, 10, "0123456789");
                    break;

                case 'o':
                    u = va_arg(args, unsigned int);
                    printed_chars += _print_unsigned(u, 8, "01234567");
                    break;

                case 'x':
                    u = va_arg(args, unsigned int);
                    printed_chars += _print_unsigned(u, 16, "0123456789abcdef");
                    break;

                case 'X':
                    u = va_arg(args, unsigned int);
                    printed_chars += _print_unsigned(u, 16, "0123456789ABCDEF");
                    break;

                default:
                    printed_chars += _putchar('%');
                    printed_chars += _putchar(*format);
                    break;
            }
        }
        else
        {
            printed_chars += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}

