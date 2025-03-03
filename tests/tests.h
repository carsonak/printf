#ifndef PRINTF_TESTS_H
#define PRINTF_TESTS_H

/* snprintf() */
#define _ISOC99_SOURCE

#include <inttypes.h> /* intmax_t */
#include <limits.h>   /* max of types */
#include <stdbool.h>  /* bool */
#include <stdio.h>    /* printf */
#include <string.h>   /* strncmp */

#include "main.h"

#define COLOUR_OFF "\033[0m"
#define COLOUR_BOLD_RED "\033[1;31m"
#define COLOUR_BOLD_WHITE "\033[1;37m"
#define COLOUR_BRIGHT_YELLOW "\033[0;93m"

#define TESTS_BUFFER_SIZE (1024 * 4)

#define CHECK_INTEQ(actual, expected, has_failed)                              \
	do                                                                         \
	{                                                                          \
		intmax_t _actual_val = actual, _expected_val = expected;               \
		if (_actual_val != _expected_val)                                      \
		{                                                                      \
			fprintf(                                                           \
				stderr,                                                        \
				COLOUR_BOLD_RED "FAIL    " COLOUR_BOLD_WHITE                   \
								":%s:%u: " COLOUR_BRIGHT_YELLOW                \
								"ints not equal" COLOUR_OFF ".\n",             \
				__FILE__, __LINE__);                                           \
			fprintf(                                                           \
				stderr,                                                        \
				"Expected: %s " COLOUR_BOLD_WHITE "==" COLOUR_OFF " %jd\n",    \
				#expected, _expected_val);                                     \
			fprintf(                                                           \
				stderr,                                                        \
				"Got     : %s " COLOUR_BOLD_WHITE "==" COLOUR_OFF " %jd\n",    \
				#actual, _actual_val);                                         \
			has_failed = true;                                                 \
		}                                                                      \
	} while (0)

#define CHECK_STREQ(actual, expected, has_failed)                              \
	do                                                                         \
	{                                                                          \
		if (strncmp(expected, actual, TESTS_BUFFER_SIZE))                      \
		{                                                                      \
			fprintf(                                                           \
				stderr,                                                        \
				COLOUR_BOLD_RED "FAIL    " COLOUR_BOLD_WHITE                   \
								":%s:%u: " COLOUR_BRIGHT_YELLOW                \
								"strings not equal" COLOUR_OFF ".\n",          \
				__FILE__, __LINE__);                                           \
			if (#expected[0] == '"')                                           \
				fprintf(stderr, "Expected: %s\n", expected);                   \
			else                                                               \
				fprintf(                                                       \
					stderr,                                                    \
					"Expected: %s " COLOUR_BOLD_WHITE "==" COLOUR_OFF " %s\n", \
					#expected, expected);                                      \
			if (#actual[0] == '"')                                             \
				fprintf(stderr, "Got     : %s\n", actual);                     \
			else                                                               \
				fprintf(                                                       \
					stderr,                                                    \
					"Got     : %s " COLOUR_BOLD_WHITE "==" COLOUR_OFF " %s\n", \
					#actual, actual);                                          \
			has_failed = true;                                                 \
		}                                                                      \
	} while (0)

extern char _printf_test_output[TESTS_BUFFER_SIZE];
extern char _printf_control_output[TESTS_BUFFER_SIZE];

ssize_t _write(int fd, const void *buf, size_t bytes);
int test(void);

#endif /* PRINTF_TESTS_H */
