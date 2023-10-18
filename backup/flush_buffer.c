#include "main.h"

/**
 * _flushbuff - prints out contents of buffer and resets it.
 * @buf: Pointer to the buffer
 * @index: Pointer to the current buffer index
 *
 * Return: number of printed characters
 */
long int _flushbuff(char *buf, unsigned int *index)
{
	unsigned int count = 0;

	if (*index < BUFSZ)
		count += write(1, buf, *index);
	else
		exit(-1);

	buf = memset(buf, '\0', BUFSZ);
	*index = 0;
	return (count);
}
