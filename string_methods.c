#include <limits.h>

#include "string_object.h"

/**
 * string_readc - returns current character and advances the string cursor.
 * @s: the string.
 *
 * An error is returned if: the cursor position < 0 or cursor position > size
 * or size <= 0.
 * Once the cursor reaches the end of the string,
 * CHAR_MIN will be returned on the next call to this function.
 *
 * Return: the current character, -1 on error.
 */
char string_readc(string *s)
{
	if (s->i < 0 || s->size <= 0 || s->i > s->size)
		return (-1);

	if (s->i == s->size)
		return (CHAR_MIN);

	return (s->s[s->i++]);
}

/**
 * string_readp - returns previous character and retreats the string cursor.
 * @s: the string.
 *
 * An error is returned if: the cursor position < 0 or cursor position >= size
 * or size < 0.
 * Once the cursor reaches the start of the string,
 * CHAR_MIN will be returned on the next call to this function.
 *
 * Return: the previous character, -1 on error.
 */
char string_readp(string *s)
{
	if (s->i < 0 || s->size <= 0 || s->i > s->size)
		return (-1);

	if (s->i == 0)
		return (CHAR_MIN);

	return (s->s[--s->i]);
}

/**
 * string_peekc - returns character at the string cursor.
 * @s: the string.
 *
 * An error is returned if: the cursor position < 0 or cursor position > size
 * or size <= 0.
 *
 * Return: the current character, -1 on error.
 */
char string_peekc(string const *const s)
{
	if (s->i < 0 || s->size <= 0 || s->i > s->size)
		return (-1);

	return (s->s[s->i]);
}

/**
 * string_peekp - returns character before the string cursor.
 * @s: the string.
 *
 * An error is returned if: the cursor position < 0 or cursor position >= size
 * or size < 0.
 * If there are no characters before the cursor, CHAR_MIN will be returned.
 *
 * Return: the previous character, -1 on error.
 */
char string_peekp(string const *const s)
{
	if (s->i < 0 || s->size <= 0 || s->i > s->size)
		return (-1);

	if (s->i == 0)
		return (CHAR_MIN);

	return (s->s[s->i - 1]);
}

/**
 * string_peekn - returns character after the string cursor.
 * @s: the string.
 *
 * An error is returned if: the cursor position < 0 or cursor position >= size
 * or size < 0.
 * If there are no characters after the cursor, CHAR_MIN will be returned.
 *
 * Return: the next character, -1 on error.
 */
char string_peekn(string const *const s)
{
	if (s->i < 0 || s->size <= 0 || s->i > s->size)
		return (-1);

	if (s->i == s->size)
		return (CHAR_MIN);

	return (s->s[s->i + 1]);
}
