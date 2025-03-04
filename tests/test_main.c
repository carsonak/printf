#include "tests.h"

char _printf_ctrl_output[PRINTF_TESTS_BUFFER_SIZE] = {0};
char _printf_test_output[PRINTF_TESTS_BUFFER_SIZE] = {0};

/**
 * main - the main test file
 *
 * Return: 0 if all tests pass, 1 otherwise.
 */
int main(void) { return (test()); }
