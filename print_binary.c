#include "main.h"

/**
 * print_binary - Function assists in printingan unsigned integer in binary
 * @n: The unsigned integer
 * Return: Number of characters printed
 */

int print_binary(unsigned int n)
{
	int printed_chars = 0;

	if (n / 2 != 0)
		printed_chars += print_binary(n / 2);

	putchar((n % 2) + '0');

	return (printed_chars + 1);
}
