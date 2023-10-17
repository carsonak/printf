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
	unsigned int a = 0;
	va_list set;

	if (format == NULL)
		return (-1);

	va_start(set, format);
	memset(buffer, '0', 1023);
	buffer[1023] = '\0';
	for (a = 0; format[a] && a < 1024; a++)
	{
		if (format[a] != '%')
			buffer[a] = format[a];
		else
		{
			a++;
			err += format_handler(set, format[a], &buffer[a]);
			if (err < 0 && format[a])
			{
				err = 0;
				buffer[a - 1] = format[a - 1];
				buffer[a] = format[a];
			}
			else
				break;
		}
	}
	va_end(set);

	if (err >= 0)
		count = _write(buffer, a);
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
