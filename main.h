#ifndef _MAIN_H_
#define _MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

#define PRINTF_BUFFER_LENGTH (1024U)

/**
 * struct conversion_specifiers - a struct for storing a format specifier and
 * it's function
 *
 * @ch: The format identifier
 * @func: The function associated
 */
typedef struct conversion_specifiers
{
	char ch;
	int (*func)(va_list args, char *const buffer, int *const buf_i);
} conversion_specifiers;

/**
 * struct flags_width_precision_length - struct prt for tracking and calling
 * functions of flag, field-width, precision and length modifiers
 *
 * @gate: bool value used as a control switch
 * @ch: The format identifier
 * @func: The function associated
 */
typedef struct flags_width_precision_length
{
	bool gate;
	char ch;
	int (*func)(int num_len, char *const buf, int *const buf_i, ...);
} f_w_p;

/**
 * struct printf_buffer - working buffer for printf and its functions.
 * @buf: memory block to be used as buffer.
 * @cursor: current index of the byte to be updated by operations.
 */
typedef struct printf_buffer
{
	char buf[PRINTF_BUFFER_LENGTH];
	int cursor;
} printf_buffer;

int _printf(const char *format, ...);

int flush_buffer(char *const buf, int *const buf_i);
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
