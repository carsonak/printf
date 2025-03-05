#include "_printf_internals.h"

/**
 * print_character - handles the 'c' (character) format specifier.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_character(va_list args, char_arr *buffer, const modifiers mods)
{
	char c = va_arg(args, int);
	intmax_t i = 0;
	int ret_val = 0, bytes_written = 0;

	if (mods.flags.left_adjust)
	{
		ret_val = buffer_putchar(buffer, c);
		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
		for (i = 1; i < mods.width; i++)
		{
			ret_val = buffer_putchar(buffer, ' ');
			if (ret_val < 0)
				return (ret_val);

			bytes_written += ret_val;
		}
	}
	else
	{
		for (i = 0; i < mods.width - 1; i++)
		{
			ret_val = buffer_putchar(buffer, ' ');
			if (ret_val < 0)
				return (ret_val);

			bytes_written += ret_val;
		}

		ret_val = buffer_putchar(buffer, c);
		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
	}

	return (bytes_written);
}
