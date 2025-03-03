#include "tests.h"

/**
 * test - the TASK0 test file
 *
 * Return: 0 if all tests are successful, 1 otherwise.
 */
int test(void)
{
	int len__printf = 0, len_snprintf = 0, failed = 0;

	/* clang-format off */
	len__printf = _printf("%c", 'S');
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "%c", 'S');
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("A char inside a sentence: %c. Did it work?\n", 'F');
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "A char inside a sentence: %c. Did it work?\n", 'F');
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("%s", "This sentence is retrieved from va_args!\n");
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "%s", "This sentence is retrieved from va_args!\n");
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Should print a single percent sign: %%\n");
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Should print a single percent sign: %%\n");
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("%c", '\0');
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "%c", '\0');
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);
	/* clang-format on */

	return (0);
}
