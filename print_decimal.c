#include "main.h"

/**
 * print_decimal - converts integer to decimal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_decimal(va_list args, char_arr buffer, modifiers mods)
{
	unsigned long int num;
	unsigned int var = 10;
	int nob = 0, count = 0, num_count = 0;

	(void)mods;
	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		buffer.buf[buffer.i] = '0';
		return (0);
	}

	while (var < num)
	{
		var = var * 10;
		count++;
	}

	num_count = count;
	if ((buffer.i + count) >= buffer.size)
		nob += flush_buffer(buffer);

	while (count >= 0)
	{
		buffer.buf[buffer.i + count] = num % 10 + '0';
		num = num / 10;
		count--;
	}

	buffer.i = buffer.i + num_count;
	return (nob);
}
