#include "main.h"
/**
  * print_lower_hexa - converts integer into lowercase hexadecimal.
  *
  *@args: variable arguments passed.
  *
  *@buff: stores before printing.
  *
  *@buff_index: pointer to an element in an array.
  *
  *Return: Return number on bytes printed on console.
  */
int print_lower_hexa(va_list args, char *const buff,
					 int *const buff_index)
{
	unsigned long int num, num_count = 0, var = 16;
	int nob = 0, count = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		buff[*buff_index] = '0';
		return (0);
	}

	while (var <= num)
	{
		var = var * 16;
		count++;
	}

	num_count = count;
	if ((*buff_index + count) >= PRINTF_BUFFER_LENGTH - 24)
		nob += flush_buffer(buff, buff_index);

	while (count >= 0)
	{
		if (num % 16 < 10)
		{
			buff[*buff_index + count] = num % 16 + '0';
		}
		else if (num % 16 >= 10 && num % 16 <= 15)
		{
			buff[*buff_index + count] = ((num % 16) - 10) + 'a';
		}
		num = num / 16;
		count--;
	}
	*buff_index = *buff_index + num_count;
	return (nob);
}
