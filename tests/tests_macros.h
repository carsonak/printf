#ifndef TESTS_MACROS_H
#define TESTS_MACROS_H

#include <ctype.h> /* isdigit */
#include <stdio.h> /* printf */

#define COLOUR_OFF "\033[0m"
#define COLOUR_BOLD_RED "\033[1;31m"
#define COLOUR_BOLD_WHITE "\033[1;37m"
#define COLOUR_BRIGHT_YELLOW "\033[0;93m"
#define COLOUR_BOLD_BRIGHT_GREEN "\033[1;92m"

#define GOT COLOUR_BOLD_WHITE "Got" COLOUR_OFF
#define EXPECTED COLOUR_BOLD_WHITE "Expected" COLOUR_OFF
#define FAIL COLOUR_BOLD_RED "Fail" COLOUR_OFF
#define OK COLOUR_BOLD_BRIGHT_GREEN "OK" COLOUR_OFF
#define EQUAL_SIGN COLOUR_BOLD_WHITE "==" COLOUR_OFF

#define PRINT_TESTS_FAIL_TEXT(                                                 \
	actual, expand_actual, expected, expand_expected, message, format_spec)    \
	do                                                                         \
	{                                                                          \
		fprintf(                                                               \
			stderr,                                                            \
			FAIL "    : " COLOUR_BOLD_WHITE                                    \
				 "%s:%u: " COLOUR_BRIGHT_YELLOW message COLOUR_OFF ".\n",      \
			__FILE__, __LINE__);                                               \
                                                                               \
		if (!expand_expected)                                                  \
			fprintf(stderr, EXPECTED ": " format_spec "\n", expected);         \
		else                                                                   \
			fprintf(                                                           \
				stderr, EXPECTED ": %s " EQUAL_SIGN " " format_spec "\n",      \
				#expected, expected);                                          \
                                                                               \
		if (!expand_actual)                                                    \
			fprintf(stderr, GOT "     : " format_spec "\n", actual);           \
		else                                                                   \
			fprintf(                                                           \
				stderr, GOT "     : %s " EQUAL_SIGN " " format_spec "\n",      \
				#actual, actual);                                              \
	} while (0)

#define PRINT_TESTS_PASS_TEXT()                                                \
	fprintf(stderr, COLOUR_BOLD_WHITE __FILE__ COLOUR_OFF ": " OK "\n")

#define CHECK_INTEQ(actual, expected, has_failed)                              \
	do                                                                         \
	{                                                                          \
		intmax_t _actual_val = actual, _expected_val = expected;               \
		if (_actual_val != _expected_val)                                      \
		{                                                                      \
			PRINT_TESTS_FAIL_TEXT(                                             \
				actual, !isdigit(#actual[0]), expected,                        \
				!isdigit(#expected[0]), "ints not equal", "%jd");              \
			has_failed = true;                                                 \
		}                                                                      \
	} while (0)

#define CHECK_STREQ(actual, expected, has_failed)                              \
	do                                                                         \
	{                                                                          \
		if (strncmp(expected, actual, PRINTF_TESTS_BUFFER_SIZE))               \
		{                                                                      \
			PRINT_TESTS_FAIL_TEXT(                                             \
				actual, !isdigit(#actual[0]), expected,                        \
				!isdigit(#expected[0]), "strings not equal", "%s");            \
			has_failed = true;                                                 \
		}                                                                      \
	} while (0)

#define PRINTF_TEST_TEMPLATE(format, ...)                                      \
	do                                                                         \
	{                                                                          \
		len__printf = _printf(format __VA_OPT__(, ) __VA_ARGS__);              \
		len_sprintf =                                                          \
			sprintf(_printf_ctrl_output, format __VA_OPT__(, ) __VA_ARGS__);   \
		CHECK_INTEQ(len__printf, len_sprintf, failed);                         \
		CHECK_STREQ(_printf_test_output, _printf_ctrl_output, failed);         \
	} while (0)

#define PRINTF_CUSTOM_TEST_TEMPLATE(control_str, format, ...)                  \
	do                                                                         \
	{                                                                          \
		len__printf = _printf(format __VA_OPT__(, ) __VA_ARGS__);              \
		len_sprintf = sprintf(_printf_ctrl_output, control_str);               \
		CHECK_INTEQ(len__printf, len_sprintf, failed);                         \
		CHECK_STREQ(_printf_test_output, _printf_ctrl_output, failed);         \
	} while (0)

#endif /* TESTS_MACROS_H */
