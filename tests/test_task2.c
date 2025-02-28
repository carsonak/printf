#include "main.h"

#include <limits.h>
#include <stdio.h>

/**
 * main - the TASK2 test file
 *
 * Return: Always 0
 */
int main(void)
{
	int ret = 0;
	long int res = INT_MAX;

	_printf("0 = ");
	ret = _printf("%b", 0);
	printf("\n%d\n\n", ret);

	_printf("1 = ");
	ret = _printf("%b", 1);
	printf("\n%d\n\n", ret);

	_printf("2 = ");
	ret = _printf("%b", 2);
	printf("\n%d\n\n", ret);

	_printf("3 = ");
	ret = _printf("%b", 3);
	printf("\n%d\n\n", ret);

	_printf("7 = ");
	ret = _printf("%b", 7);
	printf("\n%d\n\n", ret);

	_printf("8 = ");
	ret = _printf("%b", 8);
	printf("\n%d\n\n", ret);

	_printf("9 = ");
	ret = _printf("%b", 9);
	_printf("\n%d\n\n", ret);

	_printf("1024 = ");
	ret = _printf("%b", 1024);
	printf("\n%d\n\n", ret);

	_printf("-1024 = ");
	ret = _printf("%b", -1024);
	printf("\n%d\n\n", ret);

	_printf("INT_MIN = ");
	ret = _printf("%b", INT_MIN);
	printf("\n%d\n\n", ret);

	_printf("UINT_MAX = ");
	ret = _printf("%b", UINT_MAX);
	printf("\n%d\n\n", ret);

	_printf("UINT_MAX + 1024 = ");
	ret = _printf("%b", UINT_MAX + 1024);
	_printf("\n%d\n\n", ret);

	ret = _printf("There is %b bytes in %b KB\n", 1024, 1);
	printf("%d\n\n", ret);

	ret = _printf("%b - %b = %b\n", 2048, 1024, 1024);
	printf("%d\n\n", ret);

	ret = _printf("%b + %b = %b\n", INT_MAX, INT_MAX, res + res);
	printf("%d\n\n", ret);

	return (0);
}
