#include "tests.h"

/**
 * test - TASK1 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	PRINTF_TEST_TEMPLATE("%d", 1024);
	PRINTF_TEST_TEMPLATE("%d", -1024);
	PRINTF_TEST_TEMPLATE("%d", 0);
	PRINTF_TEST_TEMPLATE("%d", INT_MAX);
	PRINTF_TEST_TEMPLATE("%d", INT_MIN);
	PRINTF_TEST_TEMPLATE("%d", (long int)INT_MAX + 1024);
	PRINTF_TEST_TEMPLATE("%d", (long int)INT_MIN - 1024);
	PRINTF_TEST_TEMPLATE("There is %d bytes in %d KB\n", 1024, 1);
	PRINTF_TEST_TEMPLATE("%d - %d = %d\n", 1024, 2048, -1024);
	PRINTF_TEST_TEMPLATE(
		"%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));

	/***************************%i***************************/

	PRINTF_TEST_TEMPLATE("%i", 1024);
	PRINTF_TEST_TEMPLATE("%i", -1024);
	PRINTF_TEST_TEMPLATE("%i", 0);
	PRINTF_TEST_TEMPLATE("%i", INT_MAX);
	PRINTF_TEST_TEMPLATE("%i", INT_MIN);
	PRINTF_TEST_TEMPLATE("%i", (long int)INT_MAX + 1024);
	PRINTF_TEST_TEMPLATE("%i", (long int)INT_MIN - 1024);
	PRINTF_TEST_TEMPLATE("There is %i bytes in %i KB\n", 1024, 1);
	PRINTF_TEST_TEMPLATE("%i - %i = %i\n", 1024, 2048, -1024);
	PRINTF_TEST_TEMPLATE(
		"%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));

	/********************************************************/

	PRINTF_TEST_TEMPLATE("%d == %i\n", 1024, 1024);
	PRINTF_TEST_TEMPLATE("iddi%diddiiddi\n", 1024);
	PRINTF_TEST_TEMPLATE("%d", 10000);
	PRINTF_TEST_TEMPLATE("%i", 10000);

	return (failed);
}
