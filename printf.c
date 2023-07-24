#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _putchar - Helper function to print a single character
 */
static int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Custom printf function
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int i = 0, count = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
                return (-1);
            if (format[i] == '%')
            {
                _putchar('%');
                count++;
            }
            else if (format[i] == 'c')
            {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
            }
            else if (format[i] == 's')
            {
                char *str = va_arg(args, char*);
                int j = 0;

                while (str[j])
                {
                    if (count == BUFFER_SIZE)
                    {
                        write(1, buffer, BUFFER_SIZE);
                        count = 0;
                    }
                    buffer[count++] = str[j++];
                }
            }
            else if (format[i] == 'S')
            {
                char *str = va_arg(args, char*);
                int j = 0;

                while (str[j])
                {
                    if (str[j] < 32 || str[j] >= 127)
                    {
                        if (count >= BUFFER_SIZE - 4)
                        {
                            write(1, buffer, count);
                            count = 0;
                        }
                        buffer[count++] = '\\';
                        buffer[count++] = 'x';
                        buffer[count++] = (str[j] / 16 < 10) ? (str[j] / 16 + '0') : (str[j] / 16 - 10 + 'A');
                        buffer[count++] = (str[j] % 16 < 10) ? (str[j] % 16 + '0') : (str[j] % 16 - 10 + 'A');
                    }
                    else
                    {
                        if (count == BUFFER_SIZE)
                        {
                            write(1, buffer, BUFFER_SIZE);
                            count = 0;
                        }
                        buffer[count++] = str[j];
                    }
                    j++;
                }
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                // Handle 'd' and 'i' conversion specifiers (integer)
                // (Not included here for brevity)
            }
            else if (format[i] == 'u')
            {
                // Handle 'u' conversion specifier (unsigned integer)
                // (Not included here for brevity)
            }
            else if (format[i] == 'o')
            {
                // Handle 'o' conversion specifier (octal)
                // (Not included here for brevity)
            }
            else if (format[i] == 'x' || format[i] == 'X')
            {
                // Handle 'x' and 'X' conversion specifiers (hexadecimal)
                // (Not included here for brevity)
            }
            else
            {
                _putchar('%');
                _putchar(format[i]);
                count += 2;
            }
        }
        else
        {
            if (count == BUFFER_SIZE)
            {
                write(1, buffer, BUFFER_SIZE);
                count = 0;
            }
            buffer[count++] = format[i];
        }
        i++;
    }

    va_end(args);

    if (count > 0)
    {
        write(1, buffer, count);
    }

    return count;
}

