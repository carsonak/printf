#define _TASK0_
#ifdef _TASK0_
#include "main.h"

/**
 * main - the TASK0 test file
 *
 * Return: Always 0
 */
int main(void)
{
	int ret = 0, ret2 = 0;

	ret = printf("What!?");
	printf("\n%d\n", ret);
	ret2 = _printf("What!?");
	printf("\n%d\n\n", ret2);

	ret = printf("What %s!?", "The");
	printf("\n%d\n", ret);
	ret2 = _printf("What %s!?", "The");
	printf("\n%d\n\n", ret2);

	ret = printf("What %s %s!?", "The", "Hell");
	printf("\n%d\n", ret);
	ret2 = _printf("What %s %s!?", "The", "Hell");
	printf("\n%d\n\n", ret2);

	ret = printf("What %!?");
	printf("\n%d\n", ret);
	ret2 = _printf("What %!?");
	printf("\n%d\n\n", ret2);

	ret = printf("What %s!?", NULL);
	printf("\n%d\n", ret);
	ret2 = _printf("What %s!?", NULL);
	printf("\n%d\n\n", ret2);

	ret = printf(NULL);
	printf("\n%d\n", ret);
	ret2 = _printf(NULL);
	printf("\n%d\n\n", ret2);

	ret = printf("What!?%");
	printf("\n%d\n", ret);
	ret2 = _printf("What!?%");
	printf("\n%d\n\n", ret2);

	ret = printf("What %c!?", 'T');
	printf("\n%d\n", ret);
	ret2 = _printf("What %c!?", 'T');
	printf("\n%d\n\n", ret2);

	ret = printf("What %c%c%c!?", 'T', 'h', 'e');
	printf("\n%d\n", ret);
	ret2 = _printf("What %c%c%c!?", 'T', 'h', 'e');
	printf("\n%d\n\n", ret2);

	ret = printf("What %c!?", NULL);
	printf("\n%d\n", ret);
	ret2 = _printf("What %c!?", NULL);
	printf("\n%d\n\n", 2);

	ret = printf("What %c!?");
	printf("\n%d\n", ret);
	ret2 = _printf("What %c!?");
	printf("\n%d\n\n", ret2);

	ret = printf("What%%");
	printf("\n%d\n", ret);
	ret2 = _printf("What%%");
	printf("\n%d\n\n", ret2);

	ret = printf("What %c!?", "The");
	printf("\n%d\n", ret);
	ret2 = _printf("What %c!?", "The");
	printf("\n%d\n\n", ret2);

	return (0);
}

#endif /*_TASK0_*/
