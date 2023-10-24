#include "main.h"

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed, or an error number
 */
int _printf(const char *format, ...)
{
	char buffer[PRINTF_BUFFER];
	int buf_i = 0, fmt_i = 0, count = 0, nob = _flushbuff(buffer, &buf_i);
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (fmt_i = 0, buf_i = 0; format[fmt_i]; buf_i++, fmt_i++)
	{
		if (buf_i >= PRINTF_BUFFER - 24)
			count += _flushbuff(buffer, &buf_i);
		if (format[fmt_i] == '%')
		{
			fmt_i++;
			if (format[fmt_i] == '\0')
			{ /*If the next character is fmt_i null break out of the loop*/
				nob = -1;
				break;
			} /*Calling the format handler*/
			nob += format_handler(args, format, fmt_i, buffer, &buf_i);
			if (nob < 0)
			{ /*If no format specifier just print the percent and the character*/
				buffer[buf_i] = format[fmt_i - 1];
				buf_i++;
				buffer[buf_i] = format[fmt_i];
			}
			else
				count += nob;
			nob = 0;
		}
		else
			buffer[buf_i] = format[fmt_i];
	}
	va_end(args);
	if (nob < 0)
	{
		_flushbuff(buffer, &buf_i);
		return (nob);
	}
	return (count + _flushbuff(buffer, &buf_i));
}
