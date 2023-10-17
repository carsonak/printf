#include "main.h"

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
