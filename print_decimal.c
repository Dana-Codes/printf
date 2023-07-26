#include "main.h"

/**
 * print_decimal - Prints a decimal (signed integer) with optional flags
 * @n: The decimal number to print
 * Return: Number of characters printed
 */
void print_decimal(int n)
{
	int div;

	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	div = 1;
	while (n / div > 9)
		div *= 10;
	while (div)
	{
		putchar('0' + n / div);
		n %= div;
		div /= 10;
	}
}

/**
 * print_unsigned_dec - Helper function to print an unsigned integer with base
 * @n: The unsigned integer to print
 */
void print_unsigned_dec(unsigned int n)
{
	unsigned int div = 1;

	while (n / div > 9)
		div *= 10;
	while (div)
	{
		putchar('0' + n / div);
		n %= div;
		div /= 10;
	}
}
