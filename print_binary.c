#include "main.h"

/**
 * print_binary - converts an unsigned int into binary.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_binary(va_list args, char_arr *buffer, modifiers mods)
{
	int bytes_written = 0;
	unsigned int num = 0;
	long int character_count = 0, i = 0;

	(void)mods;
	num = va_arg(args, unsigned int);
	character_count = count_digits(num, BASE02);
	for (i = character_count - 1; i >= 0; --i)
	{
		int ret_val = buffer_putchar(buffer, (num % 2) + '0');

		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
		num /= 2;
	}

	return (bytes_written);
}
