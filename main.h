#ifndef _MAIN_H_
#define _MAIN_H_

#include <assert.h> /* assert */
#include <ctype.h>  /* isdigit, islower*/
#include <inttypes.h> /* imaxabs, fixed width types */
#include <stdarg.h>   /* va_list */
#include <stddef.h>   /* ptrdiff_t, size_t */
#include <stdlib.h>   /* malloc */
#include <unistd.h>   /* write */

#include "buffer_object.h"
#include "printf_typedefs.h"
#include "string_object.h"
#include "util_functions.h"

#define PRINTF_BUFFER_LENGTH (1024U)

ATTR_FORMAT_FUNCTION(printf, 1, 2) int _printf(const char *format, ...);

int format_handler(va_list args, string *format, char_arr *buffer);
int format_integers(uintmax_t num, char_arr *buffer, modifiers mods);
int format_strings(const char *str, char_arr *buffer, modifiers mods);

int print_binary(va_list args, char_arr *buffer, modifiers mods);
int print_character(va_list args, char_arr *buffer, modifiers mods);
int print_hexa_lower(va_list args, char_arr *buffer, modifiers mods);
int print_hexa_upper(va_list args, char_arr *buffer, modifiers mods);
int print_int_di(va_list args, char_arr *buffer, modifiers mods);
int print_int_u(va_list args, char_arr *buffer, modifiers mods);
int print_oct(va_list args, char_arr *buffer, modifiers mods);
int print_percent(va_list args, char_arr *buffer, modifiers mods);
int print_ptr(va_list args, char_arr *buffer, modifiers mods);
int print_str(va_list args, char_arr *buffer, modifiers mods);
int print_STR(va_list args, char_arr *buffer, modifiers mods);
int print_unknown(string *format, char_arr *buffer);

#endif
