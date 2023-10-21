#include "main.h"

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed, or an error number
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	long int nob, count = 0;
=======
>>>>>>> main
	char buffer[PRINTF_BUFFER];
	long int buf_i = 0, a = 0, count = 0, nob = _flushbuff(buffer, &buf_i);
	va_list args;

	if (format == NULL)
		return (-1);
<<<<<<< HEAD

	buf_i = &buffer_index;
	nob = _flushbuff(buffer, buf_i);
=======
>>>>>>> main
	va_start(args, format);
<<<<<<< HEAD

	for (a = 0, *buf_i = 0; format[a]; ++*buf_i, a++)
	{
		if (*buf_i >= PRINTF_BUFFER - 24)
		{
			count += _flushbuff(buffer, buf_i);
<<<<<<< HEAD
		}
=======
=======
	for (a = 0, buf_i = 0; format[a]; buf_i++, a++)
	{
		if (buf_i >= PRINTF_BUFFER - 24)
			count += _flushbuff(buffer, &buf_i);
>>>>>>> acdca2c12acf65c36306c7a83d8f443d948498be
>>>>>>> main
		if (format[a] == '%')
		{
			a++;
			if (format[a] == '\0')
<<<<<<< HEAD
				nob = -1;
=======
<<<<<<< HEAD
				err = -1;
>>>>>>> main
				break;
			nob += format_handler(args, format[a], buffer, buf_i);
			if (nob < 0)
				nob = 0;
				buffer[*buf_i] = format[a - 1];
				++*buf_i;
				buffer[*buf_i] = format[a];
			else
				count += nob;
				nob = 0;
		}
		else
			buffer[*buf_i] = format[a];
	}
	va_end(args);
	if (nob >= 0)
		count += _flushbuff(buffer, buf_i);
	else
		_flushbuff(buffer, buf_i);
<<<<<<< HEAD
		return (nob);
	return (count + *buf_i);
	}

	return (count);
=======
		return (err);
<<<<<<< HEAD
	return (count + *buf_i);
=======
	}

	return (count);
>>>>>>> main
<<<<<<< HEAD
>>>>>>> 6055ec1ae4464d4aa1f9114392c23864645aedb3
=======
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
>>>>>>> main
}
