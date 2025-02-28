#include "main.h"

/**
 * print_character - handles the 'c' (character) format specifier.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_character(va_list args, char_arr *buffer, modifiers mods)
{
	(void)mods;
	return (buffer_putchar(buffer, va_arg(args, int)));
}
