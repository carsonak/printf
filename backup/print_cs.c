#include "main.h"

/**
 * print_s - prints a string
 * @set: argument from the _printf function
 * @buf: buffer
 *
 * Return: number of bytes written
 */
int print_s(va_list set, char *buf)
{
	int err = 0;
	char *str;

	if (set)
	{
		str = va_arg(set, char *);
		if (str)
		{
			while (str[err])
			{
				buf[err] = str[err];
				err++;
			}
		}
		else
		{
			str = "(null)";
			while (str[err])
				buf[err] = str[err];
		}
	}

	return (err);
}

/**
 * print_c - prints a character
 * @set: argument from the _printf function
 * @buf: buffer
 *
 * Return: number of bytes written
 */
int print_c(va_list set, char *buf)
{
	if (set)
		*buf = va_arg(set, int);

	return (1);
}
