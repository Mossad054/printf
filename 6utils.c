#include "main.h"
/**
 * is_print - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa - Append hexadecimal  to buffer
 * @buffer: Arr of chars.
 * @i: Ind at which to start appending.
 * @ascii_code: ASSCI CODE.
 *
 * Return:  3
 */
int append_hexa(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];

	return (3);
}

/**
 * digit - Verify if a char is a digit
 * @c: Char  evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_num - Convert  num to spec size
 * @num: Num casted
 * @size: Num indicating the type to be casted.
 *
 * Return: Cast value of num
 */
long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsign - Conv  num to  specified size
 * @num: Num cast
 * @size: Num indicating type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsign(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
