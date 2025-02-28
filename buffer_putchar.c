#include "main.h"

/**
 * buffer_putchar - handles insertion of a character into the buffer.
 * @buffer: the buffer.
 * @c: character to insert.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int buffer_putchar(char_arr *buffer, char c)
{
	int bytes_written = 0;

	if (buffer->i >= buffer->size)
		bytes_written = buffer_flush(buffer);

	buffer->buf[buffer->i++] = c;
	return (bytes_written);
}
