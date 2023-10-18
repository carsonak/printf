#include "main.h"

/**
 * print_s - handles string format specifier
 * @args: argument from the _printf function
 * @buf: pointer to buffer
 * @buf_i: pointer to current index of the buffer
 *
 * Return: number of characters written
 */
long int print_s(va_list args, char *buf, unsigned int *buf_i)
{
	unsigned int idx, err = 0;
	char *str;

	if (args)
	{
		str = va_arg(args, char *);
		if (str)
		{
			for (idx = 0; str[idx]; idx++, ++*buf_i)
			{
				if (*buf_i >= BUFSIZ - 24)
					err += _flushbuff(buf, buf_i);

				buf[*buf_i] = str[idx];
			}
		}
		else
		{
			str = "(null)";
			for (idx = 0; str[idx]; idx++, ++*buf_i)
			{
				if (*buf_i >= BUFSIZ - 24)
					err += _flushbuff(buf, buf_i);

				buf[*buf_i] = str[idx];
			}
		}
	}

	return (err + *buf_i);
}
