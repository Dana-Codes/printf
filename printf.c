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

