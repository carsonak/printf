#include "main.h"

/**
 * print_pc - prints a %
 * @set: argument from the _printf function
 * @buf: buffer
 *
 * Return: number of bytes written
 */
int print_pc(va_list set, char *buf)
{
	(void)set;

	*buf = '%';

	return (1);
}
