#include "main.h"
/* #define _OVERALL_*/ /*Overall test for the printf function*/
/*#define _TASK0_ Tests for %c, %s and %%*/
/*#define RANDOM*/
#define _TASK1_

/**
 * main - the main test file
 *
 * Return: Always 0
 */
int main(void)
{

#ifdef _TASK1_

	int ret = printf("5 * 5 = %d, 5 * 5 = %i", 10, 10);
	printf("\n%d\n", ret);
	ret = _printf("5 * 5 = %d, 5 * 5 = %i", 10, 10);
	printf("\n%d\n\n", ret);

	ret = printf("5 * 5 = %d, 5 * 5 = %i", 5 * 5, 10);
	printf("\n%d\n", ret);
	ret = _printf("5 * 5 = %d, 5 * 5 = %i", 10, 5 * 5);
	printf("\n%d\n\n", ret);
	ret = printf("5 * 5 = %d, 5 * 5 = %i", 5 * 5, 10);
	printf("\n%d\n\n", ret);
	ret = _printf("5 * 5 = %d, 5 * 5 = %i", 5 * 5, 10);
	printf("\n%d\n\n", ret);

	ret = printf("%d is -ve and %i is +ve", -10, +10);
	printf("\n%d\n", ret);
	ret = _printf("%d is -ve and %i is +ve", -10, +10);
	printf("\n%d\n\n", ret);
	ret = printf("%d is +ve and %i is -ve", +10, -10);
	printf("\n%d\n\n", ret);
	ret = _printf("%d is +ve and %i is -ve", +10, -10);
	printf("\n%d\n\n", ret);

	ret = printf("5 * 5 = %d", NULL);
	printf("\n%d\n", ret);
	ret = _printf("5 * 5 = %d", NULL);
	printf("\n%d\n\n", ret);
	ret = printf("5 * 5 = %i", NULL);
	printf("\n%d\n\n", ret);
	ret = _printf("5 * 5 = %i", NULL);
	printf("\n%d\n\n", ret);

	ret = printf("5 * 5 = %d", INT_MAX);
	printf("\n%d\n", ret);
	ret = _printf("5 * 5 = %d", INT_MAX);
	printf("\n%d\n\n", ret);
	ret = printf("5 * 5 = %i", INT_MAX);
	printf("\n%d\n", ret);
	ret = _printf("5 * 5 = %i", INT_MAX);
	printf("\n%d\n\n", ret);

	ret = printf("5 * 5 = %d", INT_MIN);
	printf("\n%d\n", ret);
	ret = _printf("5 * 5 = %d", INT_MIN);
	printf("\n%d\n\n", ret);
	ret = printf("5 * 5 = %i", INT_MIN);
	printf("\n%d\n", ret);
	ret = _printf("5 * 5 = %i", INT_MIN);
	printf("\n%d\n\n", ret);

#endif /*_TASK1_*/
#ifdef RANDOM
	int ret = printf("What!?");
	printf("\n%d\n", ret);
	ret = _printf("What!?");
	printf("\n%d\n\n", ret);

	ret = printf("What %s!?", "The");
	printf("\n%d\n", ret);
	ret = _printf("What %s!?", "The");
	printf("\n%d\n\n", ret);

	ret = printf("What %s %s!?", "The", "Hell");
	printf("\n%d\n", ret);
	ret = _printf("What %s %s!?", "The", "Hell");
	printf("\n%d\n\n", ret);

	ret = printf("The number of %c\n", 'f');
	printf("%d\n", ret);
	ret = _printf("The number of %c\n", 'f');
	printf("%d\n", ret);
#endif /* RANDOM */
#ifdef _TASK0_
	int ret = printf("What!?");
	printf("\n%d\n", ret);
	ret = _printf("What!?");
	printf("\n%d\n", ret);

	ret = printf("What %s!?", "The");
	printf("\n%d\n", ret);
	ret = _printf("What %s!?", "The");
	printf("\n%d\n\n", ret);

	ret = printf("What %s %s!?", "The", "Hell");
	printf("\n%d\n", ret);
	ret = _printf("What %s %s!?", "The", "Hell");
	printf("\n%d\n\n", ret);

	ret = printf("What %s!?", "The");
	printf("\n%d\n", ret);
	ret = _printf("What %s!?", "The");
	printf("\n%d\n\n", ret);

	ret = printf("What %!?");
	printf("\n%d\n", ret);
	ret = _printf("What %!?");
	printf("\n%d\n\n", ret);

	ret = printf("What %s!?", NULL);
	printf("\n%d\n", ret);
	ret = _printf("What %s!?", NULL);
	printf("\n%d\n\n", ret);

	ret = printf(NULL);
	printf("\n%d\n", ret);
	ret = _printf(NULL);
	printf("\n%d\n\n", ret);

	ret = printf("What!?%");
	printf("\n%d\n", ret);
	ret = _printf("What!?%");
	printf("\n%d\n\n", ret);

	ret = printf("What %c!?", 'T');
	printf("\n%d\n", ret);
	ret = _printf("What %c!?", 'T');
	printf("\n%d\n\n", ret);

	ret = printf("What %c!?", "The");
	printf("\n%d\n", ret);
	ret = _printf("What %c!?", "The");
	printf("\n%d\n\n", ret);

#endif /*_TASK0_*/

#ifdef _OVERALL_

	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);

#endif /*_OVERALL_*/

	return (0);
}
