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
	char c = string_getc(format);

	while (c != '%')
	{
		++i;
		c = string_readp(format);
	}

	for (c = string_readc(format); (i > -1) && c > -1;
	     c = string_readc(format), --i)
	{
		int ret_val = buffer_putchar(buffer, c);

		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
	}

	string_readp(format);
	return (bytes_written);
}
