#include "tests.h"

/**
 * test - TASK2 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	PRINTF_CUSTOM_TEST_TEMPLATE("10000000000", "%b", 1024);
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"11111111111111111111110000000000", "%b", -1024);
	PRINTF_CUSTOM_TEST_TEMPLATE("0", "%b", 0);
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"11111111111111111111111111111111", "%b", UINT_MAX);
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"There is 10000000000 bytes in 1 KB\n", "There is %b bytes in %b KB\n",
		1024, 1);
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"100000000000 - 10000000000 = 10000000000\n", "%b - %b = %b\n", 2048,
		1024, 1024);
	/* clang-format off */
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"1111111111111111111111111111111 + 1111111111111111111111111111111 = 11111111111111111111111111111110\n",
		"%b + %b = %b\n", INT_MAX, INT_MAX, (long int)INT_MAX * 2);
	/* clang-format on */

	if (!failed)
		PRINT_TESTS_PASS_TEXT();

	return (failed);
}
