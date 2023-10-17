#ifndef _MAIN_H_
#define _MAIN_H_

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFSIZE 1024

int _printf(const char *format, ...);
int format_handler(va_list set, char format, char *buf);
int _write(char *buf, unsigned int a);
int print_c(va_list set, char *buf);
int print_s(va_list set, char *buf);
int print_pc(va_list set, char *buf);
int print_i(va_list set, char *buf);

/**
 * struct prt - struct prt for storing a format specifier and it's function
 *
 * @ch: The format identifier
 * @f: The printing function associated
 */
typedef struct prt
{
	char ch;
	int (*f)(va_list set, char *buf);
} f_prt;

#endif

