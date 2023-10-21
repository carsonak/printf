#include "main.h"

/**
 * format_handler - checks format specifier and executes the right functions
 * @args: the argument to be formatted
 * @format: the format specifier
 * @buf: pointer to character buffer
 * @buf_i: pointer to current index of the buffer
 *
 * Return: the number of characters printed, -1 if format doesn't match
 */
long int
format_handler(va_list args, char format, char *buf, long int *buf_i)
{
	long int b, nob = 0;

	f_prt fmts[] = {{'c', print_c},
			{'s', print_s},
			{'%', print_pc},
			{'d', print_num},
			{'i', print_num},
			{'o', print_oct},
			{'u', print_dec},
			{'x', print_dec},
			{'\0', NULL}};

	for (b = 0; fmts[b].ch; b++)
	{
		if (format == fmts[b].ch)
		{
			nob += fmts[b].f(args, buf, buf_i);
			break;
		}
	}

	if (fmts[b].ch == '\0')
		return (-1);

	return (nob);
}
