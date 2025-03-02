#include "main.h"

#define PRINTF_BUFFER_LENGTH (1024U)

/**
 * _printf - prints a formated string to stdout.
 * @format: - pointer to a string with optional format specifiers.
 *
 * Return: number of characters printed, or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int bytes_printed = 0, ret_val = 0;
	string fmt;
	char arr[PRINTF_BUFFER_LENGTH], c = 0;
	char_arr buffer;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	fmt.size = _strlen(format), fmt.i = 0, fmt.s = format;
	buffer.size = sizeof(arr), buffer.i = 0, buffer.buf = arr;
	for (c = string_readc(&fmt); c > 0; c = string_readc(&fmt))
	{
		if (c != '%')
		{
			ret_val = buffer_putchar(&buffer, c);
			if (ret_val < 0)
				return (-1);

			bytes_printed += ret_val;
			continue;
		}

		ret_val = format_handler(args, &fmt, &buffer);
		if (ret_val < 0)
			return (-1);

		bytes_printed += ret_val;
	}

	va_end(args);
	ret_val = buffer_flush(&buffer);
	if (ret_val < 0)
		return (-1);

	return (bytes_printed + ret_val);
}
