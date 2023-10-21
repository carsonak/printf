#include "main.h"

/**
 * main - the TASK0 test file
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;

	len = _printf("%c", 'S');
	printf("%d\n\n", len);
	len2 = printf("%c", 'S');
	printf("%d\n\n", len2);
	fflush(stdout);

	len = _printf("A char inside a sentence: %c. Did it work?\n", 'F');
	printf("%d\n\n", len);
	len2 = printf("A char inside a sentence: %c. Did it work?\n", 'F');
	printf("%d\n\n", len2);
	fflush(stdout);

	len = _printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	printf("%d\n\n", len);
	len2 = printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	printf("%d\n\n", len2);
	fflush(stdout);

	return (0);
}
