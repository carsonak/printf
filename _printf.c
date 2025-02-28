#include "main.h"

#define PRINTF_BUFFER_LENGTH (1024U)

/**
 * _printf - prints a string and checks for any format specifiers inside it
 * @format: - a formatted string
 *
 * Return: number of characters printed, or an error number
 */
int _printf(const char *format, ...)
{
	va_list args;
	int bytes_printed = 0, ret_val = 0;
	string fmt;
	char arr[PRINTF_BUFFER_LENGTH];
	char_arr buffer;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	fmt.size = -1;
	fmt.i = 0;
	fmt.s = format;
	buffer.size = sizeof(arr);
	buffer.i = 0;
	buffer.buf = arr;
	for (fmt.i = 0, buffer.i = 0; fmt.s[fmt.i]; ++buffer.i, ++fmt.i)
	{
		if (buffer.i >= buffer.size)
		{
			ret_val = flush_buffer(&buffer);
			if (ret_val < 0)
				goto error_handling;

			bytes_printed += ret_val;
		}

		if (format[fmt.i] != '%')
		{
			buffer.buf[buffer.i] = format[fmt.i];
			continue;
		}

		++fmt.i;
		if (format[fmt.i] == '\0')
			break;

		ret_val = format_handler(args, &fmt, &buffer);
		if (ret_val < 0)
			goto error_handling;

		bytes_printed += ret_val;
	}

	va_end(args);
	ret_val = flush_buffer(&buffer);
	if (ret_val < 0)
	{
error_handling:
		return (-1);
	}

	return (bytes_printed + ret_val);
}
