#include "main.h"

/**
  * print_number - prints number.
  *
  *@num: integer passed.
  */
void print_number(int num, char *str)
{
	int var;
	char b;
	int index;
	unsigned int num2;

	var = 1;
	index = 0;
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
}
