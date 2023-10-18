#include "main.h"

/**
 * print_s - handles string format specifier
 * @set: argument from the _printf function
 * @buf: pointer to buffer
 * @buf_i: pointer to current index of the buffer
 *
 */
void print_s(va_list set, char *buf, unsigned int *buf_i)
{
	unsigned int idx, err = 0;
	char *str;

	if (set)
	{
		str = va_arg(set, char *);
		if (str)
		{
			for (idx = 0; str[idx]; idx++, *buf_i++)
			{
				if (*buf_i >= BUFSIZ - 24)
					err += _flushbuff(buf, buf_i);

				buf[*buf_i] = str[idx];
			}
		}
		else
		{
			str = "(null)";
			for (idx = 0; str[idx]; idx++, *buf_i++)
			{
				if (*buf_i >= BUFSIZ - 24)
					err += _flushbuff(buf, buf_i);

				buf[*buf_i] = str[idx];
			}
		}
	}
}
