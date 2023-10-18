#include "main.h"

/**
 * print_num - converts int to bufing
 * @set: argument from _printf
 * @buf: Pointer to the buffer
 * @buf_i: Pointer to current index of the buffer
 *
 */
void print_num(va_list set, char *buf, unsigned int *buf_i)
{
	int var = 1;
	char b;
	unsigned int num;

	if (va_arg(set, int) < 0)
	{
		buf[*buf_i] = '-';
		num = -(va_arg(set, int));
		*buf_i++;
	}
	else
		num = va_arg(set, int);

	while (num / var >= 10)
		var *= 10;

	while (var > 0)
	{
		buf[*buf_i] = (num / var) + '0';
		num = num % var;
		var = var / 10;
		*buf_i++;
	}
}
