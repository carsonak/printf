#include <unistd.h>

#include "util_functions.h"

/**
 * _write - wrapper for `write()`.
 * @fd: an open file descriptor.
 * @buf: pointer to a memory block.
 * @bytes: size in bytes of the memory block.
 *
 * Return: number of bytes written, -1 on error.
 */
ssize_t _write(int fd, const void *buf, size_t bytes)
{
	return (write(fd, buf, bytes));
}
