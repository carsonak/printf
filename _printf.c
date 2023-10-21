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
	long int buf_i = 0, a = 0, count = 0, nob = _flushbuff(buffer, &buf_i);
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
<<<<<<< HEAD

	for (a = 0, *buf_i = 0; format[a]; ++*buf_i, a++)
		if (*buf_i >= PRINTF_BUFFER - 24)
			count += _flushbuff(buffer, buf_i);
=======
	for (a = 0, buf_i = 0; format[a]; buf_i++, a++)
	{
		if (buf_i >= PRINTF_BUFFER - 24)
			count += _flushbuff(buffer, &buf_i);
>>>>>>> acdca2c12acf65c36306c7a83d8f443d948498be
		if (format[a] == '%')
			a++;
			if (format[a] == '\0')
<<<<<<< HEAD
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
<<<<<<< HEAD
	return (count + *buf_i);
=======
	}

	return (count);
>>>>>>> main
=======
			{ /*If the next character is a null break out of the loop*/
				nob = -1;
				break;
			} /*Calling the format handler*/
			nob += format_handler(args, format[a], buffer, &buf_i);
			if (nob < 0)
			{ /*If no format specifier just print the percent and the character*/
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
>>>>>>> acdca2c12acf65c36306c7a83d8f443d948498be
}
