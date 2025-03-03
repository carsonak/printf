#include "tests.h"

/**
 * test - TASK12 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	/**************************%-6d**************************/

	PRINTF_TEST_TEMPLATE("%-6d", 102498402);
	PRINTF_TEST_TEMPLATE("%-6d", -102498402);
	PRINTF_TEST_TEMPLATE("%-6d", 0);
	PRINTF_TEST_TEMPLATE("%-6d", 1024);
	PRINTF_TEST_TEMPLATE("%-6d", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %-6d of a sentence.\n", 1024);

	/**************************%-6i**************************/

	PRINTF_TEST_TEMPLATE("%-6i", 102498402);
	PRINTF_TEST_TEMPLATE("%-6i", -102498402);
	PRINTF_TEST_TEMPLATE("%-6i", 0);
	PRINTF_TEST_TEMPLATE("%-6i", 1024);
	PRINTF_TEST_TEMPLATE("%-6i", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %-6i of a sentence.\n", 1024);

	/**************************%-6u**************************/

	PRINTF_TEST_TEMPLATE("%-6u", 102498402);
	PRINTF_TEST_TEMPLATE("%-6u", -102498402);
	PRINTF_TEST_TEMPLATE("%-6u", 0);
	PRINTF_TEST_TEMPLATE("%-6u", 1024);
	PRINTF_TEST_TEMPLATE("%-6u", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %-6u of a sentence.\n", 1024);

	/**************************%-6d**************************/

	PRINTF_TEST_TEMPLATE("%-6o", 102498402);
	PRINTF_TEST_TEMPLATE("%-6o", -102498402);
	PRINTF_TEST_TEMPLATE("%-6o", 0);
	PRINTF_TEST_TEMPLATE("%-6o", 1024);
	PRINTF_TEST_TEMPLATE("%-6o", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %-6o of a sentence.\n", 1024);

	/**************************%-6x**************************/

	PRINTF_TEST_TEMPLATE("%-6x", 102498402);
	PRINTF_TEST_TEMPLATE("%-6x", -102498402);
	PRINTF_TEST_TEMPLATE("%-6x", 0);
	PRINTF_TEST_TEMPLATE("%-6x", 1024);
	PRINTF_TEST_TEMPLATE("%-6x", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %-6x of a sentence.\n", 1024);

	/**************************%-6X**************************/

	PRINTF_TEST_TEMPLATE("%-6X", 102498402);
	PRINTF_TEST_TEMPLATE("%-6X", -102498402);
	PRINTF_TEST_TEMPLATE("%-6X", 0);
	PRINTF_TEST_TEMPLATE("%-6X", 1024);
	PRINTF_TEST_TEMPLATE("%-6X", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %-6X of a sentence.\n", 1024);

	if (!failed)
		fprintf(
			stderr,
			__FILE__ ": " COLOUR_BOLD_BRIGHT_GREEN "OK" COLOUR_OFF "\n");

	return (failed);
}
