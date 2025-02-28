#include "main.h"

/**
 * print_plus - handles the ' ' & '+' modifier, receives one variable argument
 * @len: the number of digits stored in the buffer
 * @buf: the buffer
 * @buf_i: current index of the buffer
 *
 * Return: the nuber of characters printed if any
 */
int print_plus(int len, char_arr *buffer, ...)
{
	int nob = 0, i_cpy = buffer->i;
	char ch;
	va_list arg;

	if (buffer->buf[buffer->i - len] == '-')
		return (nob);

	va_start(arg, buffer);
	ch = va_arg(arg, int);

	while (len > 0)
	{
		buffer->buf[buffer->i + 1] = buffer->buf[buffer->i];
		buffer->i -= 1;
		len--;
	}

	buffer->buf[buffer->i] = ch;
	buffer->i = (i_cpy + 1);

	return (nob);
}
