#include "main.h"

/**
 * print_int_di - handle formating of `int`s.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_int_di(va_list args, char_arr *buffer, modifiers mods)
{
	int num = va_arg(args, int);

	mods.int_mod.base = BASE10;
	if (num < 0)
		mods.int_mod.is_negative = true;

	return (format_integers(imaxabs(num), buffer, mods));
}

/**
 * print_int_u - handle formating of `unsigned int`s.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_int_u(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned int num = va_arg(args, unsigned int);

	mods.int_mod.base = BASE10;
	return (format_integers(num, buffer, mods));
}
