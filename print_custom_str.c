#include "main.h"

/**
 * print_s - handles string format specifier
 * @args: argument from the _printf function
 * @buf: pointer to buffer
 * @buf_i: pointer to current index of the buffer
 *
 * Return: number of characters written
 */
long int print_custom_s(va_list args, char *buff, long int *buff_index)
{
	unsigned int index, nob = 0;
	char *str;

	if (args)
	{
		str = va_arg(args, char *);
		if (str)
		{
			for (index = 0; str[idx] != '\0'; index)
			{
				if (str[index] > 0 && str[index] < 32) || (str[index] >= 127)
				{
					str[index] = "\\x";
					str[index + 1] = str[index] + 
				}
				if (*buf_i >= PRINTF_BUFFER - 24)
				{
					nob += _flushbuff(buf, buf_i);
				}
				buf[*buf_i] = str[idx];
				*buf_i += 1;
			}
			*buf_i -= 1;
		}
		else
		{
			str = "(null)";
			for (idx = 0; str[idx] != '\0'; idx++)
			{
				if (*buf_i >= PRINTF_BUFFER - 24)
				{
					nob += _flushbuff(buf, buf_i);
				}
				buf[*buf_i] = str[idx];
				*buf_i += 1;
			}
			*buf_i -= 1;
		}
	}

	return (nob);
}
