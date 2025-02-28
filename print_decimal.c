#include "main.h"

/**
 * count_digits - count how many decimal digits can represent an integer.
 * @n: the integer.
 *
 * Return: number of digits in the integer.
 */
static unsigned int count_digits(long int n)
{
	unsigned int digits = 0;

	/* clang-format off */
	do {
		/* clang-format on */
		n /= 10;
		++digits;
	} while (n);

	return (digits);
}

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
int print_decimal(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned long int num;
	int bytes_written = 0, i = 0, character_count = 0;

	(void)mods;
	num = va_arg(args, unsigned int);
	character_count = (int)count_digits(num);
	if ((buffer->i + character_count) >= buffer->size)
		bytes_written = flush_buffer(buffer);

	for (i = character_count - 1; i >= 0; --i)
	{
		buffer->buf[buffer->i + i] = num % 10 + '0';
		num = num / 10;
	}

	buffer->i += character_count;
	return (bytes_written);
}
