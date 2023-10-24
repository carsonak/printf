#include "main.h"

/**
 * print_dec - converts integer to decimal.
 *
 *@args: args passed.
 *
 *@buff: holds decimal before printing on the console.
 *
 *@buff_index: element of a buffer.
 *
 *Return: Returns a decimal on success and -1 on failure.
 */
int print_dec(va_list args, char *const buff, int *const buff_index)
{
	unsigned long int num, var = 10;
	int nob = 0, count = 0, num_count = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		buff[*buff_index] = '0';
		return (0);
	}

	while (var < num)
	{
		var = var * 10;
		count++;
	}

	num_count = count;
	if ((*buff_index + count) > PRINTF_BUFFER)
		nob += _flushbuff(buff, buff_index);

	while (count >= 0)
	{
		buff[*buff_index + count] = num % 10 + '0';
		num = num / 10;
		count--;
	}
	*buff_index = *buff_index + num_count;
	return (nob);
}
