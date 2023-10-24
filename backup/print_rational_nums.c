#include "main.h"

/**
 * print_Rnum - converts int to bufing
 * @args: argument from _printf
 * @buf: Pointer to the buffer
 * @buf_i: Pointer to current index of the buffer
 *
 * Return: number of characters written
 */
int print_Rnum(va_list args, char *const buf, int *const buf_i)
{
	int var = 1, nob = 0, count = 1;
	long int num = 0;

	num = va_arg(args, long int);
	if (num < 0)
	{
		buf[*buf_i] = '-';
		num = -num;
		*buf_i += 1;
	}

	while (num / var >= 10)
	{
		var *= 10;
		count++;
	}

	if ((*buf_i + count) >= PRINTF_BUFFER - 24)
		nob += _flushbuff(buf, buf_i);

	while (var > 0)
	{
		buf[*buf_i] = (num / var) + '0';
		num %= var;
		var /= 10;
		*buf_i += 1;
	}

	*buf_i -= 1;

	return (nob);
}
