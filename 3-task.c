#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    unsigned int ui;
    int res = INT_MAX;
    ui = (unsigned int)INT_MAX + 1024;

    printf("%u\n", 1024); 
    _printf("%u\n", 1024);
    printf("%u\n", -1024);
    _printf("%u\n", -1024);
    _printf("%u\n", 0);
    _printf("%u\n", UINT_MAX);
    _printf("There is %u bytes in %u KB\n", 1024);
    _printf("%u - %u = %u\n", 2048, 1024, 1024);
    _printf("%u + %u = %u\n", INT_MAX, INT_MAX, res);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    return (0);
}
