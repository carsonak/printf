#include "tests.h"

/**
 * NOTE(Andrew): Because output is being written to buffers in memory which
 * are then compared character by character, it becomes difficult to emulate
 * the infinite rolling screen of a terminal. This means that these tests may
 * fail to represent actual real world output, although the number of
 * characters written should still be correct.
 */

/**
 * test - TASK4 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0, i = 0;
	bool failed = 0;
	char *s;
	char *tmp = "Then the output consists of object files output by the "
				"assembler.\n\nOther options are passed on to one stage of "
				"processing. Some options control the";
	char *tmp2 = "options control the assembler and linker; most of these are "
				 "not documented here, since you rarely";
	const char *str =
		"When you invoke GCC, it normally does preprocessing, compilation, "
		"assembly and linking. The \"overall options\" allow you to stop this "
		"process at an intermediate stage. For example, the -c option says not "
		"to run the linker. Then the output consists of object files output by "
		"the assembler.\n\nOther options are passed on to one stage of "
		"processing. Some options control the preprocessor and others the "
		"compiler itself. Yet other options control the assembler and linker; "
		"most of these are not documented here, since you rarely need to use "
		"any of them.\n\nMost of the command line options that you can use "
		"with GCC are useful for C programs; when an option is only useful "
		"with another language (usually C ++ ), the explanation says so "
		"explicitly. If the description for a particular option does not "
		"mention a source language, you can use that option with all supported "
		"languages.\n\nThe gcc program accepts options and file names as "
		"operands. Many options have multi-letter names; therefore multiple "
		"single-letter options may not";

	PRINTF_TEST_TEMPLATE(str);
	str = "When you invoke GCC, it normally does preprocessing, compilation, "
		  "assembly and linking. The \"overall options\" allow you to stop "
		  "this process at an intermediate stage. For example, the -c option "
		  "says not to run the linker. Then the output consists of object "
		  "files output by the assembler.\n\nOther options are passed on to "
		  "one stage of processing. Some options control the preprocessor and "
		  "others the compiler itself. Yet other options control the assembler "
		  "and linker; most of these are not documented here, since you rarely "
		  "need to use any of them.\n\nMost of the command line options that "
		  "you can use with GCC are useful for C programs; when an option is "
		  "only useful with another language (usually C ++ ), the explanation "
		  "says so explicitly. If the description for a particular option does "
		  "not mention a source language, you can use that option with all "
		  "supported languages.\n\nThe gcc program accepts options and file "
		  "names as operands. Many options have multi-letter names; therefore "
		  "multiple single-letter options may not%d\n";
	PRINTF_TEST_TEMPLATE(str, 8);
	PRINTF_TEST_TEMPLATE(str, 123456789);
	str =
		"When %s invoke GCC, it %s and linking. The %coverall options%c allow "
		"you to stop this process at an intermediate stage. %s the -c option "
		"says not to run the linker. %s preprocessor and %cthers the compiler "
		"itself. Yet other %s need to use any of them.\n\nMost of the command "
		"line options that you can use with GCC are useful for C programs; "
		"when an option is only useful with another language (usually C ++ ), "
		"the explanation says so explicitly. If the description for a "
		"particular option does not mention a source language, you can use "
		"that option with all supported languages.\n\nThe gcc program accepts "
		"options and file names as operands. Many options have multi-letter "
		"names; therefore multiple single-letter options may not%d\n";
	PRINTF_TEST_TEMPLATE(
		str, "you", "normally does preprocessing, compilation, assembly", '"',
		'"', "For example,", tmp, 'o', tmp2, 8);
	PRINTF_TEST_TEMPLATE(
		str, "you", "normally does preprocessing, compilation, assembly", '"',
		'"', "For example,", tmp, 'o', tmp2, 123456789);

	s = malloc(1020);
	if (!s)
		return (failed);

	i = 0;
	while (i < 1019)
		s[i++] = 'A';

	s[i] = 0;

	len__printf = _printf("%s%b\n", s, INT_MAX);
	len_sprintf = sprintf(
		_printf_ctrl_output, "%s%s\n", s, "1111111111111111111111111111111");
	CHECK_INTEQ(len__printf, len_sprintf, failed);
	CHECK_STREQ(_printf_test_output, _printf_ctrl_output, failed);

	free(s);

	if (!failed)
		PRINT_TESTS_PASS_TEXT();

	return (failed);
}
