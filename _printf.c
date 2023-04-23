#include "main.h"
void handle_BUFF(char c[], int *i);
/**
* _printf - prints out string and arguments
* @format: string to print
* Return: size of string
*/

int _printf(const char *format, ...)
{
	int i, Bi = 0, f, w, p, s, pc = 0, c = 0;
	va_list list;
	char BUFF[BUFF_MAX];

	if (!format)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			BUFF[Bi++] = format[i];
			pc++;
			if (Bi == BUFF_MAX)
				handle_BUFF(BUFF, &Bi);
		}
		else
		{
			handle_BUFF(BUFF, &Bi);
			f = get_flags(format, &i);
			w = get_width(format, &i, list);
			p = get_precision(format, &i, list);
			s = get_size(format, &i);
			i++;
			c = handle_print(format, &i, list, BUFF, f, w, p, s);
			if (c == -1)
				return (-1);
			pc += c;
		}
	}
	handle_BUFF(BUFF, &Bi);
	va_end(list);
	return (pc);
}

/**
* handle_BUFF - prints out to stdout
* @c: string to print
* @i: index to print to
*/

void handle_BUFF(char c[], int *i)
{
	if (*i > 0)
		write(1, c, *i);
	*i = 0;
}
