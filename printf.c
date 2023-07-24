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
 * print_octal - Helper function to print an unsigned integer in octal
 */
static int print_octal(unsigned int num)
{
    int printed_chars = 0;
    if (num > 7)
    {
        printed_chars += print_octal(num / 8);
    }
    putchar('0' + (num % 8));
    printed_chars++;
    return (printed_chars);
}

/**
 * print_hex - Helper function to print an unsigned integer in hexadecimal (lowercase)
 */
static int print_hex(unsigned int num)
{
    int printed_chars = 0;
    if (num > 15)
    {
        printed_chars += print_hex(num / 16);
    }
    if ((num % 16) < 10)
    {
        putchar('0' + (num % 16));
    }
    else
    {
        putchar('a' + (num % 16) - 10);
    }
    printed_chars++;
    return (printed_chars);
}

/**
 * print_hex_upper - Helper function to print an unsigned integer in hexadecimal (uppercase)
 */
static int print_hex_upper(unsigned int num)
{
    int printed_chars = 0;
    if (num > 15)
    {
        printed_chars += print_hex_upper(num / 16);
    }
    if ((num % 16) < 10)
    {
        putchar('0' + (num % 16));
    }
    else
    {
        putchar('A' + (num % 16) - 10);
    }
    printed_chars++;
    return (printed_chars);
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
    unsigned int o;
    unsigned int x;
    unsigned int X;

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

            case 'u':
                u = va_arg(args, unsigned int);
                printed_chars += print_integer(u);
                break;

            case 'o':
                o = va_arg(args, unsigned int);
                printed_chars += print_octal(o);
                break;

            case 'x':
                x = va_arg(args, unsigned int);
                printed_chars += print_hex(x);
                break;

            case 'X':
                X = va_arg(args, unsigned int);
                printed_chars += print_hex_upper(X);
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

