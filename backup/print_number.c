#include "main.h"

/**
 * print_num - converts int to bufing
 * @args: argument from _printf
 * @buf: Pointer to the buffer
 * @buf_i: Pointer to current index of the buffer
 *
 * Return: number of characters written
 */
long int print_num(va_list args, char *buf, unsigned int *buf_i)
{
	long int var = 1, err = 0;
	unsigned int num;

	if (va_arg(args, int) < 0)
	{
		buf[*buf_i] = '-';
		num = -(va_arg(args, int));
		++*buf_i;
	}
	else
		num = va_arg(args, int);

	while (num / var >= 10)
		var *= 10;

	while (var > 0)
	{
		if (*buf_i >= BUFSIZ - 24)
			err += _flushbuff(buf, buf_i);

		buf[*buf_i] = (num / var) + '0';
		num = num % var;
		var = var / 10;
		++*buf_i;
	}

	return (err + *buf_i);
}
