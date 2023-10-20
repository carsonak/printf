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
	int ret;

	ret = printf("What!?");
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

	ret = printf("What %c%c%c!?", 'T', 'h', 'e');
	printf("\n%d\n", ret);
	ret = _printf("What %c%c%c!?", 'T', 'h', 'e');
	printf("\n%d\n\n", ret);

	ret = printf("What %c!?", NULL);
	printf("\n%d\n", ret);
	ret = _printf("What %c!?", NULL);
	printf("\n%d\n\n", ret);

	ret = printf("What %c!?");
	printf("\n%d\n", ret);
	ret = _printf("What %c!?");
	printf("\n%d\n\n", ret);

	ret = printf("What%%");
	printf("\n%d\n", ret);
	ret = _printf("What%%");
	printf("\n%d\n\n", ret);

	ret = printf("What %c!?", "The");
	printf("\n%d\n", ret);
	ret = _printf("What %c!?", "The");
	printf("\n%d\n\n", ret);

	return (0);
}

#endif /*_TASK0_*/
