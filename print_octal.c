#include "main.h"
/**
  * print_octal - converts int to octal.
  *
  *@args: integer passed.
  *
  *@format: format specifier.
  *
  *Return: Return number of chara
  */
long int print_oct(va_list args, char *buff, long int *buff_index)
{
	long int num, var;
	long int nob = 0;

	num = va_arg(args, int);
	if (num < 0)
	{
		num = -num;
	}
	while (num / var >= 8)
	{
		var = var * 8;
	}
	while (num >= 0)
	{
		if (*buff_index > PRINTF_BUFFER - 24)
		{
			nob += _flushbuff(buff, buff_index);
		}
			buff[*buff_index] = num % 8 + '0';
			num = num / 8;
			*buff_index = *buff_index + 1;
	}
	return (nob);
}
