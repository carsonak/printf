#include "main.h"

/**
 * format_handler - checks format specifier and executes the right functions
 * @set: the argument to be formatted
 * @format: the format specifier
 * @buf: pointer to character buffer
 * @buf_i: pointer to current index of the buffer
 *
 * Return: the number of characters printed, -1 if format doesn't match
 */
int format_handler(va_list set, char format, char *buf, unsigned int *buf_i)
{
	int b = 0;
	f_prt fmts[] = {{'c', print_c},
					{'s', print_s},
					{'%', print_pc},
					{'d', print_num},
					{'i', print_num},
					{NULL, NULL}};

	for (b = 0; fmts[b].ch; b++)
	{
		if (format == fmts[b].ch)
		{
			fmts[b].f(set, buf, buf_i);
			break;
		}
	}

	if (fmts[b].ch == NULL)
		return (-1);

	return (0);
}
