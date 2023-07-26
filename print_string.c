#include "main.h"

/**
 * print_string - Prints a string
 * @s: String to print
 */
void print_string(const char *s, int *printed_chars)
{
	int len;

	if (s = 0)
	{
		print_buffer(6, printed_chars);
		return;
	}
	len = strlen(s);
	print_buffer(s, len, printed_chars);
}
