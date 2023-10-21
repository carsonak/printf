#ifndef _MAIN_H_
#define _MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define PRINTF_BUFFER (1024)

long int print_hexa(va_list args, char *buff, long int *buff_index);
long int print_oct(va_list args, char *buff, long int *buff_index);
long int print_dec(va_list args, char *buffer, long int *buff_index);
int _printf(const char *format, ...);
long int _flushbuff(char *buf, long int *index);
long int
format_handler(va_list args, char format, char *buf, long int *buf_i);
long int print_c(va_list args, char *buf, long int *buf_i);
long int print_s(va_list args, char *buf, long int *buf_i);
long int print_pc(va_list args, char *buf, long int *buf_i);
long int print_num(va_list args, char *buf, long int *buf_i);

/**
 * struct prt - struct prt for storing a format specifier and it's function
 *
 * @ch: The format identifier
 * @f: The printing function associated
 */
typedef struct prt
{
	char ch;
	long int (*f)(va_list args, char *buf, long int *buf_i);
} f_prt;

#endif

