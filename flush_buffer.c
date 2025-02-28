#include "main.h"

/**
 * flush_buffer - prints out contents of buffer and resets the cursor.
 * @buffer: the printf buffer to flush.
 *
 * Return: number of printed characters, -1 on error.
 */
int flush_buffer(printf_buffer buffer)
{
	int bytes_printed = write(STDOUT_FILENO, buffer.buf, buffer.cursor);

	buffer.cursor = 0;
	return (bytes_printed);
}
