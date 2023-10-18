#ifndef _MAIN_H_
#define _MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFSZ (1024)

int _printf(const char *format, ...);
unsigned int _flushbuff(char *buf, unsigned int *index);
int format_handler(va_list set, char format, char *buf, unsigned int *buf_i);
void print_c(va_list set, char *buf, unsigned int *buf_i);
void print_s(va_list set, char *buf, unsigned int *buf_i);
void print_pc(va_list set, char *buf, unsigned int *buf_i);
void print_num(va_list set, char *buf, unsigned int *buf_i);

/**
 * struct prt - struct prt for storing a format specifier and it's function
 *
 * @ch: The format identifier
 * @f: The printing function associated
 */
typedef struct prt
{
	char ch;
	int (*f)(va_list set, char *buf, unsigned int *buf_i);
} f_prt;

#endif

