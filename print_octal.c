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
		n /= 8;
		++digits;
	} while (n);

	return (digits);
}

/**
 * print_oct - converts int to octal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_oct(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned long int num, var = 8;
	int nob = 0;
	long int count = 0, num_count = 0;

	(void)mods;
	num = va_arg(args, unsigned int);
	count = count_digits(num);
	num_count = count;
	while (count >= 0)
	{
		int ret_val = buffer_putchar(buffer, num % 8 + '0');

		if (ret_val < 0)
			return (ret_val);

		nob += ret_val;
		num = num / 8;
		count--;
	}

	buffer->i += num_count;
	return (nob);
}
