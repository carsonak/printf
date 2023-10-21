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
	long int nob = 0, num = 0, i = 0;
	unsigned long int num_cpy = 0, hlp = 1;

	if (args)
	{
		num = va_arg(args, long int);
		num_cpy = (num < 0 ? -num : num);

		if (num == 0)
		{
			buf[*buf_i] = '0';
			return (0);
		}
		while (hlp < num_cpy)
		{
			hlp *= 2;
			i++;
		}

		if (hlp > num_cpy)
			i--;

		hlp = i;
		if ((*buf_i + i) >= PRINTF_BUFFER - 24)
			nob += _flushbuff(buf, buf_i);

		while (i >= 0)
		{
			buf[*buf_i + i] = (num_cpy % 2) + '0';
			num_cpy /= 2;
			i--;
		}

		*buf_i += hlp;
	}

	return (nob);
}
