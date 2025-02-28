#include "main.h"
/**
 * print_hexa_lower - converts integer into lowercase hexadecimal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_hexa_lower(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned long int num, num_count = 0, var = 16;
	int nob = 0, count = 0;

	(void)mods;
	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		buffer->buf[buffer->i] = '0';
		return (0);
	}

	while (var <= num)
	{
		var = var * 16;
		count++;
	}

	num_count = count;
	if ((buffer->i + count) >= buffer->size)
		nob += flush_buffer(buffer);

	while (count >= 0)
	{
		if (num % 16 < 10)
		{
			buffer->buf[buffer->i + count] = num % 16 + '0';
		}
		else if (num % 16 >= 10 && num % 16 <= 15)
		{
			buffer->buf[buffer->i + count] = ((num % 16) - 10) + 'a';
		}
		num = num / 16;
		count--;
	}
	buffer->i = buffer->i + num_count;
	return (nob);
}
