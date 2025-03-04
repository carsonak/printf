#include "main.h"

/**
 * print_reversed - handles reversed string format specifier.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: number of characters written, -1 on error.
 */
int print_reversed(va_list args, char_arr *buffer, modifiers mods)
{
	char *to_reverse = va_arg(args, char *);
	int bytes_written = 0;
	char_arr wip_str = {0};
	intmax_t str_i = 0, str_chars = _strlen(to_reverse);

	if (!to_reverse)
		return (buffer_puts(buffer, "(null)"));

	if (mods.precision > -1 && mods.precision < str_chars)
		str_chars = mods.precision;

	init_working_string(&wip_str, mods, str_chars);
	if (!wip_str.buf)
	{
		buffer_flush(buffer);
		return (-1);
	}

	for (str_i = _strlen(to_reverse) - 1; str_chars > 0; --str_i, --str_chars)
		wip_str.buf[wip_str.i++] = to_reverse[str_i];

	bytes_written = buffer_puts(buffer, wip_str.buf);
	free(wip_str.buf);
	return (bytes_written);
}
