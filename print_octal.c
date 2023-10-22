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
long int print_oct(va_list args, char *buff, long int *buff_index)
{
	long int num, var = 8;
	long int nob = 0;
	long int count = 0, num_count = 0;

	num = va_arg(args, unsigned int);
	if (num < 0)
	{
		num = -num;
	}
	while (var < num)
	{
		var = var * 8;
		count++;
	}
	num_count = count;
	while (count >= 0)
	{
		if (*buff_index > PRINTF_BUFFER - 24)
		{
			nob += _flushbuff(buff, buff_index);
		}
		buff[*buff_index + count] = num % 8 + '0';
		num = num / 8;
		count--;
	}
	*buff_index = *buff_index + num_count;
	return (nob);
}
