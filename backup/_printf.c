#include "main.h"

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, *ch = malloc(sizeof(int));
	va_list set;
	unsigned long int a = 0;

	if (format == NULL)
		return (0);

	va_start(set, format);
	for (a = 0; format[a]; a++)
	{
		if (format[a] != '%')
		{
			*ch = format[a];
			write(1, ch, sizeof(*ch));
			count++;
		}
		else
		{
			a++;
			if (format_handler(format[a], set) == -1)
			{
				*ch = format[a];
				write(1, ch, sizeof(*ch));
				count++;
			}

			count += format_handler(format[a], set);
		}
	}

	va_end(set);

	return (count);
}
