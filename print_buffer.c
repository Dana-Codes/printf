#include "main.h"

/**
 *
 * print_buffer - Prints present buffer contents
 * @buffer: Char array
 * @length: Length
 * Return: Length 
 */

int print_buffer(const char *buffer, int length)
{
	if (*buff_count > 0)
	{
		write(1, buffer, *buff_count);
		*buff_count = 0;
	}
	return (length);
}
