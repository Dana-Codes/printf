#include "main.h"
#include <stdarg.h>

/**
 * printf - Produces output according to a format
 * @format: Pointer to string containing what's to be printed
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	const char *fptr = format;
	int printed_chars = 0;
	char c, *s;

	va_start(args, format);

	if (format)
	{
		while (*fptr)
		{
			if (*fptr == '%')
			{
				fptr++;

				if (*fptr == 'c')
				{
					c = va_arg(args, int);
					_putchar(c);
					printed_chars++;
				}
				else if (*fptr == 's')
				{
					s = va_arg(args, char *);
					while (*s)
					{
						_putchar(*s);
						printed_chars++;
						s++;
					}
				}
				else if (*fptr == '%')
				{
					_putchar('%');
					printed_chars++;
				}
			}
			else
			{
				_putchar(*fptr);
				printed_chars++;
			}
			fptr++;
		}
	}

	va_end(args);

	return (printed_chars);
}
