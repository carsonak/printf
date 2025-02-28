#include "main.h"

/**
 * print_binary - converts an unsigned int into binary.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_binary(va_list args, char_arr buffer, modifiers mods)
{
	int nob = 0;
	long int count = 0;
	unsigned long int num = 0, hlp = 2;

	(void)mods;
	if (args)
	{
		num = va_arg(args, unsigned int);
		if (num == 0)
		{
			buffer.buf[buffer.i] = '0';
			return (0);
		}
		while (hlp <= num)
		{
			hlp *= 2;
			count++;
		}

		hlp = count;
		if ((buffer.i + count) >= buffer.size)
			nob += flush_buffer(buffer);

		while (count >= 0)
		{
			buffer.buf[buffer.i + count] = (num % 2) + '0';
			num /= 2;
			count--;
		}

		buffer.i += hlp;
	}

	return (nob);
}
