#include "_printf_internals.h"
/**
 * _imaxabs - returns the absolute value of an intmax_t integer.
 * @n: the integer.
 *
 * Return: the absolute value of `n`.
 */
static uintmax_t _imaxabs(intmax_t n)
{
	if (n < 0)
	{
		if (n == INTMAX_MIN)
			return ((uintmax_t)(INTMAX_MAX) + 1);

		return (-n);
	}

	return (n);
}

/**
 * print_int_di - handle formating of `int`s.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_int_di(va_list args, char_arr *buffer, modifiers mods)
{
	intmax_t num = 0;

	switch (mods.length)
	{
	case PRINTF_CHAR:
		num = (char)va_arg(args, int);
		break;
	case PRINTF_SHORT:
		num = (short int)va_arg(args, int);
		break;
	case PRINTF_LONG:
		num = va_arg(args, long int);
		break;
		/* case PRINTF_LLONG: */
		/* num = va_arg(args, long long int); */
		/* break; */
	case PRINTF_INTMAX_T:
		num = va_arg(args, intmax_t);
		break;
	case PRINTF_SIZE_T:
		num = va_arg(args, ssize_t);
		break;
	case PRINTF_PTRDIFF_T:
		num = va_arg(args, ptrdiff_t);
		break;
	default:
		num = va_arg(args, int);
		break;
	}

	if (num < 0)
		mods.int_mod.is_negative = true;

	mods.int_mod.base = BASE10;
	return (format_integers(_imaxabs(num), buffer, mods));
}

/**
 * print_int_u - handle formating of `unsigned int`s.
 * @args: the arguments to be formatted.
 * @buffer: working buffer for `_printf`.
 * @mods: modifier flags.
 *
 * Return: Returns a positive int on success, negative int on failure.
 */
int print_int_u(va_list args, char_arr *buffer, modifiers mods)
{
	uintmax_t num = 0;

	switch (mods.length)
	{
	case PRINTF_CHAR:
		num = (unsigned char)va_arg(args, unsigned int);
		break;
	case PRINTF_SHORT:
		num = (unsigned short int)va_arg(args, unsigned int);
		break;
	case PRINTF_LONG:
		num = va_arg(args, unsigned long int);
		break;
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

	mods.int_mod.base = BASE10;
	return (format_integers(num, buffer, mods));
}
