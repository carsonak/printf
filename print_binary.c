#include "main.h"

/**
 * print_b - converts an unsigned int into binary
 * @args: arguments from _printf
 * @buf: Buffer used to store the converted number
 * @buf_i: Current index of the buffer
 *
 * Return: Number of characters printed if any
 */
long int print_b(va_list args, char *buf, long int *buf_i)
{
	long int nob = 0, count = 0;
	unsigned long int num = 0, hlp = 2;

	if (args)
	{
		num = va_arg(args, unsigned long int);
		if (num == 0)
		{
			buf[*buf_i] = '0';
			return (0);
		}
		while (hlp <= num)
		{
			hlp *= 2;
			count++;
		}

		hlp = count;
		if ((*buf_i + count) >= PRINTF_BUFFER - 24)
			nob += _flushbuff(buf, buf_i);

		while (count >= 0)
		{
			buf[*buf_i + count] = (num % 2) + '0';
			num /= 2;
			count--;
		}

		*buf_i += hlp;
	}

	return (nob);
}
