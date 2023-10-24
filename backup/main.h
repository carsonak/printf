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
	int (*f)(va_list args, char *const buf, int *const buf_i);
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
	int (*f)(int num_len, char *const buf, int *const buf_i, ...);
} f_w_p;

int _printf(const char *format, ...);
int _flushbuff(char *const buf, int *const buf_i);
int format_handler(va_list args, const char *const format,
				   int fmt_i, char *const buf, int *const buf_i);
int fwp(char mod, int num_len, f_w_p *edits, char *const buf,
		int *const buf_i);
int print_c(va_list args, char *const buf, int *const buf_i);
int print_s(va_list args, char *const buf, int *const buf_i);
int print_pc(va_list args, char *const buf, int *const buf_i);
int print_Rnum(va_list args, char *const buf, int *const buf_i);
int print_b(va_list args, char *const buf, int *const buf_i);
int print_lower_hexa(va_list args, char *const buff, int *const buff_index);
int print_upper_hexa(va_list args, char *const buff, int *const buff_index);
int print_oct(va_list args, char *const buff, int *const buff_index);
int print_dec(va_list args, char *const buffer, int *const buff_index);
int print_p(va_list args, char *const buff, int *const buff_index);
int print_prefix(int len, char *const buf, int *const buf_i, ...);
int print_plus(int len, char *const buf, int *const buf_i, ...);

#endif
