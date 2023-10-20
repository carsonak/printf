#include "main.h"

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed, or an error number
 */
int _printf(const char *format, ...)
{
	long int err, count = 0;
	char buffer[PRINTF_BUFFER];
	unsigned int *buf_i, a = 0, buffer_index = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	buf_i = &buffer_index;
	err = _flushbuff(buffer, buf_i);
	va_start(args, format);

	for (a = 0, *buf_i = 0; format[a]; ++*buf_i, a++)
		if (*buf_i >= PRINTF_BUFFER - 24)
			count += _flushbuff(buffer, buf_i);
		if (format[a] == '%')
			a++;
			if (format[a] == '\0')
				err = -1;
				break;
			err += format_handler(args, format[a], buffer, buf_i);
			if (err < 0)
				err = 0;
				buffer[*buf_i] = format[a - 1];
				++*buf_i;
				buffer[*buf_i] = format[a];
			else
				count += err;
				err = 0;
		else
			buffer[*buf_i] = format[a];
	va_end(args);
	if (err >= 0)
		count += _flushbuff(buffer, buf_i);
	else
		_flushbuff(buffer, buf_i);
		return (err);
	return (count + *buf_i);
}
