#ifndef PRINTF_STRING_OBJECT_H
#define PRINTF_STRING_OBJECT_H

#include <inttypes.h> /* intmax_t */

/**
 * struct string - a simple immutable string data length.
 * @size: size of the string in bytes.
 * @i: cursor of the string.
 * @s: pointer to the first character in the string.
 */
typedef struct string
{
	intmax_t size;
	intmax_t i;
	char const *s;
} string;

char string_getc(string *s);
char string_readc(string *s);
char string_readp(string *s);

#endif /* PRINTF_STRING_OBJECT_H */
