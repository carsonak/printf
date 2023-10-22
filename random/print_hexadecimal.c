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
	unsigned int num;
	unsigned int nob = 0;

	num = va_arg(args, int);
	if (num > 0)
	{
		if (*buff_index > PRINTF_BUFFER - 24)
		{
			nob += _flushbuff(buff, buff_index);
		}
		else
		{
			if (num % 16 <= 9)
			{
				buff[*buff_index] = num % 16 + '0';
				num = num / 16;
			}
			else if (num % 16
		}
	}
	return (nob);
}
