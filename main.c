#include <stdio.h>
#include <limits.h>
#include "main.h"

int main(void)
{
    int len;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d]\n", len);
    _printf("Negative:[%d]\n", -762534);
    ui = (unsigned int)INT_MAX + 1024;
    _printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    addr = (void *)0x7ffe637541f0;
    _printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);

    return (0);
}

