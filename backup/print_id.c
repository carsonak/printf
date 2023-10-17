#include "main.h"

/**
 * print_i - prints an integer
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_i(va_list set)
{
	int num, err = 0;
	char *numS;

	if (set)
	{
		num = va_arg(set, int);
		if (!num)
		{
			numS = malloc(1);
			*numS = '0';
			err += write(1, numS, sizeof(*numS));
			free(numS);
			return (err);
		}

		numS = itos(num);
		if (numS)
			err += write(1, numS, strlen(numS));
	}

	free(numS);
	return (err);
}

/**
 * itos - converts an integer to a string
 * @n: the integer
 *
 * Return: a pointer to the created string
 */
char *itos(int n)
{
	unsigned int num, div = 1;
	long int b = 0, len = 0;
	char *numS;

	/*Turning -ve numbers to +ve*/
	if (n < 0)
	{
		num = -n;
		len++;
	}
	else
		num = n;

	/*Calculating the highest total value of num*/
	while (num / div > 9)
	{
		div *= 10;
		len++;
	}

	numS = malloc(len + 1);
	if (numS)
	{
		numS[len + 1] = '\0';
		/*Storing number in string*/
		if (n < 0)
		{
			numS[b] = '-';
			b++;
		}

		for (; div > 0 && b <= len; b++)
		{
			numS[b] = ('0' + (num / div));
			num %= div;
			div /= 10;
		}
	}

	return (numS);
}
