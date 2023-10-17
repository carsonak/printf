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
			numS = malloc(sizeof(*numS));
			if (numS)
			{
				*numS = '0';
				err += write(1, numS, sizeof(*numS));
				free(numS);
			}
			return (err);
		}

		numS = itos(num);
		if (numS)
			err += write(1, numS, strlen(numS));
	}

	free(numS);
	return (err);
}
