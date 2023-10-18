#include "main.h"

/**
 * print_num - converts int to bufing
 * @set: argument from _printf
 * @buf: Buffer to store the number
 *
 * Return: The number of characters printed
 */
int print_num(va_list set, char *buf)
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
		buf[index] = '-';
		num2 = -num;
		index++;
	}
	else
		num2 = num;
	while (num2 / var >= 10)
	{
		var = var * 10;
	}
	while (var > 0)
	{
		b = num2 / var;
		buf[index] = (b + '0');
		num2 = num2 % var;
		var = var / 10;
		index++;
	}
	buf[index] = '\0';
	return (index);
}
