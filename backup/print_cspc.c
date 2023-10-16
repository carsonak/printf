#include "main.h"

/**
 * print_c - prints a character
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_c(va_list set)
{
	int count = 0;
	int ch;

	if (set)
	{
		ch = va_arg(set, int);
		count += write(1, ch, sizeof(ch));
	}

	return (count);
}

/**
 * print_s - prints a string
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_s(va_list set)
{
	int count = 0;
	char *str;

	if (set)
	{
		str = va_arg(set, int);
		count += write(1, str, strlen(str));
	}
	else
	{
		str = "(null)";
		count += write(1, str, strlen(str));
	}

	return (count);
}

/**
 * print_pc - prints a %
 * @set: argument from the _printf function
 *
 * Return: number of bytes written
 */
int print_pc(va_list set)
{

	int count = 0;
	int pc;

	if (set)
	{
		pc = va_arg(set, int);
		count += write(1, pc, sizeof(pc));
	}

	return (count);
}
