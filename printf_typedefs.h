#ifndef PRINTF_TYPEDEFS_H
#define PRINTF_TYPEDEFS_H

#include <inttypes.h> /* intmax_t */
#include <stdarg.h>   /* va_list */
#include <stdbool.h>  /* bool */

#define ATTR_FORMAT_FUNCTION(archetype, str_position, first_to_check)

/* https://gcc.gnu.org/onlinedocs/cpp/_005f_005fhas_005fattribute.html */
#if defined __has_attribute

	/**
	 * https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html
	 * #index-format-function-attribute
	 */
	#if __has_attribute(format)

		#undef ATTR_FORMAT_FUNCTION
		#define ATTR_FORMAT_FUNCTION(archetype, str_position, first_to_check)  \
			__attribute__((format(archetype, str_position, first_to_check)))

	#endif /* __has_attribute(format) */

#endif /* __has_attribute */

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

/**
 * struct printf_flag_modifiers - printf flag modifiers.
 * @alternate_form: '#' flag.
 * @zero_padding: '0' flag.
 * @left_adjust: '-' flag.
 * @space: ' ' flag.
 * @sign: '+' flag.
 */
struct printf_flag_modifiers
{
	bool alternate_form, zero_padding, left_adjust, space, sign;
};

/**
 * enum printf_int_length_modifiers - printf length modifiers.
 * @PRINTF_CHAR: signed char or unsigned char.
 * @PRINTF_SHORT: short or unsigned short.
 * @PRINTF_LONG: long or unsigned long.
 * @PRINTF_LLONG: long or unsigned long.
 * @PRINTF_LDOUBLE: long double.
 * @PRINTF_INTMAX_T: intmax_t or uintmax_t.
 * @PRINTF_SIZE_T: size_t or ssize_t.
 * @PRINTF_PTRDIFF_T: ptrdiff_t.
 */
enum printf_int_length_modifiers
{
	PRINTF_CHAR = 1,
	PRINTF_SHORT,
	PRINTF_LONG,
	PRINTF_LLONG,
	PRINTF_LDOUBLE,
	PRINTF_INTMAX_T,
	PRINTF_SIZE_T,
	PRINTF_PTRDIFF_T
};

/**
 * enum integer_bases - valid radii for integers.
 * @BASE02: base 2.
 * @BASE08: base 8.
 * @BASE10: base 10.
 * @BASE16: base 16.
 */
enum integer_bases
{
	BASE02 = 2U,
	BASE08 = 8U,
	BASE10 = 10U,
	BASE16 = 16U
};

/**
 * enum integer_alphabet_cases - symbols for integers > base10.
 * @UPPER: uppercase A.
 * @LOWER: lowercase a.
 */
enum integer_alphabet_cases
{
	UPPER = 'A',
	LOWER = 'a'
};

/**
 * struct integer_modifiers - flags for integer types.
 * @base: the radix of the number.
 * @alphabet_case: case to use for numbers greater than base 10.
 * @is_negative: flag to indicate signedness.
 */
typedef struct integer_modifiers
{
	enum integer_bases base;
	enum integer_alphabet_cases alphabet_case;
	bool is_negative;
} integer_mods;

/**
 * struct printf_modifiers - modifiers for `_printf` conversion.
 * @flags: flags.
 * @width: width.
 * @precision: precision.
 * @length: length.
 * @int_mod: integer flags.
 */
typedef struct printf_modifiers
{
	struct printf_flag_modifiers flags;
	intmax_t width;
	intmax_t precision;
	enum printf_int_length_modifiers length;
	integer_mods int_mod;
} modifiers;

/**
 * struct format_funcs - formatting functions and their identifiers.
 * @func: The handling function.
 * @ch: The format identifier.
 */
typedef struct format_funcs
{
	int (*func)(va_list args, char_arr *buffer, modifiers mods);
	char ch;
} format_funcs;

#endif /* PRINTF_TYPEDEFS_H */
