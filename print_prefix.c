#include "main.h"

/**
 * print_prefix - handles the '#' modifier, receives one variable argument
 * @len: the number of digits stored in the buffer
 * @buf: the buffer
 * @buf_i: current index of the buffer
 *
 * Return: the number of characters printed if any
 */
int print_prefix(int len, char_arr buffer, ...)
{
	int nob = 0, i_cpy = buffer.i;
	char ch;
	va_list arg;

	va_start(arg, buffer);
	ch = va_arg(arg, int);
	if (ch == 'x')
	{
		for (; len > 0; len--)
		{
			buffer.buf[buffer.i + 2] = buffer.buf[buffer.i];
			buffer.i -= 1;
		}

		buffer.buf[buffer.i] = '0';
		buffer.buf[buffer.i + 1] = ch;
		buffer.i = (i_cpy + 2);
	}
	else if (ch == 'X')
	{
		for (; len > 0; len--)
		{
			buffer.buf[buffer.i + 2] = buffer.buf[buffer.i];
			buffer.i -= 1;
		}
		buffer.buf[buffer.i] = '0';
		buffer.buf[buffer.i + 1] = ch;
		buffer.i = (i_cpy + 2);
	}
	else if (ch == 'o')
	{
		for (; len > 0; len--)
		{
			buffer.buf[buffer.i + 1] = buffer.buf[buffer.i];
			buffer.i -= 1;
		}
		buffer.buf[buffer.i] = ch;
		buffer.i = (i_cpy + 1);
	}
	va_end(arg);

	return (nob);
}
