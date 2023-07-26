#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Helper function to print a single character
 */
static int print_char(char c)
{
    putchar(c);
    return (1);
}

/**
 * print_string - Helper function to print a string
 */
static int print_string(char *str)
{
    int printed_chars = 0;
    while (*str != '\0')
    {
        putchar(*str);
        printed_chars++;
        str++;
    }
    return (printed_chars);
}

/**
 * print_integer - Helper function to print an integer
 */
static int print_integer(int num)
{
    unsigned int abs_num;
    int printed_chars = 0;

    if (num < 0)
    {
        putchar('-');
        printed_chars++;
        abs_num = -num;
    }
    else
    {
        abs_num = num;
    }

    if (abs_num > 9)
    {
        printed_chars += print_integer(abs_num / 10);
    }

    putchar('0' + (abs_num % 10));
    printed_chars++;

    return (printed_chars);
}

/**
 * print_binary - Helper function to print an unsigned integer in binary
 */
static int print_binary(unsigned int num)
{
    int printed_chars = 0;
    if (num > 1)
    {
        printed_chars += print_binary(num / 2);
    }
    putchar('0' + (num % 2));
    printed_chars++;
    return (printed_chars);
}

/**
 * _printf - Custom printf function that handles conversion specifiers: c, s, %, d, i, and b
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
    unsigned int b;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c':
                c = (char)va_arg(args, int);
                printed_chars += print_char(c);
                break;

            case 's':
                str = va_arg(args, char*);
                printed_chars += print_string(str);
                break;

            case '%':
                printed_chars += print_char('%');
                break;

            case 'd':
            case 'i':
                d = va_arg(args, int);
                printed_chars += print_integer(d);
                break;

            case 'b':
                b = va_arg(args, unsigned int);
                printed_chars += print_binary(b);
                break;

            default:
                printed_chars += print_char('%');
                printed_chars += print_char(*format);
                break;
            }
        }
        else
        {
            printed_chars += print_char(*format);
        }

        format++;
    }

    va_end(args);

    return (printed_chars);
}

