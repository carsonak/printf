#include "tests.h"

/**
 * test - TASK13 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	/* int len__printf = 0, len_sprintf = 0; */
	bool failed = 0;

	if (!failed)
		fprintf(
			stderr,
			__FILE__ ": " COLOUR_BOLD_BRIGHT_GREEN "OK" COLOUR_OFF "\n");

	return (failed);
}
