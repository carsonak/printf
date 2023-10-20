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
	unsigned int buf_i = 0, a = 0;
	long int count = 0, nob = _flushbuff(buffer, &buf_i);
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (a = 0, buf_i = 0; format[a]; buf_i++, a++)
	{
		if (buf_i >= PRINTF_BUFFER - 24)
			count += _flushbuff(buffer, &buf_i);

		if (format[a] == '%')
		{
			a++;
			if (format[a] == '\0')
			{ /*If the next character is a null break out of the loop*/
				nob = -1;
				break;
			}
			nob += format_handler(args, format[a], buffer, &buf_i); /*Calling the format handler*/
			if (nob < 0)
			{ /*If there is no format specifier just print the percent and the character*/
				buffer[buf_i] = format[a - 1];
				buf_i++;
				buffer[buf_i] = format[a];
			}
			else
				count += nob;
			nob = 0;
		}
		else
			buffer[buf_i] = format[a];
	}
	va_end(args);
	if (nob < 0)
	{
		_flushbuff(buffer, &buf_i);
		return (nob);
	}
	return (count + _flushbuff(buffer, &buf_i));
}
