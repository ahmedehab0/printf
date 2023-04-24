#include "main.h"
int handle_print(const char *format, int i, va_list list);
/**
* _printf - prints out string and arguments
* @format: string to print
* Return: size of string -1 if fail
*/

int _printf(const char *format, ...)
{
	int i, pc = 0, p = 0;
	va_list list;


	if (!format)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			(pc == -1) ? (_putchar(format[i])) : (pc += _putchar(format[i]));
		}
		else
		{
			if (!format[i + 1])
				pc = -1;
			p = handle_print(format, i + 1, list);
			if (p == -1)
				pc = -1;
			else if (p == 0)
				pc += _putchar(format[i + 1]);
			else
				pc += p;
			i++;
						
		}
	}
	va_end(list);
	return (pc);
}

/**
 * handle_print - takes care of printing
 * @format: pointer to format string
 * @i: index of char
 * @list: arguments
 * Return: size of print or -1 if fail
 */


int handle_print(const char *format, int i, va_list list)
{
	ff function[] = {
		{'c', print_char}, {'s', print_str},
		{'%', print_37}, {'i', print_int},
		{'d', print_int}, {'\0', NULL}
	};
	int j;

	for (j = 0; j < 6; ++j)
	{
		if (function[j].c == format[i])
			return (function[j].print(list));
	}
	return (-1);
}
