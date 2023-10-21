#ifndef _MAIN_H_
#define _MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

#define PRINTF_BUFFER (1024)

/**
 * struct conversion_specifiers - a struct for storing a format specifier and
 * it's function
 *
 * @ch: The format identifier
 * @f: The function associated
 */
typedef struct conversion_specifiers
{
	char ch;
	long int (*f)(va_list args, char *buf, long int *buf_i);
} c_sp;

/**
 * struct flags_width_precision_length - struct prt for tracking and calling
 * functions of flag, field-width, precision and length modifiers
 *
 * @gate: bool value used as a control switch
 * @ch: The format identifier
 * @f: The function associated
 */
typedef struct flags_width_precision_length
{
	bool gate;
	char ch;
	long int (*f)(va_list args, char *buf, long int *buf_i);
} f_w_p_l;

int _printf(const char *format, ...);
long int _flushbuff(char *buf, long int *index);
long int format_handler(va_list args, char *format,
						long int fmt_i, char *buf, long int *buf_i);
long int print_c(va_list args, char *buf, long int *buf_i);
long int print_s(va_list args, char *buf, long int *buf_i);
long int print_pc(va_list args, char *buf, long int *buf_i);
long int print_num(va_list args, char *buf, long int *buf_i);
long int print_b(va_list args, char *buf, long int *buf_i);

#endif

