#ifndef PRINTF_BUFFER_OBJECT_H
#define PRINTF_BUFFER_OBJECT_H

/**
 * struct char_arr - a simple mutable char buffer data type.
 * @size: size of the array in bytes.
 * @i: cursor of the array.
 * @buf: pointer to the first byte in the array.
 */
typedef struct char_arr
{
	long int size;
	long int i;
	char *buf;
} char_arr;

int buffer_flush(char_arr *buffer);
int buffer_putchar(char_arr *buffer, char c);
int buffer_puts(char_arr *buffer, const char *str);

#endif /* PRINTF_BUFFER_OBJECT_H */
