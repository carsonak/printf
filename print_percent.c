#include "main.h"

/**
 * print_percent - handles format specifier for '%'.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_percent(va_list args, char_arr *buffer, modifiers mods)
{
	(void)args;
	(void)mods;
	return (buffer_putchar(buffer, '%'));
}
