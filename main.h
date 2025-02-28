#ifndef _MAIN_H_
#define _MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

#include "printf_typedefs.h"

ATTR_FORMAT_FUNCTION(printf, 1, 2) int _printf(const char *format, ...);
int flush_buffer(char_arr buffer);

int print_character(va_list args, char_arr buffer, modifiers mods);
int print_str(va_list args, char_arr buffer, modifiers mods);
int print_percent(va_list args, char_arr buffer, modifiers mods);
int print_binary(va_list args, char_arr buffer, modifiers mods);
int print_lower_hexa(va_list args, char_arr buffer, modifiers mods);
int print_upper_hexa(va_list args, char_arr buffer, modifiers mods);
int print_oct(va_list args, char_arr buffer, modifiers mods);
int print_decimal(va_list args, char_arr buffer, modifiers mods);
int print_ptr(va_list args, char_arr buffer, modifiers mods);
int print_prefix(int len, char_arr buffer, ...);
int print_plus(int len, char_arr buffer, ...);

#endif
