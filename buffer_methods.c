#include <unistd.h> /* STDOUT_FILENO */

#include "buffer_object.h"

/**
 * buffer_flush - prints out contents of buffer and resets the cursor.
 * @buffer: the printf buffer to flush.
 *
 * Return: number of printed characters, -1 on error.
 */
int buffer_flush(char_arr *buffer)
{
	int bytes_printed = 0;

	if (!buffer || !buffer->buf || buffer->size < 1 || buffer->i < 0)
		return (-1);

	bytes_printed = _write(STDOUT_FILENO, buffer->buf, buffer->i);
	buffer->i = 0;
	return (bytes_printed);
}

/**
 * buffer_putchar - handles insertion of a character into the buffer.
 * @buffer: the buffer.
 * @c: character to insert.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * -1 on error.
 */
int buffer_putchar(char_arr *buffer, char c)
{
	int bytes_written = 0;

	if (!buffer || !buffer->buf || buffer->size < 1 || buffer->i < 0)
		return (-1);

	if (buffer->i >= buffer->size)
		bytes_written = buffer_flush(buffer);

	buffer->buf[buffer->i++] = c;
	return (bytes_written);
}

/**
 * buffer_puts - handles insertion of a string into a buffer.
 * @buffer: the buffer.
 * @str: pointer to the string.
 *
 * Return: Returns a positive int on success
 * (if buffer was flushed the number returned will be greater than 0),
 * negative int on failure.
 */
int buffer_puts(char_arr *buffer, const char *str)
{
	int bytes_written = 0;

	while (str && *str)
	{
		int ret_val = buffer_putchar(buffer, *str);

		if (ret_val < 0)
			return (ret_val);

		bytes_written += ret_val;
		++str;
	}

	return (bytes_written);
}
