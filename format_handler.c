#include "main.h"

/**
 * get_flags - interpret the flag modifiers in the string.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_flags(string *format, modifiers *mods)
{
	char c = string_readc(format);

	if (c < 0)
		return;

	while (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
	{
		switch (c)
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

		c = string_readc(format);
	}

	string_readp(format);
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
	if (string_peekc(format) == '*')
	{
		mods->width = va_arg(args, int);
		string_readc(format);
		return;
	}

	if (!isdigit(string_peekc(format)))
		return;

	mods->width = _atoimax(&format->s[format->i]);
	for (i = count_digits(mods->width, BASE10); i > 0; --i)
		string_readc(format);
}

/**
 * get_precision - interpret the precision modifiers in the string.
 * @args: list of arguments to `_printf`.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_precision(va_list args, string *format, modifiers *mods)
{
	char c = string_peekc(format);

	mods->precision = -1;
	if (c != '.')
		return;

	string_readc(format);
	c = string_peekc(format);
	if (c == '*')
	{
		mods->precision = va_arg(args, int);
		string_readc(format);
		return;
	}

	mods->precision = _atoimax(&format->s[format->i]);
	if (c == '-')
		string_readc(format);

	while (isdigit(string_peekc(format)))
		string_readc(format);
}

/**
 * get_type - interpret the length modifiers in the string.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_type(string *format, modifiers *mods)
{
	char c = string_readc(format);

	if (c < 0)
		return;

	if (c == 'h')
	{
		mods->length = PRINTF_SHORT;
		if (string_peekc(format) == 'h')
		{
			string_readc(format);
			mods->length = PRINTF_CHAR;
		}
	}
	else if (c == 'l')
	{
		mods->length = PRINTF_LONG;
		if (string_peekc(format) == 'l')
		{
			string_readc(format);
			mods->length = PRINTF_LLONG;
		}
	}
	else if (c == 'L')
		mods->length = PRINTF_LDOUBLE;
	else if (c == 'j')
		mods->length = PRINTF_INTMAX_T;
	else if (c == 'z')
		mods->length = PRINTF_SIZE_T;
	else if (c == 't')
		mods->length = PRINTF_PTRDIFF_T;
	else
		string_readp(format);
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
	char c = 0;
	int bytes_printed = 0, i = 0;
	modifiers mods = {0};
	format_funcs fmt_funcs[] = {
		{print_character, 'c'},  {print_str, 's'},    {print_percent, '%'},
		{print_int_di, 'd'},     {print_int_di, 'i'}, {print_binary, 'b'},
		{print_oct, 'o'},        {print_int_u, 'u'},  {print_hexa_lower, 'x'},
		{print_hexa_upper, 'X'}, {print_ptr, 'p'},    {print_STR, 'S'},
		{print_reversed, 'r'},   {print_rot13, 'R'},  {0},
	};

	assert(format && buffer);
	get_flags(format, &mods);
	get_width(args, format, &mods);
	get_precision(args, format, &mods);
	get_type(format, &mods);
	c = string_peekc(format);
	for (i = 0; fmt_funcs[i].ch; i++)
	{
		if (c == fmt_funcs[i].ch)
		{
			bytes_printed = fmt_funcs[i].func(args, buffer, mods);
			string_readc(format);
			break;
		}
	}

	if (!fmt_funcs[i].ch)
		bytes_printed = print_unknown(format, buffer);

	return (bytes_printed);
}
