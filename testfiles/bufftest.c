#include "main.h"
#include <stdio.h>
#include <string.h>
#define BUFFSIZE 9000

void buf_filler(char *buf);
void turnit(char *track, unsigned int i);

/**
 * main - tests max buffer size
 *
 * Return: always 0
 */
int main(void)
{
	char bigBuff[BUFFSIZE];
	int ret;

	memset(bigBuff, '\0', sizeof(bigBuff));
	buf_filler(bigBuff);

	ret = printf("%s", bigBuff);
	printf("\n\nNumber of characters printed: %d\n\n", ret);
	ret = _printf("%s", bigBuff);
	printf("\n\nNumber of characters printed: %d\n\n", ret);

	return (0);
}

/**
 * buf_filler - fills every 4 of a char buffer bytes of with a number
 * @buf: the buffer
 */
void buf_filler(char *buf)
{
	unsigned int i = 0, y;
	char track[6];

	while (i < BUFFSIZE)
	{
		memset(track, '0', sizeof(track) - 1);
		turnit(track, (i / 5));
		for (y = 0; (i < BUFFSIZE) && track[y]; y++, i++)
			buf[i] = track[y];
	}
}

/**
 * turnit - convert integers into 4 byte strings
 * @track: the array in which the number is to be stored
 * @i: the integer
 */
void turnit(char *track, unsigned int i)
{
	int num = i + 1, y = 3;

	track[y + 2] = '\0';

	if (!(num % 16) && num > 15)
		track[y + 1] = '\n';
	else
		track[y + 1] = ' ';

	while (num && y >= 0)
	{
		track[y] = (num % 10) + '0';
		num /= 10;
		y--;
	}
}
