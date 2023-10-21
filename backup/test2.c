#define _TASK2_
#ifdef _TASK2_
#include "main.h"

/**
 * main - the TASK2 test file
 *
 * Return: Always 0
 */
int main(void)
{
	int ret = 0;
	long int res = INT_MAX * (long)2, l = UINT_MAX + 1024;

	_printf("1024 = ");
	ret = _printf("%b", 1024);
	_printf("\n%d\n\n", ret);

	_printf("-1024 = ");
	ret = _printf("%b", -1024);
	_printf("\n%d\n\n", ret);

	_printf("0 = ");
	ret = _printf("%b", 0);
	_printf("\n%d\n\n", ret);

	_printf("3 = ");
	ret = _printf("%b", 3);
	_printf("\n%d\n\n", ret);

	_printf("6 = ");
	ret = _printf("%b", 6);
	_printf("\n%d\n\n", ret);

	_printf("8 = ");
	ret = _printf("%b", 8);
	_printf("\n%d\n\n", ret);

	_printf("10 = ");
	ret = _printf("%b", 10);
	_printf("\n%d\n\n", ret);

	_printf("15 = ");
	ret = _printf("%b", 15);
	_printf("\n%d\n\n", ret);

	_printf("17 = ");
	ret = _printf("%b", 17);
	_printf("\n%d\n\n", ret);

	ret = _printf("%b", UINT_MAX);
	_printf("\n%d\n\n", ret);

	ret = _printf("%b", l);
	_printf("\n%d\n\n", ret);

	ret = _printf("There is %b bytes in %b KB\n", 1024, 1);
	_printf("%d\n\n", ret);

	ret = _printf("%b - %b = %b\n", 2048, 1024, 1024);
	_printf("%d\n\n", ret);

	ret = _printf("%b + %b = %b\n", INT_MAX, INT_MAX, res);
	_printf("%d\n\n", ret);

	return (0);
}

#endif /*_TASK2_*/
