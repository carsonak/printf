#ifndef PRINTF_TYPEDEFS
#define PRINTF_TYPEDEFS

#include <stdarg.h>  /* va_list */
#include <stdbool.h> /* bool */

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
 * struct string - a simple immutable string data type.
 * @size: size of the string in bytes.
 * @i: cursor of the string.
 * @s: pointer to the first character in the string.
 */
typedef struct string
{
	long int size;
	long int i;
	char const *s;
} string;

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
 * enum printf_type_modifiers - printf length modifiers.
 * @hh: signed char or unsigned char.
 * @h: short or unsigned short.
 * @l: long or unsigned long.
 * @ll: long or unsigned long.
 * @L: long double.
 * @j: intmax_t or uintmax_t.
 * @z: size_t or ssize_t.
 * @t: ptrdiff_t.
 */
enum printf_type_modifiers
{
	hh,
	h,
	l,
	ll,
	L,
	j,
	z,
	t
};

/**
 * struct printf_modifiers - modifiers for the conversion.
 * @flags: flags.
 * @width: width.
 * @precision: precision.
 * @type: length.
 */
typedef struct printf_modifiers
{
	struct printf_flag_modifiers flags;
	long int width;
	long int precision;
	enum printf_type_modifiers type;
} modifiers;

/**
 * struct format_funcs - formatting functions and their identifiers.
 * @func: The handling function.
 * @ch: The format identifier.
 */
typedef struct format_funcs
{
	int (*func)(va_list args, char_arr buffer, modifiers mods);
	char ch;
} format_funcs;

#endif /* PRINTF_TYPEDEFS */
