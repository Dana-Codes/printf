#include "main.h"

/**
 * print_octal - Prints an unsigned integer in octal format
 * @num: The unsigned integer to print
 * @hash_flag: Flag for '#'
 */

void print_octal(unsigned int n)
{
	unsigned int div = 1;

	while (n / div > 7)
		div *= 8;
	while (div)
	{
		putchar('0' + n / div);
		n %= div;
		div /= 8;
	}
}
