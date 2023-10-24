#include "main.h"

/**
 * _flushbuff - prints out contents of buffer and resets it.
 * @buf: Pointer to the buffer
 * @buf_i: Pointer to the current buffer index
 *
 * Return: number of printed characters
 */
int _flushbuff(char *const buf, int *const buf_i)
{
	int nob = 0;

	if (*buf_i < PRINTF_BUFFER)
		nob += write(1, buf, *buf_i);
	else
		exit(-1);

	memset(buf, '*', PRINTF_BUFFER);
	*buf_i = 0;
	return (nob);
}
