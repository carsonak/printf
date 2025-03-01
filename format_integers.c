#include "main.h"

/**
 * count_digits - calculate how many digits can represent a number in the
 * given base.
 * @n: the integer.
 * @base: the radix of the number.
 *
 * Return: number of digits in the integer.
 */
unsigned short int count_digits(uintmax_t n, unsigned short int base)
{
	unsigned short int digits = 0;

	/* clang-format off */
	do {
		/* clang-format on */
		n /= base;
		++digits;
	} while (n);

	return (digits);
}

/**
 * int_to_str - converts a number to a string representation.
 * @str: pointer to memory block to store the string.
 * @num: the natural number to convert.
 * @mods: modifier flags.
 *
 * Return: pointer to the string.
 */
static char *int_to_str(char *const str, uintmax_t num, integer_mods mods)
{
	int digits = count_digits(num, mods.base) - 1;

	for (; digits > -1; --digits)
	{
		if (num % mods.base < 10)
			str[digits] = num % mods.base + '0';
		else
			str[digits] = ((num % mods.base) - 10) + mods.alphabet_case;

		num /= mods.base;
	}

	return (str);
}

/**
 * calculate_str_size - calculate size of string required to store the formated
 * number.
 * @num: the number.
 * @mods: modifier flags.
 *
 * Return: the calculated size.
 */
static intmax_t calculate_str_size(const uintmax_t num, const modifiers mods)
{
	intmax_t character_count = count_digits(num, mods.int_mod.base);

	if (mods.flags.sign || mods.int_mod.is_negative)
		++character_count;

	if (mods.flags.alternate_form && mods.int_mod.base != BASE10)
	{
		++character_count;
		if (mods.int_mod.base == BASE16)
			++character_count;
	}

	if (mods.width > mods.precision)
		character_count += mods.width;
	else
		character_count += mods.precision;

	return (character_count);
}

/**
 * insert_special_characters - insert sign and alt characters if needed.
 * @str: the string to format.
 * @mods: modifier flags.
 *
 * Return: number of characters inserted.
 */
static unsigned int insert_special_characters(char *str, modifiers mods)
{
	unsigned int i = 0;

	if (mods.flags.sign || mods.flags.space || mods.int_mod.is_negative)
	{
		if (mods.int_mod.is_negative)
			str[i++] = '-';
		else if (mods.flags.sign)
			str[i++] = '+';
	}

	if ((mods.int_mod.base == BASE08 || mods.int_mod.base == BASE16) &&
	    mods.flags.alternate_form)
	{
		str[i++] = '0';
		if (mods.int_mod.base == BASE16)
			str[i++] = _islower(mods.int_mod.alphabet_case) ? 'x' : 'X';
	}

	return (i);
}

/**
 * format_integers - handles formatting of hexadecimal integers.
 * @num: the number to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int format_integers(uintmax_t num, char_arr *buffer, modifiers mods)
{
	char *wip_str = NULL;
	int bytes_written = 0;
	long int character_count = calculate_str_size(num, mods);
	long int digits = count_digits(num, mods.int_mod.base);
	long int start_idx = character_count - digits;
	long int zeros = mods.precision - digits < 0 ? 0 : mods.precision - digits;

	wip_str = malloc(character_count + 1);
	if (!wip_str)
		return (-1);

	_memset(wip_str, ' ', character_count);
	wip_str[character_count] = '\0';
	if (!mods.flags.left_adjust)
	{
		int_to_str(wip_str + start_idx, num, mods.int_mod);
		start_idx -= zeros;
		if (mods.flags.alternate_form && mods.int_mod.base != BASE10)
		{
			--start_idx;
			if (mods.int_mod.base == BASE16)
				--start_idx;
		}

		if (mods.flags.sign || mods.flags.space || mods.int_mod.is_negative)
			--start_idx;
	}
	else
	{
		start_idx -=
			mods.width - mods.precision < 0 ? 0 : mods.width - mods.precision;
		int_to_str(wip_str + start_idx, num, mods.int_mod);
		start_idx = 0;
	}

	start_idx += insert_special_characters(&wip_str[start_idx], mods);
	_memset(wip_str + start_idx, '0', zeros);
	bytes_written = buffer_puts(buffer, wip_str);
	free(wip_str);
	return (bytes_written);
}
