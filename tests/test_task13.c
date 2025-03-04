#include "tests.h"

/**
 * test - TASK13 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	PRINTF_CUSTOM_TEST_TEMPLATE(
		"!sgra_av morf deveirter si ecnetnes sihT\n", "%r",
		"\nThis sentence is retrieved from va_args!");
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"Complete the sentence: You wonk nothing, Jon Snow.\n",
		"Complete the sentence: You %r nothing, Jon Snow.\n", "know");
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"Complete the sentence: You  nothing, Jon Snow.\n",
		"Complete the sentence: You %r nothing, Jon Snow.\n", "");
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"Complete the sentence: You (null) nothing, Jon Snow.\n",
		"Complete the sentence: You %r nothing, Jon Snow.\n", (char *)0);

	PRINTF_CUSTOM_TEST_TEMPLATE("--    Backward--", "--%12r--", "drawkcaB");
	PRINTF_CUSTOM_TEST_TEMPLATE("--    Backward--", "--%*r--", 12, "drawkcaB");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Backward--", "--%4r--", "drawkcaB");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Backward--", "--%*r--", 4, "drawkcaB");

	PRINTF_CUSTOM_TEST_TEMPLATE("--Backward--", "--%.12r--", "drawkcaB");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Backward--", "--%.*r--", 12, "drawkcaB");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Back--", "--%.4r--", "drawkcaB");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Back--", "--%.*r--", 4, "drawkcaB");

	PRINTF_CUSTOM_TEST_TEMPLATE("--    Backward--", "--%012r--", "drawkcaB");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Backward    --", "--%-12r--", "drawkcaB");

	PRINTF_CUSTOM_TEST_TEMPLATE("--        Back--", "--%12.4r--", "drawkcaB");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Backward--", "--%4.12r--", "drawkcaB");

	if (!failed)
		PRINT_TESTS_PASS_TEXT();

	return (failed);
}
