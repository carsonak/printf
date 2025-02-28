#include "main.h"

/**
 * print_percent - handles format specifier for '%'.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_percent(va_list args, char_arr *buffer, modifiers mods)
{
	(void)args;
	(void)mods;
	buffer->buf[buffer->i] = '%';
	return (0);
}
