#include "main.h"

/**
  * print_dec - converts integer to decimal.
  *
  *@args: args passed.
  *
  *@buffer: holds decimal before printing on the console.
  *
  *@buff_index: element of a buffer.
  *
  *Return: Returns a decimal on success and -1 on failure.
  */
long int print_dec(va_list args, char *buffer, long int *buff_index)
{
	long int num, num_count = 0;
	long int nob = 0, count = 0;
	long int var = 10;

	num = va_arg(args, unsigned int);
	while (var < num)
	{
		var = var * 10;
		count++;
	}
	num_count = count;
	while (count >= 0)
	{
		if (*buff_index > PRINTF_BUFFER)
		{
			nob += _flushbuff(buffer, buff_index);
		}
		buffer[*buff_index + count] = num % 10 + '0';
		num = num / 10;
		count--;
	}
	*buff_index = *buff_index + num_count;
	return (nob);
}
