#include "main.h"
/**
 * get_width - Calculates the width for printing
 * @format: Formatted str in which to print the arg
 * @i: arg of arguments to be printed.
 * @arg: list of arg
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list arg)
{
	int curr_b;
	int width = 0;

	for (curr_b = *i + 1; format[curr_b] != '\0'; curr_b++)
	{
		if (digit(format[curr_b]))
		{
			width *= 10;
			width += format[curr_b] - '0';
		}
		else if (format[curr_b] == '*')
		{
			curr_b++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*i = curr_b - 1;

	return (width);
}
