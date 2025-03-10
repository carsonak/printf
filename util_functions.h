#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <inttypes.h> /* uintmax_t */

intmax_t _atoimax(char const *const s);
char *_memset(char *s, char b, unsigned int n);
int _strlen(char const *const s);
unsigned short int count_digits(uintmax_t n, unsigned short int base);

#endif /* UTIL_FUNCTIONS_H */
