#include "main.h"

/**
  * print_number - prints number.
  *
  *@num: integer passed.
  */
int print_number(va_list set, char *str)
{
	int num;
	int var;
	char b;
	int index;
	unsigned int num2;

	var = 1;
	index = 0;
	num = va_arg(set, int);
	if (num < 0)
	{
		str[index] = '-';
		num2 = -num;
		index++;
	}
	else
		num2 = num;
	while (num2 / var >= 10)
	{
		var = var * 10;
	}
	while ( var > 0)
	{
		b = num2 / var;
		str[index] = (b + '0');
		num2 = num2 % var;
		var = var / 10;
		index++;
	}
	str[index] = '\0';
	return (index);
}
