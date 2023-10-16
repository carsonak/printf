#include "main.h"


/**
  * _printf - produces output according to a format.
  *
  *@format: format to be passed to _printf function.
  *
  *
  */
int _printf(const char *format, ...)
{
	int index;
	va_list args;
	int num = 0;

	va_start(args, format);
	for (index = 0; format[index] != '\0'; index++)
	{
		char *ch = malloc(sizeof(char));
		if (format[index] == '%' && format[index + 1] == 'c')
		{
			*ch = va_arg(args, int);
			write(1, ch, sizeof(char));
			num += 1;
			index++;
		}
		else if (format[index] == '%' && format[index + 1] == 's')
		{
			char *str = va_arg(args, char *);
			write(1, str, strlen(str));
			num += strlen(str);
			index++;
		}
		else
		{
			*ch = format[index];
			write(1, ch, sizeof(char));
			num += 1;
		}
	}
	va_end(args);
	return (num);
}
