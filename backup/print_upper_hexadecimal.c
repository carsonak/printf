#include "main.h"
/**
  * print_upper_hexa - converts integer into lowercase hexadecimal.
  *
  *@args: variable arguments passed.
  *
  *@buff: stores before printing.
  *
  *@buff_index: pointer to an element in an array.
  *
  *Return: Return number on bytes printed on console.
  */
int print_upper_hexa(va_list args, char *const buff, int *const buff_index)
{
	unsigned long int num, num_count = 0;
	unsigned long int var = 16;
	int nob = 0, count = 0;

	num = va_arg(args, unsigned int);
	while (var <= num)
	{
		var = var * 16;
		count++;
	}
	num_count = count;
	while (count >= 0)
	{
		if (*buff_index >= PRINTF_BUFFER)
		{
			nob += _flushbuff(buff, buff_index);
		}
		if (num % 16 < 10)
		{
			buff[*buff_index + count] = num % 16 + '0';
		}
		else if (num % 16 >= 10 && num % 16 <= 15)
		{
			buff[*buff_index + count] = ((num % 16) - 10) + 'A';
		}
		num = num / 16;
		count--;
	}
	*buff_index = *buff_index + num_count;
	return (nob);
}
