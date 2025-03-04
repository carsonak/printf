#include "main.h"

/**
 * count_digits - calculate how many digits can represent a number in the
 * given base.
 * @n: the integer.
 * @base: the radix of the number.
 *
 * Return: number of digits in the integer.
 */
unsigned short int count_digits(uintmax_t n, const unsigned short int base)
{
	unsigned short int digits = 0;

	if (base < 2)
		return (0);

	/* clang-format off */
	do {
		/* clang-format on */
		n /= base;
		++digits;
	} while (n);

	return (digits);
}

/**
 * insert_symbols - insert sign and alt characters if needed.
 * @str: pointer to memory block to store the characters.
 * @num: the number to be formatted.
 * @mods: modifier flags.
 */
static void insert_symbols(char *str, uintmax_t num, const modifiers mods)
{
	if (mods.flags.sign || mods.flags.space || mods.int_mod.is_negative)
	{
		if (mods.int_mod.is_negative)
			*(str++) = '-';
		else if (mods.flags.sign)
			*(str++) = '+';
	}

	if (num && mods.flags.alternate_form && mods.int_mod.base != BASE10)
	{
		*(str++) = '0';
		if (mods.int_mod.base == BASE02)
			*(str++) = 'b';

		if (mods.int_mod.base == BASE16)
			*(str++) = islower(mods.int_mod.alphabet_case) ? 'x' : 'X';
	}
}

/**
 * itostr - converts a number to a string representation.
 * @str: pointer to memory block to store the string.
 * @num: the natural number to convert.
 * @mods: modifier flags.
 */
static void itostr(char *const str, uintmax_t num, const integer_mods mods)
{
	int d = count_digits(num, mods.base) - 1;

	for (; d > -1; --d)
	{
		if (num % mods.base < 10)
			str[d] = num % mods.base + '0';
		else
			str[d] = ((num % mods.base) - 10) + mods.alphabet_case;

		num /= mods.base;
	}
}

/**
 * init_lengths - initialises various variables.
 * @num: the number to be formatted.
 * @mods: modifier flags.
 * @len: total length of the result string.
 * @digits: number of non-zero digits in the number.
 * @symbols: length of sign + alternate form symbols.
 * @zeros: number of 0's to be used as padding.
 * @padding: number of blanks/zeros used for padding.
 */
static void init_lengths(
	uintmax_t num, const modifiers mods, int *len, int *digits, int *symbols,
	int *zeros, int *padding)
{
	if (mods.flags.sign || mods.flags.space || mods.int_mod.is_negative)
		++(*symbols);

	if (num && mods.flags.alternate_form && mods.int_mod.base != BASE10)
	{
		++(*symbols);
		if (mods.int_mod.base != BASE08)
			++(*symbols);
	}

	if (num || mods.precision)
		*digits = count_digits(num, mods.int_mod.base);

	if (mods.precision > *digits)
		*zeros = mods.precision - *digits;

	*len = *symbols + *digits + *zeros;
	if (mods.width > *len)
		*padding = mods.width - *len;
}

/**
 * format_integers - handles formatting of hexadecimal integers.
 * @num: the number to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int format_integers(uintmax_t num, char_arr *buffer, const modifiers mods)
{
	char *wip_str = NULL;
	int bytes_written = 0;
	int len = 0, digits = 0, symbols = 0, zeros = 0, padding = 0;

	init_lengths(num, mods, &len, &digits, &symbols, &zeros, &padding);
	wip_str = malloc(padding + symbols + digits + zeros + 1);
	if (!wip_str)
	{
		buffer_flush(buffer);
		return (-1);
	}

	_memset(wip_str, ' ', (padding + symbols + digits + zeros));
	wip_str[(padding + symbols + digits + zeros)] = '\0';
	if (!mods.flags.left_adjust && !mods.flags.zero_padding)
		wip_str += padding;

	if (!mods.flags.left_adjust && mods.flags.zero_padding)
		zeros += padding;

	insert_symbols(wip_str, num, mods);
	_memset(wip_str + symbols, '0', zeros);
	if (digits)
		itostr(wip_str + symbols + zeros, num, mods.int_mod);

	if (!mods.flags.left_adjust && !mods.flags.zero_padding)
		wip_str -= padding;

	bytes_written = buffer_puts(buffer, wip_str);
	free(wip_str);
	return (bytes_written);
}
