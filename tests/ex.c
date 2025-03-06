#include "_printf.h"

#include <limits.h>
#include <inttypes.h>
#include <stddef.h>

int main(void)
{
	/* clang-format off */
	_printf("A simple sentence.\n");
	_printf("Percent: [%%]\n");
	_printf("Integers: [%d, %i]\n", INT_MAX, INT_MIN);
	_printf("Zero Padding: [%010d]\n", -762534);
	_printf("Unsigned long int: [%lu]\n", 1024U + (unsigned long)LONG_MAX);
	_printf("Precision and width: [%#16.10x == %#16.10X == %16.10u == %#16.10b]\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	_printf("Chars with alignment: [%3c%-3c]\n", '<', '3');
	_printf("Strings with precision: You %.2s %s, Jon Snow.\n", "nothing", "nothing");
	_printf("Null pointer with string: You know %s, Jon Snow.\n", (char *)0);
	_printf("Non-printables formatter: [%S]\n", "\3\t\n\v\f\r\26\30");
	_printf("Pointer: [%p]\n", (void *)0x7ffe637541f0);
	_printf("Various length modifiers: [%ju - (% ti + %+hd) = %+zi]\n", UINTMAX_MAX, INTMAX_MAX, SHRT_MAX, UINTMAX_MAX - ((size_t)INTMAX_MAX + SHRT_MAX));
	_printf("Unknown: [%v]\n");
	_printf("\nIf you follow the river's flow\n");
	_printf("You will find where deer hide in the %rs\n", "deer");
	_printf("and people are part of a %r's %r\n", "flow", "part");
	return (0);
}
