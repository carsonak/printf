#include "main.h"

/**
 * count_digits - count how many hexadecimal digits can represent an integer.
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
		n /= 16;
		++digits;
	} while (n);

	return (digits);
}

/**
 * print_hexadecimal - handles formatting of hexadecimal integers.
 * @num: the number to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 * @is_negative: flag to indicate when number is negative.
 * @is_upper: flag indicating whether to use upper case letters.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_hexadecimals(
	uintmax_t num, char_arr *buffer, modifiers mods, bool is_negative,
	bool is_upper)
{
	int bytes_written = 0, ret_val = 0;
	long int i = 0, character_count = 0;
	char a = is_upper ? 'A' : 'a';

	(void)mods;
	character_count = count_digits(num);
	if (is_negative)
	{
		ret_val = buffer_putchar(buffer, '-');
		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
	}

	for (i = character_count - 1; i >= 0; --i)
	{
		if (num % 16 < 10)
			ret_val = buffer_putchar(buffer, num % 16 + '0');
		else
			ret_val = buffer_putchar(buffer, ((num % 16) - 10) + a);

		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
		num = num / 16;
	}

	buffer->i += character_count - 1;
	return (bytes_written);
}

/**
 * print_hexa_lower - converts integer into lowercase hexadecimal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_hexa_lower(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_hexadecimals(num, buffer, mods, false, false));
}

/**
 * print_hexa_upper - converts integer into uppercase hexadecimal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_hexa_upper(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_hexadecimals(num, buffer, mods, false, true));
}
