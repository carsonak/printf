#include "main.h"

/**
 * _flushbuff - prints out contents of buffer and resets it.
 * @buf: Pointer to the buffer
 * @buf_i: Pointer to the current buffer index
 *
 * Return: number of printed characters
 */
long int _flushbuff(char *buf, unsigned int *buf_i)
{
	long int err = 0;

	if (*buf_i < PRINTF_BUFFER)
		err += write(1, buf, *buf_i);
	else
		exit(-1);

	memset(buf, '\0', PRINTF_BUFFER);
	*buf_i = 0;
	return (err);
}
