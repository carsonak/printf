#include "main.h"
/**
  * print_hexa - converts integer into lowercase hexadecimal.
  *
  *@args: variable arguments passed.
  *
  *@buff: stores before printing.
  *
  *@buff_index: pointer to an element in an array.
  *
  *Return: Return number on bytes printed on console.
  */
long int print_hexa(va_list args, char *buff, long int *buff_index)
{
	long int num, num_count = 0;
	long int var = 16;
	long int nob = 0, count = 0;

	buff_index = 0;
	num = va_arg(args, unsigned int);
	if (num < 0)
	{
		num = -num;
	}
	while (var < num)
	{
		var = var * 16;
		count++;
	}
	num_count = count;
	while (count >= 0)
	{
		if (*buff_index > PRINTF_BUFFER)
		{
			nob += _flushbuff(buff, buff_index);
		}
		if (num % 16 < 10)
		{
			buff[*buff_index + count] = num % 16 + 48;
		}
		else if (num % 16 >= 10 && num % 16 <= 15)
		{
			buff[*buff_index + count] = num % 16 + 55;
		}
		num = num / 16;
		count--;
	}
	*buff_index = *buff_index + num_count;
	return (nob);
}