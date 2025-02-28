#include "main.h"

/**
 * print_str - handles string format specifier.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_str(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned int idx, nob = 0;
	const char *str;

	(void)mods;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	for (idx = 0; str[idx] != '\0'; idx++)
	{
		int ret_val = buffer_putchar(buffer, str[idx]);

		if (ret_val < 0)
			return (ret_val);

		nob += ret_val;
		++buffer->i;
	}

	buffer->i -= 1;
	return (nob);
}
