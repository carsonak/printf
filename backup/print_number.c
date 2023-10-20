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
	long int var = 1, nob = 0, num = 0;

	num = va_arg(args, int);
	if (num < 0)
	{
		buf[*buf_i] = '-';
		num = -num;
		++*buf_i;
	}

	while (num / var >= 10)
		var *= 10;

	while (var > 0)
	{
		if (*buf_i >= PRINTF_BUFFER - 24)
			nob += _flushbuff(buf, buf_i);

		buf[*buf_i] = (num / var) + '0';
		num %= var;
		var /= 10;
		++*buf_i;
	}

	return (nob + *buf_i);
}
