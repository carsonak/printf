#include "main.h"

/**
 * init_working_string - allocates and initialises scratch space for formatting
 * strings.
 * @wip_str: struct where pointer to the scratch area is stored.
 * @mods: modifier flags.
 * @str_chars: number of characters that should be formatted.
 */
void init_working_string(
	/* clang-format off */
	char_arr * const wip_str, const modifiers mods, const intmax_t str_chars)
/* clang-format on */
{
	intmax_t spaces = 0;

	assert(wip_str && str_chars > -1);
	if (str_chars < mods.width)
		spaces = mods.width - str_chars;

	wip_str->size = str_chars + spaces + 1;
	wip_str->buf = malloc(wip_str->size);
	if (!wip_str->buf)
		return;

	wip_str->buf[wip_str->size - 1] = 0;
	if (mods.flags.left_adjust)
		_memset(wip_str->buf + str_chars, ' ', spaces);
	else
	{
		_memset(wip_str->buf, ' ', spaces);
		wip_str->i = spaces;
	}
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
	const char *str = va_arg(args, char *);
	int bytes_written = 0;
	char_arr wip_str = {0};
	intmax_t str_i = 0, str_chars = _strlen(str);

	if (!str)
		return (buffer_puts(buffer, "(null)"));

	if (mods.precision > -1 && mods.precision < str_chars)
		str_chars = mods.precision;

	init_working_string(&wip_str, mods, str_chars);
	if (!wip_str.buf)
	{
		buffer_flush(buffer);
		return (-1);
	}

	for (str_i = 0; str[str_i] && str_i < str_chars; ++str_i, ++wip_str.i)
		wip_str.buf[wip_str.i] = str[str_i];

	bytes_written = buffer_puts(buffer, wip_str.buf);
	free(wip_str.buf);
	return (bytes_written);
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
	const char *str = va_arg(args, char *);
	modifiers m = {0};

	(void)mods;
	m.precision = 2, m.int_mod.base = BASE16, m.int_mod.alphabet_case = UPPER;
	if (!str)
		return (buffer_puts(buffer, "(null)"));

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
