#include "tests.h"

/**
 * test - TASK9 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	/**************************%6d**************************/

	PRINTF_TEST_TEMPLATE("%6d", 102498402);
	PRINTF_TEST_TEMPLATE("%6d", -102498402);
	PRINTF_TEST_TEMPLATE("%6d", 0);
	PRINTF_TEST_TEMPLATE("%6d", 1024);
	PRINTF_TEST_TEMPLATE("%6d", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %6d of a sentence.\n", 1024);

	/**************************%6i**************************/

	PRINTF_TEST_TEMPLATE("%6i", 102498402);
	PRINTF_TEST_TEMPLATE("%6i", -102498402);
	PRINTF_TEST_TEMPLATE("%6i", 0);
	PRINTF_TEST_TEMPLATE("%6i", 1024);
	PRINTF_TEST_TEMPLATE("%6i", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %6i of a sentence.\n", 1024);

	/**************************%6u**************************/

	PRINTF_TEST_TEMPLATE("%6u", 102498402);
	PRINTF_TEST_TEMPLATE("%6u", -102498402);
	PRINTF_TEST_TEMPLATE("%6u", 0);
	PRINTF_TEST_TEMPLATE("%6u", 1024);
	PRINTF_TEST_TEMPLATE("%6u", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %6u of a sentence.\n", 1024);

	/**************************%6d**************************/

	PRINTF_TEST_TEMPLATE("%6o", 102498402);
	PRINTF_TEST_TEMPLATE("%6o", -102498402);
	PRINTF_TEST_TEMPLATE("%6o", 0);
	PRINTF_TEST_TEMPLATE("%6o", 1024);
	PRINTF_TEST_TEMPLATE("%6o", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %6o of a sentence.\n", 1024);

	/**************************%6x**************************/

	PRINTF_TEST_TEMPLATE("%6x", 102498402);
	PRINTF_TEST_TEMPLATE("%6x", -102498402);
	PRINTF_TEST_TEMPLATE("%6x", 0);
	PRINTF_TEST_TEMPLATE("%6x", 1024);
	PRINTF_TEST_TEMPLATE("%6x", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %6x of a sentence.\n", 1024);

	/**************************%6X**************************/

	PRINTF_TEST_TEMPLATE("%6X", 102498402);
	PRINTF_TEST_TEMPLATE("%6X", -102498402);
	PRINTF_TEST_TEMPLATE("%6X", 0);
	PRINTF_TEST_TEMPLATE("%6X", 1024);
	PRINTF_TEST_TEMPLATE("%6X", -1024);
	PRINTF_TEST_TEMPLATE("In the middle %6X of a sentence.\n", 1024);

	/**************************%6c**************************/

	PRINTF_TEST_TEMPLATE("%6c", 'A');
	PRINTF_TEST_TEMPLATE("%6c", 0);
	PRINTF_TEST_TEMPLATE("In the middle %6c of a sentence.\n", 'H');

	/**************************%6s**************************/

	PRINTF_TEST_TEMPLATE("%6s", "Best School !\n");
	PRINTF_TEST_TEMPLATE("%6s", "Hi!\n");
	PRINTF_TEST_TEMPLATE("In the middle %6s of a sentence.\n", "Hey");

	/**************************%6d**************************/

	PRINTF_TEST_TEMPLATE("%*d", 6, 102498402);
	PRINTF_TEST_TEMPLATE("%*d", 6, -102498402);
	PRINTF_TEST_TEMPLATE("%*d", 6, 0);
	PRINTF_TEST_TEMPLATE("%*d", 6, 1024);
	PRINTF_TEST_TEMPLATE("%*d", 6, -1024);
	PRINTF_TEST_TEMPLATE("In the middle %*d of a sentence.\n", 6, 1024);

	/**************************%6i**************************/

	PRINTF_TEST_TEMPLATE("%*i", 6, 102498402);
	PRINTF_TEST_TEMPLATE("%*i", 6, -102498402);
	PRINTF_TEST_TEMPLATE("%*i", 6, 0);
	PRINTF_TEST_TEMPLATE("%*i", 6, 1024);
	PRINTF_TEST_TEMPLATE("%*i", 6, -1024);
	PRINTF_TEST_TEMPLATE("In the middle %*i of a sentence.\n", 6, 1024);

	/**************************%6u**************************/

	PRINTF_TEST_TEMPLATE("%*u", 6, 102498402);
	PRINTF_TEST_TEMPLATE("%*u", 6, -102498402);
	PRINTF_TEST_TEMPLATE("%*u", 6, 0);
	PRINTF_TEST_TEMPLATE("%*u", 6, 1024);
	PRINTF_TEST_TEMPLATE("%*u", 6, -1024);
	PRINTF_TEST_TEMPLATE("In the middle %*u of a sentence.\n", 6, 1024);

	/**************************%6d**************************/

	PRINTF_TEST_TEMPLATE("%*o", 6, 102498402);
	PRINTF_TEST_TEMPLATE("%*o", 6, -102498402);
	PRINTF_TEST_TEMPLATE("%*o", 6, 0);
	PRINTF_TEST_TEMPLATE("%*o", 6, 1024);
	PRINTF_TEST_TEMPLATE("%*o", 6, -1024);
	PRINTF_TEST_TEMPLATE("In the middle %*o of a sentence.\n", 6, 1024);

	/**************************%6x**************************/

	PRINTF_TEST_TEMPLATE("%*x", 6, 102498402);
	PRINTF_TEST_TEMPLATE("%*x", 6, -102498402);
	PRINTF_TEST_TEMPLATE("%*x", 6, 0);
	PRINTF_TEST_TEMPLATE("%*x", 6, 1024);
	PRINTF_TEST_TEMPLATE("%*x", 6, -1024);
	PRINTF_TEST_TEMPLATE("In the middle %*x of a sentence.\n", 6, 1024);

	/**************************%6X**************************/

	PRINTF_TEST_TEMPLATE("%*X", 6, 102498402);
	PRINTF_TEST_TEMPLATE("%*X", 6, -102498402);
	PRINTF_TEST_TEMPLATE("%*X", 6, 0);
	PRINTF_TEST_TEMPLATE("%*X", 6, 1024);
	PRINTF_TEST_TEMPLATE("%*X", 6, -1024);
	PRINTF_TEST_TEMPLATE("In the middle %*X of a sentence.\n", 6, 1024);

	/**************************%6c**************************/

	PRINTF_TEST_TEMPLATE("%*c", 6, 'A');
	PRINTF_TEST_TEMPLATE("%*c", 6, 0);
	PRINTF_TEST_TEMPLATE("In the middle %*c of a sentence.\n", 6, 'H');

	/**************************%6s**************************/

	PRINTF_TEST_TEMPLATE("%*s", 6, "Best School !\n");
	PRINTF_TEST_TEMPLATE("%*s", 6, "Hi!\n");
	PRINTF_TEST_TEMPLATE("In the middle %*s of a sentence.\n", 6, "Hey");

	if (!failed)
		fprintf(
			stderr,
			__FILE__ ": " COLOUR_BOLD_BRIGHT_GREEN "OK" COLOUR_OFF "\n");

	return (failed);
}
