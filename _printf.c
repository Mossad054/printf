#include "main.h"

void print_buff(char buffer[], int *buff_index);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int j, print = 0, print_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list arg;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_index++] = format[j];
			if (buff_index == BUFF_SIZE)
				print_buff(buffer, &buff_index);
			/* write(1, &format[i], 1);*/
			print_chars++;
		}
		else
		{
			print_buff(buffer, &buff_index);
			flags = get_flags(format, &j);
			width = get_width(format, &j, arg);
			precision = get_precision(format, &j, arg);
			size = get_size(format, &j);
			++j;
			print = han_print(format, &j, arg, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_chars += print;
		}
	}

	print_buff(buffer, &buff_index);

	va_end(arg);

	return (print_chars);
}

/**
 * print_buff - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_index: Index at which to add next char, represents the len.
 */
void print_buff(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
