#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: Pointer to string containing what's to be printed
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *fptr = format;
	int printed_chars = 0, d;
	char c, *s;
	unsigned int u;

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
					printed_chars += putchar(c);
				}
				else if (*fptr == 's')
				{
					s = va_arg(args, char *);
					for (; *s != '\0'; s++)
						printed_chars += putchar(*s);
				}
				else if (*fptr == '%')
					printed_chars += putchar('%');
				else if (*fptr == 'd' || *fptr == 'i')
				{
					d = va_arg(args, int);
					printed_chars += printf("%d", d);
				}
				else if (*fptr == 'b')
				{
					u = va_arg(args, unsigned int);
					printed_chars += print_binary(u);
				}
				else
				{
					printed_chars += putchar('%');
					printed_chars += putchar(*fptr);
				}
			}
			else
				printed_chars += putchar(*fptr);
			fptr++;
		}
	}
	va_end(args);
	return (printed_chars);
}
