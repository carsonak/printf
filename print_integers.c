#include "main.h"

/**
 * count_digits - count how many decimal digits can represent an integer.
 * @n: the integer.
 *
 * Return: number of digits in the integer.
 */
static int count_digits(long int n)
{
	int digits = 0;

	/* clang-format off */
	do {
		/* clang-format on */
		n /= 10;
		++digits;
	} while (n);

	return (digits);
}

/**
 * print_integers - handles formatting of decimal integers.
 * @num: the number to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 * @is_negative: flag to indicate when number is negative.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
static int print_integers(
	uintmax_t num, char_arr *buffer, modifiers mods, bool is_negative)
{
	int bytes_written = 0, i = 0, character_count = 0;

	(void)mods;
	character_count = count_digits(num);
	if ((buffer->i + character_count) >= buffer->size)
		bytes_written = flush_buffer(buffer);

	if (is_negative)
		buffer->buf[buffer->i++] = '-';

	for (i = character_count - 1; i >= 0; --i)
	{
		buffer->buf[buffer->i + i] = num % 10 + '0';
		num /= 10;
	}

	buffer->i += character_count - 1;
	return (bytes_written);
}

/**
 * print_int_di - handle formating of `int`s.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_int_di(va_list args, char_arr *buffer, modifiers mods)
{
	int num = va_arg(args, int);

	return (print_integers(imaxabs(num), buffer, mods, num < 0 ? true : false));
}
