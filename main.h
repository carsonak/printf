#ifndef _MAIN_H_
#define _MAIN_H_

#include <inttypes.h> /* imaxabs, fixed width types */
#include <stdarg.h>   /* va_list */
#include <unistd.h>   /* write */

#include "printf_typedefs.h"

ATTR_FORMAT_FUNCTION(printf, 1, 2) int _printf(const char *format, ...);

int flush_buffer(char_arr *buffer);
int format_handler(va_list args, string *format, char_arr *buffer);

int print_binary(va_list args, char_arr *buffer, modifiers mods);
int print_character(va_list args, char_arr *buffer, modifiers mods);
int print_hexa_lower(va_list args, char_arr *buffer, modifiers mods);
int print_hexa_upper(va_list args, char_arr *buffer, modifiers mods);
int print_int_di(va_list args, char_arr *buffer, modifiers mods);
int print_oct(va_list args, char_arr *buffer, modifiers mods);
int print_percent(va_list args, char_arr *buffer, modifiers mods);
int print_plus(int len, char_arr *buffer, ...);
int print_prefix(int len, char_arr *buffer, ...);
int print_ptr(va_list args, char_arr *buffer, modifiers mods);
int print_str(va_list args, char_arr *buffer, modifiers mods);
int print_unknown(string format, char_arr *buffer);

#endif
