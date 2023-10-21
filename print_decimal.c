#include "main.h"

/**
  * print_dec - converts integer to decimal.
  *
  *@buffer: holds decimal before printing on the console.
  *
  *@buff_index: element of a buffer.
  *
  *Return: Returns a decimal on success and -1 on failure.
  */
long int print_dec(va_list args, char *buffer, long int *buff_index)
{
	unsigned int num;
	unsigned int nob = 0;

	num = va_arg(args, int);
	while (num > 0)
	{
		if (*buff_index > PRINTF_BUFFER)
		{
			nob += _flushbuff(buffer, buff_index);
		}
		buffer[*buff_index] = num % 10 + '0';
		num = num / 10;
		*buff_index = *buff_index + 1;
	}
	return (nob);
}
