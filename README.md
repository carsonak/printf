# 0x11. C - printf

The goal of this project is to build a custom printf function that mimics
most of the behaviour of the C standard library printf function. Calls to
the standard library printf like functions are not allowed in the main
project.

The C code in this project follows the [Betty style guide](https://github.com/alx-tools/Betty/wiki).

## Structure

The printf function `_printf` is located in [_printf.c](./_printf.c).

All sub-functions used by `_printf` are contained in files in the top level
of the repository. The prototypes and other defines used in the project
are aggregated into [main.h](./main.h).

Tests are contained in the [tests](./tests) directory and can be run with the
make program, just run the following command in the top level of the repository.

```bash
make all-tests
```

## Format Specification

The format string has an identical syntax to the standard library printf.

> **%\[flags...\]\[width\]\[.precision\]\[length modifier\]conversion**

The format string begins with a "**%**" and ends with a conversion specifier.
In between there may be (in this order) zero or more **flags**, an optional
**minimum field width**, an optional **precision** and an optional **length modifier**.

Each **conversion** specifier or **\*** character consumes one argument from
the variable list of arguments. The arguments must correspond properly
(after type promotion) with the conversion specifier.

### Flag characters

The character % is followed by zero or more of the following flags:

| FLAG | DESCRIPTION |
| :---: | :--- |
| # | The value should be converted to an "alternate form". For **o** conversions, the first character of the output string is made zero (by prefixing a `0` if it was not zero already). For **x** and **X** conversions, a nonzero result has the string `0x` (or `0X` for **X** conversions) prepended to it. For **b** conversions, a nonzero result has the string `0b` prepended to it. |
| `0` | For **b**, **d**, **i**, **o**, **u**, **x** and **X** conversions, the converted value is padded on the left with zeros rather than blanks.  If the **`0`** and **-** flags both appear, the **`0`** flag is ignored. If a precision is given with an integer conversion (**b**, **d**, **i**, **o**, **u**, **x**, and **X**), the **`0`** flag is ignored. |
| - | The converted value is to be left adjusted on the field boundary (the default is right justification). The converted value is padded on the right with blanks, rather than on the left with blanks or zeros. A **-** overrides a **`0`** if both are given. |
| ' ' | A blank (a space) should be left before a positive number (or empty string) produced by a signed conversion. |
| + | A  sign  (+  or -) should always be placed before a number produced by a signed conversion. By default, a sign is used only for negative numbers. A **+** overrides a space if both are used. |

### Field width

This is an optional decimal digit string specifying a minimum field width.
The decimal digit string *should not* begin with a `0` as it will be interpreted
as the **`0`** flag. One may instead write **\*** to specify that the field width
is given in the next argument which must be of type *int*. A negative field
width is taken as a **-** flag followed by a positive field width.

If the converted value has fewer characters than the field width, it will be
padded with spaces on the left (or right, if the left-adjustment flag has been
given). Characters resulting from the **Flag** modifiers such as `0x` and the
single character to indicate signedness all consume the field width.
In no case does a nonexistent or small field width cause truncation of a field;
if the result of a conversion is wider than the field width, the field
is expanded to contain the conversion result.

### Precision

This is an optional precision, in the form of a period ('.') followed by an
optional decimal digit string. If the decimal digit string is omitted, the
precision is taken to be zero. Just like with the field width, one may instead
write **\*** to specify that the precision is given in the next argument which
must be of type *int*. A negative precision is taken as if the precision were
omitted.
The precision gives the minimum number of digits to appear for **b**, **d**,
**i**, **o**, **u**, **x**, and **X** conversions and the maximum number of
characters to be printed from a string for **s**, **S**, **r** and **R**
conversions.

### Length modifier

The length modifier specifies what type the following interger conversion the
next argument corresponds to.
Here, "integer conversion" stands for **b**, **d**, **i**, **o**, **u**, **x**,
or **X** conversion.

| Modifier | Description |
| :---: | :--- |
| hh | *signed char* or *unsigned char* |
| h | *short* or *unsigned short* |
| l | *long* or *unsigned long* |
| j | *intmax_t* or *uintmax_t* |
| z | *size_t* or *ssize_t* |
| t | *ptrdiff_t* |

### Conversion specifier

This is a character that specifies the type of conversion to be applied.

| Conversio | Description |
| :---: | :--- |
| d, i | The *int* argument is converted to signed decimal notation. The **precision**, if any, gives the minimum number of digits that must appear; if the converted value  requires fewer digits, it is padded on the left with zeros.  The default **precision** is 1.  When 0 is printed with an explicit **precision** 0, the output is empty. |
| b, o, u, x, X | The *unsigned int* argument is converted to unsigned binary (**b**), unsigned octal (**o**), unsigned decimal (**u**), or unsigned hexadecimal (**x** and **X**) notation. The letters **abcdef** are  used for **x** conversions; the letters **ABCDEF** are used for **X** conversions. The **precision**, if any, gives the minimum number of digits that must appear; if the converted value requires fewer digits, it is padded on the left with zeros. The default **precision** is 1. When 0 is printed with an explicit **precision** 0, the output is empty. |
| c | The *int* argument is converted to an *unsigned char*, and the resulting character is written. |
| s | the *const char \** argument is expected to be a pointer to an array of character type (i.e., pointer to a string).  Characters from the array are written up to (but not including) a terminating null byte ('`\0`'); if a **precision** is specified, no more characters than the number specified  are written. If a **precision** is given, no null byte need be present; if the **precision** is not specified, or is greater than the size of the array, the array must contain a terminating null byte. |
| r | The string type argument treated similarly to the **s** conversion specifier, is written in a reversed order. That is, the last character in the string is printed first and the characters preceding it follow till the first character is written first. The string must always be null terminated. If a **precision** is specified, no more characters than the number specified are written. |
| R | The string type argument treated similarly to the **s** conversion specifier, has its characters transformed by the [ROT13](https://en.wikipedia.org/wiki/ROT13) cipher. If a **precision** is specified, no more characters than the number specified are written. |
| S | The string type argument treated similarly to the **s** conversion specifier, has its non-printable characters written in the format `\xNN`, where **NN** is the ascii value of the character in uppercase hexadecimal. |
| p | The *void \** pointer argument is printed in hexadecimal (as if by **%#x** or **%#lx**). |
| % | A '%' is written.  No argument is converted.  The complete conversion specification is '%%'. |

## Return value

Upon successful return, the `_printf` function returns the number of bytes printed (excluding the null byte used to end output to strings).

If an output, memory, syntax or any other error is encountered, a negative value is returned.

## Examples

```C
#include <limits.h>
#include <stddef.h>

#include "main.h"

int main(void)
{
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
```

#### Ouput

```txt
A simple sentence.
Percent: [%]
Integers: [2147483647, -2147483648]
Zero Padding: [-000762534]
Unsigned long int: [9223372036854776831]
Precision and width: [    0x00ffffffff ==     0X00FFFFFFFF ==       4294967295 == 0b11111111111111111111111111111111]
Chars with alignment: [  <3  ]
Strings with precision: You no nothing, Jon Snow.
Null pointer with string: You know (null), Jon Snow.
Non-printables formatter: [\x03\x09\x0A\x0B\x0C\x0D\x16\x1C]
Pointer: [0x7ffe637541f0]
Various length modifiers: [18446744073709551615 - ( 9223372036854775807 + +32767) = +9223372036854743041]
Unknown: [%v]

If you follow the river's flow
You will find where deer hide in the reeds
and people are part of a wolf's trap
```
