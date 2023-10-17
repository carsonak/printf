#include "main.h"

/**
 * format_handler - handles formatting of strings
 * @format: the format specifier
 * @set: the argument to be formatted
 * @buf: character buffer
 *
 * Return: the number of characters printed, -1 if format doesn't match
 */
int format_handler(va_list set, char format, char *buf)
{
	int b = 0, err = 0;
	f_prt fmts[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_pc},
		{'d', print_i},
		{'i', print_i},
		{'\0', NULL}};

	for (b = 0; fmts[b].ch; b++)
	{
		if (format == fmts[b].ch)
		{
			err += fmts[b].f(set, buf);
			break;
		}
	}

	if (fmts[b].ch == '\0')
		return (-1);

	return (err);
}
