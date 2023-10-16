#include "main.h"

/**
 * print_d - prints an integer
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_d(va_list set)
{
	int count = 0;
	int num;

	if (set)
	{
		num = va_arg(set, int);
		count += write(1, num, sizeof(num));
	}

	return (count);
}

/**
 * print_i - prints an integer
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_i(va_list set)
{
	int count = 0;
	int num;

	if (set)
	{
		num = va_arg(set, int);
		count += write(1, num, sizeof(num));
	}

	return (count);
}
