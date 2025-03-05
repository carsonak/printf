#include "util_functions.h"

/**
 * _strlen - calculates length of a string.
 * @s: the string.
 *
 * Return: length of the string.
 */
int _strlen(char const *const s)
{
	int i;

	for (i = 0; s && s[i] != '\0'; i++)
		;

	return (i);
}
