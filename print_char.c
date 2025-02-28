#include "main.h"

/**
 * print_character - handles the 'c' (character) format specifier.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int print_character(va_list args, char_arr *buffer, modifiers mods)
{
	char ch;

	(void)mods;
	if (args)
	{
		ch = va_arg(args, int);
		if (ch)
			buffer->buf[buffer->i] = ch;
		else
			buffer->buf[buffer->i] = '\0';
	}

	return (0);
}
