#include "main.h"

/**
 * print_prefix - handles the '#' modifier, receives one variable argument
 * @len: the number of digits stored in the buffer
 * @buf: the buffer
 * @buf_i: current index of the buffer
 *
 * Return: the nuber of characters printed if any
 */
int print_prefix(int len, char *const buf, int *const buf_i, ...)
{
	int nob = 0, i_cpy = *buf_i;
	char ch;
	va_list arg;

	va_start(arg, buf_i);
	ch = va_arg(arg, int);
	if (ch == 'x')
	{
		for (; len > 0; len--)
		{
			buf[*buf_i + 2] = buf[*buf_i];
			*buf_i -= 1;
		}
		buf[*buf_i] = '0';
		buf[*buf_i + 1] = ch;
		*buf_i = (i_cpy + 2);
	}
	else if (ch == 'X')
	{
		for (; len > 0; len--)
		{
			buf[*buf_i + 2] = buf[*buf_i];
			*buf_i -= 1;
		}
		buf[*buf_i] = '0';
		buf[*buf_i + 1] = ch;
		*buf_i = (i_cpy + 2);
	}
	else if (ch == 'o')
	{
		for (; len > 0; len--)
		{
			buf[*buf_i + 1] = buf[*buf_i];
			*buf_i -= 1;
		}
		buf[*buf_i] = ch;
		*buf_i = (i_cpy + 1);
	}
	va_end(arg);
	return (nob);
}
