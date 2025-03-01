#include "main.h"

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

	mods.int_mod.alphabet_case = LOWER;
	mods.int_mod.base = BASE16;
	mods.int_mod.is_negative = false;
	return (format_integers(num, buffer, mods));
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

	mods.int_mod.alphabet_case = UPPER;
	mods.int_mod.base = BASE16;
	mods.int_mod.is_negative = false;
	return (format_integers(num, buffer, mods));
}
