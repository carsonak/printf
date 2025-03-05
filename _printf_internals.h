#ifndef PRINTF_INTERNALS_H
#define PRINTF_INTERNALS_H

#include <assert.h>   /* assert */
#include <ctype.h>    /* isdigit, islower*/
#include <inttypes.h> /* imaxabs, fixed width types */
#include <stdarg.h>   /* va_list */
#include <stdbool.h>  /* bool */
#include <stddef.h>   /* ptrdiff_t, size_t */
#include <stdlib.h>   /* malloc */
#include <unistd.h>   /* write */

#include "_printf_typedefs.h"
#include "buffer_object.h"
#include "string_object.h"
#include "util_functions.h"

#define PRINTF_BUFFER_LENGTH (1024U)

int format_handler(va_list args, string *format, char_arr *buffer);
int format_integers(uintmax_t num, char_arr *buffer, modifiers mods);
void init_working_string(
	char_arr *const wip_str, const modifiers mods, const intmax_t str_len);

int print_binary(va_list args, char_arr *buffer, modifiers mods);
int print_character(va_list args, char_arr *buffer, modifiers mods);
int print_hexa_lower(va_list args, char_arr *buffer, modifiers mods);
int print_hexa_upper(va_list args, char_arr *buffer, modifiers mods);
int print_int_di(va_list args, char_arr *buffer, modifiers mods);
int print_int_u(va_list args, char_arr *buffer, modifiers mods);
int print_oct(va_list args, char_arr *buffer, modifiers mods);
int print_percent(va_list args, char_arr *buffer, modifiers mods);
int print_ptr(va_list args, char_arr *buffer, modifiers mods);
int print_reversed(va_list args, char_arr *buffer, modifiers mods);
int print_rot13(va_list args, char_arr *buffer, modifiers mods);
int print_str(va_list args, char_arr *buffer, modifiers mods);
int print_STR(va_list args, char_arr *buffer, modifiers mods);
int print_unknown(string *format, char_arr *buffer);

#endif /* PRINTF_INTERNALS_H */
