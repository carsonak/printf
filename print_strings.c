#include "main.h"

/**
 * format_strings - handles formating of strings.
 * @str: the str to be formated.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int format_strings(const char *str, char_arr *buffer, modifiers mods)
{
	int bytes_written = 0;
	char *wip_str = NULL;
	intmax_t wip_i = 0, wip_chars = _strlen(str);
	intmax_t str_i = 0, spaces = 0;

	if (mods.precision > -1 && mods.precision < wip_chars)
		wip_chars = mods.precision;

	if (wip_chars < mods.width)
		spaces = mods.width - wip_chars;

	wip_str = malloc(wip_chars + spaces + 1);
	wip_str[wip_chars + spaces] = 0;
	if (mods.flags.left_adjust)
		_memset(wip_str + wip_chars, ' ', spaces);
	else
	{
		_memset(wip_str, ' ', spaces);
		wip_i = spaces;
	}

	for (str_i = 0; str[str_i] && str_i < wip_chars; str_i++, wip_i++)
		wip_str[wip_i] = str[str_i];

	bytes_written = buffer_puts(buffer, wip_str);
	free(wip_str);
	return (bytes_written);
}

/**
 * print_str - handles string format specifier.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_str(va_list args, char_arr *buffer, modifiers mods)
{
	const char *str;

	(void)mods;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	return (format_strings(str, buffer, mods));
}

/**
 * print_STR - handles custom string format specifier.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_STR(va_list args, char_arr *buffer, modifiers mods)
{
	unsigned int idx, nob = 0;
	const char *str;
	modifiers m = {0};

	(void)mods;
	m.precision = 2, m.int_mod.base = BASE16, m.int_mod.alphabet_case = UPPER;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	for (idx = 0; str[idx] != '\0'; idx++)
	{
		int ret_val;

		if (str[idx] > 31 && str[idx] < 127)
			ret_val = buffer_putchar(buffer, str[idx]);
		else
		{
			ret_val = buffer_puts(buffer, "\\x");
			if (ret_val < 0)
				return (ret_val);

			nob += ret_val;
			ret_val = format_integers(str[idx], buffer, m);
		}

		if (ret_val < 0)
			return (ret_val);

		nob += ret_val;
	}

	return (nob);
}
