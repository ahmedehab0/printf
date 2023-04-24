#include "main.h"
/**
 * print_char - Prints a char
 * Return: number of characters printed
 * @args: argument
 */
int print_char(va_list args)
{
char c = va_arg(args, int);

write(STDOUT_FILENO, &c, 1);
return (1);
}
/**
 * print_str - prints a string
 * @args: argument
 * Return: number of character printed
 */
int print_str(va_list args)
{
const char *s = va_arg(args, const char*);
int len = strlen(s);

write(STDOUT_FILENO, str, len);
return (len);
}
/**
 * print_int - prints an integer.
 * @args: argument
 * Return: number of chars printed
 */

int print_int(va_list args)
{
int n = va_arg(args, int);
char buffer[16];
int i, count = 0;

	if (list == NULL)
		return (-1);
if (n < 0)
{
write(STDOUT_FILENO, '-', 1);
n = -n;
count++;
}
for (i = 0; i < n; i++)
{
buffer[i++] = '0' + (n % 10);
n /= 10;

}
while (i > 0)
{
write(STDOUT_FILENO, buffer[--i], 1);
count++;
}
return (count);
}
/**
 * print_37 - Prints a percent sign
 * Return: Number of chars printed
 */
int print_37(void)
{
	return (_putchar('%'));
}
