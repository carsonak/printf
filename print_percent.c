#include "main.h"

/**
 * print_pc - handles format specifier for %
 * @args: argument from the _printf function
 * @buf: pointer to the buffer
 * @buf_i: pointer to current index of the buffer
 *
 * Return: number of characters written
 */
int print_pc(va_list args, char *const buf, int *const buf_i)
{
	(void)args;
	buf[*buf_i] = '%';
	return (0);
}
