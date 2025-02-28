#include "main.h"

/**
 * print_unknown - backtracks to the last '%' and prints the string as is.
 * @format: the format string.
 * @buffer: working buffer for `_printf`.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_unknown(string format, char_arr *buffer)
{
	int i = 0, bytes_written = 0;

	while (format.s[format.i - i] != '%')
		++i;

	if (buffer->i + i >= buffer->size)
		bytes_written = flush_buffer(buffer);

	while (i > -1)
	{
		buffer->buf[buffer->i] = format.s[format.i - i];
		++buffer->i;
		--i;
	}

	--buffer->i;
	return (bytes_written);
}
