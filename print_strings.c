#include "main.h"

/**
 * print_strings - handles formating of strings.
 * @str: the str to be formated.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_strings(const char *str, char_arr *buffer, modifiers mods)
{
	unsigned int idx, nob = 0;

	(void)mods;
	for (idx = 0; str[idx] != '\0'; idx++)
	{
		int ret_val = buffer_putchar(buffer, str[idx]);

		if (ret_val < 0)
			return (ret_val);

		nob += ret_val;
		++buffer->i;
	}

	buffer->i -= 1;
	return (nob);
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

	return (print_strings(str, buffer, mods));
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

	(void)mods;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";

	for (idx = 0; str[idx] != '\0'; idx++)
	{
		int ret_val;

		if (str[idx] > 31 /* && str[idx] < 128 */)
			ret_val = buffer_putchar(buffer, str[idx]);
		else
		{
			modifiers m = {0};

			m.precision = 2;
			ret_val = print_hexadecimals(str[idx], buffer, m, false, true);
		}

		if (ret_val < 0)
			return (ret_val);

		nob += ret_val;
		++buffer->i;
	}

	buffer->i -= 1;
	return (nob);
}
