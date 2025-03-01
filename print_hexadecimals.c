#include "main.h"

/**
 * print_hexa_lower - converts integer into lowercase hexadecimal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_hexa_lower(va_list args, char_arr *buffer, modifiers mods)
{
	uintmax_t num = 0;

	switch (mods.length)
	{
		/* case PRINTF_CHAR: */
		/* num = va_arg(args, unsigned char); */
		/* break; */
		/* case PRINTF_SHORT: */
		/* num = va_arg(args, unsigned short int); */
		/* break; */
		/* case PRINTF_LONG: */
		/* num = va_arg(args, unsigned long int); */
		/* break; */
		/* case PRINTF_LLONG: */
		/* num = va_arg(args, unsigned long long int); */
		/* break; */
	case PRINTF_INTMAX_T:
		num = va_arg(args, uintmax_t);
		break;
	case PRINTF_SIZE_T:
		num = va_arg(args, size_t);
		break;
	case PRINTF_PTRDIFF_T:
		num = va_arg(args, ptrdiff_t);
		break;
	default:
		num = va_arg(args, unsigned int);
		break;
	}

	mods.int_mod.alphabet_case = LOWER;
	mods.int_mod.base = BASE16;
	mods.int_mod.is_negative = false;
	return (format_integers(num, buffer, mods));
}

/**
 * print_hexa_upper - converts integer into uppercase hexadecimal.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_hexa_upper(va_list args, char_arr *buffer, modifiers mods)
{
	uintmax_t num = 0;

	switch (mods.length)
	{
		/* case PRINTF_CHAR: */
		/* num = va_arg(args, unsigned char); */
		/* break; */
		/* case PRINTF_SHORT: */
		/* num = va_arg(args, unsigned short int); */
		/* break; */
		/* case PRINTF_LONG: */
		/* num = va_arg(args, unsigned long int); */
		/* break; */
		/* case PRINTF_LLONG: */
		/* num = va_arg(args, unsigned long long int); */
		/* break; */
	case PRINTF_INTMAX_T:
		num = va_arg(args, uintmax_t);
		break;
	case PRINTF_SIZE_T:
		num = va_arg(args, size_t);
		break;
	case PRINTF_PTRDIFF_T:
		num = va_arg(args, ptrdiff_t);
		break;
	default:
		num = va_arg(args, unsigned int);
		break;
	}

	mods.int_mod.alphabet_case = UPPER;
	mods.int_mod.base = BASE16;
	mods.int_mod.is_negative = false;
	return (format_integers(num, buffer, mods));
}
