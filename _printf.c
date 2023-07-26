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
	int printed_chars = 0, d, plusflag, spaceflag, hashflag, zeroflag, minsflag, field_width, precision;
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
				plusflag = 0;
				spaceflag = 0;
				hashflag = 0;
				zeroflag = 0;
				minusflag = 0;
				field_width = 0;
				precision = -1;
				while (*fptr == '+' || *fptr == ' ' || *fptr == '#' || *fptr == '0' || *fptr == '-')
				{
					if (*fptr == '+')
						plus = 1;
					else if (*fptr == ' ')
						space = 1;
					else if (*fptr == '#')
						hash = 1;
					else if (*fptr == '0')
						zeroflag = 1;
					else if (*fptr == '-')
						minusflag = 1;
					fptr++;
				}
				while (*fptr >= '0' && *fptr <= '9')
				{
					field_width = field_width * 10 + (*fptr - '0');
					fptr++;
				}
				if (*fptr == '.')
				{
					fptr++;
					precision = 0;
					while (*fptr >= '0' && *fptr <= '9')
					{
						precision = precision * 10 + (*fptr - '0');
						fptr++;
					}
				}
				if (*fptr == 'c')
				{
					c = va_arg(args, int);
					printed_chars += putchar(c);
				}
				else if (*fptr == 's' || *fptr == 'S')
				{
					s = va_arg(args, char *);
					printed_chars += print_string(s, field_width, precision, minusflag);
				}
				else if (*fptr == '%')
					printed_chars += putchar('%');
				else if (*fptr == 'd' || *fptr == 'i')
				{
					d = va_arg(args, int);
					printed_chars += print_decimal(d, field_width, precision, plusflag, spaceflag, zeroflag, minusflag);
				}
				else if (*fptr == 'u')
				{
					u = va_arg(args, unsigned int);
					printed_chars += print_unsigned_dec(u, ield_width, precision, minusflag);
				}
				else if (*fptr == 'o')
				{
					u = va_arg(args, unsigned int);
					printed_chars += print_octal(u, field_width, precision, hashflag, zeroflag, minusflag);
				}
				else if (*fptr == 'x' || *fptr == 'X')
				{
					 u = va_arg(args, unsigned int);
					 printed_chars += print_hexadecimal(u, field_width, precision, hashflag, zeroflag, minusflag, *fptr);
				}
				else if (*fptr == 'b')
				{
					u = va_arg(args, unsigned int);
					printed_chars += print_binary(u);
				}
				else if (*fptr == 'p')
				{
					ptr = va_arg(args, void *);
					printed_chars += print_pointer(ptr, field_width, precision, zeroflag);
				}
				else if (*fptr == 'r')
				{
					s = va_arg(args, char *);
					printed_chars += rev_string(s, field_width, precision, flag_minus);
				}
				else if (*fptr == 'R')
				{
					s = va_arg(args, char *);
					printed_chars += rot13_string(s, field_width, precision, flag_minus);
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
