#include "tests.h"

/**
 * test - TASK14 tests.
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
bool test(void)
{
	int len__printf = 0, len_sprintf = 0;
	bool failed = 0;

	PRINTF_CUSTOM_TEST_TEMPLATE(
		"This sentence is retrieved from va_args!\n", "%R",
		"Guvf fragrapr vf ergevrirq sebz in_netf!\n");
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"Complete the sentence: You know nothing, Jon Snow.\n",
		"Complete the sentence: You %R nothing, Jon Snow.\n", "xabj");
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"Complete the sentence: You  nothing, Jon Snow.\n",
		"Complete the sentence: You %R nothing, Jon Snow.\n", "");
	PRINTF_CUSTOM_TEST_TEMPLATE(
		"Complete the sentence: You (null) nothing, Jon Snow.\n",
		"Complete the sentence: You %R nothing, Jon Snow.\n", (char *)0);

	PRINTF_CUSTOM_TEST_TEMPLATE("--     Rot13--", "--%10R--", "Ebg13");
	PRINTF_CUSTOM_TEST_TEMPLATE("--     Rot13--", "--%*R--", 10, "Ebg13");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Rot13--", "--%3R--", "Ebg13");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Rot13--", "--%*R--", 3, "Ebg13");

	PRINTF_CUSTOM_TEST_TEMPLATE("--Rot13--", "--%.10R--", "Ebg13");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Rot13--", "--%.*R--", 10, "Ebg13");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Rot--", "--%.3R--", "Ebg13");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Rot--", "--%.*R--", 3, "Ebg13");

	PRINTF_CUSTOM_TEST_TEMPLATE("--     Rot13--", "--%010R--", "Ebg13");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Rot13     --", "--%-10R--", "Ebg13");

	PRINTF_CUSTOM_TEST_TEMPLATE("--       Rot--", "--%10.3R--", "Ebg13");
	PRINTF_CUSTOM_TEST_TEMPLATE("--Rot13--", "--%3.10R--", "Ebg13");

	if (!failed)
		PRINT_TESTS_PASS_TEXT();

	return (failed);
}
