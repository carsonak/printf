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
int print_str(va_list args, char_arr buffer, modifiers mods)
{
	unsigned int idx, nob = 0;
	char *str;

	(void)mods;
	if (args)
	{
		str = va_arg(args, char *);
		if (str)
		{
			for (idx = 0; str[idx] != '\0'; idx++)
			{
				if (buffer.i >= buffer.size)
					nob += flush_buffer(buffer);

				buffer.buf[buffer.i] = str[idx];
				buffer.i += 1;
			}
			buffer.i -= 1;
		}
		else
		{
			str = "(null)";
			for (idx = 0; str[idx] != '\0'; idx++)
			{
				if (buffer.i >= buffer.size)
					nob += flush_buffer(buffer);

				buffer.buf[buffer.i] = str[idx];
				buffer.i += 1;
			}
			buffer.i -= 1;
		}
	}

	return (nob);
}
