#include "main.h"

/**
 * print_unknown - backtracks to the last '%' and prints the string as is.
 * @format: the format string.
 * @buffer: working buffer for `_printf`.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_unknown(string *format, char_arr *buffer)
{
	intmax_t i = 0, bytes_written = 0;

	while (format->s[format->i - i] != '%')
		++i;

	while ((i > -1) && format->s[format->i - i])
	{
		int ret_val = buffer_putchar(buffer, format->s[format->i - i]);

		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
		--i;
	}

	if ((i > -1) && !format->s[format->i - i])
		--format->i;

	return (bytes_written);
}
