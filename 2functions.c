#include "main.h"
int print_ptr(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1; /* len=2, for '0x' */
	unsigned long num_addrs;
	char map[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_ptr(buffer, ind, len,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * non_printable - output ASCII codes in hexa of non printable char
 * @type: arguments
 * @buffer: Buff arr to handle print
 * @flags:  Calculates  flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Num of chars output
 */
int non_printable(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, off = 0;
	char *str = va_arg(type, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_print(str[i]))
			buffer[i + off] = str[i];
		else
			off += append_hexa(str[i], buffer, i + off);

		i++;
	}

	buffer[i + off] = '\0';

	return (write(1, buffer, i + off));
}

/************************* PRINT REVERSE *************************/
/**
 * print_rvrse - output reverse string.
 * @type: arguments
 * @buffer: Buff arrto handle print
 * @flags:  Calculates  flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Num of chars output
 */

int print_rvrse(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(type, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13str - ouput string in rot13.
 * @type: arguments
 * @buffer: Buff arr to handle print
 * @flags:  Calculates  flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num of chars output
 */
int print_rot13str(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				y = out[j];
				write(1, &y, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			y = str[i];
			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
