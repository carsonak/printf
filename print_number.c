#include "main.h"

/**
 * print_num - converts int to bufing
 * @args: argument from _printf
 * @buf: Pointer to the buffer
 * @buf_i: Pointer to current index of the buffer
 *
 * Return: number of characters written
 */
long int print_num(va_list args, char *buf, long int *buf_i)
{
	long int var = 1, nob = 0, num = 0;

	num = va_arg(args, int);
	if (num < 0)
	{
		buf[*buf_i] = '-';
		num = -num;
		*buf_i += 1;
	}

	while (num / var >= 10)
		var *= 10;

	while (var > 0)
	{
<<<<<<< HEAD
		if (*buf_i >= PRINTF_BUFFER - 24) 
=======
		if (*buf_i >= PRINTF_BUFFER - 24)
>>>>>>> acdca2c12acf65c36306c7a83d8f443d948498be
			nob += _flushbuff(buf, buf_i);

		buf[*buf_i] = (num / var) + '0';
		num %= var;
		var /= 10;
		*buf_i += 1;
	}

<<<<<<< HEAD
	return (nob + *buf_i);
=======
	*buf_i -= 1;

	return (nob);
>>>>>>> acdca2c12acf65c36306c7a83d8f443d948498be
}
