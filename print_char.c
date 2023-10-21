#include "main.h"

/**
 * print_c - handles the character format specifier
 * @args: argument from the _printf function
 * @buf: pointer to buffer
 * @buf_i: pointer to current index of
 *
 * Return: number of characters written
 */
long int print_c(va_list args, char *buf, long int *buf_i)
{
	char ch;

	if (args)
	{
		ch = va_arg(args, int);
		if (ch)
			buf[*buf_i] = ch + '0';
		else
			buf[*buf_i] = '\0';
	}

	return (0);
}
