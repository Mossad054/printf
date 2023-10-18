#include "main.h"
/**
 * get_precision - Calculates the prec for printing
 * @format: Format str in which to print the arguments
 * @i: List of arguments to be printed.
 * @arg: list of arguments.
 *
 * Return: Prec
 */
int get_precision(const char *format, int *i, va_list arg)
{
	int curr_b = *i + 1;
	int precision = -1;

	if (format[curr_b] != '.')
		return (precision);

	precision = 0;

	for (curr_b += 1; format[curr_b] != '\0'; curr_b++)
	{
		if (digit(format[curr_b]))
		{
			precision *= 10;
			precision += format[curr_b] - '0';
		}
		else if (format[curr_b] == '*')
		{
			curr_b++;
			precision = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*i = curr_b - 1;

	return (precision);
}
