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
int print_oct(va_list args, char *buff, long int *buff_index)
{
	int num;
	int nob = 0;

	num = va_arg(args, int);
	if (num < 0)
	{
		exit(-1);
	}
	while (num > 0)
	{
		if (*buff_index > PRINTF_BUFFER - 24)
		{
			nob += _flushbuff(buff, buff_index);
		}
			buff[*buff_index] = num % 8;
			num = num / 8;
	}
	va_end(args);
	return (nob);
}
