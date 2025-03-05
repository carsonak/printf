#ifndef PRINTF_TESTS_H
#define PRINTF_TESTS_H

#include <inttypes.h> /* intmax_t */
#include <limits.h>   /* max of types */
#include <stdbool.h>  /* bool */
#include <string.h>   /* strncmp */
#include <unistd.h>   /* ssize_t */

#include "main.h"
#include "tests_macros.h"

#define PRINTF_TESTS_BUFFER_SIZE (1024U * 2)

extern char _printf_test_output[PRINTF_TESTS_BUFFER_SIZE];
extern char _printf_ctrl_output[PRINTF_TESTS_BUFFER_SIZE];

ssize_t _write(int fd, const void *buf, size_t bytes);
bool test(void);

#endif /* PRINTF_TESTS_H */
