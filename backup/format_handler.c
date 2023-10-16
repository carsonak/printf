#include "main.h"

/**
 * format_handler - handles formatting of strings
 * @format: the format specifier
 * @set: the argument to be formatted
 *
 * Return: the number of characters printed, -1 if format doesn't match
 */
int format_handler(char format, va_list set)
{
	unsigned long int b = 0, count = 0;
	f_prt fmts[] = {
		{'c', print_c},
		{'d', print_d},
		{'s', print_s},
		{'%', print_pc},
		{'\0', NULL}};

	for (b = 0; fmts[b].ch; b++)
	{
		if (format == fmts[b].ch)
		{
			count += fmts[b].f(set);
			break;
		}
	}

	if (fmts[b].ch == '\0')
		return (-1);

	return (count);
}
