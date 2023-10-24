#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len;
	void *p = (void *)0x7fff5100b608;

	len = _printf("%p", p);
	printf("\n%d\n\n", len);
	len = printf("%p", p);
	printf("\n%d\n\n", len);

	len = _printf("%p", NULL);
	printf("\n%d\n\n", len);
	len = printf("%p", NULL);
	printf("\n%d\n\n", len);

	return (0);
}
