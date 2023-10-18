#include "main.h"

/**
 * print_c - handles the character format specifier
 * @args: argument from the _printf function
 * @buf: pointer to buffer
 * @buf_i: pointer to current index of
 *
 * Return: number of characters written
 */
long int print_c(va_list args, char *buf, unsigned int *buf_i)
{
	if (args)
	{
		buf[*buf_i] = (va_arg(args, int)) + '0';
		++*buf_i;
		return (1);
	}

	return (0);
}
