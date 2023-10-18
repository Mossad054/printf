#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - op
 *
 * @format: format.
 * @func: function associated.
 */
struct format
{
	char format;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - op
 *
 * @format: format.
 * @format_t: format function associated.
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int han_print(const char *format, int *i,
va_list  arg, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int func_char_print(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int func_print_str(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int func_print_prcnt(va_list type, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int func_prnt_int(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int func_prnt_bnry(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int func_prnt_unsgd(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int func_prnt_octl(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int func_prnt_hexa(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int func_prnt_hexa_up(va_list type, char buffer[],
	int flags, int width, int precision, int size);

int func_prnt_hexadecimal(va_list type, char map[],
char buffer[], int flags, char flag_char, int width, int precision, int size);

/* Function to print non printable characters */
int non_printable(va_list type, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_ptr(va_list type, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list arg);
int get_precision(const char *format, int *i, va_list arg);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_rvrse(va_list type, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13str(va_list type, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int han_write_num(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int handle_write_num(int ind, char bff[], int flags, int width, int precision,
	int len, char padd, char extra_c);
int write_ptr(char buffer[], int ind, int len,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsign(int negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_print(char);
int append_hexa(char, char[], int);
int digit(char);

long int convert_size_num(long int num, int size);
long int convert_size_unsign(unsigned long int num, int size);

#endif
