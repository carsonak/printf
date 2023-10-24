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

	len = _printf("%s", "This sentence is retrieved from va_args!\n");
	printf("%d\n\n", len);
	len2 = printf("%s", "This sentence is retrieved from va_args!\n");
	printf("%d\n\n", len2);
	fflush(stdout);

	len = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("%d\n\n", len);
	len2 = printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("%d\n\n", len2);
	fflush(stdout);

	len = _printf("Should print a single percent sign: %%\n");
	printf("%d\n\n", len);
	len2 = printf("Should print a single percent sign: %%\n");
	fflush(stdout);
	printf("%d\n\n", len2);
	fflush(stdout);

	len = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("%d\n\n", len);
	len2 = printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("%d\n\n", len2);
	fflush(stdout);

	len = _printf("%c", '\0');
	_printf("%d\n\n", len);
	len2 = printf("%c", '\0');
	_printf("%d\n\n", len2);
	fflush(stdout);

	return (0);
}
