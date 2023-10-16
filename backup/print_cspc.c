#include "main.h"

/**
 * print_s - prints a string
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_s(va_list set)
{
	int err = 0;
	char *str;

	if (set)
	{
		str = va_arg(set, char *);
		if (str)
			err += write(1, str, strlen(str));
		else
		{
			str = "(null)";
			err += write(1, str, strlen(str));
		}
	}

	return (err);
}

/**
 * print_c - prints a character
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_c(va_list set)
{
	int err = 0;
	int *ch = malloc(sizeof(int));

	if (set)
	{
		*ch = va_arg(set, int);
		err += write(1, ch, sizeof(*ch));
	}

	return (err / sizeof(*ch));
}

/**
 * print_pc - prints a %
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_pc(va_list set)
{
	int err = 0;
	char pc[] = {'%'};
	(void)set;

	err += write(1, pc, sizeof(*pc));

	return (err);
}
