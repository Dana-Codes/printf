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
	int printed_chars = 0, d, plus = 0, space = 0, hash = 0;
	char c, *s;
	unsigned int u;
	void *ptr;

	va_start(args, format);
	if (format)
	{
		while (*fptr)
		{
			if (*fptr == '%')
			{
				fptr++;
				while (*fptr == '+' || *fptr == ' '|| *fptr == '#')
				{
					if (*fptr == '+')
						plus = 1;
					else if (*fptr == ' ')
						space = 1;
					else if (*fptr == '#')
						hash = 1;
					fptr++;
				}
				if (*fptr == 'c')
				{
					c = va_arg(args, int);
					printed_chars += putchar(c);
				}
				else if (*fptr == 's' || *fptr == 'S')
				{
					s = va_arg(args, char *);
					for (; *s != '\0'; s++)
					{
						if (*s >= 32 && *s < 127)
							printed_chars += putchar(*s);
						else
							printed_chars += print_hexadecimal(*s);
					}
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
				else if (*fptr == 'p')
				{
					ptr = va_arg(args, void *);
					printed_chars += print_pointer(ptr);
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
