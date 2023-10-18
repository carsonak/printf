#include "main.h"

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed, or an error number
 */
int _printf(const char *format, ...)
{
	int err = 0;
	char buffer[BUFSZ];
	unsigned int *buf_i, a = 0, buffer_index = 0, count = 0;
	va_list set;

	if (format == NULL)
		return (-1);

	buf_i = buffer_index;
	_flushbuff(buffer, &buf_i);
	va_start(set, format);

	for (a = 0, buf_i = 0; format[a]; *buf_i++, a++)
	{
		if (*buf_i >= BUFSZ - 24)
			count += _flushbuff(buffer, buf_i);

		if (format[a] != '%')
		{
			a++;
			if (format[a] == '\0')
			{
				err = -1;
				break;
			}

			err += format_handler(set, format[a], buffer, buf_i);

			if (err == -1)
			{
				err = 0;
				buffer[*buf_i] = format[a - 1];
				*buf_i++;
				buffer[*buf_i] = format[a];
			}
		}
		else
			buffer[*buf_i] = format[a];
	}

	va_end(set);

	if (err >= 0)
		count += _flushbuff(buffer, buf_i);
	else
		return (err);

	return (count);
}
