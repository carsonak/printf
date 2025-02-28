#include "main.h"
/**
 * print_p - prints an address in lowercase hexadecimal
 *@args: variable arguments passed.
 *@buf: bufer storing the string.
 *@buf_i: current index of the buffer
 *
 *Return: Return bytes printed to console.
 */
int print_p(va_list args, char *buf, int *buf_i)
{
	int nob = 0, count = 0;
	unsigned long int address, address_count = 0, var = 16;
	char *null = "(nil)";

	address = (unsigned long int)va_arg(args, void *);
	if (address == 0)
	{
		if ((*buf_i + 5) >= PRINTF_BUFFER_LENGTH - 24)
			nob += flush_buffer(buf, buf_i);
		while (null[count])
		{
			buf[*buf_i] = null[count];
			*buf_i += 1;
			count++;
		}
		*buf_i -= 1;
		return (nob);
	}

	while (var <= address)
	{
		var = var * 16;
		count++;
	}
	if ((*buf_i + count) >= PRINTF_BUFFER_LENGTH - 24)
		nob += flush_buffer(buf, buf_i);

	address_count = count;
	while (count >= 0)
	{
		if (address % 16 < 10)
			buf[*buf_i + count] = address % 16 + '0';
		else if (address % 16 > 9 && address % 16 < 16)
			buf[*buf_i + count] = ((address % 16) - 10) + 'a';

		address /= 16;
		count--;
	}
	*buf_i += address_count;
	return (print_prefix(address_count, buf, buf_i, 'x'));
}
