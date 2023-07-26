#include "main.h"

/**
 * rev_string - Reverses string
 * @s: String to be reversed
 */
void rev_string(char *s)
{
	int left = 0, right;
	char temp;
	
	right = strlen(s) - 1;
	while (left < right)
	{
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
}

/**
 * r_conversion_specifier - Handles custom conversion specifier r
 * @args: List of arguments
 * Return: Printed characters
 */
int r_conversion_specifier(va_list args)
{
	int printed_chars = 0;
	char *s = va_arg(args, char *);
	int len = strlen(s);
	char *reversed_str = malloc(len + 1);

	if (reversed_str)
	{
		strcpy(reversed_str, s);
		rev_string(reversed_str);
		print_string(reversed_str, &printed_chars);
		free(reversed_str);
	}
	else
	{
		print_string(NULL, &printed_chars);
	}

	return (printed_chars);
}
