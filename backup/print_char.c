#include "main.h"

/**
 * print_c - handles the character format specifier
 * @set: argument from the _printf function
 * @buf: pointer to buffer
 * @buf_i: pointer to current index of
 *
 */
void print_c(va_list set, char *buf, unsigned int *buf_i)
{
	if (set)
	{
		buf[*buf_i] = (va_arg(set, int)) + '0';
		*buf_i++;
	}
}
