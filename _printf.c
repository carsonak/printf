#include "main.h"

#define PRINTF_BUFFER_LENGTH (1024U)

/**
 * get_flags - interpret the flag modifiers in the string.
 * @format: the format string.
 * @mods: variable to store results.
 */
static void get_flags(string format, modifiers mods)
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
static void get_width(va_list args, string format, modifiers mods)
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
static void get_precision(va_list args, string format, modifiers mods)
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
static void get_type(string format, modifiers mods)
{
	(void)format;
	(void)mods;
}

/**
 * format_handler - handles formatting of an argument.
 * @args: the argument to be formatted.
 * @format: the format string.
 * @buffer: working buffer for `_printf`.
 *
 * Return: the number of characters printed, -1 if format doesn't match
 */
static int format_handler(va_list args, string format, char_arr buffer)
{
	int bytes_printed = -1, i = 0;
	modifiers mods = {0};
	format_funcs fmt_funcs[] = {
		{print_character, 'c'},  {print_str, 's'},     {print_percent, '%'},
		{print_decimal, 'd'},    {print_decimal, 'i'}, {print_binary, 'b'},
		{print_oct, 'o'},        {print_decimal, 'u'}, {print_lower_hexa, 'x'},
		{print_upper_hexa, 'X'}, {print_ptr, 'p'},     {0},
	};

	get_flags(format, mods);
	get_width(args, format, mods);
	get_precision(args, format, mods);
	get_type(format, mods);
	for (i = 0; i < (int)(sizeof(fmt_funcs) / sizeof(*fmt_funcs)); i++)
	{
		if (format.s[format.i] == fmt_funcs[i].ch)
		{
			bytes_printed = fmt_funcs[i].func(args, buffer, mods);
			break;
		}
	}

	return (bytes_printed);
}

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed, or an error number
 */
int _printf(const char *format, ...)
{
	va_list args;
	int bytes_printed = 0, ret_val = 0;
	string fmt;
	char arr[PRINTF_BUFFER_LENGTH];
	char_arr buffer;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	fmt.size = -1;
	fmt.i = 0;
	fmt.s = format;
	buffer.size = sizeof(arr);
	buffer.i = 0;
	buffer.buf = arr;
	for (fmt.i = 0, buffer.i = 0; fmt.s[fmt.i]; ++buffer.i, ++fmt.i)
	{
		if (buffer.i >= buffer.size)
		{
			ret_val = flush_buffer(buffer);
			if (ret_val < 0)
				goto error_handling;

			bytes_printed += ret_val;
		}

		if (format[fmt.i] != '%')
		{
			buffer.buf[buffer.i] = format[fmt.i];
			continue;
		}

		++fmt.i;
		if (format[fmt.i] == '\0')
			break;

		ret_val = format_handler(args, fmt, buffer);
		if (ret_val < 0)
			goto error_handling;

		bytes_printed += ret_val;
	}

	va_end(args);
	ret_val = flush_buffer(buffer);
	if (ret_val < 0)
	{
error_handling:
		return (-1);
	}

	return (bytes_printed + ret_val);
}
