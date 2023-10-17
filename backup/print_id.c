#include "main.h"

/**
 * print_i - prints an integer
 * @set: argument from the _printf function
 * @buf: buffer
 *
 * Return: number of bytes written
 */
int print_i(va_list set, char *buf)
{
	int n;
	unsigned int num, div = 1, b = 0;

	if (set)
	{
		n = va_arg(set, int);
		if (n)
		{
			/*Turning -ve numbers to +ve*/
			if (n < 0)
				num = -n;
			else
				num = n;

			/*Calculating the highest total value of num*/
			while (num / div > 9)
				div *= 10;

			/*Storing number in string*/
			if (n < 0)
			{
				buf[b] = '-';
				b++;
			}

			for (; div > 0; b++)
			{
				buf[b] = ('0' + (num / div));
				num %= div;
				div /= 10;
			}
		}
	}

	return (b);
}
