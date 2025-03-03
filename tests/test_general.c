#include "tests.h"

int test(void)
{
	int len__printf = 0, len_snprintf = 0, failed = 0;
	int l = 39;
	unsigned int ui = (unsigned int)INT_MAX + 1024;
	void *addr = (void *)0x7ffe637541f0;

	/* clang-format off */
	len__printf = _printf("Let's try to printf a simple sentence.\n");
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Let's try to printf a simple sentence.\n");
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Length:[%d, %i]\n", l, l);
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Length:[%d, %i]\n", l, l);
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Negative:[%d]\n", -762534);
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Negative:[%d]\n", -762534);
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Unsigned:[%u]\n", ui);
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Unsigned:[%u]\n", ui);
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Unsigned octal:[%o]\n", ui);
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Unsigned octal:[%o]\n", ui);
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	CHECK_INTEQ(snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Unsigned hexadecimal:[%x, %X]\n", ui, ui), _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui), failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Character:[%c]\n", 'H');
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Character:[%c]\n", 'H');
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("String:[%s]\n", "I am a string !");
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "String:[%s]\n", "I am a string !");
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Address:[%p]\n", addr);
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Address:[%p]\n", addr);
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Percent:[%%]\n");
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Percent:[%%]\n");
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	l = 13;
	len__printf = _printf("Len:[%d]\n", l);
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Len:[%d]\n", l);
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Unknown:[%r]\n");
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Unknown:[%r]\n");
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Unknown:[% 6.4lr]\n");
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Unknown:[% 6.4lr]\n");
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);

	len__printf = _printf("Percent end: %");
	len_snprintf = snprintf(_printf_control_output, TESTS_BUFFER_SIZE, "Percent end: %");
	CHECK_INTEQ(len__printf, len_snprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_control_output, failed);
	/* clang-format on */

	return (failed);
}
