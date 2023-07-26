#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int print_binary(unsigned int n);
void print_hexadecimal(unsigned int n, int uppercase);
void print_pointer(void *ptr);
int print_buffer(const char *buffer, int length);
void print_string(const char *s, int *printed_chars);
void print_decimal(int n);
void print_unsigned_dec(unsigned int n);
void print_octal(unsigned int n)
void rev_string(char *s);
void r_conversion_specifier(va_list args, int *printed_chars);
void R_conversion_specifier(va_list args, int *printed_chars);
char rot13_char(char c);
void rot13_string(char *s);

#endif /* MAIN_H */
