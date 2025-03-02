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
	char c = 0;

	while (string_readp(format) != '%')
		++i;

	c = string_readn(format);
	while ((i > -1) && c > 0)
	{
		int ret_val = buffer_putchar(buffer, c);

		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
		--i;
		c = string_readn(format);
	}

	return (bytes_written);
}
