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
	char buffer[1024];
	unsigned int a = 0, b = 0;
	va_list set;

	if (format == NULL)
		return (-1);

	va_start(set, format);
	memset(buffer, '0', sizeof(buffer));
	buffer[1023] = '\0';
	while (format[a] && b < 1024)
	{
		if (format[a] != '%')
			buffer[b] = format[a];
		else
		{
			a++;
			if (format[a] == '\0')
				break;
			err += format_handler(set, format[a], &buffer[b]);
			if (err < 0 && format[a])
			{
				err = 0;
				buffer[b] = format[a - 1];
				b++;
				buffer[b] = format[a];
			}
			else
			{
				b = b + err;
			}
		}
		b++;
		a++;
	}
	va_end(set);

	if (err >= 0)
		count = _write(buffer, b);
	else
		return (err);

	return (count);
}

/**
 * _write - writes contents of buffer
 * @buf: the buffer
 * @a: number of bytes to be written
 *
 * Return: Number of bytes written
 */
int _write(char *buf, unsigned int a)
{
	return (write(1, buf, a));
}
