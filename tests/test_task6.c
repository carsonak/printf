#include "tests.h"

/**
 * test - TASK6 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	PRINTF_TEST_TEMPLATE("%p", (void *)0x7fff5100b608);
	PRINTF_TEST_TEMPLATE("%p", NULL);
	PRINTF_TEST_TEMPLATE(
		"Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	PRINTF_TEST_TEMPLATE(
		"Can you print several addresses?\n%p,%p,%p,%p\nNice!\n",
		(void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8,
		(void *)0x7fff510236f8);
	PRINTF_TEST_TEMPLATE("");
	PRINTF_TEST_TEMPLATE("Can you print an address?\n%p\nNice!\n", (void *)-1);
	PRINTF_TEST_TEMPLATE("%pppp", (void *)0x7fff5100b6f8);

	return (failed);
}
