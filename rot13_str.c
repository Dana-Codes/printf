#include "main.h"

/**
 * rot13 - Apply rot13 to a character
 * @c: Chaaracter
 * Return: Character
 */
char rot13_char(char c)
{
	char base;

	if (isalpha(c))
	{
		base = islower(c) ? 'a' : 'A';
		return (((c - base + 13) % 26) + base);
	}
	return (c);
}

/**
 * rot13_str - Apply rot13 to string
 * @s: String
 */
void rot13_string(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		s[i] = rot13_char(s[i]);
}

/**
 * R_conversion_specifier - Handles conversion specifier R
 * @args: List of arguments
 * Return: Printed characters
 */
int R_conversion_specifier(va_list args, int *printed_chars)
{
	int len;
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		*printed_chars += print_string();
		return (0);
	}

	len = 0;
	for(len = 0; s[len]; len++)
		s[len] = rot13_char(s[len]);

	*prined_chars += print_string(s);

	return (1);
}
