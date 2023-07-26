#include "main.h"

/**
 * print_hexadecimal - Converts ASCII code to a 2digit hexadecimal
 * @c: Input character
 * Return: Hexadecimal vallue
 */
void print_hexadecimal(unsigned int n, int uppercase)
{
	char hex[3];
	unsigned char ascii = (unsigned char)c;

	hex[0] = (ascii / 16) < 10 ? (ascii / 16) + '0' : (ascii / 16) - 10 + 'A';        hex[1] = (ascii % 16) < 10 ? (ascii % 16) + '0' : (ascii % 16) - 10 + 'A';        hex[2] = '\0';
}
