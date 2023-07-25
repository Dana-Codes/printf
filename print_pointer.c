#include "main.h"

/**
 * print_pointer - Prints a void * pointer in hexadecimal
 * @ptr: Pointer
 * Return: Characters printed
 */

int print_pointer(void *ptr)
{
	unsigned long p = (unsigned long)ptr;
	int digit_count, printed_chars = 0, i, H_digit;
	char H_char;

	digit_count = 2 * sizeof(void *);

	putchar('0');
	putchar('x');

	for (i = digit_count - 1; i >= 0; i--)
	{
		H_digit = (p >> (4 * i)) & 0xF;
		H_char = H_digit < 10 ? '0' + H_digit : 'A' + (H_digit - 10);
		putchar(H_char);
		printed_chars++;
	}

	return (printed_chars);
}
