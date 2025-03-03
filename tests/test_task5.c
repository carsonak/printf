#include "tests.h"

/**
 * test - TASK5 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	PRINTF_CUSTOM_TEST_TEMPLATE(
		"No special character.", "%S", "No special character.");
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"\\x01\\x02\\x03\\x04\\x05\\x06\\x07", "%S",
		"\x01\x02\x03\x04\x05\x06\x07");
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"Could you print some non-prntable "
		"characters?\nSure:\\x1F\\x7F\\x0A\nThanks!\n",
		"Could you print some non-prntable characters?\n%S\nThanks!\n",
		"Sure:\x1F\x7F\n");
	PRINTF_TEST_TEMPLATE("");

	len__printf =
		_printf("- What did you say?\n- %S\n- That's what I thought.\n", "");
	len_sprintf = sprintf(
		_printf_control_output,
		"- What did you say?\n- %s\n- That's what I thought.\n", "");
	CHECK_INTEQ(len__printf, len_sprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	return (failed);
}
