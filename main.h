#ifndef _MAIN_H_
#define _MAIN_H_

#include <inttypes.h> /* imaxabs, fixed width types */
#include <stdarg.h>   /* va_list */
#include <unistd.h>   /* write */

#include "printf_typedefs.h"

ATTR_FORMAT_FUNCTION(printf, 1, 2) int _printf(const char *format, ...);

int buffer_flush(char_arr *buffer);
int buffer_putchar(char_arr *buffer, char c);
int format_handler(va_list args, string *format, char_arr *buffer);
int print_hexadecimals(
	uintmax_t num, char_arr *buffer, modifiers mods, bool is_negative,
	bool is_upper);
int print_integers(
	uintmax_t num, char_arr *buffer, modifiers mods, bool is_negative);

int print_binary(va_list args, char_arr *buffer, modifiers mods);
int print_character(va_list args, char_arr *buffer, modifiers mods);
int print_hexa_lower(va_list args, char_arr *buffer, modifiers mods);
int print_hexa_upper(va_list args, char_arr *buffer, modifiers mods);
int print_int_di(va_list args, char_arr *buffer, modifiers mods);
int print_int_u(va_list args, char_arr *buffer, modifiers mods);
int print_oct(va_list args, char_arr *buffer, modifiers mods);
int print_percent(va_list args, char_arr *buffer, modifiers mods);
int print_plus(int len, char_arr *buffer, ...);
int print_prefix(int len, char_arr *buffer, ...);
int print_ptr(va_list args, char_arr *buffer, modifiers mods);
int print_str(va_list args, char_arr *buffer, modifiers mods);
int print_unknown(string format, char_arr *buffer);

#endif
