#include "main.h"

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed, or an error number
 */
int _printf(const char *format, ...)
{
	int err = 0, count = 0;
	char *ch = malloc(sizeof(*ch));
	unsigned long int a = 0;
	va_list set;

	if (format == NULL)
		return (-1);

	va_start(set, format);
	for (a = 0; format[a]; a++)
	{
		if (format[a] != '%')
		{
			*ch = format[a];
			count += write(1, ch, sizeof(*ch));
		}
		else
		{
			a++;
			err += format_handler(format[a], set);
			if (err >= 0)
				count += err;
			else if (err < 0 && format[a])
			{
				err = 0;
				*ch = format[a - 1];
				count += write(1, ch, sizeof(*ch));
				*ch = format[a];
				count += write(1, ch, sizeof(*ch));
			}
			else
				break;
		}
	}
	va_end(set);

	if (err < 0)
		return (err);

	return (count);
}
