#include "main.h"

/**
 * get_flags - interpret the flag modifiers in the string.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_flags(string *format, modifiers *mods)
{
	(void)format;
	(void)mods;
}

/**
 * get_width - interpret the width modifiers in the string.
 * @args: list of arguments to `_printf`.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_width(va_list args, string *format, modifiers *mods)
{
	(void)args;
	(void)format;
	(void)mods;
}

/**
 * get_precision - interpret the precision modifiers in the string.
 * @args: list of arguments to `_printf`.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_precision(va_list args, string *format, modifiers *mods)
{
	(void)args;
	(void)format;
	(void)mods;
}

/**
 * get_type - interpret the length modifiers in the string.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_type(string *format, modifiers *mods)
{
	(void)format;
	(void)mods;
}

/**
 * format_handler - handles formatting of an argument.
 * @args: the argument to be formatted.
 * @format: pointer to the format string.
 * @buffer: pointer to the working buffer for `_printf`.
 *
 * Return: the number of characters printed, -1 if format doesn't match
 */
int format_handler(va_list args, string *format, char_arr *buffer)
{
	int bytes_printed = 0, i = 0;
	modifiers mods = {0};
	format_funcs fmt_funcs[] = {
		{print_character, 'c'},
		{print_str, 's'},
		{print_percent, '%'},
		{print_int_di, 'd'},
		{print_int_di, 'i'},
		{print_binary, 'b'},
		{print_oct, 'o'},
		{print_int_u, 'u'},
		{print_hexa_lower, 'x'},
		{print_hexa_upper, 'X'},
		{print_ptr, 'p'},
		{print_STR, 'S'},
		{0},
	};

	get_flags(format, &mods);
	get_width(args, format, &mods);
	get_precision(args, format, &mods);
	get_type(format, &mods);
	for (i = 0; fmt_funcs[i].ch; i++)
	{
		if (format->s[format->i] == fmt_funcs[i].ch)
		{
			bytes_printed = fmt_funcs[i].func(args, buffer, mods);
			break;
		}
	}

	if (!fmt_funcs[i].ch)
		bytes_printed = print_unknown(*format, buffer);

	return (bytes_printed);
}
