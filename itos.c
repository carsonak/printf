#include "main.h"

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
