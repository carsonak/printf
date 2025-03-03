#include "tests.h"

/**
 * test - TASK0 tests.
 *
 * Return: 0 if all tests are successful, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	PRINTF_TEST_TEMPLATE("Let's print a simple sentence.\n");
	PRINTF_TEST_TEMPLATE("%c", 'S');
	PRINTF_TEST_TEMPLATE("A char inside a sentence: %c. Did it work?\n", 'F');
	PRINTF_TEST_TEMPLATE(
		"Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	PRINTF_TEST_TEMPLATE("%s", "This sentence is retrieved from va_args!\n");
	PRINTF_TEST_TEMPLATE(
		"Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	PRINTF_TEST_TEMPLATE(
		"%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ",
		"more", 'r', "s", "", "know", 't', ", Jon", '\n');
	PRINTF_TEST_TEMPLATE("%%");
	PRINTF_TEST_TEMPLATE("Should print a single percent sign: %%\n");
	PRINTF_TEST_TEMPLATE(
		"%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait",
		'\n');
	PRINTF_TEST_TEMPLATE("css%ccs%scscscs", 'T', "Test");
	PRINTF_TEST_TEMPLATE("%c", '\0');
	PRINTF_TEST_TEMPLATE("%");
	PRINTF_TEST_TEMPLATE("%!\n");
	PRINTF_TEST_TEMPLATE("%K\n");

	return (failed);
}
