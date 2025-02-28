#include "main.h"

/**
 * print_ptr - prints an address in lowercase hexadecimal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_ptr(va_list args, char_arr *buffer, modifiers mods)
{
	int nob = 0, count = 0;
	size_t address;
	char *null = "(nil)";

	(void)mods;
	address = (size_t)va_arg(args, void *);
	if (address == 0)
	{
		while (null[count])
		{
			buffer->buf[buffer->i] = null[count];
			buffer->i += 1;
			count++;
		}
		buffer->i -= 1;
		return (nob);
	}

	mods.flags.alternate_form = true;
	return (print_hexadecimals(address, buffer, mods, false, false));
}
