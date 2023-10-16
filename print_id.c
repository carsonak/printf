#include "main.h"

/**
 * print_i - prints an integer
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_i(va_list set)
{
	int err = 0;
	int *num = malloc(sizeof(int));

	if (set)
	{
		*num = va_arg(set, int);
		err += write(1, num, sizeof(*num));
	}

	return (err / sizeof(*num));
}
