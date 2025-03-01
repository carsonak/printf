#include "main.h"

/**
 * get_flags - interpret the flag modifiers in the string.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_flags(string *format, modifiers *mods)
{
	while (format->s[format->i] == '#' || format->s[format->i] == '0' ||
	       format->s[format->i] == '-' || format->s[format->i] == ' ' ||
	       format->s[format->i] == '+')
	{
		switch (format->s[format->i])
		{
		case '#':
			mods->flags.alternate_form = true;
			break;
		case '0':
			mods->flags.zero_padding = true;
			break;
		case '-':
			mods->flags.left_adjust = true;
			break;
		case ' ':
			mods->flags.space = true;
			break;
		case '+':
			mods->flags.sign = true;
			break;
		default:
			break;
		}

		++format->i;
	}
}

/**
 * get_width - interpret the width modifiers in the string.
 * @args: list of arguments to `_printf`.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_width(va_list args, string *format, modifiers *mods)
{
	int i = 0;

	(void)args;
	if (!_isdigit(format->s[format->i]))
		return;

	mods->width = _atoimax(&format->s[format->i]);
	for (i = count_digits(mods->width, BASE10); i > 0; --i)
		++format->i;
}

/**
 * get_precision - interpret the precision modifiers in the string.
 * @args: list of arguments to `_printf`.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_precision(va_list args, string *format, modifiers *mods)
{
	int i = 0;

	(void)args;
	if (format->s[format->i] != '.')
		return;

	++format->i;
	mods->precision = _atoimax(&format->s[format->i]);
	for (i = count_digits(mods->width, BASE10); i > 0; --i)
		++format->i;
}

/**
 * get_type - interpret the length modifiers in the string.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_type(string *format, modifiers *mods)
{
	switch (format->s[format->i])
	{
	case 'h':
		mods->length = PRINTF_SHORT;
		if (format->s[format->i + 1] == 'h')
		{
			++format->i;
			mods->length = PRINTF_CHAR;
		}

		break;
	case 'l':
		mods->length = PRINTF_LONG;
		if (format->s[format->i + 1] == 'l')
		{
			++format->i;
			mods->length = PRINTF_LLONG;
		}

		break;
	case 'L':
		mods->length = PRINTF_LDOUBLE;
		break;
	case 'j':
		mods->length = PRINTF_INTMAX_T;
		break;
	case 'z':
		mods->length = PRINTF_SIZE_T;
		break;
	case 't':
		mods->length = PRINTF_PTRDIFF_T;
		break;
	default:
		break;
	}

	++format->i;
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
