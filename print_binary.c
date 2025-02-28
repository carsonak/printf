#include "main.h"

/**
 * count_digits - count how many binary digits can represent an integer.
 * @n: the integer.
 *
 * Return: number of digits in the integer.
 */
static unsigned int count_digits(long int n)
{
	int digits = 0;

	/* clang-format off */
	do {
		/* clang-format on */
		n /= 2;
		++digits;
	} while (n);

	return (digits);
}

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
int print_binary(va_list args, char_arr *buffer, modifiers mods)
{
	int bytes_written = 0;
	unsigned int num = 0;
	long int character_count = 0, i = 0;

	(void)mods;
	num = va_arg(args, unsigned int);
	character_count = count_digits(num);
	for (i = character_count - 1; i >= 0; --i)
	{
		int ret_val = buffer_putchar(buffer, (num % 2) + '0');

		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
		num /= 2;
	}

	buffer->i += character_count - 1;
	return (bytes_written);
}
