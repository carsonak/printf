#include "_printf_internals.h"

/**
 * rot13_letter - rotates a letter by 13 characters.
 * @c: the letter.
 *
 * Return: the rotated letter.
 */
static char rot13_letter(char c)
{
	if (!isalpha(c))
		return (c);

	if (islower(c))
		c = (((c - 'a') + 13) % 26) + 'a';
	else
		c = (((c - 'A') + 13) % 26) + 'A';

	return (c);
}

/**
 * print_rot13 - handles rot13 string format specifier.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: number of characters written, -1 on error.
 */
int print_rot13(va_list args, char_arr *buffer, modifiers mods)
{
	char *to_rotate = va_arg(args, char *);
	int bytes_written = 0;
	char_arr wip_str = {0};
	intmax_t str_i = 0, str_chars = _strlen(to_rotate);

	if (!to_rotate)
		return (buffer_puts(buffer, "(null)"));

	if (mods.precision > -1 && mods.precision < str_chars)
		str_chars = mods.precision;

	init_working_string(&wip_str, mods, str_chars);
	if (!wip_str.buf)
	{
		buffer_flush(buffer);
		return (-1);
	}

	for (str_i = 0; str_i < str_chars; ++str_i)
		wip_str.buf[wip_str.i++] = rot13_letter(to_rotate[str_i]);

	bytes_written = buffer_puts(buffer, wip_str.buf);
	free(wip_str.buf);
	return (bytes_written);
}
