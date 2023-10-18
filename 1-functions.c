#include "main.h"
/**
 * func_prnt_unsgd - outputs an unsigned number
 * @type: arguments
 * @buffer: Buff arr to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int func_prnt_unsgd(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);

	num = convert_size_unsign(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_unsign(0, k, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * func_prnt_octl- Output unsigned number in octal.
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flags:   calculate flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of character printed
 */
int func_prnt_octl(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{

	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsign(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[k--] = '0';

	k++;

	return (write_unsign(0, k, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * func_prnt_hexa - Output unsigned number in hexadecimal
 * @type: arguments
 * @buffer: Buffer array to handle print
 * @flags:  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num character ouput
 */
int func_prnt_hexa(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	return (func_prnt_hexadecimal(type, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * func_prnt_hexa_up - Output unsigned number in upper hexadecimal
 * @type: arguments
 * @buffer: Buff arr to handle print
 * @flags:  Calculates  flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Num of chars printed
 */
int func_prnt_hexa_up(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	return (func_prnt_hexadecimal(type, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * func_prnt_hexadecimal - Output hexa number in lower or upper
 * @type: arguments
 * @map: Arr of value to map the number
 * @buffer: Buff arr to handle print
 * @flags:  Calculates  flags
 * @flag_char: Calculates  flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * @size: Size specifier
 * Return: Num of chars ouput
 */
int func_prnt_hexadecimal(va_list type, char map[], char buffer[],
	int flags, char flag_char, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsign(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_char;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsign(0, i, buffer, flags, width, precision, size));
}
