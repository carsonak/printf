#ifndef _MAIN_H_
#define _MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_c(va_list st);
int print_s(va_list st);
int print_pc(va_list st);
int print_i(va_list st);
int print_d(va_list st);

/**
 * struct prt - struct prt for storing a format specifier and it's function
 *
 * @ch: The format identifier
 * @f: The printing function associated
 */
typedef struct prt
{
	char ch;
	int (*f)(va_list set);
} f_prt;

#endif
