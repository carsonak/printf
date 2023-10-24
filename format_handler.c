#include "main.h"

/**
 * format_handler - checks format specifier and executes the right functions
 * @args: the argument to be formatted
 * @format: the format string
 * @fmt_i: index of the format string
 * @buf: pointer to character buffer
 * @buf_i: pointer to current index of the buffer
 *
 * Return: the number of characters printed, -1 if format doesn't match
 */
int format_handler(va_list args, const char *const format,
				   int fmt_i, char *const buf, int *const buf_i)
{
	long int b, i_cpy = *buf_i;
	int nob = 0;
	f_w_p *edits = malloc(sizeof(*edits) * 4);
	c_sp fmts[] = {{'c', print_c},
				   {'s', print_s},
				   {'%', print_pc},
				   {'d', print_Rnum},
				   {'i', print_Rnum},
				   {'b', print_b},
				   {'o', print_oct},
				   {'u', print_dec},
				   {'x', print_lower_hexa},
				   {'X', print_upper_hexa},
				   {'p', print_p},
				   {'\0', NULL}};

	for (b = 0; fmts[b].ch; b++)
	{
		if (format[fmt_i] == fmts[b].ch)
		{
			nob += fmts[b].f(args, buf, buf_i);
			break;
		}
		else
			fwp(format[fmt_i], -1, edits, buf, buf_i);
	}

	nob += fwp('G', (*buf_i - i_cpy), edits, buf, buf_i);
	free(edits);
	if (fmts[b].ch == '\0')
		return (-1);

	return (nob);
}

/**
 * fwp - handles the flags, width, precision and length modifiers
 * @mod: modifier specifier
 * @num_len: number of digits in the number
 * @edits: pointer to an array of structures
 * @buf: the buffer
 * @buf_i: current buffer index
 *
 * Return: number of bytes printed if any
 */
int fwp(int mod, int num_len, f_w_p *edits, char *const buf,
		int *const buf_i)
{
	int nob = 0, b;

	edits[0].gate = false;
	edits[0].ch = ' ';
	edits[0].f = print_plus;

	edits[1].gate = false;
	edits[1].ch = '+';
	edits[1].f = print_plus;

	edits[2].gate = false;
	edits[2].ch = '#';
	edits[2].f = print_prefix;

	edits[3].gate = false;
	edits[3].ch = '\0';
	edits[3].f = NULL;

	if (num_len < 0 && mod != 'G')
	{
		for (b = 0; edits[b].ch; b++)
			if (mod == edits[b].ch)
				edits[b].gate = true;
	}
	else
	{
		for (b = 0; edits[b].ch; b++)
			if (edits[b].gate)
				return (edits[b].f(num_len, buf, buf_i, mod));
	}

	return (nob);
}
