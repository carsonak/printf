#include "main.h"

/**
 * print_oct - converts int to octal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_oct(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned int num = va_arg(args, unsigned int);

	mods.int_mod.base = BASE08;
	return (format_integers(num, buffer, mods));
}
