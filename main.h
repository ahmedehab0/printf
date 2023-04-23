#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_MAX 1024

/**
* struct flags - struct containing pointers to functions
*
* @in: format
* @out: pointer to function assosciated
*/
struct flags
{
	char in;
	int (*out)(va_list, char[], int, int, int, int);
};

/**
* typedef struct flags ff - struct definition
*
* @flags: format
* @ff: function assosciated
*/

typedef struct flags ff;

int _printf(const char format[], ...);
int handle_print(const char *fmt, int *i, va_list list,
	char buffer[], int flags, int width, int precision, int size);

/*functions to handle specifiers*/

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_hexa(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags,
	int width, int precision, int size);


/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13(va_list types, char buffer[], int flags,
	int width, int precision, int size);

#endif
