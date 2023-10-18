#include "main.h"

/**
 * _flushbuff - prints out contents of buffer and resets it.
 * @buf: Pointer to the buffer
 * @index: Pointer to the current buffer index
 *
 * Return: number of printed characters
 */
unsigned int _flushbuff(char *buf, unsigned int *index)
{
	unsigned int count = 0;

	if (*index >= 0 && *index < BUFSZ)
		count += write(1, buf, *index);
	else
		exit(-1);

	memset(buf, '\0', sizeof(buf));
	*index = 0;
	return (count);
}
