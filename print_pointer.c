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
	size_t address = (size_t)va_arg(args, void *);

	if (address == 0)
		return (buffer_puts(buffer, "(nil)"));

	mods.flags.alternate_form = true;
	mods.int_mod.base = BASE16;
	mods.int_mod.alphabet_case = LOWER;
	return (format_integers(address, buffer, mods));
}
