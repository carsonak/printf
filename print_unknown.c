#include "_printf_internals.h"

/**
 * is_length_modifier - checks if a character is a `_printf()` length modifier.
 * @c: the character.
 *
 * Return: true if the character is a length modifier, false otherwise.
 */
static bool is_length_modifier(char c)
{
	return (
		c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z' || c == 't');
}

/**
 * print_unknown - backtracks to the last '%' and prints the string as is.
 * @format: the format string.
 * @buffer: working buffer for `_printf`.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_unknown(string *format, char_arr *buffer)
{
	intmax_t i = 0, bytes_written = 0;
	char c = string_peekc(format);
	bool length_modifier_seen = false;

	if (!isprint(c) && !isspace(c))
	{
		buffer_flush(buffer);
		return (-1);
	}

	while (c != '%')
	{
		++i;
		c = string_readp(format);
	}

	for (c = string_readc(format); (i > -1) && c > -1;
	     c = string_readc(format), --i)
	{
		int ret_val;

		if (!length_modifier_seen && is_length_modifier(c))
		{
			length_modifier_seen = true;
			continue;
		}

		ret_val = buffer_putchar(buffer, c);
		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
	}

	string_readp(format);
	return (bytes_written);
}
