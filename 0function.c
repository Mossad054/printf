#include "main.h"
/**
 * func_char_print- Prints a character
 * @type:  arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int func_char_print(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(type, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * func_print_str - output a string
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int func_print_str(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(type, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * func_print_prcnt - output percent
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int func_print_prcnt(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(type);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * func_prnt_int - output integer
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int func_prnt_int(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int negative = 0;
	long int n = va_arg(type, long int);
	unsigned long int num;

	n = convert_size_num(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (han_write_num(negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * func_prnt_bnry - Output an unsigned number
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int func_prnt_bnry(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int j, k, l, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(type, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	a[0] = j / k;
	for (l = 1; l < 32; l++)
	{
		k /= 2;
		a[l] = (j / k) % 2;
	}
	for (l = 0, sum = 0, count = 0; l < 32; l++)
	{
		sum += a[l];
		if (sum || l == 31)
		{
			char z = '0' + a[l];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
