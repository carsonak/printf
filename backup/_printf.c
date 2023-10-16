#include "main.h"

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int ch, count = 0;
	va_list set;
	unsigned long int a = 0, b = 0;
	f_prt fmts[] = {
		{'c', print_c},
		{'d', print_d},
		{'s', print_s},
		{'%', print_pc},
		{'\0', NULL}};

	if (format == NULL)
		return (0);

	va_start(set, format);
	for (a = 0; format[a]; a++)
	{
		if (format[a] != '%')
		{
			ch = format[a];
			count += write(1, ch, sizeof(ch));
		}
		else
		{
			a++;
			for (b = 0; fmts[b].ch; b++)
			{
				if (format[a] == fmts[b].ch)
				{
					count += fmts[b].f(set);
					break;
				}
			}
		}
	}

	va_end(set);

	return (count);
}
