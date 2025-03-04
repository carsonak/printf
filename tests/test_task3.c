#include "tests.h"

/**
 * test - TASK3 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	PRINTF_TEST_TEMPLATE("%u", 1024);
	PRINTF_TEST_TEMPLATE("%u", -1024);
	PRINTF_TEST_TEMPLATE("%u", 0);
	PRINTF_TEST_TEMPLATE("%u", INT_MAX);
	PRINTF_TEST_TEMPLATE("%u", INT_MIN);
	PRINTF_TEST_TEMPLATE("%u", (long int)INT_MAX + 1024);
	PRINTF_TEST_TEMPLATE("%u", (long int)INT_MIN - 1024);
	PRINTF_TEST_TEMPLATE("There is %u bytes in %u KB\n", 1024, 1);
	PRINTF_TEST_TEMPLATE("%u - %u = %u\n", 1024, 2048, -1024);
	PRINTF_TEST_TEMPLATE(
		"%u + %u = %u\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));

	/**************************%o**************************/

	PRINTF_TEST_TEMPLATE("%o", 1024);
	PRINTF_TEST_TEMPLATE("%o", -1024);
	PRINTF_TEST_TEMPLATE("%o", 0);
	PRINTF_TEST_TEMPLATE("%o", INT_MAX);
	PRINTF_TEST_TEMPLATE("%o", INT_MIN);
	PRINTF_TEST_TEMPLATE("%o", (long int)INT_MAX + 1024);
	PRINTF_TEST_TEMPLATE("%o", (long int)INT_MIN - 1024);
	PRINTF_TEST_TEMPLATE("There is %o bytes in %o KB\n", 1024, 1);
	PRINTF_TEST_TEMPLATE("%o - %o = %o\n", 1024, 2048, -1024);
	PRINTF_TEST_TEMPLATE(
		"%o + %o = %o\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));

	/**************************%x**************************/

	PRINTF_TEST_TEMPLATE("%x", 1024);
	PRINTF_TEST_TEMPLATE("%x", -1024);
	PRINTF_TEST_TEMPLATE("%x", 0);
	PRINTF_TEST_TEMPLATE("%x", INT_MAX);
	PRINTF_TEST_TEMPLATE("%x", INT_MIN);
	PRINTF_TEST_TEMPLATE("%x", (long int)INT_MAX + 1024);
	PRINTF_TEST_TEMPLATE("%x", (long int)INT_MIN - 1024);
	PRINTF_TEST_TEMPLATE("There is %x bytes in %x KB\n", 1024, 1);
	PRINTF_TEST_TEMPLATE("%x - %x = %x\n", 1024, 2048, -1024);
	PRINTF_TEST_TEMPLATE(
		"%x + %x = %x\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));

	/**************************%X**************************/

	PRINTF_TEST_TEMPLATE("%X", 1024);
	PRINTF_TEST_TEMPLATE("%X", -1024);
	PRINTF_TEST_TEMPLATE("%X", 0);
	PRINTF_TEST_TEMPLATE("%X", INT_MAX);
	PRINTF_TEST_TEMPLATE("%X", INT_MIN);
	PRINTF_TEST_TEMPLATE("%X", (long int)INT_MAX + 1024);
	PRINTF_TEST_TEMPLATE("%X", (long int)INT_MIN - 1024);
	PRINTF_TEST_TEMPLATE("There is %X bytes in %X KB\n", 1024, 1);
	PRINTF_TEST_TEMPLATE("%X - %X = %X\n", 1024, 2048, -1024);
	PRINTF_TEST_TEMPLATE(
		"%X + %X = %X\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));

	/******************************************************/

	PRINTF_TEST_TEMPLATE("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);
	PRINTF_TEST_TEMPLATE("uuoxxX%xuoXo\n", 1024);

	if (!failed)
		PRINT_TESTS_PASS_TEXT();

	return (failed);
}
