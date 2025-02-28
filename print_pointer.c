#include "main.h"

/**
 * print_ptr - prints an address in lowercase hexadecimal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_ptr(va_list args, char_arr buffer, modifiers mods)
{
	int nob = 0, count = 0;
	unsigned long int address, address_count = 0, var = 16;
	char *null = "(nil)";

	(void)mods;
	address = (unsigned long int)va_arg(args, void *);
	if (address == 0)
	{
		if ((buffer.i + 5) >= buffer.size - 24)
			nob += flush_buffer(buffer);
		while (null[count])
		{
			buffer.buf[buffer.i] = null[count];
			buffer.i += 1;
			count++;
		}
		buffer.i -= 1;
		return (nob);
	}

	while (var <= address)
	{
		var = var * 16;
		count++;
	}
	if ((buffer.i + count) >= buffer.size - 24)
		nob += flush_buffer(buffer);

	address_count = count;
	while (count >= 0)
	{
		if (address % 16 < 10)
			buffer.buf[buffer.i + count] = address % 16 + '0';
		else if (address % 16 > 9 && address % 16 < 16)
			buffer.buf[buffer.i + count] = ((address % 16) - 10) + 'a';

		address /= 16;
		count--;
	}
	buffer.i += address_count;
	return (print_prefix(address_count, buffer, 'x'));
}
