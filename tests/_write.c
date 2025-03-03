#include "tests.h"

char _printf_test_output[TESTS_BUFFER_SIZE] = {0};

/**
 * _write - wrapper for `write()`, writes to a buffer instead of a file
 * descriptor.
 * @fd: an open file descriptor.
 * @buf: pointer to a memory block.
 * @bytes: size in bytes of the memory block.
 *
 * Return: number of bytes written, -1 on error.
 */
ssize_t _write(int fd, const void *buf, size_t bytes)
{
	ssize_t i = 0;
	const char *const str = buf;

	(void)fd;
	if (!buf || bytes >= TESTS_BUFFER_SIZE)
		return (-1);

	for (i = 0; i < (ssize_t)bytes; i++)
		_printf_test_output[i] = str[i];

	_printf_test_output[i] = 0;
	return (i);
}
