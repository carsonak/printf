#include "tests.h"

/**
 * test - TASK11 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	/**************************%06d**************************/

	PRINTF_TEST_TEMPLATE("%06d", 102498402);
	PRINTF_TEST_TEMPLATE("%06d", -102498402);
	PRINTF_TEST_TEMPLATE("%06d", 0);
	PRINTF_TEST_TEMPLATE("%06d", 1024);
	PRINTF_TEST_TEMPLATE("%06d", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %06d of a sentence.\n", 1024);

	/**************************%06i**************************/

	PRINTF_TEST_TEMPLATE("%06i", 102498402);
	PRINTF_TEST_TEMPLATE("%06i", -102498402);
	PRINTF_TEST_TEMPLATE("%06i", 0);
	PRINTF_TEST_TEMPLATE("%06i", 1024);
	PRINTF_TEST_TEMPLATE("%06i", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %06i of a sentence.\n", 1024);

	/**************************%06u**************************/

	PRINTF_TEST_TEMPLATE("%06u", 102498402);
	PRINTF_TEST_TEMPLATE("%06u", -102498402);
	PRINTF_TEST_TEMPLATE("%06u", 0);
	PRINTF_TEST_TEMPLATE("%06u", 1024);
	PRINTF_TEST_TEMPLATE("%06u", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %06u of a sentence.\n", 1024);

	/**************************%06d**************************/

	PRINTF_TEST_TEMPLATE("%06o", 102498402);
	PRINTF_TEST_TEMPLATE("%06o", -102498402);
	PRINTF_TEST_TEMPLATE("%06o", 0);
	PRINTF_TEST_TEMPLATE("%06o", 1024);
	PRINTF_TEST_TEMPLATE("%06o", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %06o of a sentence.\n", 1024);

	/**************************%06x**************************/

	PRINTF_TEST_TEMPLATE("%06x", 102498402);
	PRINTF_TEST_TEMPLATE("%06x", -102498402);
	PRINTF_TEST_TEMPLATE("%06x", 0);
	PRINTF_TEST_TEMPLATE("%06x", 1024);
	PRINTF_TEST_TEMPLATE("%06x", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %06x of a sentence.\n", 1024);

	/**************************%06X**************************/

	PRINTF_TEST_TEMPLATE("%06X", 102498402);
	PRINTF_TEST_TEMPLATE("%06X", -102498402);
	PRINTF_TEST_TEMPLATE("%06X", 0);
	PRINTF_TEST_TEMPLATE("%06X", 1024);
	PRINTF_TEST_TEMPLATE("%06X", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %06X of a sentence.\n", 1024);

	if (!failed)
		fprintf(
			stderr,
			__FILE__ ": " COLOUR_BOLD_BRIGHT_GREEN "OK" COLOUR_OFF "\n");

	return (failed);
}
