#include "main.h"
/**
 * get_size -Calculates the size to the argument
 * @format: Formatted string in which to print the arg
 * @i: List of arguments printed
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_b = *i + 1;
	int size = 0;

	if (format[curr_b] == 'l')
		size = S_LONG;
	else if (format[curr_b] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_b - 1;
	else
		*i = curr_b;

	return (size);
}
