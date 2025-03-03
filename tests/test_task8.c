#include "tests.h"

/**
 * test - TASK8 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	/**************************%ld**************************/

	PRINTF_TEST_TEMPLATE("%ld", 1024L);
	PRINTF_TEST_TEMPLATE("%ld", -1024L);
	PRINTF_TEST_TEMPLATE("%ld", 0L);
	PRINTF_TEST_TEMPLATE("%ld", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%ld", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %ld bytes in %ld KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%ld - %ld = %ld\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%li**************************/

	PRINTF_TEST_TEMPLATE("%li", 1024L);
	PRINTF_TEST_TEMPLATE("%li", -1024L);
	PRINTF_TEST_TEMPLATE("%li", 0L);
	PRINTF_TEST_TEMPLATE("%li", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%li", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %li bytes in %li KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%li - %li = %li\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%li + %li = %li\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%lu**************************/

	PRINTF_TEST_TEMPLATE("%lu", 1024L);
	PRINTF_TEST_TEMPLATE("%lu", -1024L);
	PRINTF_TEST_TEMPLATE("%lu", 0L);
	PRINTF_TEST_TEMPLATE("%lu", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%lu", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %lu bytes in %lu KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%lu - %lu = %lu\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%lu + %lu = %lu\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%lo**************************/

	PRINTF_TEST_TEMPLATE("%lo", 1024L);
	PRINTF_TEST_TEMPLATE("%lo", -1024L);
	PRINTF_TEST_TEMPLATE("%lo", 0L);
	PRINTF_TEST_TEMPLATE("%lo", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%lo", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %lo bytes in %lo KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%lo - %lo = %lo\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%lo + %lo = %lo\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%lx**************************/

	PRINTF_TEST_TEMPLATE("%lx", 1024L);
	PRINTF_TEST_TEMPLATE("%lx", -1024L);
	PRINTF_TEST_TEMPLATE("%lx", 0L);
	PRINTF_TEST_TEMPLATE("%lx", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%lx", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %lx bytes in %lx KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%lx - %lx = %lx\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%lx + %lx = %lx\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%lX**************************/

	PRINTF_TEST_TEMPLATE("%lX", 1024L);
	PRINTF_TEST_TEMPLATE("%lX", -1024L);
	PRINTF_TEST_TEMPLATE("%lX", 0L);
	PRINTF_TEST_TEMPLATE("%lX", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%lX", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %lX bytes in %lX KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%lX - %lX = %lX\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%lX + %lX = %lX\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%hd**************************/

	PRINTF_TEST_TEMPLATE("%hd", 1024L);
	PRINTF_TEST_TEMPLATE("%hd", -1024L);
	PRINTF_TEST_TEMPLATE("%hd", 0L);
	PRINTF_TEST_TEMPLATE("%hd", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%hd", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %hd bytes in %hd KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%hd - %hd = %hd\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%hd + %hd = %hd\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%hi**************************/

	PRINTF_TEST_TEMPLATE("%hi", 1024L);
	PRINTF_TEST_TEMPLATE("%hi", -1024L);
	PRINTF_TEST_TEMPLATE("%hi", 0L);
	PRINTF_TEST_TEMPLATE("%hi", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%hi", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %hi bytes in %hi KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%hi - %hi = %hi\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%hi + %hi = %hi\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%hu**************************/

	PRINTF_TEST_TEMPLATE("%hu", 1024L);
	PRINTF_TEST_TEMPLATE("%hu", -1024L);
	PRINTF_TEST_TEMPLATE("%hu", 0L);
	PRINTF_TEST_TEMPLATE("%hu", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%hu", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %hu bytes in %hu KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%hu - %hu = %hu\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%hu + %hu = %hu\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%ho**************************/

	PRINTF_TEST_TEMPLATE("%ho", 1024L);
	PRINTF_TEST_TEMPLATE("%ho", -1024L);
	PRINTF_TEST_TEMPLATE("%ho", 0L);
	PRINTF_TEST_TEMPLATE("%ho", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%ho", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %ho bytes in %ho KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%ho - %ho = %ho\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%ho + %ho = %ho\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%hx**************************/

	PRINTF_TEST_TEMPLATE("%hx", 1024L);
	PRINTF_TEST_TEMPLATE("%hx", -1024L);
	PRINTF_TEST_TEMPLATE("%hx", 0L);
	PRINTF_TEST_TEMPLATE("%hx", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%hx", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %hx bytes in %hx KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%hx - %hx = %hx\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%hx + %hx = %hx\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	/**************************%hX**************************/

	PRINTF_TEST_TEMPLATE("%hX", 1024L);
	PRINTF_TEST_TEMPLATE("%hX", -1024L);
	PRINTF_TEST_TEMPLATE("%hX", 0L);
	PRINTF_TEST_TEMPLATE("%hX", LONG_MAX);
	PRINTF_TEST_TEMPLATE("%hX", LONG_MIN);
	PRINTF_TEST_TEMPLATE("There is %hX bytes in %hX KB\n", 1024L, 1L);
	PRINTF_TEST_TEMPLATE("%hX - %hX = %hX\n", 1024L, 2048L, -1024L);
	PRINTF_TEST_TEMPLATE(
		"%hX + %hX = %hX\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));

	if (!failed)
		fprintf(
			stderr,
			__FILE__ ": " COLOUR_BOLD_BRIGHT_GREEN "OK" COLOUR_OFF "\n");

	return (failed);
}
