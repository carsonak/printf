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
unsigned int print_oct(va_list args, char *buff, char *buff_index)
{
	unsigned int num;
	unsigned int nob = 0;

	num = va_arg(args, format);
	if (num < 0)
	{
		exit(-1);
	}
	while (num > 0)
	{
		if (buff[buff_index] >= PRINT_BUFFER)
		{
			nob += _flushbuff(buff, buff_index);
		}
			buff[buff_index] = num % 8;
			num = num / 8;
		nob = _flushbuff(buff, buff[buff_index]);
	}
	return (nob);
}
