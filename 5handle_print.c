#include "main.h"
/**
 * handle_print - Prints an arg based on its type
 * @format: Formatted str in which to print the arguments.
 * @arg: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int han_print(const char *format, int *ind, va_list arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	format_t format_type[] = {
		{'c', func_char_print}, {'s', func_print_str}, {'%', func_print_prcnt},
		{'i', func_prnt_int}, {'d', func_prnt_int}, {'b', func_prnt_bnry},
		{'u', func_prnt_unsgd}, {'o', func_prnt_octl}, {'x', func_prnt_hexa},
		{'X', func_prnt_hexa_up}, {'p', print_ptr}, {'S', non_printable},
		{'r', print_rvrse}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (i = 0; format_type[i].format != '\0'; i++)
		if (format[*ind] == format_type[i].format)
			return (format_type[i].func(arg, buffer, flags, width, precision, size));

	if (format_type[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
