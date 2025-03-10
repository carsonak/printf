#include "tests.h"

/**
 * test - general tests.
 *
 * Return: 0 if all tests are successful, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;
	unsigned int ui = (unsigned int)INT_MAX + 1024;

	PRINTF_TEST_TEMPLATE("Let's try to printf a simple sentence.\n");
	PRINTF_TEST_TEMPLATE("Length:[%d, %i]\n", 39, 39);
	PRINTF_TEST_TEMPLATE("Negative:[%d]\n", -762534);
	PRINTF_TEST_TEMPLATE("Unsigned:[%u]\n", ui);
	PRINTF_TEST_TEMPLATE("Unsigned octal:[%o]\n", ui);
	PRINTF_TEST_TEMPLATE("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	PRINTF_TEST_TEMPLATE("Character:[%c]\n", 'H');
	PRINTF_TEST_TEMPLATE("String:[%s]\n", "I am a string !");
	PRINTF_TEST_TEMPLATE("Address:[%p]\n", (void *)0x7ffe637541f0);
	PRINTF_TEST_TEMPLATE("Percent:[%%]\n");
	PRINTF_TEST_TEMPLATE("Len:[%d]\n", 39);
	PRINTF_TEST_TEMPLATE("--%-8.6d--", 1024);
	PRINTF_TEST_TEMPLATE("--%08.6d--", 1024);
	PRINTF_TEST_TEMPLATE("--%-08.6d--", 1024);
	PRINTF_TEST_TEMPLATE("--%0-8.6d--", 1024);
	PRINTF_TEST_TEMPLATE("%.006d", 1024);
	PRINTF_TEST_TEMPLATE("Unknown:[%t]\n");
	PRINTF_TEST_TEMPLATE("Unknown + precision:[% 6.4lt]\n");
	PRINTF_TEST_TEMPLATE("Hanging:[% 6.4l]\n");

	if (!failed)
		PRINT_TESTS_PASS_TEXT();

	return (failed);
}
