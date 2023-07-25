#include "main.h"

/**
 * print_hexadecimal - Converts ASCII code to a 2digit hexadecimal
 * @c: Input character
 * Return: Hexadecimal vallue
 */

int print_hexadecimal(char c)
{
	char hex[3];
	unsigned char asc_code = (unsigned char)c;

	hex[0] = ((asc_code / 16) < 10 ? (asc_code / 16) + '0' : (asc_code / 16) - 10 + 'A');
	hex[1] = ((asc_code % 16) < 10 ? (asc_code % 16) + '0' : (asc_code % 16) - 10 + 'A');
	hex[2] = '\0';

	return printf("\\x%s", hex);
}
