#include "main.h"
/**
  * print_oct - converts int to octal.
  *
  * @args: integer passed.
  *
  * @buff: buffer
  *
  * @buff_index: element in buffer.
  *
  *Return: Return number of bytes to the console.
  */
int print_oct(va_list args, char *const buff, int *const buff_index)
{
	unsigned long int num, var = 8;
	int nob = 0;
	long int count = 0, num_count = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		buff[*buff_index] = '0';
		return (0);
	}

	while (var <= num)
	{
		var = var * 8;
		count++;
	}

	num_count = count;
	if ((*buff_index + count) > PRINTF_BUFFER - 24)
		nob += _flushbuff(buff, buff_index);

	while (count >= 0)
	{

		buff[*buff_index + count] = num % 8 + '0';
		num = num / 8;
		count--;
	}
	*buff_index = *buff_index + num_count;
	return (nob);
}
