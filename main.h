#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int print_binary(unsigned int n);
int print_hexadecimal(char c);

#endif /* MAIN_H */
