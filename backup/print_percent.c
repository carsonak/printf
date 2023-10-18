#include "main.h"

/**
 * print_pc - handles format specifier for %
 * @set: argument from the _printf function
 * @buf: pointer to the buffer
 * @buf_i: pointer to current index of the buffer
 *
 */
void print_pc(va_list set, char *buf, unsigned int *buf_i)
{
	(void)set;
	buf[*buf_i] = '%';
	*buf_i++;
}
