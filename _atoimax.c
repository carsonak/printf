#include <ctype.h>  /* isdigit */
#include <limits.h> /* INTMAX_MAX */
#include <stddef.h> /* size_t */

#include "util_functions.h"

/**
 * _atoimax - converts the initial digits in a string into an integer.
 * @s: the string with a number.
 *
 * Return: the integer in the string `s`.
 */
intmax_t _atoimax(char const *const s)
{
	uintmax_t output = 0, max_val = INTMAX_MAX;
	size_t i = 0;
	unsigned char is_negative = 0;

	while (*(s + i) && (*(s + i) == '-' || *(s + i) == '+'))
	{
		if (*(s + i) == '-')
			is_negative = !is_negative;

		i++;
	}

	if (is_negative)
		++max_val;

	while (*(s + i) && isdigit(*(s + i)) && output < max_val)
	{
		uintmax_t tmp = (output * 10) + (*(s + i) - '0');

		if (tmp > max_val)
			break;

		output = tmp;
		i++;
	}

	if (is_negative)
		return (-output);

	return (output);
}
