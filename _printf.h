#ifndef PRINTF_MAIN_H
#define PRINTF_MAIN_H

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

ATTR_FORMAT_FUNCTION(printf, 1, 2) int _printf(const char *format, ...);

#endif /* PRINTF_MAIN_H */
