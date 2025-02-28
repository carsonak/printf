#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	long int intmax_plus = INT_MAX + 1024;
	long int intmax_by_2 = INT_MAX * 2;
	int ret1, ret2;

	/******** u ********/

	ret1 = printf("%X\n", 1024);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%X\n", -1024);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", -1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%X\n", 0);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", 0);
	printf("%d\n\n", ret2);

	ret1 = printf("%X\n", UINT_MAX);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", UINT_MAX);
	printf("%d\n\n", ret2);

	ret1 = printf("%X\n", intmax_plus);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", intmax_plus);
	printf("%d\n\n", ret2);

	ret1 = printf("There is %X bytes in %X KB\n", 1024);
	printf("%d\n", ret1);
	ret2 = _printf("There is %X bytes in %X KB\n", 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%X - %X = %X\n", 2048, 1024, 1024);
	printf("%d\n", ret1);
	ret2 = _printf("%X - %X = %X\n", 2048, 1024, 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%X + %X = %X\n", INT_MAX, INT_MAX, intmax_by_2);
	printf("%d\n", ret1);
	ret2 = _printf("%X + %X = %X\n", INT_MAX, INT_MAX, intmax_by_2);
	printf("%d\n\n", ret2);

	/******** o ********/

	ret1 = printf("%o\n", 1024);
	printf("%d\n", ret1);
	ret2 = _printf("%o\n", 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%o\n", -1024);
	printf("%d\n", ret1);
	ret2 = _printf("%o\n", -1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%o\n", 0);
	printf("%d\n", ret1);
	ret2 = _printf("%o\n", 0);
	printf("%d\n\n", ret2);

	ret1 = printf("%o\n", UINT_MAX);
	printf("%d\n", ret1);
	ret2 = _printf("%o\n", UINT_MAX);
	printf("%d\n\n", ret2);

	ret1 = printf("%o\n", intmax_plus);
	printf("%d\n", ret1);
	ret2 = _printf("%o\n", intmax_plus);
	printf("%d\n\n", ret2);

	ret1 = printf("There is %o bytes in %o KB\n", 1024);
	printf("%d\n", ret1);
	ret2 = _printf("There is %o bytes in %o KB\n", 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%o - %o = %o\n", 2048, 1024, 1024);
	printf("%d\n", ret1);
	ret2 = _printf("%o - %o = %o\n", 2048, 1024, 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%o + %o = %o\n", INT_MAX, INT_MAX, intmax_by_2);
	printf("%d\n", ret1);
	ret2 = _printf("%o + %o = %o\n", INT_MAX, INT_MAX, intmax_by_2);
	printf("%d\n\n", ret2);

	/******** x ********/

	ret1 = printf("%x\n", 1024);
	printf("%d\n", ret1);
	ret2 = _printf("%x\n", 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%x\n", -1024);
	printf("%d\n", ret1);
	ret2 = _printf("%x\n", -1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%x\n", 0);
	printf("%d\n", ret1);
	ret2 = _printf("%x\n", 0);
	printf("%d\n\n", ret2);

	ret1 = printf("%x\n", UINT_MAX);
	printf("%d\n", ret1);
	ret2 = _printf("%x\n", UINT_MAX);
	printf("%d\n\n", ret2);

	ret1 = printf("%x\n", intmax_plus);
	printf("%d\n", ret1);
	ret2 = _printf("%x\n", intmax_plus);
	printf("%d\n\n", ret2);

	ret1 = printf("There is %x bytes in %x KB\n", 1024);
	printf("%d\n", ret1);
	ret2 = _printf("There is %x bytes in %x KB\n", 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%x - %x = %x\n", 2048, 1024, 1024);
	printf("%d\n", ret1);
	ret2 = _printf("%x - %x = %x\n", 2048, 1024, 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%x + %x = %x\n", INT_MAX, INT_MAX, intmax_by_2);
	printf("%d\n", ret1);
	ret2 = _printf("%x + %x = %x\n", INT_MAX, INT_MAX, intmax_by_2);
	printf("%d\n\n", ret2);

	/******** X ********/

	ret1 = printf("%X\n", 1024);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%X\n", -1024);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", -1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%X\n", 0);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", 0);
	printf("%d\n\n", ret2);

	ret1 = printf("%X\n", UINT_MAX);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", UINT_MAX);
	printf("%d\n\n", ret2);

	ret1 = printf("%X\n", intmax_plus);
	printf("%d\n", ret1);
	ret2 = _printf("%X\n", intmax_plus);
	printf("%d\n\n", ret2);

	ret1 = printf("There is %X bytes in %X KB\n", 1024);
	printf("%d\n", ret1);
	ret2 = _printf("There is %X bytes in %X KB\n", 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%X - %X = %X\n", 2048, 1024, 1024);
	printf("%d\n", ret1);
	ret2 = _printf("%X - %X = %X\n", 2048, 1024, 1024);
	printf("%d\n\n", ret2);

	ret1 = printf("%X + %X = %X\n", INT_MAX, INT_MAX, intmax_by_2);
	printf("%d\n", ret1);
	ret2 = _printf("%X + %X = %X\n", INT_MAX, INT_MAX, intmax_by_2);
	printf("%d\n\n", ret2);

	return (0);
}
